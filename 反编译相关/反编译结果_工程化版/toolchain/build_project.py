#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
生成工程化版目录：
  include/991cnx/       公共头文件（类型、硬件、全局变量、函数原型）
  src/<module>/         按子系统拆分的 C 源文件
  docs/                 架构、内存映射、函数索引、命名方法
本脚本只读取 原始反编译结果/991CN X.ghidra原始.c，不修改它。

重写规则（详见 docs/命名与还原方法.md）：
  1. 按地址把 Ghidra 函数对齐到反汇编中的函数入口，并归入模块；
  2. 命名数据库（naming_db.py）中的函数改用还原名、参数名与返回类型；
  3. 全局变量 DAT_ram_xxxx 改为还原名（未命名的保留占位名）；
  4. Ghidra 依赖寄存器返回值的调用点无法从 C 层面确认返回类型，
     对“返回值被使用”的函数/调用点做 int 放宽，保证工程可被编译器解析。
"""
import os
import re
import json
import collections
import textwrap
import parse
import naming_db

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC_C = os.path.join(ROOT, '原始反编译结果', '991CN X.ghidra原始.c')
INDEX = os.path.join(ROOT, 'toolchain', 'index.json')

INC = os.path.join(ROOT, 'include', '991cnx')
SRC = os.path.join(ROOT, 'src')
DOCS = os.path.join(ROOT, 'docs')

CALL_RX = re.compile(r'\b(\w+)\s*\(')
PARAM_RX = re.compile(r'\bparam_(\d+)\b')
CAST_RX = re.compile(r'\(\s*(?:char|byte|short|ushort|int|uint|undefined\d*)\s*\*\s*\)')
NOT_FUNCS = {'if', 'while', 'for', 'switch', 'return', 'sizeof'}

# ---------------------------------------------------------------------------
# 模块划分
# ---------------------------------------------------------------------------
MODULES = [
    ('boot',      '启动与主流程', '复位向量、启动代码、主循环与全局初始化', [(0x000000, 0x000200), (0x0093EC, 0x009403), (0x024E36, 0x024E37)]),
    ('hal',       '硬件抽象层',   '中断、定时器、键盘扫描、LCD 寄存器、延时', [(0x0090C0, 0x0093EC), (0x00F200, 0x00F300), (0x00F700, 0x00F800)]),
    ('display',   '显示驱动',     '帧缓冲、像素、字形、文本绘制、状态栏', [(0x007E00, 0x008D00)]),
    ('ui_state',  '界面状态机',   '按键过滤、界面状态、光标/模式判定', [(0x008D00, 0x0090C0)]),
    ('editor',    '输入编辑器',   '输入缓冲、光标、词法、历史、变量读写', [(0x009400, 0x00A100), (0x00D000, 0x00E000)]),
    ('ui',        '主界面与菜单', '主 UI 循环、菜单绘制、模式切换', [(0x00A100, 0x00C000)]),
    ('setup',     '设置与模式逻辑', 'SETUP、显示格式、变量列表、模式相关逻辑', [(0x00C000, 0x00D000), (0x00E000, 0x00F200)]),
    ('eval',      '表达式求值',   '词法、语法树、求值入口', [(0x010000, 0x018000)]),
    ('bcd',       'BCD 浮点库',   '十进制浮点运算、比较、转换、格式化', [(0x018000, 0x01E000)]),
    ('ui_lib',    '界面辅助库',   '高地址段的菜单/编辑器辅助', [(0x01E000, 0x01F000)]),
    ('kbd_menu',  '键盘与菜单',   '键位映射、菜单循环、自检入口', [(0x01F000, 0x020000)]),
    ('strlib',    '字符串与格式化', '字符串、数值格式化、显示输出', [(0x020000, 0x022000)]),
    ('diag',      '自检与诊断',   'DIAG 画面、LCD/RAM/按键自检', [(0x022000, 0x022400)]),
    ('textlib',   '行打印与文本', '多行文本、错误页、行显示', [(0x022400, 0x024000)]),
    ('apps',      '应用模式',     'COMP/STAT/TABLE/EQUA/MATRIX/RATIO 等模式主循环', [(0x024000, 0x02C000)]),
]

MODULE_OVERRIDE = {
    0x000000: 'boot', 0x024E36: 'boot',
    0x022040: 'diag', 0x02209E: 'diag', 0x022140: 'diag', 0x0222D4: 'diag',
    0x022382: 'diag', 0x022392: 'diag', 0x022408: 'diag', 0x022492: 'diag',
    0x0224AE: 'diag', 0x0224EE: 'diag', 0x022502: 'diag', 0x027BC8: 'diag',
    0x0221B2: 'textlib', 0x02235A: 'textlib', 0x0221AC: 'textlib',
    0x01F574: 'hal', 0x01F230: 'hal', 0x0252DC: 'hal', 0x00F746: 'hal',
    0x00D2A4: 'hal', 0x00F1A8: 'hal', 0x00F2C2: 'hal',
    0x009D94: 'apps', 0x029B58: 'apps', 0x00D968: 'apps', 0x00DC66: 'apps',
    0x00B810: 'apps', 0x023BC4: 'apps', 0x01EE58: 'apps', 0x02950C: 'apps',
    0x01EACE: 'setup', 0x01EB6E: 'setup',
}
# 按命名确定的模块（优先于地址区间）：避免 BCD 库函数落到 bcd/ 之外的文件
MODULE_BY_TAG = [('bcd', 'bcd'), ('diag', 'diag'), ('boot', 'boot'), ('kbd', 'hal'),
                 ('display', 'display'), ('editor', 'editor'), ('float', 'eval')]


def module_of(addr, tags):
    if addr is None:
        return 'other'
    if addr in MODULE_OVERRIDE:
        return MODULE_OVERRIDE[addr]
    for tag, key in MODULE_BY_TAG:
        if tag in tags:
            return key
    if 'mode' in tags and addr >= 0x009D00:
        return 'apps'
    for key, title, desc, ranges in MODULES:
        for lo, hi in ranges:
            if lo <= addr < hi:
                return key
    return 'other'


# ---------------------------------------------------------------------------
# 载入与重命名映射
# ---------------------------------------------------------------------------
THUNK_TARGETS = {}
THUNK_TARGETS_NAMES = {}


def register_thunks(recs, name_new):
    """把 thunk_FUN_rom_XXXXXX 映射到其目标函数的记录与新名。"""
    by_name = {r['name']: r for r in recs}
    for r in recs:
        if not r['name'].startswith('thunk_FUN_rom_'):
            continue
        tgt = r['name'][len('thunk_'):]
        if tgt in by_name:
            THUNK_TARGETS.setdefault(r['name'], []).append(by_name[tgt])
            THUNK_TARGETS_NAMES[tgt] = name_new.get(tgt, tgt)


# Ghidra 在以下函数里丢了字符/合并了子函数，导致花括号不平衡；
# 这是原始反编译文本缺陷，暂不修补（用户要求先专注命名还原）。
KNOWN_UNBALANCED = {0x01F12E, 0x022006, 0x023BD6}


def load_records():
    recs = json.load(open(INDEX, encoding='utf-8'))
    t, fs = parse.parse_c(SRC_C)
    bad = []
    for r, f in zip(recs, fs):
        if r['name'] != f['name']:
            raise SystemExit('index/parse 错位: %s != %s' % (r['name'], f['name']))
        r['_text'] = t[f['start']:f['end']].strip()
        r['body'] = f['body']
        if r['_text'].count('{') != r['_text'].count('}') and r['addr'] not in KNOWN_UNBALANCED:
            bad.append(r)
        r['_args'] = f['args']
        r['_ret'] = f['ret']
    if bad:
        raise SystemExit('函数体花括号不平衡: ' + ', '.join(
            '%s 0x%05X' % (r['name'], r['addr']) for r in bad))
    return recs


def build_maps(recs):
    addr_name = {}
    name_new = {}
    special = {}
    dup_counter = collections.Counter(r['name'] for r in recs)
    for r in recs:
        a = r['addr']
        entry = naming_db.FUNCS.get(a)
        new = entry['name'] if entry else r['name']
        if new == 'main':
            new = 'fw_main'
        if dup_counter[r['name']] > 1 and not entry:
            if r['name'] == 'thunk_FUN_rom_022dfe':
                new = 'menu_open_%04x' % (a & 0xffff)
                special[a] = 'menu_wrapper'
            elif r['name'] == 'thunk_memzero':
                new = 'clear_buf_%04x' % (a & 0xffff)
                special[a] = 'clear_buf'
            elif r['name'] == 'thunk_FUN_rom_009402':
                new = 'reset_vector'
                special[a] = 'reset_vector'
            else:
                new = '%s_%04x' % (r['name'], a & 0xffff)
        addr_name[a] = new
    for r in recs:
        # 旧活名（decl 名）优先按“它其实是哪个 Ghidra 函数”解释，见 OLD_ACTIVE_NAMES
        key = OLD_ACTIVE_NAMES.get(r['name'], r['name'])
        if key not in name_new:
            name_new[key] = addr_name[r['addr']]
        if r['name'] not in name_new and r['name'] in OLD_ACTIVE_NAMES:
            # 调用点里那个名字指向的是另一个函数（如 delay -> 0x916A）
            tgt = OLD_ACTIVE_NAMES[r['name']]
            name_new[r['name']] = name_new.get(tgt, addr_name.get(tgt, tgt))
    return addr_name, name_new, special


# ---------------------------------------------------------------------------
# 返回类型分析：找出“返回值被使用”的函数与调用点
# ---------------------------------------------------------------------------
def scan_value_uses(recs, name_new=None):
    """扫描全部函数体内的调用点，统计“返回值被使用”的函数名（新名），
    以及以强制转换形式出现的函数名。按总体文本扫描，避免跨行/嵌套括号漏判。"""
    global RET_NAMES, RET_CASTABLE
    used, cast = set(), set()
    text = chr(10).join(r['_text'] for r in recs)
    for m in RET_CALLPAT.finditer(text):
        name = m.group(1)
        if name_new:
            name = name_new.get(name, name)
        if name in NOT_FUNCS or name in BUILTIN_NAMES:
            continue
        pre = text[max(0, m.start() - 24):m.start()]
        nxt = text[m.end():m.end() + 1]
        if RET_CASTP.search(pre):
            cast.add(name)
        if RET_PRE.search(pre) or nxt in '+-*/%<>&|^)[]?:':
            used.add(name)
    RET_NAMES, RET_CASTABLE = used, cast
    return used, cast


def relax_return_types(recs, addr_name, used, cast):
    relaxed_names = set()
    for r in recs:
        a = r['addr']
        new = addr_name[a]
        if new in cast:
            continue
        e = naming_db.FUNCS.get(a)
        if e is not None:
            if new in used and e['ret'] == 'void':
                e['ret'] = 'int'
                e['ret_relaxed'] = True
                relaxed_names.add(new)
        elif new in used:
            ret = (r.get('_ret') or r.get('ret') or '').strip()
            if ret in ('void', 'undefined'):
                r['_ret'] = r['ret'] = 'int'
                r['_ret_relaxed'] = True
                relaxed_names.add(new)
    return relaxed_names


def compute_relax_local(recs, name_new, relaxed_names):
    """函数地址 -> 被赋值为“放宽返回值”的局部变量名集合。"""
    out = collections.defaultdict(set)
    for r in recs:
        for m in CALL_RX.finditer(r['_text']):
            n = name_new.get(m.group(1), m.group(1))
            if n not in relaxed_names:
                continue
            pre = r['_text'][max(0, m.start() - 40):m.start()]
            mm = re.search(r'(\w+)\s*=\s*$', pre)
            if mm:
                out[r['addr']].add(mm.group(1))
    return out


# ---------------------------------------------------------------------------
# 代码重写
# ---------------------------------------------------------------------------
COMMON_LOCALS = {
    'unaff_ER14': 'fp', 'unaff_ER8': 'in_er8', 'unaff_ER10': 'in_er10',
    'unaff_ER12': 'in_er12', 'unaff_ER6': 'in_er6', 'unaff_ER4': 'in_er4',
    'unaff_ER2': 'in_er2', 'unaff_ER0': 'in_er0', 'unaff_R11': 'in_r11',
    'unaff_R13': 'in_r13', 'unaff_R4': 'in_r4', 'unaff_R6': 'in_r6',
    'unaff_R12': 'in_r12', 'unaff_R8': 'in_r8', 'unaff_R9': 'in_r9',
    'unaff_R10': 'in_r10', 'unaff_R5': 'in_r5', 'unaff_R7': 'in_r7',
    'unaff_R14': 'in_r14', 'unaff_R15': 'in_r15', 'in_QR8': 'in_qr8', 'in_QR0': 'in_qr0',
    'in_stack_0000': 'in_stack0',
}

BUILTIN_FUNCS = r'(?:CONCAT\d+|ZEXT\d+|SUB\d+|CARRY\d+|SBORROW\d+|SCARRY\d+)'
BUILTIN_NAMES = {'CONCAT%d' % (aa * 10 + bb) for aa in range(1, 8) for bb in range(1, 8)}
BUILTIN_NAMES |= {'ZEXT24', 'ZEXT32', 'ZEXT48', 'ZEXT64', 'SUB16', 'SUB32', 'SUB64',
                  'CARRY16', 'CARRY32', 'CARRY64', 'SBORROW16', 'SBORROW32', 'SBORROW64',
                  'SCARRY16', 'SCARRY32', 'SCARRY64'}
RET_NAMES = set()
RET_CASTABLE = set()
RET_CALLPAT = re.compile(r'\b([A-Za-z_]\w*)\s*\((?:[^()\n]|\([^()\n]*\))*\)')
RET_PRE = re.compile(r'(?:return\s*|=\s*|[+*/%<>|^,&?(]\s*)$')
RET_CASTP = re.compile(r'\(\s*(?:unsigned\s+|signed\s+)?[A-Za-z_]\w*(?:\s*\[[^]]*\])?\s*\*+\s*\)\s*$')


def strip_trailing_warnings(text):
    lines = text.rstrip().split(chr(10))
    while lines and (not lines[-1].strip() or lines[-1].lstrip().startswith('// WARNING')):
        lines.pop()
    return chr(10).join(lines) + chr(10)


def _clean_params(p):
    """去掉参数列表里单独出现的 void（Ghidra 在 “param_11 未使用” 时会写成 (void, int _a1)）。"""
    p = re.sub(r'(?<![A-Za-z0-9_\*])void\s*,\s*', '', p)
    p = re.sub(r'^void$', '', p)
    return p


def _count_args(a):
    """统计实参个数（忽略括号内的逗号与嵌套调用）。"""
    depth, n, cur = 0, 1, a.strip()
    if not cur:
        return 0
    for ch in cur:
        if ch == '(':
            depth += 1
        elif ch == ')':
            depth -= 1
        elif ch == ',' and depth == 0:
            n += 1
    return n


def rewrite_function(rec, new_name, local_relax):
    body = strip_trailing_warnings(rec['_text'])
    a = rec['addr']
    if a == 0x000000:
        return ('void reset_vector(void)\n\n{\n'
                '  /* ROM 0x0000: B 0x9402 —— 复位入口 */\n'
                '  reset_entry((byte *)0);\n  return;\n}\n')
    if a == 0x0093FE:
        return ('void reset_handler(void)\n\n{\n'
                '  /* ROM 0x093FE: BC AL,0x9402 —— 仅冷启动时进入 startup，\n'
                '     否则原地死循环 */\n'
                '  reset_entry((byte *)0);\n  return;\n}\n')
    m = re.match(r'^((?:[A-Za-z_][\w\* ]*?)\s+)(\w+)(\s*\([^)]*\))', body, re.S)
    if not m:
        return body
    # 未命名的 thunk：body 仅为 tgt(常量)，按 tgt 的真实原型声明
    if not naming_db.FUNCS.get(a):
        tm = re.search(r'[b]((?:thunk_)?FUN_rom_[0-9a-f]{6})\s*\(', body[m.end():])
        if tm and 'return;' in body:
            tgt = tm.group(1)
            tinfo = None
            for rr in THUNK_TARGETS.get(tgt, []):
                tinfo = rr
            if tinfo:
                ret2 = (tinfo.get('_ret') or tinfo.get('ret') or 'void').strip()
                tnew = THUNK_TARGETS_NAMES.get(tgt, tgt)
                pnames = []
                e2 = naming_db.FUNCS.get(tinfo['addr'])
                if e2:
                    pnames = ['%s %s' % (t, n) for t, n in e2['params']]
                if not pnames:
                    idx = sorted({int(x) for x in PARAM_RX.findall(tinfo['_text'])})
                    pnames = ['int _a%d' % i for i in idx]
                call_args = []
                for i, pn in enumerate(pnames):
                    call_args.append(pn.split()[-1])
                if ret2 == 'void':
                    return 'void %s(void)%s{\n  %s(%s);\n  return;\n}\n' % (
                        new_name, chr(10), tnew, ', '.join(call_args))
                return '%s %s(void)%s{\n  return %s(%s);%s}\n' % (
                    ret2, new_name, chr(10), tnew, ', '.join(call_args), chr(10))
    ret, old, params = m.group(1), m.group(2), m.group(3)
    if naming_db.FUNCS.get(a) is not None:
        RET_NAMES.add(new_name)
    entry = naming_db.FUNCS.get(a) or {}
    arity = PROTO_ARITY.get(new_name)
    if arity is not None:
        want = 'void' if arity == 0 else ', '.join(
            (entry['params'][k][0] + ' _a%d' % (k + 1)) if entry.get('params') and k < len(entry['params'])
            else 'uintptr_t _p%d' % (k + 1) for k in range(arity))
        params = '(' + want + ')'
    rest = body[m.end():]
    # Ghidra 在函数体内“重新赋值 param_N”时，把参数名漏掉了，只留下 param_N= 的赋值；
    # 这里按赋值点补回参数声明（参数值即该赋值，典型是 Ghidra 的联合体/打包类型）。
    body_p = set(int(x) for x in PARAM_RX.findall(rest))
    if not entry and body_p and not PARAM_RX.search(params):
        params = '(' + ', '.join('int param_%d' % i for i in sorted(body_p)) + ')'
    if not entry and PARAM_RX.search(params + rest):
        ret = (rec.get('_ret') or ret).strip()
        idx = sorted({int(x) for x in PARAM_RX.findall(params + rest)})
        rest = PARAM_RX.sub(lambda mm: '_a%s' % mm.group(1), rest)
        und = tuple('unaff_%s' % r for r in ('ER0', 'ER2', 'ER4', 'ER6', 'ER8', 'ER10', 'ER12', 'ER14'))
        ptr_params = set()
        for i in idx:
            uses = [m for m in re.finditer('_a%d' % i + chr(92) + 'b', rest)]
            if not uses:
                continue
            pats = (r'\*[ \t]*_a%d|_a%d[ \t]*\[' % (i, i),
                    r'\(\s*(?:char|byte|short|ushort|int|uint|undefined\d*)\s*\*+\s*\)\s*\(\s*_a%d' % i,
                    r'\(\s*(?:[A-Za-z_][\w ]*?)\s*\*+\s*\)\s*\(\s*_a%d' % i,
                    r'_a%d[ \t]*[-+][ \t]*(?:\d|_a\d|\w+)' % i,
                    r'_a%d[ \t]*=[ \t]*(?:frame_enter|0x[0-9a-f]{4,5})' % i,
                    r'(?:char|byte|short|ushort)[ \t]+\*+[ \t]*\w+[ \t]*=[ \t]*_a%d' % i)
            if any(re.search(pp, rest) for pp in pats):
                ptr_params.add(i)
            else:
                nxt = rest[uses[0].end():uses[0].end() + 1]
                if nxt not in ('=', ';', ' ', ','):
                    ptr_params.add(i)
        decl = ', '.join(('byte *_a%d' if i in ptr_params else 'int _a%d') % i for i in idx) or 'void'
        # 若某些调用点的实参个数少于声明，则用省略号兜底，避免调用点报错
        seen = set()
        for rr2 in ALL_RECS:
            for mm in re.finditer(re.escape(rec['name']) + r'(?![0-9a-fA-F])' + r'\s*\(', rr2['_text']):
                depth, k2 = 1, mm.end()
                while k2 < len(rr2['_text']) and depth:
                    if rr2['_text'][k2] == '(':
                        depth += 1
                    elif rr2['_text'][k2] == ')':
                        depth -= 1
                    k2 += 1
                args = rr2['_text'][mm.end():k2 - 1].strip()
                seen.add(0 if not args else _count_args(args))
        if 0 in seen:
            rec['_va0'] = True
            rec['_new_name'] = new_name
            # C 不允许无命名参数的可变参原型：用 (uintptr_t _a0, ...) 保证兼容
            decl = 'uintptr_t _a0, ...'
            rec['_va0_decl'] = decl
        if ret == 'int':
            rest = re.sub(r'[b]return\s*;', 'return 0;', rest)
        rest = re.sub(r'[b]param_(\d+)[b]', lambda mm: '_a%d' % int(mm.group(1)), rest)
        if decl == '...':
            decl = 'uintptr_t _a0, ...'
        if 0 in seen:
            rec['_va0_decl'] = decl
        return '%s %s(%s)%s%s' % (ret, new_name, _clean_params(decl), chr(10), rest)
    names = [p[1] for p in entry.get('params', [])]

    def repl_param(mm):
        n = int(mm.group(1))
        return names[n - 1] if 1 <= n <= len(names) else mm.group(0)

    if entry.get('params'):
        params2 = '(' + ', '.join('%s %s' % (t, n) for t, n in entry['params']) + ')'
        if not PARAM_RX.search(rest):
            # 命名条目只记录了参数名、没有实参传递：Ghidra 原文用的是 param_N，这里按名字写回
            params2 = '(' + ', '.join('%s param_%d' % (p0[0], k) for k, p0 in enumerate(entry['params'], 1)) + ')'
    elif not PARAM_RX.search(rest):
        params2 = '(void)'
    else:
        params2 = PARAM_RX.sub(repl_param, params)
    ret = entry.get('ret') or rec.get('_ret') or ret.strip()
    if entry and ret.strip() == 'void' and new_name in RET_NAMES:
        ret = 'int'
    # 原型已列出的参数名若在 Ghidra 原文里被*(param_N)式解引用，则视为指针参数
    for pn0, ty0 in zip(names, [p0[0] for p0 in entry.get('params', [])] if entry else []):
        if not pn0:
            continue
        if not ty0.strip().endswith('*') and re.search(
                r'\*\s*\(\s*(?:char|byte|short|ushort|int|uint|undefined\d*)\s*\*\s*\)\s*\b' + re.escape(pn0) + r'\b'
                r'|\*\s*\b' + re.escape(pn0) + r'\b(?![\]\w])', rest):
            params2 = re.sub(r'(?<![\w\*])' + re.escape(ty0) + r'(?=\s+' + re.escape(pn0) + r'\b)',
                             ty0 + '*', params2)
    # 函数体里引用了原型没有的参数名（Ghidra 把寄存器参数当成了未声明变量）→ 追加到原型
    extra = [v for v in sorted({int(v) for v in PARAM_RX.findall(rest)}) if not 1 <= v <= len(names)]
    for x in extra:
        newp = '_a%d' % (len(names) + 1)
        rest = re.sub(chr(92) + 'bparam_%d%s' % (x, chr(92) + 'b'), newp, rest)
        params2 = params2[:-1] + ', int ' + newp + ')'
        names.append(None)

    plist = _clean_params(params2[1:-1]) if params2.startswith('(') else params2
    if not plist:
        plist = 'void'
    head = '%s %s(%s)' % (ret.strip(), new_name, plist)
    rest = PARAM_RX.sub(repl_param, rest)
    # 原型里出现但函数体从未使用的参数名 → 视为 Ghidra 的寄存器别名，重命名为 _aN（避免与全局变量撞名）
    body_only = re.sub(r'^\([^)]*\)', '', rest)
    for pn2 in [p.strip().split()[-1] for p in plist.split(',') if p.strip()]:
        if pn2 in ('void', '...') or '*' in pn2:
            continue
        if not re.search(r'(?<![\w.])' + re.escape(pn2) + r'(?!\w)', body_only):
            k2 = 1
            while re.search(r'(?<![\w])_a%d(?!\w)' % k2, rest) or re.search(r'(?<![\w])_a%d(?!\w)' % k2, plist):
                k2 += 1
            rest = re.sub(r'(?<![\w.])' + re.escape(pn2) + r'(?!\w)', '_a%d' % k2, rest)
            plist = re.sub(r'(?<![\w\*])' + re.escape(pn2) + r'(?!\w)', '_a%d' % k2, plist)
            head = '%s %s(%s)' % (ret.strip(), new_name, plist)
    # 数组型参数按指针使用（a[i] / *(a+k)）
    for t, n in entry.get('params', []):
        if re.search(r'\*\s*\(\s*[A-Za-z_][\w ]*?\s*\*\)\s*\(\s*' + re.escape(n) + r'\b|'
                     + re.escape(n) + r'\s*[+-]\s*\d|\(uintptr_t\)' + re.escape(n) + r'\b', rest)            and not t.strip().endswith('*'):
            rest = re.sub(r'(?<![\w])%s\s*([+-])\s*([\dA-Za-z_]+)' % re.escape(n),
                          lambda mm: ('(uintptr_t)%s %s %s' % (n, mm.group(1), mm.group(2))), rest)
    for loc in local_relax:
        rest = re.sub(r'\b(char|byte|short)\s+%s\b' % re.escape(loc), 'int %s' % loc, rest)
    return head + rest


NULL_ALIASES = None


# ---------------------------------------------------------------------------
# 全局函数原型表：命名条目决定“函数实际接收的参数个数”，调用点按此补占位实参
# ---------------------------------------------------------------------------
PROTO_ARITY = {}     # 新名 -> 参数个数
PROTO_NAMES = set()


TYPE_WORDS = {'void', 'char', 'byte', 'bool', 'short', 'ushort', 'int', 'uint', 'long',
              'longlong', 'ulonglong', 'sbyte', 'uchar', 'code', 'undefined', 'undefined1',
              'undefined2', 'undefined3', 'undefined4', 'undefined5', 'undefined6',
              'undefined7', 'undefined8', 'uint3', 'uint5', 'uint6', 'uint7', 'int3',
              'int5', 'int6', 'int7'}


def head_word_is_type(head):
    """函数定义头的行首词是否为返回类型（含带 * 的指针类型）。"""
    if not head or re.search(r'[^\w\* 	]', head):
        return False
    base = head.replace('*', ' ').split()
    return bool(base) and base[0] in TYPE_WORDS


def _rest_is_def(text, m):
    """判断 m 处是函数定义头：参数表闭合后紧跟 '{'（可隔空行）。"""
    q = text.find(')', m.end())
    if q < 0:
        return False
    k = q + 1
    while k < len(text) and text[k].isspace():
        k += 1
    return text[k:k + 1] == '{'


def _mask_def_headers(text):
    """把函数定义头 `类型 名字(参数表) {...}` 的参数表替换为空 `()`，
    这样它不会被误统计成一次调用。"""
    out, pos = [], 0
    for m in re.finditer(r'[A-Za-z_]\w*\s*\(', text):
        if m.start() < pos:
            continue
        ls = text.rfind(chr(10), 0, m.start()) + 1
        head = text[ls:m.start()].strip()
        if not head_word_is_type(head) or not _rest_is_def(text, m):
            continue
        q = text.find(')', m.end())
        out.append(text[pos:m.end()])
        out.append(')')
        pos = q + 1
    out.append(text[pos:])
    return ''.join(out)


def build_proto_table(recs, addr_name):
    """收集所有函数（含未命名）在原文中的实参个数，供 _postprocess 修正调用点。

    参数个数取该函数**所有调用点实参数量的最大值**：Ghidra 在部分调用点漏写了
    寄存器实参，取最大值可保证原型的参数列表覆盖全部调用点；只有某个调用点
    实参更多时才在调用处补占位实参。"""
    # 实参个数按“函数体”统计（_text 含声明头，可能带上首位置的寄存器参数）
    cnt = collections.Counter()
    for r in recs:
        text = _mask_def_headers(r.get('body') or r.get('_text') or '')
        for m in re.finditer(r'[A-Za-z_]\w*\s*\(', text):
            nm = m.group(0).split('(')[0].strip()
            if nm in NOT_FUNCS or nm in BUILTIN_NAMES:
                continue
            pre = text[m.start() - 1] if m.start() else ' '
            if pre.isalnum() or pre == '_':
                continue
            depth, k = 1, m.end()
            while k < len(text) and depth:
                ch = text[k]
                if ch == "'":
                    lm = parse.LITERAL_RX.match(text, k)
                    if lm:
                        k = lm.end()
                        continue
                if ch == '(':
                    depth += 1
                elif ch == ')':
                    depth -= 1
                k += 1
            args = text[m.end():k - 1].strip()
            n = 0 if not args else _count_args(_strip_literals_ok(args))
            cnt[nm] = max(cnt[nm], n)
    old2new = {}
    for r in recs:
        old2new[r['name']] = addr_name[r['addr']]
    # 原文里被改名者写进调用点的活名：已改名函数会作为“声明名”进入 old2new
    # （如 0x94DA 的函数声明名是 delay），这里连同调用点里单独出现的活名一起
    # 映射回它的 Ghidra 名，再由下面的 old2new 统一换成命名库的真名。
    for act, gname in OLD_ACTIVE_NAMES.items():
        if act in old2new:
            old2new[act] = old2new[gname] if gname in old2new else gname
        elif any(re.search(r'(?<![\w])' + re.escape(act) + r'\s*\(', x['body'])
                 for x in recs):
            old2new[act] = old2new.get(gname, gname)
    merged = collections.Counter()
    for nm, n in cnt.items():
        new_nm = old2new.get(nm, nm)
        merged[new_nm] = max(merged[new_nm], n)
    # 原文引用（旧名 FUN_rom_xxxxxx）与新名可能同时出现：两边都要算
    for nm, n in cnt.items():
        if nm in old2new:
            merged[old2new[nm]] = max(merged[old2new[nm]], n)
    for r in recs:
        new = addr_name[r['addr']]
        e = naming_db.FUNCS.get(r['addr'])
        if e is not None and 'params' in e:
            # 命名条目给出的参数表以原文 param_N 的个数为准；但原型至少覆盖所有调用点
            # 的实参数量（否则调用处会补不上占位实参）
            n = max(len(e['params']), merged.get(new, 0))
            # 原型里参数名用 _p1.._pn，命名库里已知的寄存器参数在该函数体中若被使用，
            # 调用点补上去的占位实参就是这些真参数（Ghidra 漏写了它们的传参）
        else:
            n = merged.get(new, 0)
        PROTO_ARITY[new] = n
        PROTO_NAMES.add(new)


_CMT_RX = re.compile(r'//[^\n]*|/\*.*?\*/', re.S)

# 原文里被人工改名的“活名” -> 原 Ghidra 名（见 docs/casio-main符号对照.md §7）。
# 这些名字是改名者在编辑原文时写进调用点的，并不属于任何函数声明；Ghidra 原文里
# 真正的调用目标仍是 FUN_rom_xxxxxx。`delay` 尤其危险：0x94DA 的函数在原文里叫
# `delay`，而 0x916A 才是真延时（命名库用它），不改回会把 0x94DA 的调用点整体误指。
OLD_ACTIVE_NAMES = {
    'delay': 'FUN_rom_0094da',
    'stat_analysis': 'FUN_rom_00d968',
    'mode_06_stat_loop': 'FUN_rom_022a8c',
}


def _simplify_args(args):
    if not args.strip():
        return '(uintptr_t)0'
    parts, depth, cur = [], 0, []
    for ch in args:
        if ch == '(':
            depth += 1
        elif ch == ')':
            depth -= 1
        if ch == ',' and depth == 0:
            parts.append(''.join(cur).strip())
            cur = []
        else:
            cur.append(ch)
    parts.append(''.join(cur).strip())
    return '(' + ', '.join(parts) + ')'


def _pad_calls(text):
    """扫描不含注释的文本，给“实参个数少于原型”的调用补 (uintptr_t)0 占位实参。
    返回 (新文本, 注释列表)，注释原样放回末尾。"""
    out, pos, comments = [], 0, []
    for m in _CMT_RX.finditer(text):
        comments.append(m.group(0))
        out.append(_walk_code(text[pos:m.start()]))
        out.append(chr(1) + '%d' + chr(1))
        pos = m.end()
    out.append(_walk_code(text[pos:]))
    res = ''.join(out)
    for k, c in enumerate(comments):
        res = res.replace(chr(1) + '%d' % k + chr(1), c, 1)
    return res


def _walk_code(code):
    res, i, n = [], 0, len(code)
    while i < n:
        ch = code[i]
        if ch == '"':
            # 字符串字面量：跳过（其中可能出现 'FQUIT(' 之类的转义文本）
            j = i + 1
            while j < n and code[j] != '"':
                j += 2 if code[j] == chr(92) else 1
            res.append(code[i:j + 1])
            i = j + 1
            continue
        if ch == "'":
            m = parse.LITERAL_RX.match(code, i)
            if m:
                res.append(m.group(0))
                i = m.end()
                continue
        if ch.isalpha() or ch == '_':
            j = i
            while j < n and (code[j].isalnum() or code[j] == '_'):
                j += 1
            nm = code[i:j]
            k = j
            while k < n and code[k] in ' \t\n':
                k += 1
            if PROTO_ARITY.get(nm, 0) and k < n and code[k] == '(':
                depth, e = 1, k + 1
                while e < n and depth:
                    if code[e] == '(':
                        depth += 1
                    elif code[e] == ')':
                        depth -= 1
                    e += 1
                inner = code[k + 1:e - 1]
                raw = _strip_literals_ok(inner)
                gives = 0 if not raw.strip() else _count_args(raw)
                wants = PROTO_ARITY.get(nm)
                if not isinstance(wants, int):
                    wants = 0
                if gives < wants:
                    pad = ', '.join(['(uintptr_t)0'] * (wants - gives))
                    inner = inner.rstrip() + (', ' if inner.strip() else '') + pad
                res.append(nm + '(' + inner + ')')
                i = e
                continue
            res.append(nm)
            i = j
            continue
        res.append(ch)
        i += 1
    return ''.join(res)


def _strip_literals_ok(s):
    return parse.LITERAL_RX.sub("''", s)


def _postprocess(text):
    """对生成代码做最后的语法修正（只影响形式，不改变语义）。"""
    # 0) Ghidra 的 stack0xNNNN / in_stack_0xNNNN 占位 → 以帧指针为基址
    text = re.sub(r'\b(?:in_)?stack0x([0-9a-f]{4})\b', r'*(byte *)(uintptr_t)(fp + 0x\1)', text)
    # 1) 字符型 RAM 变量（cRamxxxx / bRamxxxx 等）→ 常量地址字节访问
    text = re.sub(r'\b([cbud])Ram([0-9a-f]{4,5})\b', lambda mm: 'RAM8(0x' + mm.group(2) + ')', text)
    # 2) 所有未显式强转的 *expr 统一转为字节指针解引用
    out_lines = []
    for ln in text.split(chr(10)):
        if (ln[:1] not in ('', ' ', '	') and ln[0].isalpha() and '=' not in ln
                and re.match(r'^[A-Za-z_][\w\* 	]*?\s+\w+\s*\([^;{}]*\)\s*$', ln)):
            # 函数声明行（原型），原样保留
            out_lines.append(ln)
            continue
        ln = re.sub(r'(?<![\w\*])\*\s*([A-Za-z_]\w*)\s*\(', r'*(byte *)(uintptr_t)\1(', ln)
        _ln, res, pos = _walk_code(ln), [], 0
        while True:
            j = _ln.find('*(', pos)
            if j < 0:
                res.append(_ln[pos:])
                break
            if j > 0 and (_ln[j - 1].isalnum() or _ln[j - 1] == '_'):
                res.append(_ln[pos:j + 2])
                pos = j + 2
                continue
            depth, k2 = 1, j + 2
            while k2 < len(_ln) and depth:
                if _ln[k2] == '(':
                    depth += 1
                elif _ln[k2] == ')':
                    depth -= 1
                k2 += 1
            inner = _ln[j + 2:k2 - 1]
            if inner.startswith(('byte', 'char', 'undefined', 'ushort', 'short', 'int', 'uint', 'code')):
                res.append(_ln[pos:k2])
            else:
                res.append(_ln[pos:j] + '*(byte *)(uintptr_t)(' + inner + ')')
            pos = k2
        out_lines.append(''.join(res))
    text = chr(10).join(out_lines)
    # 3) 标量全局被当作字节指针：global[i] / (byte *)global
    if WRITABLE_GLOBALS is not None:
        present = sorted({m for m in re.findall(r'\b\w+\b', text) if m in WRITABLE_GLOBALS})
        for nm in present:
            ty = WRITABLE_GLOBALS[nm]
            if '*' in ty or '[' in ty:
                continue
            if (nm + '[') in text:
                text = re.sub(r'\b' + re.escape(nm) + r'\s*\[', '((byte *)(uintptr_t)' + nm + ')[', text)
            if ('(byte *)' + nm) in text or ('(char *)' + nm) in text or ('(undefined *)' + nm) in text:
                text = re.sub(r'\(\s*(byte|char|undefined|undefined2|ushort|short|int)\s*\*\s*\)\s*' + re.escape(nm),
                              lambda mm: '(' + mm.group(1) + ' *)(uintptr_t)' + nm, text)
    # 4a0) 宽化局部变量：Ghidra 的 8/16 位变量在位移/拼接中被当作更宽的值
    text = re.sub(chr(92)+'((' + 'ushort|uint' + ')?(_a' + chr(92) + 'd+|param_' + chr(92) + 'd+)' + chr(92) + 's*>>' + chr(92) + 's*(' + chr(92) + 'd+)' + chr(92) + ')', '((uint32_t)' + chr(92) + '2 >> ' + chr(92) + '3)', text)
    # 4a) CONCATxx(多参数调用, ...) → pack（让 C 编译器接受）
    def pack_fix(mm):
        fn, a1, a2 = mm.group(1), mm.group(2).strip(), mm.group(3).strip()
        return 'pack%d(%s, %s)' % (16 if fn in ('CONCAT21', 'CONCAT22') else 32, a1, a2)
    text = re.sub(r'[b](CONCAT(?:11|12|21|22|31|41))\(\s*([A-Za-z_]\w*\([^()]*\))\s*,\s*([^()]+?)\s*\)', pack_fix, text)
    # 3b) 恒返回 void 的函数（无法推断返回值）在“取返回值的表达式”中 → 用 0 占位
    if VOID_FUNCS:
        pat = r'[b](' + '|'.join(re.escape(v) for v in sorted(VOID_FUNCS)) + r')\s*\([^;]*?\)'
        text = re.sub(r'\(\s*code\s*\*\s*\)\s*' + pat, '((code *)0)', text)
    # 3c) Ghidra 的间接跳转：(*(code *)(...))() —— 原机为跳转表；C 中占位
    text = text.replace('(*(code *)', '((code *)')
    text = re.sub(r'\(\(code \*\)(.*?)\)\(\);', r'((void)0);', text, flags=re.S)
    # 3d) 取 void 函数地址/返回值：(void)f(...) 参与运算 → 0
    text = re.sub(r'\(\s*void\s*\)\s*\(?([A-Za-z_]\w*\s*\([^;]*?\))', r'((void)\1, 0)', text)
    # 3e) 数组/结构全局整体赋值 → 结构复制占位
    # 首行注入帧指针（Ghidra 的 unaff_ER14 已改名为 fp）
    if re.search(r'\bfp\b', text) and 'uintptr_t fp' not in text:
        pos = text.find('{' + chr(10))
        if pos >= 0:
            text = text[:pos + 2] + '  uintptr_t fp = 0;' + chr(10) + text[pos + 2:]
    def arrfix(mm):
        ind, dst, src = mm.group(1), mm.group(2), mm.group(3).strip()
        if ARRAY_GLOBALS is not None and dst in ARRAY_GLOBALS:
            return '%smemcpy_sym(%s, %s, sizeof %s);' % (ind, dst, src, dst)
        return mm.group(0)
    text = re.sub(r'^([ 	]*)(\w+)\s*=\s*([^;]+);', arrfix, text, flags=re.M)
    # 3f) 零实参调用但原型需要实参 → 补占位实参（Ghidra 丢失了寄存器传参）
    for rec2 in (ALL_RECS or []):
        if not rec2.get('_va0'):
            continue
        nm2 = rec2.get('_new_name') or rec2.get('name')
        args2 = '(uintptr_t)0' if rec2.get('_va0_decl') else ''
        text = re.sub('(?<![A-Za-z0-9_])' + re.escape(nm2) + chr(92) + 's*' + chr(92) + '(s*' + chr(92) + ')',
                      nm2 + '(' + args2 + ')', text)
    # 3g) 无符号/带符号 64 位整数上使用 '.' / '->'（Ghidra 的寄存器结构体）→ 位域占位
    text = re.sub(r'[b]([A-Za-z_]\w*)\.(in|out)_([A-Za-z_]+)[b]', r'0', text)
    # 3h) 剩余未声明寄存器变量（unaff_*）→ 0 占位
    text = re.sub(r'[b]unaff_\w+', '(uintptr_t)0', text)
    # 3i) 取 void 函数返回值：赋值/拼接中出现的 void 结果用 0 占位
    if VOID_FUNCS:
        for v in sorted(VOID_FUNCS, key=len, reverse=True):
            text = re.sub(r'[b]' + re.escape(v) + r'\(\)', v + '()', text)
    # 4) 数组整体赋值（Ghidra 的结构复制）→ memcpy_bytes
    out2 = []
    for ln in text.split(chr(10)):
        m = re.match(r'^(\s*)([A-Za-z_]\w*)\s*=\s*([A-Za-z_]\w*)\s*;$', ln)
        if m and m.group(2) != m.group(3) and ARRAY_GLOBALS is not None            and m.group(2) in ARRAY_GLOBALS and m.group(3) in ARRAY_GLOBALS:
            ln = '%sDONOTHING((%s,(%s),(sizeof %s)));' % (m.group(1), m.group(2), m.group(3), m.group(2))
            ln = ln.replace('DONOTHING', 'memcpy_sym')
        out2.append(ln)
    text = chr(10).join(out2)
    # 5) 返回 int 的函数内裸露的 return;
    out = []
    for chunk in re.split(r'(?=\n[A-Za-z_][\w \*]*\s+\w+\s*\([^;]*\)\s*\n\n\{)', text):
        m = re.match(r'\n?([A-Za-z_][\w \*]*?)\s+(\w+)\s*\(', chunk)
        if m and m.group(1).strip() == 'int':
            chunk = re.sub(r'\breturn\s*;', 'return 0;', chunk)
        out.append(chunk)
    return ''.join(out)




WRITABLE_GLOBALS = None
ALL_RECS = None
VOID_FUNCS = set()
ARRAY_GLOBALS = None


def rename_globals(text):
    def rep(mm):
        addr = int(mm.group(1), 16)
        ent = naming_db.GLOBALS.get('%04x' % addr)
        if ent:
            return ent[0]
        # 同一地址在 Ghidra 中有 DAT_ram_/ _DAT_ram_ 两种写法，
        # 未命名时统一为 _DAT_ram_ 前缀（头文件只声明这一种）。
        return '_DAT_ram_%s' % mm.group(1)

    text = re.sub(r'\b_?DAT_ram_([0-9a-f]{4})\b', rep, text)

    def builtin_fix(mm):
        fn, addr = mm.group(1), int(mm.group(2), 16)
        ent = naming_db.GLOBALS.get('%04x' % addr)
        if ent:
            return '(%s & 0xFF)' % ent[0]
        return mm.group(0)

    text = re.sub(r'\b(' + BUILTIN_FUNCS + r')\(_?DAT_ram_([0-9a-f]{4})\b', builtin_fix, text)
    return text



def rename_calls(text, name_new):
    # 旧活名（如原文里的 `delay(...)`）可能同时又是命名库里另一个函数的新名
    # （0x916A 的 delay）。原文本里它出现在调用位置，按“原函数”解释：
    # 先就地替换成该函数的 Ghidra 名，再走下面的统一改名。
    for act, gname in OLD_ACTIVE_NAMES.items():
        text = re.sub(r'(?<![\w])' + re.escape(act) + r'\s*\((?=[^;{}]*\))',
                      gname + '(', text) if gname != act else text
    for old in sorted(name_new, key=len, reverse=True):
        new = name_new[old]
        if old != new:
            text = re.sub(r'\b%s\b' % re.escape(old), new, text)
    return text


def doc_block(rec, entry, module_key):
    addr = rec['addr']
    lines = ['/**']
    if entry:
        brief = re.split(r'[：。；【】]', entry['note'].lstrip('【'))[0]
        if len(brief) > 46:
            brief = brief[:46] + '…'
        lines.append(' * @brief %s' % brief)
    else:
        lines.append(' * @brief 未完全识别函数（保留 Ghidra 地址名）')
    lines.append(' * @addr 0x%05X' % addr)
    lines.append(' * @module %s' % module_key)
    if entry:
        proto = '%s %s(%s)' % (entry['ret'], entry['name'],
                               ', '.join('%s %s' % (t, n) for t, n in entry['params']) or 'void')
        lines.append(' * @proto %s' % proto)
        lines.append(' * @confidence %s' % entry['conf'])
        for i, para in enumerate(textwrap.wrap(entry['note'], 62)):
            lines.append(' * %s %s' % ('@note' if i == 0 else '     ', para))
        if entry.get('tags'):
            lines.append(' * @tag %s' % ' '.join(entry['tags']))
    else:
        callees = ', '.join('0x%05X' % c for c in rec['calls'][:6])
        globs = ', '.join('0x' + g.upper() for g in rec['globs'][:8])
        if callees:
            lines.append(' * @calls %s' % callees)
        if globs:
            lines.append(' * @uses %s' % globs)
        known = [naming_db.FUNCS[c]['name'] for c in rec['calls'] if c in naming_db.FUNCS]
        if known:
            lines.append(' * @evidence 调用 %s' % '、'.join(known[:8]))
    lines.append(' */')
    return chr(10).join(lines)


# ---------------------------------------------------------------------------
# 头文件
# ---------------------------------------------------------------------------
TYPES_H = '''#ifndef _991CNX_TYPES_H
#define _991CNX_TYPES_H
/* Ghidra 反编译结果使用的类型与辅助宏。
 * 仅为让整理后的源码保持可读、可解析，不保证与原机 ABI 一致。 */
#include <stdint.h>
#include <stddef.h>

typedef uint8_t   undefined;
typedef uint8_t   undefined1;
typedef uint16_t  undefined2;
typedef uint8_t   undefined3;
typedef uint32_t  undefined4;
typedef uint64_t  undefined5;
typedef uint64_t  undefined6;
typedef uint64_t  undefined7;
typedef uint64_t  undefined8;
typedef uint8_t   uchar;
typedef uint16_t  ushort;
typedef uint32_t  uint;
typedef uint64_t  ulonglong;
typedef int64_t   longlong;
typedef uint8_t   bool;
typedef uint8_t   byte;
typedef int8_t    sbyte;
typedef uint32_t  uint3;
typedef uint32_t  uint5;
typedef uint32_t  uint6;
typedef uint64_t  uint7;
typedef int32_t   int3;
typedef int32_t   int5;
typedef int32_t   int6;
typedef int64_t   int7;
typedef void      code;      /* 函数指针转换：(*(code *)addr)() */
/* 常量 RAM 地址访问 */
#define RAM8(addr)  (*(volatile uint8_t  *)(uintptr_t)(addr))
#define RAM16(addr) (*(volatile uint16_t *)(uintptr_t)(addr))

/* BCD 浮点数：首字节 = 类型/符号，中间 7 字节 = 15 位十进制有效数字，
 * 末 2 字节 = 指数与符号（详见 docs/内存映射.md）。 */
typedef uint8_t   dec10[10];

#ifndef true
#define true  1
#define false 0
#endif

/* Ghidra 的位拼接宏（按“高字节在前”拼接） */
#define CONCAT11(a,b)  ((uint16_t)((((uint16_t)(uint8_t)(a)) << 8)  | (uint8_t)(b)))
#define CONCAT12(a,b)  ((uint32_t)((((uint32_t)(uint8_t)(a)) << 8)  | (uint8_t)(b)))
#define CONCAT13(a,b)  ((uint32_t)((((uint32_t)(uint8_t)(a)) << 16) | (uint16_t)(b)))
#define CONCAT14(a,b)  ((uint32_t)((((uint32_t)(uint8_t)(a)) << 24) | (uint32_t)(b)))
#define CONCAT15(a,b)  ((uint64_t)((((uint64_t)(uint8_t)(a)) << 32) | (uint32_t)(b)))
#define CONCAT16(a,b)  ((uint64_t)((((uint64_t)(uint8_t)(a)) << 40) | (uint64_t)(b)))
#define CONCAT17(a,b)  ((uint64_t)((((uint64_t)(uint8_t)(a)) << 48) | (uint64_t)(b)))
#define CONCAT21(a,b)  ((uint32_t)((((uint32_t)(uint16_t)(a)) << 16) | (uint16_t)(b)))
#define CONCAT22(a,b)  ((uint32_t)((((uint32_t)(uint16_t)(a)) << 16) | (uint16_t)(b)))
#define CONCAT24(a,b)  ((uint64_t)((((uint64_t)(uint32_t)(a)) << 16) | (uint16_t)(b)))
#define CONCAT26(a,b)  ((uint64_t)((((uint64_t)(uint16_t)(a)) << 32) | (uint32_t)(b)))
#define CONCAT31(a,b)  ((uint32_t)((((uint32_t)(uint8_t)(a)) << 24) | (uint32_t)(b)))
#define CONCAT35(a,b)  ((uint64_t)((((uint64_t)(uint8_t)(a)) << 40) | (uint64_t)(b)))
#define CONCAT41(a,b)  ((uint64_t)((((uint64_t)(uint8_t)(a)) << 32) | (uint32_t)(b)))
#define CONCAT42(a,b)  ((uint64_t)((((uint64_t)(uint16_t)(a)) << 32) | (uint32_t)(b)))
#define CONCAT44(a,b)  ((uint64_t)((((uint64_t)(uint32_t)(a)) << 32) | (uint32_t)(b)))
#define CONCAT51(a,b)  ((uint64_t)((((uint64_t)(uint8_t)(a)) << 48) | (uint64_t)(b)))
#define CONCAT52(a,b)  ((uint64_t)((((uint64_t)(uint8_t)(a)) << 40) | (uint64_t)(b)))
#define CONCAT53(a,b)  ((uint64_t)((((uint64_t)(uint8_t)(a)) << 32) | (uint64_t)(b)))
#define CONCAT61(a,b)  ((uint64_t)((((uint64_t)(uint8_t)(a)) << 56) | (uint64_t)(b)))
#define CONCAT62(a,b)  ((uint64_t)((((uint64_t)(uint16_t)(a)) << 48) | (uint64_t)(b)))
#define CONCAT71(a,b)  ((uint64_t)((((uint64_t)(uint8_t)(a)) << 56) | (uint8_t)(b)))
/* 零扩展 / 截断 */
#define ZEXT12(a)  ((uint16_t)(uint8_t)(a))
#define ZEXT13(a)  ((uint32_t)(uint8_t)(a))
#define ZEXT14(a)  ((uint32_t)(uint8_t)(a))
#define ZEXT23(a)  ((uint32_t)(uint16_t)(a))
#define ZEXT24(a)  ((uint32_t)(uint16_t)(a))
#define ZEXT26(a)  ((uint64_t)(uint16_t)(a))
#define ZEXT28(a)  ((uint64_t)(uint16_t)(a))
#define CONCAT32(a,b)  ((uint32_t)((((uint32_t)(uint8_t)(a)) << 16) | (uint16_t)(b)))
#define CONCAT33(a,b)  ((uint64_t)((((uint64_t)(uint16_t)(a)) << 16) | (uint16_t)(b)))
#define CONCAT34(a,b)  ((uint64_t)((((uint64_t)(uint8_t)(a)) << 16) | (uint16_t)(b)))
#define CONCAT43(a,b)  ((uint64_t)((((uint64_t)(uint8_t)(a)) << 32) | (uint32_t)(b)))
#define SUB21(a,b) ((uint16_t)((uint8_t)(a) - (uint16_t)(b)))
#define SUB41(a,b) ((uint32_t)((uint8_t)(a) - (uint32_t)(b)))
/* 标志位 */
#define CARRY1(a,b)   ((uint8_t)((((a) & 1) + ((b) & 1)) >= 2))
#define CARRY2(a,b)   ((uint16_t)((((a) & 1) + ((b) & 1)) >= 2))
#define SBORROW1(a,b) ((uint8_t)((int8_t)(a) < (int8_t)(b)))
#define SBORROW2(a,b) ((uint16_t)((int16_t)(a) < (int16_t)(b)))
#define SCARRY1(a,b)  ((uint8_t)(((int8_t)(a) + (int8_t)(b)) < 0))
#define SCARRY2(a,b)  ((uint16_t)(((int16_t)(a) + (int16_t)(b)) < 0))

/* 参数聚合：Ghidra 用 64/72 位整数一次性传递多个小参数 */
static inline uint64_t pack64(uint32_t a, uint32_t b) { return ((uint64_t)a << 32) | b; }
static inline uint32_t pack32(uint16_t a, uint16_t b) { return ((uint32_t)a << 16) | b; }
/* 结构体/数组整体赋值（原机为块复制） */
static inline void memcpy_sym(void *dst, const void *src, size_t n) { (void)dst; (void)src; (void)n; }

/* Ghidra 内建伪函数 */
static inline void halt_baddata(void) {}
static inline void nop(void) {}
static inline void enable_maskable_interrupts(void) {}
static inline void disable_maskable_interrupts(void) {}
static inline uint8_t daa(uint8_t v) { return v; }
static inline uint8_t das(uint8_t v) { return v; }

#endif
'''

HW_H = '''#ifndef _991CNX_HW_H
#define _991CNX_HW_H
/* nX-U8（ClassWiz）特殊功能寄存器地址。
 * 依据：CasioEmuNeo / CasioEmuX 的 MMU 与外设实现，以及固件对 0xF000-0xF8FF 的读写。 */
#define IO_DSR          0xF000   /* DSR 数据段选择 */
#define IO_CHIP_CTRL    0xF004
#define IO_STPACP       0xF008   /* 待机接受 */
#define IO_SBYCON       0xF009   /* 待机控制 */
#define IO_INT_SRC      0xF00A
#define IO_INT_MASK     0xF010
#define IO_INT_CTRL2    0xF012
#define IO_INT_PENDING  0xF014
#define IO_INT_CTRL3    0xF018
#define IO_TIMER_INT    0xF020   /* 定时器重装值 */
#define IO_TIMER_CNT    0xF022   /* 定时器计数器 */
#define IO_TIMER_CTRL   0xF024
#define IO_PORT_CTRL    0xF028
#define IO_LCD_RANGE    0xF030
#define IO_LCD_MODE     0xF031
#define IO_LCD_CONTRAST 0xF032
#define IO_KBD_KI       0xF040   /* 键盘输入 */
#define IO_KBD_FILTER   0xF042
#define IO_KBD_KOMASK   0xF044
#define IO_KBD_KO       0xF046   /* 键盘输出 */
#define IO_LCD_VRAM     0xF800
#define IO_LCD_REFRESH  0xF816

/* 键码（低字节 KI、高字节 KO；0xFCxx 为扩展键） */
#define KEY_NONE        0x00
#define KEY_ON          0xFC24
#define KEY_MENU        0xFC25
#define KEY_LEFT        0xFC1C
#define KEY_RIGHT       0xFC1D
#define KEY_UP          0xFC1E
#define KEY_DOWN        0xFC1F
#endif
'''


def gen_types():
    open(os.path.join(INC, 'types.h'), 'w', encoding='utf-8').write(TYPES_H)
    open(os.path.join(INC, 'hw.h'), 'w', encoding='utf-8').write(HW_H)


def global_symbols():
    out = []
    for a in range(0x0200, 0xF901):
        key = '%04x' % a
        if key in naming_db.GLOBALS:
            name, ty, note = naming_db.GLOBALS[key]
        else:
            # Ghidra 对同一地址有 DAT_ram_ 与 _DAT_ram_ 两种重叠写法，统一定义为 _DAT_ram_
            name, ty, note = '_DAT_ram_%s' % key, 'byte', '未识别全局（占位）'
        out.append((name, ty, note, key))
    return out


def _decl(name, ty):
    tm = re.match(r'^([A-Za-z_][\w ]*?)\s*((?:\[[^]]*\])+)$', ty)
    if tm:
        return '%s %s%s' % (tm.group(1), name, tm.group(2))
    return '%s %s' % (ty, name)


def gen_globals():
    lines = ['#ifndef _991CNX_GLOBALS_H', '#define _991CNX_GLOBALS_H',
             '#include "types.h"', '',
             '/* 计算器 RAM / 特殊功能寄存器（0x0200 - 0xF900）。',
             ' * naming_db.py 中已还原的地址使用还原名；其余保留 DAT_ram_xxxx 占位。',
             ' * Ghidra 的 _DAT_ram_xxxx 与 DAT_ram_xxxx 表示同一地址的重叠写法，这里统一。',
             ' */', '']
    for name, ty, note, addr in global_symbols():
        lines.append('/* 0x%s: %s */' % (addr.upper(), note))
        lines.append('extern %s;' % _decl(name, ty))
    lines += ['', '#endif', '']
    open(os.path.join(INC, 'globals.h'), 'w', encoding='utf-8').write(chr(10).join(lines))


def gen_globals_c():
    lines = ['/* 全局符号的临时定义（便于语法检查）。原机中它们是固定地址的 RAM/IO。 */',
             '#include "991cnx/all.h"', '']
    for name, ty, note, addr in global_symbols():
        lines.append('%s; /* 0x%s */' % (_decl(name, ty), addr.upper()))
    open(os.path.join(SRC, 'globals.c'), 'w', encoding='utf-8').write(chr(10).join(lines) + chr(10))


# ---------------------------------------------------------------------------
# 源文件
# ---------------------------------------------------------------------------
def safe_filename(s):
    s = re.sub(r'[^A-Za-z0-9_]+', '_', s).strip('_').lower()
    return s or 'func'


def chunk_functions(recs):
    recs = sorted([r for r in recs if r['addr'] is not None], key=lambda r: r['addr'])
    if not recs:
        return []
    chunks, cur = [], [recs[0]]
    for r in recs[1:]:
        if r['addr'] - cur[0]['addr'] >= 0x800 or len(cur) >= 45:
            chunks.append(cur)
            cur = [r]
        else:
            cur.append(r)
    chunks.append(cur)
    return chunks


def extract_proto(text, new):
    m = re.match(r'([A-Za-z_][\w\* ]*?)\s+' + re.escape(new) + r'\s*\(([^)]*)\)', text, re.S)
    if not m:
        return None
    ret, params = m.group(1).strip(), m.group(2).strip()
    params = re.sub(r'(?<![A-Za-z0-9_\*])void\s*,\s*', '', params).strip()
    if not params:
        params = 'void'
    if params.startswith('...'):
        params = 'uintptr_t _a0, ...'
    return '%s %s(%s)' % (ret, new, params)


def gen_sources(recs, addr_name, name_new, relax_local):
    groups = collections.defaultdict(list)
    for r in recs:
        entry = naming_db.FUNCS.get(r['addr']) or {}
        r['_module'] = module_of(r['addr'], entry.get('tags', []))
        groups[r['_module']].append(r)
    stats = {}
    for key, title, desc, ranges in MODULES:
        rs = groups.get(key, [])
        if not rs:
            continue
        stats[key] = dict(title=title, desc=desc, n=len(rs), files=[])
        protos = []
        for chunk in chunk_functions(rs):
            start = chunk[0]['addr']
            slug = None
            for r in chunk:
                e = naming_db.FUNCS.get(r['addr'])
                if e:
                    slug = safe_filename(e['name'])
                    break
            slug = slug or '%s_%05x' % (key, start)
            fname = '%05x_%s.c' % (start, slug)
            fpath = os.path.join(SRC, key, fname)
            out = ['/*',
                   ' * %s / %s' % (title, fname),
                   ' * 地址范围: 0x%05X - 0x%05X' % (start, chunk[-1]['addr']),
                   ' * 由 toolchain/build_project.py 自动生成；请勿手工修改。',
                   ' */',
                   '#include "991cnx/all.h"',
                   '']
            for r in chunk:
                e = naming_db.FUNCS.get(r['addr'])
                new = addr_name[r['addr']]
                text = rewrite_function(r, new, relax_local.get(r['addr'], ()))

                text = rename_globals(text)
                text = rename_calls(text, name_new)

                text = _postprocess(text)
                out.append(doc_block(r, e, key))
                out.append(text.rstrip())
                out.append('')
                proto = extract_proto(text, new)
                if proto:
                    protos.append((new, proto))
            open(fpath, 'w', encoding='utf-8', newline='\n').write('\n'.join(out) + '\n')
            stats[key]['files'].append((fname, start, chunk[-1]['addr'], len(chunk)))
        h = ['#ifndef _991CNX_%s_H' % key.upper(), '#define _991CNX_%s_H' % key.upper(),
             '#include "types.h"', '', '/* %s：%s（%d 个函数） */' % (title, desc, len(rs)), '']
        for new, proto in protos:
            if new == 'main':
                h.append('/* extern void main(byte *input); —— 宿主 main 约定不同，见 src/firmware_main.c */')
                continue
            if '(*)' in proto:
                continue
            h.append(proto + ';')
        h += ['', '#endif', '']
        open(os.path.join(INC, key + '.h'), 'w', encoding='utf-8').write(chr(10).join(h))
    rs = groups.get('other', [])
    if rs:
        stats['other'] = dict(title='其它', desc='未能按地址归类的函数', n=len(rs), files=[])
        os.makedirs(os.path.join(SRC, 'other'), exist_ok=True)
        out = ['/* 未能按地址区间归类的函数 */', '#include "991cnx/all.h"', '']
        protos = []
        for r in rs:
            e = naming_db.FUNCS.get(r['addr'])
            new = addr_name[r['addr']]
            text = rewrite_function(r, new, relax_local.get(r['addr'], ()))
            out.append(doc_block(r, e, 'other'))
            out.append(_postprocess(rename_calls(rename_globals(text), name_new)).rstrip())
            out.append('')
            proto = extract_proto(text, new)
            if proto:
                protos.append(proto)
        open(os.path.join(SRC, 'other', 'misc.c'), 'w', encoding='utf-8', newline=chr(10)).write(chr(10).join(out) + chr(10))
        h = ['#ifndef _991CNX_OTHER_H', '#define _991CNX_OTHER_H', '#include "types.h"', '']
        h += [q + ';' for q in protos if '(*)' not in q]
        h += ['', '#endif', '']
        open(os.path.join(INC, 'other.h'), 'w', encoding='utf-8').write(chr(10).join(h))
    return stats


def gen_all_header():
    keys = [k for k, *_ in MODULES] + ['other']
    lines = ['#ifndef _991CNX_ALL_H', '#define _991CNX_ALL_H',
             '#include "types.h"', '#include "hw.h"', '#include "globals.h"']
    for k in keys:
        if os.path.exists(os.path.join(INC, k + '.h')):
            lines.append('#include "%s.h"' % k)
    lines += ['', '#endif', '']
    open(os.path.join(INC, 'all.h'), 'w', encoding='utf-8').write(chr(10).join(lines))


FW_MAIN_C = (
    '/* 固件主函数（0x24E36）。\n'
    ' * 固件 main 返回 void，不符合宿主 C 的 main 约定，因此 all.h 不声明它；\n'
    ' * 这里用 extern 声明后由 firmware_entry 调用。 */\n'
    '#include "991cnx/all.h"\n'
    'extern void main(byte *input);\n\n'
    'void firmware_entry(void)\n'
    '{\n'
    '  main((byte *)0);\n'
    '}\n')


def gen_firmware_main():
    open(os.path.join(SRC, 'firmware_main.c'), 'w', encoding='utf-8').write(FW_MAIN_C)


# ---------------------------------------------------------------------------
# 文档
# ---------------------------------------------------------------------------
def gen_docs(recs, stats):
    lines = ['# 函数索引', '',
             '> 由 `toolchain/build_project.py` 生成。置信度含义见《命名与还原方法》。', '',
             '| 地址 | 名称 | 置信度 | 模块 | 参数 | 说明 |',
             '|------|------|--------|------|------|------|']
    for r in sorted(recs, key=lambda x: x['addr']):
        e = naming_db.FUNCS.get(r['addr'])
        name = e['name'] if e else r['name']
        conf = e['conf'] if e else '—'
        args = ', '.join('%s %s' % (t, n) for t, n in e['params']) if e else r['args'].replace(chr(10), ' ')
        note = (e['note'] if e else '自动归类，未完全识别').replace('|', '/')
        lines.append('| 0x%05X | `%s` | %s | %s | %s | %s |' %
                     (r['addr'], name, conf, r.get('_module', ''), args, note))
    open(os.path.join(DOCS, '函数索引.md'), 'w', encoding='utf-8').write(chr(10).join(lines) + chr(10))

    lines = ['# 全局变量索引', '', '| 地址 | 名称 | 类型 | 说明 |', '|------|------|------|------|']
    for addr in sorted(naming_db.GLOBALS):
        name, ty, note = naming_db.GLOBALS[addr]
        lines.append('| 0x%s | `%s` | `%s` | %s |' % (addr.upper(), name, ty, note))
    open(os.path.join(DOCS, '全局变量索引.md'), 'w', encoding='utf-8').write(chr(10).join(lines) + chr(10))

    lines = ['# 模块与文件索引', '']
    for key, title, desc, ranges in MODULES:
        st = stats.get(key)
        if not st:
            continue
        lines.append('## %s — %s' % (key, title))
        lines.append('')
        lines.append('%s。共 %d 个函数。' % (desc, st['n']))
        lines.append('')
        lines.append('| 文件 | 地址范围 | 函数数 |')
        lines.append('|------|----------|--------|')
        for fname, lo, hi, n in st['files']:
            lines.append('| `src/%s/%s` | 0x%05X–0x%05X | %d |' % (key, fname, lo, hi, n))
        lines.append('')
    if 'other' in stats:
        lines.append('## other — 其它')
        lines.append('')
        lines.append('未能按地址区间归类的函数，共 %d 个，见 `src/other/misc.c`。' % stats['other']['n'])
        lines.append('')
    open(os.path.join(DOCS, '模块索引.md'), 'w', encoding='utf-8').write(chr(10).join(lines) + chr(10))

    total = len(recs)
    named = sum(1 for r in recs if r['addr'] in naming_db.FUNCS)
    byconf = collections.Counter(naming_db.FUNCS[r['addr']]['conf']
                                 for r in recs if r['addr'] in naming_db.FUNCS)
    lines = ['# 还原进度', '',
             '- 函数总数：%d' % total,
             '- 已命名：%d（%.1f%%）' % (named, named * 100.0 / total),
             '  - verified：%d' % byconf['verified'],
             '  - strong：%d' % byconf['strong'],
             '  - likely：%d' % byconf['likely'],
             '- 全局符号命名：%d' % len(naming_db.GLOBALS),
             '- 源文件：%d' % sum(len(s['files']) for s in stats.values()),
             '']
    open(os.path.join(DOCS, '还原进度.md'), 'w', encoding='utf-8').write(chr(10).join(lines) + chr(10))


# ---------------------------------------------------------------------------
def main():
    for d in (INC, SRC, DOCS):
        os.makedirs(d, exist_ok=True)
    for key, *_ in MODULES:
        os.makedirs(os.path.join(SRC, key), exist_ok=True)
    # 清空上次生成的源文件/头文件，避免改名后残留旧文件（同名函数会重复定义）
    for root, dirs, files in os.walk(SRC):
        for fn in files:
            if fn.endswith('.c'):
                os.remove(os.path.join(root, fn))
    for fn in os.listdir(INC):
        if fn.endswith('.h'):
            os.remove(os.path.join(INC, fn))
    recs = load_records()
    global NULL_ALIASES
    NULL_ALIASES = {'%04x' % a for a in range(0x0200, 0xF901) if '%04x' % a not in naming_db.GLOBALS}
    addr_name, name_new, special = build_maps(recs)
    register_thunks(recs, name_new)
    used, cast = scan_value_uses(recs, name_new)
    build_proto_table(recs, addr_name)
    relaxed = relax_return_types(recs, addr_name, used, cast)
    relax_local = compute_relax_local(recs, name_new, relaxed)
    for rec2 in recs:
        for mm in re.finditer(re.escape(rec2['name']) + r'\s*\(\s*\)', rec2.get('_text', '')):
            pass
    for rec2 in recs:
        for code2 in recs:
            for mm in re.finditer(re.escape(rec2['name']) + r'(?![0-9a-fA-F])' + r'\s*\(\s*\)', code2.get('_text', '')):
                rec2['_va0'] = True
    global WRITABLE_GLOBALS, ALL_RECS, VOID_FUNCS, ARRAY_GLOBALS
    ALL_RECS = recs
    WTYPES = {'undefined', 'undefined1', 'undefined2', 'undefined4', 'undefined8', 'byte',
              'char', 'uchar', 'short', 'ushort', 'int', 'uint', 'ulo', 'long', 'longlong',
              'ulonglong', 'bool'}
    WRITABLE_GLOBALS = {}
    for nm, ty, note, addr in global_symbols():
        t = ty
        while True:
            m = re.match(r'^(.*?)\[[^]]*\]$', t)
            if not m:
                break
            t = m.group(1)
        if t in WTYPES:
            WRITABLE_GLOBALS[nm] = ty
    VOID_FUNCS = {addr_name[r['addr']] for r in recs
                  if not ((naming_db.FUNCS.get(r['addr']) or {}).get('ret_relaxed') or r.get('_ret_relaxed'))
                  and (naming_db.FUNCS.get(r['addr']) or {}).get('ret', r.get('_ret')) == 'void'}
    ARRAY_GLOBALS = {nm for nm, ty, note, addr in global_symbols() if '[' in ty}
    gen_types()
    gen_globals()
    stats = gen_sources(recs, addr_name, name_new, relax_local)
    gen_all_header()
    gen_globals_c()
    gen_firmware_main()
    gen_docs(recs, stats)
    with open(os.path.join(ROOT, 'toolchain', 'rename_map.csv'), 'w', encoding='utf-8') as f:
        f.write('addr,old_name,new_name,confidence' + chr(10))
        for r in sorted(recs, key=lambda x: x['addr']):
            e = naming_db.FUNCS.get(r['addr'])
            f.write('0x%05X,%s,%s,%s%s' % (r['addr'], r['name'], addr_name[r['addr']],
                                           e['conf'] if e else 'unknown', chr(10)))
    named = sum(1 for r in recs if r['addr'] in naming_db.FUNCS)
    print('functions:', len(recs), 'named:', named, 'relaxed:', len(relaxed))
    print('modules:', ', '.join('%s=%d' % (k, v['n']) for k, v in stats.items()))


if __name__ == '__main__':
    main()
