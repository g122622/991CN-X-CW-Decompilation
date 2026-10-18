#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
命名数据库：已核实的函数名 / 全局变量名 / 参数名 / 文档注释。

每个函数条目都在原始反汇编（原始反编译结果/991CN X.汇编.txt）中逐条核对过；
`note` 记录判定依据，`conf` 表示置信度：

  verified  逐指令核对，或由唯一入口/调用点直接确定
  strong    由上下文（调用者、数据结构、运行环境）强确定
  likely    由同族函数、常量结构推断，仍可能有偏差
"""

FUNCS = {}

def F(addr, name, ret, params, note, conf='strong', tags=None):
    FUNCS[addr] = dict(name=name, ret=ret, params=params, note=note,
                       conf=conf, tags=tags or [])

V = 'void'

# ===========================================================================
# 1. 启动 / 异常向量 / 主循环
# ===========================================================================
F(0x0093FE, 'reset_handler', V, [],
  'RESET 向量（中断向量表 [1]）。BC AL, reset_entry：仅当 C=0（硬复位）时进入启动代码；'
  '否则原地死循环。Ghidra 因无法理解 BC 的 C 标志语义，把它误认作普通函数。',
  'verified', tags=['boot'])
F(0x009402, 'reset_entry', V, [],
  '冷启动：以 0xBEE6 处的 {源:3B, 目标:3B, 长度:2B} 初始化表逐项把 ROM 数据块复制到 RAM'
  '（0xFC05、0xFC46 等地址段），表以 0xFFFF 结束；随后 BL 0xB90A（仅 RT 的空函数）、'
  '清 0xF000(DSR) 并跳转 main。原记录错误地把它命名为 thunk_FUN_rom_009402。',
  'verified', tags=['boot'])
F(0x024E36, 'main', V, [('byte*', 'input')],
  '程序主入口（由 reset_entry 跳转）。先初始化系统（0x9242）、RAM 有效性检查'
  '（0x90CE，失败则全清）、模式界面初始化（0x8CEE）、存储/显示初始化（0x8CE...）、'
  '自检与显示复位（0x2250E/0x22006/0x22040/0x10E9C），随后按 0xD111（模式字）'
  '无限分派各模式顶层循环。',
  'verified', tags=['boot'])

F(0x000000, 'reset_vector', V, [],
  'ROM 首地址：B 0x9402（复位入口）。Ghidra 把该跳转反编译成了自递归函数，'
  '这里按真实语义改写为对 reset_entry 的调用。',
  'verified', tags=['boot'])

# ===========================================================================
# 2. 公共序言/尾声（编译器生成的共享代码，不是普通函数）
# ===========================================================================
F(0x009D22, 'frame_enter', 'short', [],
  '函数序言辅助：PUSH QR8 → PUSH XR4 → MOV ER14,SP → RT。约 230 个函数先 CALL 它，'
  '再保存其他寄存器，形成可变长序言。Ghidra 不理解跨调用的栈帧，把它当作无参函数。',
  'verified', tags=['frame'])
F(0x009D2A, 'frame_leave', V, [],
  '函数尾声辅助：MOV SP,ER14 → POP XR4 → POP QR8 → POP PC。与 frame_enter 成对使用，'
  '所有复杂函数都以它收尾。',
  'verified', tags=['frame'])

# ===========================================================================
# 3. 时钟 / 中断 / 键盘硬件
# ===========================================================================
F(0x00916A, 'timer_wait', V, [('ushort', 'interval')],
  '定时器延时 / 进入 STOP：先写 0xF00A、清 0xF022(计数器)、0xF024=0x0101、清 0xF014，'
  '再写 0xF008(STPACP)=0xA0、0xF009(SBYCON)=2 进入 STOP；随后写 0xF020=interval。'
  '若 0xF042(键盘滤波) 为 0，则按 0x079E/0x010F 重装并使能中断。',
  'verified', tags=['hw'])
F(0x009288, 'irq_enable', V, [], 'EI：开可屏蔽中断。', 'verified', tags=['hw'])
F(0x00928C, 'irq_disable', V, [], 'DI：关可屏蔽中断。', 'verified', tags=['hw'])
F(0x009198, 'timer_stop_wait', V, [],
  '再次进入 STOP：STPACP=0xA0、SBYCON=2、F020=0x079E、F024=0x010F。',
  'verified', tags=['hw'])
F(0x0091E4, 'timer_rearm', V, [],
  '重新装载定时器（F020=0x079E、F024=0x010F、清 F014/F015）并使能中断。',
  'strong', tags=['hw'])
F(0x0091E8, 'timer_clear_pending', V, [],
  '清 F014 bit1 并再次置 STPACP=0xA0、SBYCON=2（轻量版 STOP）。',
  'strong', tags=['hw'])
F(0x009208, 'irq_pending', 'byte', [], '读取 F014（可屏蔽中断待处理标志）。', 'verified', tags=['hw'])
F(0x009210, 'key_flag_bit7', 'char', [],
  '读 0xD13A：若 bit7 置位返回 1，否则写 0xD13A=0x88 并返回 0x88。',
  'likely', tags=['hw'])
F(0x009218, 'key_flag_write', V, [('char', 'value')], '写 0xD13A。', 'likely', tags=['hw'])
F(0x009226, 'key_flag_clear', V, [], '清 0xD13A。', 'likely', tags=['hw'])
F(0x00922E, 'key_flag_test7', 'char', [], 'TB 0xD13A.7，返回 0/1。', 'likely', tags=['hw'])
F(0x009236, 'key_flag_test3', 'char', [], 'TB 0xD13A.3，返回 0/1。', 'likely', tags=['hw'])
F(0x009242, 'hw_init', V, [],
  '系统初始化：F00A=0x31、F028=0x17，延时循环，初始化中断/定时器/显示寄存器，'
  'F03D=7、等待 0x50 tick、刷新对比度、清中断。',
  'verified', tags=['hw'])
F(0x009290, 'irq_stub_init', V, [], 'F220=0x7F00、F222=0x7F00、F224=0（未识别寄存器）。',
  'verified', tags=['hw'])
F(0x0092A0, 'timer_stub_init', V, [], 'F048=0、F04A=7、F04C=7（未识别寄存器）。',
  'verified', tags=['hw'])
F(0x0092B0, 'irq_mask_low_init', V, [], 'F010=0x22（中断屏蔽低字节）、F012=0、F018=3。',
  'verified', tags=['hw'])
F(0x0092DA, 'timer_base_init', V, [],
  'F030=4、F031=0x17、F032=0x14、F033=7、F034=9、F035=0x17、F036=1、F039=0。'
  'F030=屏幕范围、F031=屏幕模式、F032=对比度（见 CasioEmu 的 MMU 映射）。',
  'verified', tags=['hw'])
F(0x009304, 'contrast_set', V, [('uchar', 'contrast')], 'F032 = contrast（LCD 对比度，0..0x3F）。',
  'verified', tags=['hw'])
F(0x00930A, 'timer_base_main', V, [],
  '主流程定时器基值：F00A=1、F030=4、F031=0x15、F033=3、F034=9、F035=0x17、F036=1、F039=0。',
  'strong', tags=['hw'])
F(0x009310, 'timer_base_restore', V, [], '恢复 F030..F039 的一组基值（F031=0x15）。',
  'strong', tags=['hw'])
F(0x009358, 'status_flags_clear', V, [], '清 F800/F801/F803/F811/F812/F815（状态栏/蜂鸣器位）。',
  'strong', tags=['hw'])
F(0x009376, 'buzzer_set', V, [('char', 'on')], 'F815 = (on != 0)。', 'strong', tags=['hw'])
F(0x009382, 'kbd_filter_on', V, [], 'F042（键盘输入滤波）置 0xFF。', 'verified', tags=['kbd'])
F(0x00938A, 'kbd_filter_off', V, [], 'F042 清 0。', 'verified', tags=['kbd'])
F(0x009392, 'kbd_ko_enable', V, [], 'F046（键盘输出 KO）置 0x7F。', 'verified', tags=['kbd'])
F(0x00939A, 'kbd_ko_disable', V, [], 'F046 清 0。', 'verified', tags=['kbd'])
F(0x0093A2, 'kbd_any_key', 'bool', [],
  '短延时后 F046=0x7F，读 F040(KI)；有任一键按下返回 true。',
  'verified', tags=['kbd'])
F(0x0093BA, 'kbd_wait_key', 'ushort', [],
  '轮询等待按键：检测到按键立即返回 0；5 次轮询后超时，0xD150=0x1004 并返回非 0。',
  'strong', tags=['kbd'])
F(0x01F574, 'read_key', 'ushort', [],
  '读键盘：按 0xD110(扫描状态) 驱动 KO 编码，调用 key_decode 查模式相关的键位映射表'
  '（COMP 0x775C / STAT 0x62E2 / TABLE 0x3668 / 复数线性 0x3BF2 / SHIFT 0x0A10 / ALPHA 0x198E），'
  '返回 16 位键码（低字节 KI、高字节 KO）。',
  'verified', tags=['kbd'])
F(0x0252DC, 'key_decode', 'ushort', [('byte*', 'scancode'), ('ushort', 'table')],
  '把 (KI 行位索引, KO 列位索引) 合并成表内偏移，返回键位映射表中对应的键码。',
  'verified', tags=['kbd'])
F(0x01F230, 'wait_any_key', V, [],
  '阻塞等待按键（start/end 包裹，查 0x62E2 表），用于自检/诊断页的"按任意键继续"。',
  'strong', tags=['kbd'])
F(0x00F746, 'loop_read_key', 'bool', [],
  '主循环的阻塞读键：清当前输入、循环 read_key 直到有键；处理 SHIFT/ALPHA 等；返回是否有输入。',
  'strong', tags=['kbd'])
F(0x00D2A4, 'key_repeat_wait', 'char', [],
  '等待按键松开（最多 10×10ms），超时清 0xD13A。',
  'strong', tags=['kbd'])
F(0x0096BE, 'key_pos_offset', 'ushort', [('ushort', 'pos')],
  '把 16 位键位坐标换算成表内偏移：高字节 × 0x28 + 低字节 × 10。'
  '原记录命名为 waitkey，实际与等待按键无关（真正的等待在 0x93BA/0x221B2）。',
  'verified', tags=['kbd'])
F(0x0096FC, 'input_is_empty', 'bool', [],
  '若输入区 0xD180 为空（strlen==0）或 0xD116 bit6 置位则返回 true，'
  '否则 false。原记录命名为 read_key，实际并不读键盘。',
  'verified', tags=['editor'])
F(0x0094DA, 'editor_action', V, [('ushort', 'op')],
  '编辑器动作（撤销/重做/删除等）分派：按 0xD015 状态和 op 修改输入区并重绘。'
  '原记录命名为 delay，实际没有任何延时循环。',
  'strong', tags=['editor'])
F(0x008D5E, 'key_is_extended', 'short', [('ushort', 'key')],
  '判断是否为扩展键（高字节 0xFC）；key==0 或 0xFC42..0xFC5F 范围内返回 0。',
  'likely', tags=['kbd'])
F(0x008D7A, 'return_zero', 'short', [], '恒返回 0（多个代码分支的公共出口）。',
  'verified', tags=['util'])
F(0x008D7E, 'key_is_menu_key', 'short', [('ushort', 'key')],
  '若键码为 0xFC01 或 0xFC31..0xFC3B 区间则返回 0xFC01，否则返回 0。',
  'likely', tags=['kbd'])
F(0x008D94, 'input_variant', 'char*', [('undefined*', 'out')],
  '按模式/编辑状态返回当前输入变体（COMPLEX/进制等）并写 *out。',
  'strong', tags=['ui'])
F(0x008DF6, 'key_is_value', 'short', [('ushort', 'key')],
  '键码 0xFC26 特殊判断，否则转 is_up_down。', 'likely', tags=['kbd'])
F(0x008E04, 'is_modifier_3_5', 'char', [],
  '0xD116 低 4 位为 3 或 5 时返回 1。', 'strong', tags=['kbd'])
F(0x008E14, 'is_modifier_1', 'char', [], '0xD116 低 4 位为 1 时返回 1。',
  'strong', tags=['kbd'])
F(0x008E22, 'is_arrow_key', 'byte', [('byte', 'lo'), ('char', 'hi')],
  'hi==0xFC 且 0x1C<lo<0x20 时返回 1（方向键）。', 'verified', tags=['kbd'])
F(0x008E32, 'return_false', 'byte', [], '恒返回 0。', 'verified', tags=['util'])
F(0x008E36, 'is_left_right', 'byte', [('byte', 'lo'), ('char', 'hi')],
  'hi==0xFC 且 lo 为 0x1C/0x1D（左右键）时返回 1。', 'verified', tags=['kbd'])
F(0x008E44, 'is_up_down', 'byte', [('byte', 'lo'), ('char', 'hi')],
  'hi==0xFC 且 lo 为 0x1E/0x1F（上下键）时返回 1。', 'verified', tags=['kbd'])
F(0x008E52, 'is_key_20_23', 'byte', [('byte', 'lo'), ('char', 'hi')],
  'hi==0xFC 且 0x20<lo<0x24 时返回 1。', 'verified', tags=['kbd'])
F(0x008E60, 'is_key_12_15', 'byte', [('byte', 'lo'), ('char', 'hi')],
  'hi==0xFC 且 0x12<lo<0x16 时返回 1。', 'verified', tags=['kbd'])
F(0x008E6E, 'is_ratio_mode', 'char', [], '0xD111==0x88 且 0xD114==0x12 时返回 1。',
  'strong', tags=['ui'])
F(0x008E88, 'key_filter_mode', 'short', [('short', 'key')],
  '按模式选择过滤表（0x7DDA/0x5A92/0x52E8）的键过滤入口。',
  'strong', tags=['kbd'])
F(0x008EB0, 'key_filter_582c', 'short', [('short', 'key')],
  '按键白名单过滤（表 0x582C）。', 'verified', tags=['kbd'])
F(0x008EB8, 'key_filter_52e8', 'short', [('short', 'key')],
  '按键白名单过滤（表 0x52E8）。', 'verified', tags=['kbd'])
F(0x008EC8, 'key_filter_386c', 'short', [('short', 'key')],
  '按键白名单过滤（表 0x386C）。', 'verified', tags=['kbd'])
F(0x008ED0, 'stat_cell_addr', 'short', [('ushort', 'rc'), ('char', 'col')],
  '计算统计表单元格地址：0xD392 + ((行-1)*4 + (列-1) + 页*16) * 10。',
  'verified', tags=['stat'])
F(0x008EF2, 'stat_cell_addr_ex', 'undefined2', [('ushort', 'rc'), ('short*', 'addr')],
  '带滚动偏移的统计表单元格地址计算。', 'strong', tags=['stat'])
F(0x008F34, 'stat_table_base', 'byte', [('ushort*', 'out')],
  '返回当前页 *out=0xD400，函数值 = 0xD0F6（页号）。', 'verified', tags=['stat'])
F(0x008F48, 'stat_table_width', 'char', [],
  '按模式返回统计/表格宽度：0x88 模式 2 或 3，C 模式 1..3，其余 1/2。',
  'strong', tags=['stat'])
F(0x008F7C, 'stat_table_clear', 'undefined2', [('byte', 'page')],
  '设置页号并清空 0xD400 处的 900 字节统计区。', 'verified', tags=['stat'])
F(0x008FAA, 'expr_state_clear', V, [], '清零 0xD16C 的 20 字节表达式状态。',
  'verified', tags=['editor'])
F(0x008FEC, 'var_get_value', 'short', [('byte', 'idx'), ('byte*', 'dst')],
  '取第 idx 个变量（0xD31A + idx*10）到 dst；复数模式再取虚部（0xD612 区），'
  '否则清零余下部分。', 'verified', tags=['vars'])
F(0x009A08, 'is_ratio_input', 'char', [], '0xD111==0x88 且 0xD114==1 时返回 1。',
  'strong', tags=['ui'])
F(0x009A20, 'emit_hint', 'undefined2', [('undefined2', 'a'), ('char', 'flag')],
  '调用 0x20F98/0x20EE6 输出提示字符串。', 'likely', tags=['ui'])
F(0x009A3A, 'memmove', 'undefined*', [('undefined*', 'dst'), ('undefined*', 'src'), ('short', 'len')],
  '标准 memmove（处理重叠区间）。', 'verified', tags=['libc'])
F(0x009AA6, 'menu_numeric_select', V, [],
  '数字键 1..4 选择菜单项：索引表 0x394E，上限 0x6798，返回选中项字节。',
  'strong', tags=['menu'])
F(0x009B6E, 'input_max_len', 'byte', [],
  '返回输入区最大长度：常态 200，0x0D 模式 0x32，特定状态 0x31。',
  'strong', tags=['editor'])
F(0x009B98, 'expr_append_A', V, [],
  '若当前编辑状态为 1 且词法单元为函数，则向输入区追加字符 A。',
  'likely', tags=['editor'])
F(0x009BD8, 'scroll_init', V, [], '初始化滚动/高亮状态（0xD157/0xD15A/0xD15B）。',
  'strong', tags=['ui'])
F(0x009C0A, 'result_clear', V, [], '把结果变量 0xD16C 置 0（0xD176 也清零）。',
  'strong', tags=['vars'])
F(0x009C40, 'draw_var_table', V, [], '绘制变量/表格内容（遍历 0x4B42 表并格式化数值）。',
  'strong', tags=['vars'])
F(0x009CC4, 'token_class2', 'undefined2', [('byte*', 'p')],
  '输入字符分类：数字 0x3A..0x3F 与 0x01 特殊处理，用于 token 化。',
  'strong', tags=['editor'])
F(0x009CF6, 'wait_arrow_exit', 'undefined', [], '等待按键直到方向键（0xFC2D/0xFC30）或取消（0xFC26/0xFC27）。',
  'strong', tags=['kbd'])
F(0x009D32, 'abs_col_diff', 'char', [('byte', 'col')], '返回 |col - 光标列|。',
  'verified', tags=['editor'])
F(0x009DC8, 'input_context_switch', V, [('short*', 'p')],
  '切换输入上下文（保存/恢复 0xD144、清 0xD00C/0xD011），并调用 0x1FC7C/0x25D7C。',
  'strong', tags=['editor'])
F(0x009E4C, 'append_number_str', 'byte*', [('byte*', 'p')],
  '解析 p 处 BCD 数值，格式化为科学计数并追加到目标字符串。',
  'strong', tags=['format'])
F(0x009F66, 'char_class', V, [], '对输入区首字符做分类（供 token 分派跳转表使用）。',
  'strong', tags=['editor'])
F(0x00A014, 'key_is_23', 'short', [('short', 'key')], '键码 0x23 或 0 时返回 1。',
  'verified', tags=['kbd'])
F(0x00A026, 'is_edit_state_6_9', 'char', [],
  '0xD114 为 6/9/0xA0/0xC0 且 0xD115<3、0xD116==1 时返回 1。',
  'strong', tags=['ui'])
F(0x00A052, 'expr_matrix_scan', 'ushort*', [('ushort*', 'p')],
  '在输入区按行列扫描（调用 key_pos_offset），用于矩阵/表格输入。',
  'likely', tags=['editor'])

F(0x00A16E, 'ui_update', V, [],
  '主界面刷新：处理当前键/输入（0xD10E）与显示光标，调用 0xD812 处理输入并刷新。'
  'Ghidra 认为无返回值，但调用点把结果当作状态使用。',
  'strong', tags=['ui'])
F(0x026484, 'key_repeat_start', V, [], '按键重复初始化（清重复计数）。', 'likely', tags=['kbd'])
F(0x02086C, 'set_dirty_flag', V, [('undefined2', 'v')], '写显示脏/状态标志。', 'likely', tags=['ui'])

# ===========================================================================
# 4. 显示硬件 / 帧缓冲 / 字体
# ===========================================================================
F(0x00F1A8, 'memset', 'byte*', [('byte*', 'dst'), ('byte', 'value'), ('ushort', 'len')],
  '标准 memset（返回 dst；len 由调用者压栈，位于 0x02[FP]）。与 Labels/memset.md 一致。',
  'verified', tags=['libc'])
F(0x008FB8, 'memzero', V, [('byte*', 'dst'), ('ushort', 'len')],
  '把 dst..dst+len 清零（调用 memset）。', 'verified', tags=['libc'])
F(0x022DC4, 'memcpy_bytes', 'byte*', [('byte*', 'dst'), ('byte*', 'src'), ('ushort', 'len')],
  '标准 memcpy（len 由调用者压栈）。ROP 教程中 0x22DC4 的用法与之一致。',
  'verified', tags=['libc'])
F(0x00D070, 'strcpy', 'char*', [('char*', 'dst'), ('char*', 'src')],
  '标准 strcpy（复制到 NUL 为止）。', 'verified', tags=['libc'])
F(0x02536A, 'strlen', 'ushort', [('char*', 's')], '字节串长度（到 NUL）。', 'verified', tags=['libc'])
F(0x025388, 'strchr', 'char*', [('char*', 's'), ('char', 'c')], '查找字符 c，找不到返回 0。',
  'verified', tags=['libc'])
F(0x0203B8, 'strlen_checked', 'ushort', [('char*', 's')], '空指针安全的 strlen（= strlen(s) 或 0）。',
  'verified', tags=['libc'])
F(0x0203C2, 'strcpy_checked', V, [('char*', 'dst'), ('char*', 'src')],
  '空指针安全的 strcpy：src 为 0 时只写结尾 NUL。', 'verified', tags=['libc'])
F(0x0203D6, 'strcat_checked', V, [('char*', 'dst'), ('char*', 'src')],
  '字符串拼接（调用 0x2A020）；src 为 0 时把 dst 置空。', 'verified', tags=['libc'])
F(0x00B5BA, 'is_two_byte_char', 'char', [('char*', 'p')],
  '判断 p 处是否为双字节字符：首字节 0x19 后跟 0x1B/0x1C 时返回 1。'
  '原记录命名为 byte_strlen，语义不符。',
  'strong', tags=['charset'])
F(0x0086E0, 'fb_to_lcd', V, [],
  '主缓冲 0xDDD4 复制 0x600 字节到 LCD 显存 0xF800（memcpy_bytes）。',
  'verified', tags=['gfx'])
F(0x0086F8, 'fb_alt_flush', V, [],
  '把 0xE3D4 子缓冲按 24→32 字节/行扩展渲染到 LCD 显存 0xF800（64 行），再请求刷新。'
  '原记录称 render_e3d4。',
  'verified', tags=['gfx'])
F(0x008704, 'fb_flush', V, [],
  '把主缓冲 0xDDD4 按 24→32 字节/行扩展渲染到 LCD 显存 0xF800，再请求刷新。',
  'verified', tags=['gfx'])
F(0x00A15A, 'lcd_request_refresh', V, [], '刷新请求：0xF816=1（当 0xD0F5==0 且 0xD0F7 bit0 置位）。',
  'verified', tags=['gfx'])
F(0x007EAC, 'fill_screen', 'ushort', [('ushort', 'pattern')],
  '按 pattern 高字节选择填充区：0x04 → 0xE3D4 区 0x600 字节；bit8 → 主缓冲 0xDDD4（0x600）；'
  'bit9 → LCD 显存 0xF800（0x800）。低字节为填充值。',
  'verified', tags=['gfx'])
F(0x007F00, 'clear_screen', V, [], '清主缓冲 0xDDD4（0x600 字节 = 64 行 × 24 字节）。',
  'verified', tags=['gfx'])
F(0x007F1A, 'scroll_screen', V, [('char', 'lines')],
  '屏幕上滚 lines 行：把 0xDDD4 中从 (lines+1) 行开始的内容前移，尾部清零。',
  'strong', tags=['gfx'])
F(0x007F58, 'draw_vline', V, [('ushort', 'pos'), ('ushort', 'flags')],
  '在 (行 = pos 高位, 列位 = pos 低位) 处画竖线；flags 的 bit15/13 控制左右相邻像素、'
  'bit14/12 控制上下相邻行是否连线。', 'strong', tags=['gfx'])
F(0x007FA0, 'draw_vline2', V, [('ushort', 'pos'), ('ushort', 'flags')],
  '双像素宽版 draw_vline（作框线左侧竖边）。', 'strong', tags=['gfx'])
F(0x008060, 'draw_hline', V, [('ushort', 'pos'), ('ushort', 'flags')],
  '画横线：在行区间内连接像素，flags 同上，用于框线的上/下边。', 'strong', tags=['gfx'])
F(0x008102, 'draw_hline_animated', V, [('ushort', 'pos'), ('ushort', 'flags')],
  '与 draw_hline 类似但带逐像素节奏（配合 0xF046 扫描），用于光标闪烁/呼吸线条。',
  'likely', tags=['gfx'])
F(0x008486, 'px_clear', V, [('ushort', 'pos')], '画白点（清像素）。缓冲由 0xD139 选 0xE3D4/0xDDD4。',
  'verified', tags=['gfx'])
F(0x00848A, 'px_set', V, [('ushort', 'pos')], '画黑点（置像素）。', 'verified', tags=['gfx'])
F(0x00849C, 'px_write', V, [('ushort', 'pos'), ('char', 'clear')],
  '像素写：pos 高字节 = 行号，低字节为列位；clear=0 置黑、非 0 置白。'
  '原记录称 set_display_position，实际是像素操作。',
  'verified', tags=['gfx'])
F(0x008672, 'px_or_run', V, [('byte*', 'src'), ('byte*', 'dst'), ('byte', 'mask')],
  '把 src 指定位区间按 mask 按位或入 dst（字符点阵拼接的基础操作）。',
  'strong', tags=['gfx'])
F(0x008746, 'calc_fb_ptr', 'byte', [('byte', 'x'), ('byte', 'y'), ('short*', 'out')],
  '由 (行 y, 列 x) 算出 0xE3D4 区显存指针写入 *out，返回水平位偏移 x&7。',
  'strong', tags=['gfx'])
F(0x008750, 'calc_px_ptr', 'byte', [('byte', 'x'), ('byte', 'y'), ('ushort*', 'out')],
  '由屏幕坐标算像素地址（按 0xD139 选 0xDDD4/0xE3D4 缓冲），返回位偏移。',
  'verified', tags=['gfx'])
F(0x008786, 'status_bits_init', V, [],
  '按 0xD110 的标志位初始化状态栏（F800/F802）位：S/A/M/STO/MATH/D/R/G/FIX/SCI/E/复角等。',
  'strong', tags=['gfx'])
F(0x0087B2, 'status_bits_draw', V, [],
  '按 0xD110/0xD111/0xD112/0xD11A..0xD11D 的组合点亮状态栏图标（Angle/Fix/Sci/Rnd 等）。',
  'strong', tags=['gfx'])
F(0x0084D8, 'glyph_get_small', 'ushort*', [('ushort', 'code'), ('ushort*', 'buf')],
  '取单字节字符的 14 宽小号点阵：用 0xB8A 页指针表定位字形，把竖排字节转为横排位图写入 buf；'
  '字符 ''|''(0x7C) 或首字节为 0 时填充 0xE000。',
  'verified', tags=['font'])
F(0x0085B8, 'glyph_get_large', 'byte*', [('ushort', 'code'), ('byte*', 'buf')],
  '取大号（5 位/像素压缩）点阵：0x3DE6/0x3BA 页指针表，按 0xD137 是否为 8 选择字号。',
  'verified', tags=['font'])
F(0x0082F6, 'draw_char', V, [('ushort', 'pos'), ('ushort', 'code')],
  '在 pos 处绘制一个字符：取字形后逐位 OR 到 0xDDD4/0xE3D4 缓冲。',
  'verified', tags=['text'])
F(0x0082EC, 'draw_char_fast', V, [('ushort', 'pos'), ('byte', 'ch')],
  '与 draw_char 共享函数体的前导块（ROM 中 0x82EC 与 0x82F6 指令重叠），由 0x82F6 的完整函数覆盖；'
  '保留此入口仅为对照 Ghidra 的函数切分。', 'likely', tags=['text'])
F(0x00821C, 'draw_string_nl', 'ushort', [('ushort', 'pos'), ('ushort', 'str')],
  '绘制字符串：0x01 = 换行、0x04 或 >=0xF0 的字节组成双字节字符；返回结束光标。',
  'verified', tags=['text'])
F(0x00821E, 'draw_string', 'ushort', [('ushort', 'pos'), ('ushort', 'str')],
  '同 draw_string_nl，但不处理换行（0x01 为普通占位）。', 'verified', tags=['text'])
F(0x008296, 'draw_blank_slot', V, [('ushort', 'pos')],
  '把 str 中的 0x01 渲染为一个空格（处理 ALPHA/SHIFT 等占位）。',
  'strong', tags=['text'])
F(0x0081A4, 'draw_format_string', V, [('ushort', 'pos'), ('char*', 'fmt')],
  '绘制格式化字符串：0x02/0x04 之后的字节为"数值引用"，用 0x9D52 转成当前显示格式的字符串。',
  'strong', tags=['text'])
F(0x0081A2, 'draw_format_string_al', V, [('ushort', 'pos'), ('char*', 'fmt')],
  'draw_format_string 的 AL 参数变体（被 0x8C4A 使用）。', 'likely', tags=['text'])
F(0x0088F0, 'draw_frame', V, [('ushort', 'pos'), ('short', 'w'), ('byte', 'style'), ('byte', 'top')],
  '绘制菜单/对话框边框（调用各角与边），style 选择圆角/直角/虚线。', 'likely', tags=['gfx'])
F(0x008966, 'draw_frame_edge_a', V, [('ushort', 'pos'), ('short', 'w'), ('ushort', 's')],
  '边框边绘制（方向 A）。', 'likely', tags=['gfx'])
F(0x008972, 'draw_frame_edge_b', V, [('ushort', 'pos'), ('short', 'w'), ('ushort', 's')],
  '边框边绘制（方向 B）。', 'likely', tags=['gfx'])
F(0x00897E, 'draw_frame_edge_c', V, [('ushort', 'pos'), ('short', 'w'), ('ushort', 's')],
  '边框边绘制（方向 C）。', 'likely', tags=['gfx'])
F(0x00898A, 'draw_frame_edge_d', V, [('ushort', 'pos'), ('short', 'w'), ('ushort', 's')],
  '边框边绘制（方向 D）。', 'likely', tags=['gfx'])
F(0x008996, 'frame_corner_1', 'ushort', [('char', 'x'), ('char', 'y')], '边框角图案 1。',
  'likely', tags=['gfx'])
F(0x0089BC, 'frame_corner_2', 'ushort', [('char', 'x'), ('char', 'y')], '边框角图案 2。',
  'likely', tags=['gfx'])
F(0x0089E2, 'frame_corner_3', 'ushort', [('char', 'x'), ('char', 'y')], '边框角图案 3。',
  'likely', tags=['gfx'])
F(0x008A08, 'frame_corner_4', 'char', [('char', 'x')], '边框角图案 4。', 'likely', tags=['gfx'])
F(0x008A3C, 'draw_label', V, [('ushort*', 'dst'), ('ushort', 'num'), ('char', 'sel')],
  '绘制带数字的标签（如菜单项序号）。', 'likely', tags=['text'])
F(0x008AAE, 'draw_list_scroller', 'short', [('short', 'x'), ('ushort', 'flag')],
  '列表滚动条/滑块绘制 1。', 'likely', tags=['gfx'])
F(0x008ABC, 'draw_list_scroller2', 'short', [('short', 'x'), ('ushort', 'flag')],
  '列表滚动条/滑块绘制 2。', 'likely', tags=['gfx'])
F(0x008ACE, 'draw_list_scroller3', 'byte*', [('byte*', 'p'), ('ushort', 'a'), ('short', 'b')],
  '列表滚动条/滑块绘制 3。', 'likely', tags=['gfx'])
F(0x008B80, 'draw_menu_row_bg', V, [('uchar', 'row')], '菜单行背景。', 'likely', tags=['menu'])
F(0x008BC0, 'draw_menu_row_text', V, [('byte', 'row'), ('char*', 'text')], '菜单行文字。',
  'likely', tags=['menu'])
F(0x008BF4, 'draw_text4', V, [('ushort', 'p1'), ('ushort', 'p2'), ('ushort', 'p3'), ('ushort', 'p4')],
  '一次性绘制 4 段字符串（自检、错误页）。', 'strong', tags=['text'])
F(0x008C4A, 'draw_text4x', V, [('ushort', 'pos')],
  '显示 4 行文本（DISP/诊断/错误确认页）：smallprint 后以 0x10 像素行距绘制 4 行。',
  'strong', tags=['text'])
F(0x008C6C, 'smallprint', V, [('ushort', 'pat')],
  '小字/状态行显示入口：0xD137=14、0xD139=0，清屏并绘制。',
  'verified', tags=['text'])
F(0x008C88, 'show_press_ac', V, [], '显示 Press AC 并等待 AC。', 'verified', tags=['text'])
F(0x008C90, 'show_error_press_ac', V, [], '显示错误页并等待 AC。', 'verified', tags=['text'])
F(0x0221AC, 'draw_line_diag', V, [('char', 'row'), ('ushort', 'str')],
  '诊断页绘制一行：0xD137=14 后 draw_string_nl。', 'verified', tags=['diag'])
F(0x022040, 'diag_main', 'ushort', [('ushort', 'a')],
  '自检/诊断入口（《异常教程》示例 1 的自检函数）：清屏、绘制 DIAG 标题、等待按键。',
  'verified', tags=['diag'])
F(0x02209E, 'diag_test', V, [('byte', 'b')],
  '诊断测试项：检查 RAM、执行按键测试，绘制/刷新自检画面。', 'strong', tags=['diag'])
F(0x027BC8, 'self_test_display', V, [],
  'LCD 自检：逐段点亮屏幕并绘制测试图，等待按键。', 'strong', tags=['diag'])
F(0x0221CA, 'diag_fill_55aa', V, [], '诊断填充：F800 显存填充 0x55/0xAA 交替。', 'strong', tags=['diag'])
F(0x0221CC, 'diag_fill_pattern', V, [('byte', 'b')], '诊断填充：F800 显存填充 b/!b 交替。',
  'strong', tags=['diag'])
F(0x022140, 'diag_ram_test', V, [], 'RAM 测试（BCD 累加/校验）并绘制进度。', 'strong', tags=['diag'])
F(0x022408, 'diag_key_test', 'byte', [], '按键/接口测试结果判断（返回 0xA5 表示 OK）。',
  'strong', tags=['diag'])
F(0x0222D4, 'diag_item', 'ushort', [], '诊断页主循环：显示测试结果并等待按键返回。', 'strong', tags=['diag'])
F(0x022382, 'diag_print', V, [], '诊断页文字输出辅助（保存 QR0 到栈）。', 'likely', tags=['diag'])
F(0x022392, 'diag_ram_sum', 'ushort', [], '内存校验和计算（多轮回绕）。', 'strong', tags=['diag'])
F(0x022492, 'nibble_to_ascii', 'char', [('byte', 'b')], '半字节转大写十六进制字符。',
  'verified', tags=['libc'])
F(0x0224AE, 'draw_hex_byte', V, [('byte', 'b')], '把字节以 2 位十六进制绘制到自检页。',
  'strong', tags=['diag'])
F(0x0224EE, 'bit_reverse_index', 'byte', [('byte', 'b')], '返回 b 的最高有效位位置。',
  'strong', tags=['libc'])
F(0x022502, 'diag_flush', V, [], 'flush 显存并等待按键（诊断页）。', 'verified', tags=['diag'])

# ===========================================================================
# 5. 编辑器
# ===========================================================================
F(0x009D72, 'prev_char_ptr', 'byte*', [('byte*', 'start'), ('byte*', 'p')],
  '返回 p 之前一个"字符"的地址：若 p-2 字节 >= 0xF0（双字节字符首字节）则 p-2，否则 p-1；'
  'p<=start 返回 0。原记录误命名为 memcpy。',
  'verified', tags=['editor'])
F(0x009D52, 'input_read_str', 'char*', [],
  '原地回显/读取输入区的当前字符串（Ghidra 的"参数"其实是调用后由 ER0 返回的指针，'
  '调用点总是写成 input_read_str((char*)buf) 后才用 ER0，C 原型按无参声明），'
  '返回输入区字符串指针。', 'likely', tags=['editor'])
F(0x00F2C2, 'mul16', 'short', [('ushort', 'a'), ('ushort', 'b')],
  '16 位无符号乘法（MUL 指令封装）。', 'verified', tags=['math'])
F(0x00AF74, 'token_class', 'ushort', [('char*', 'p')],
  '返回 p 处词法单元分类，编辑器据���区分数字/运算符/括号。',
  'strong', tags=['editor'])
F(0x00D226, 'var_index_to_char', 'char*', [('char*', 'out'), ('byte', 'idx')],
  '把变量序号转换成变量名字符。', 'likely', tags=['editor'])
F(0x00D328, 'skip_brackets', V, [], '跳过成对括号。', 'strong', tags=['editor'])
F(0x00D2E8, 'restore_history_line', V, [], '从历史记录恢复一行到输入区（0xD155 历史游标）。',
  'strong', tags=['editor'])
F(0x00D3A2, 'cursor_left', V, [('short', 'n')], '光标左移。', 'likely', tags=['editor'])
F(0x00D4C8, 'token_at', 'ushort', [('byte*', 'p')], '读取输入区一个字符（处理双字节字符）。',
  'strong', tags=['editor'])
F(0x00DE96, 'draw_cursor', V, [('ushort*', 'pos')], '根据光标位置绘制光标（并在模式行显示图标）。',
  'strong', tags=['editor'])
F(0x00E21E, 'edit_loop', V, [], '编辑器输入循环：读键、插入/删除/移动、重绘。',
  'strong', tags=['editor'])
F(0x00E1D4, 'cursor_pos_update', 'ushort', [('ushort*', 'pos'), ('byte*', 'flag')], '更新光标坐标。',
  'likely', tags=['editor'])
F(0x00E5D6, 'editor_mark_dirty', V, [], '标记输入需要重绘。', 'likely', tags=['editor'])
F(0x00E620, 'editor_backspace', V, [('ushort', 'n')], '编辑器退格处理。', 'likely', tags=['editor'])
F(0x00E674, 'editor_selection', 'ushort', [('ushort', 'a'), ('char', 'b')], '编辑选择区域处理。',
  'likely', tags=['editor'])
F(0x00E698, 'editor_format', V, [('char*', 'p')], '编辑器格式化/分词。', 'likely', tags=['editor'])
F(0x00EC54, 'editor_max_cols', 'byte', [], '返回当前显示行对应的最大列数（10 或 14）。',
  'strong', tags=['editor'])
F(0x00EC04, 'editor_accept_ready', 'char', [], 'K 模式且状态 1 时返回 1。', 'likely', tags=['editor'])
F(0x00EC1C, 'editor_init', V, [('byte*', 'p'), ('ushort', 'len')], '初始化编辑区与模式。',
  'strong', tags=['editor'])
F(0x00EC64, 'is_var_token', 'ushort', [('byte*', 'p')], '判断是否为变量名。', 'likely', tags=['editor'])
F(0x00EC86, 'skip_expr_end', V, [('byte*', 'flag')], '定位表达式结尾。', 'likely', tags=['editor'])
F(0x009EA4, 'editor_run', V, [], '运行编辑器直到用户按 ON 或完成输入。', 'strong', tags=['editor'])

F(0x00B342, 'is_stat_running', 'char', [], 'STAT 模式 0xD114 为 0x13/0x14 时返回 1。', 'strong', tags=['mode'])
F(0x029D7A, 'expr_to_const', 'char*', [('char*', 'p')], '把输入表达式转换成常量（0x2101E 处理）。', 'likely', tags=['eval'])

# ===========================================================================
# 6. 模式循环
# ===========================================================================
F(0x009D94, 'mode_02_comp_loop', V, [('short', 'input')],
  '【0xD111==2，通常为 COMP 计算模式】主循环：显示光标、编辑、回车触发计算并更新历史。',
  'strong', tags=['mode'])
F(0x029B58, 'mode_03_table_loop', V, [('byte*', 'input')],
  '【0xD111==3，推测为 TABLE 表格模式】主循环：切换到子模式 1 后运行编辑循环。',
  'strong', tags=['mode'])
F(0x00D968, 'mode_06_stat_loop', V, [('byte*', 'input')],
  '【0xD111==6，推测为 STAT 统计模式】主循环；0xD115==3 时进入 0x22A8C 数据处理。',
  'strong', tags=['mode'])
F(0x00DC66, 'mode_45_base_loop', V, [('byte*', 'input')],
  '【0xD111==0x45，推测为 BASE-N 进制模式】主循环：调用 0x280B0 处理，直到退出键 0x24。',
  'strong', tags=['mode'])
F(0x00B810, 'mode_4a_eqn_loop', V, [('byte*', 'input')],
  '【0xD111==0x4A，推测为方程/函数模式】主循环：反复调用 0xDCFA 直到退出键 0x24。',
  'strong', tags=['mode'])
F(0x023BC4, 'mode_4b_matrix_loop', V, [('byte*', 'input')],
  '【0xD111==0x4B，推测为矩阵/向量模式】主循环：调用 0x28594。',
  'strong', tags=['mode'])
F(0x01EE58, 'mode_88_ratio_loop', V, [('byte*', 'input')],
  '【0xD111==0x88，推测为比例模式】主循环：编辑比值表达式，处理 = 求值。',
  'strong', tags=['mode'])
F(0x02950C, 'mode_c4_disp_loop', V, [('byte*', 'input')],
  '【0xD111==0xC4（默认分支）】主循环：编辑/滚动显示并等待按键。',
  'strong', tags=['mode'])

# ===========================================================================
# 7. BCD 浮点核心
# ===========================================================================
F(0x01DA02, 'dec_copy', V, [('undefined2*', 'dst'), ('undefined2*', 'src')],
  '复制 10 字节 BCD 浮点寄存器（dst ← src）。', 'verified', tags=['bcd'])
F(0x01D66E, 'dec_set_uint_small', 'short', [('ushort*', 'dst'), ('byte', 'v')],
  '把 dst 设为小整数 v（v<10 时存为 0x00v0 型小整数，否则置错误标记 0xF0）。', 'verified', tags=['bcd'])
F(0x0203E6, 'dec_parse', 'byte*', [('byte*', 'p'), ('byte**', 'out')], '从缓冲区解析 10 字节 BCD 数值。',
  'strong', tags=['bcd'])
F(0x020462, 'fmt_number', V, [('short', 'ctx'), ('char*', 'out')],
  '把内部数值格式化为显示字符串。', 'strong', tags=['format'])
F(0x02051E, 'fmt_sci', V, [('ushort', 'ctx'), ('char*', 'out')], '科学计数格式化。',
  'strong', tags=['format'])
F(0x01D5B6, 'dec_cmp', 'undefined2', [('undefined2*', 'a'), ('undefined2', 'b')], '比较 a 与 b。',
  'verified', tags=['bcd'])
F(0x01881C, 'dec_xy_add', V, [('undefined2*', 'tmp'), ('undefined2*', 'x')],
  'X ← X + *x（先把 *x 复制到 tmp，再调用加减法入口 0x1CFA4 opcode 0）。',
  'verified', tags=['bcd'])
F(0x018858, 'dec_xy_sub', V, [('undefined2*', 'tmp'), ('undefined2*', 'x')],
  'X ← X − *x（以 opcode 1 调用二元运算入口）。',
  'verified', tags=['bcd'])
F(0x01CF54, 'dec_bin_mul', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '二元运算入口（opcode 9 = 乘法）：存 *b 到 0xD05C 后进入 0x1CFA4。',
  'verified', tags=['bcd'])
F(0x01CF68, 'dec_bin_div', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '二元运算入口（opcode 8 = 除法）。',
  'verified', tags=['bcd'])
F(0x01CF90, 'dec_bin_pow', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '二元运算入口（opcode 6 = 乘方 x^y）。',
  'likely', tags=['bcd'])
F(0x01CF7C, 'dec_bin_and', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '二元运算入口（opcode 7 = 逻辑与，见 0x1C880 的分派表）。',
  'likely', tags=['bcd'])
F(0x01CFA4, 'dec_bin_dispatch', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '二元运算主分派：按 0xD01E 操作码（0..9）选择 0x1CA7E 起的 10 个入口之一，'
  '结果写回 *a（0xD05C 保存 *b）。', 'verified', tags=['bcd'])
F(0x01C81A, 'dec_zero_helper', V, [], '清 0xD000..0xD009（运算寄存器）。', 'strong', tags=['bcd'])
F(0x01D800, 'bcd_type', 'byte', [], '返回 BCD 单元的高 4 位（0 为浮点，F 为特殊值）。',
  'verified', tags=['bcd'])
F(0x01C3C8, 'dec_status_low', 'byte', [], '返回 0xD009 低 4 位（特殊值时 0）。', 'verified', tags=['bcd'])
F(0x01C392, 'dec_store', V, [], '把算数寄存器（0xD000..）写回 *0xD05C 指定的 BCD 单元。',
  'verified', tags=['bcd'])
F(0x01C35C, 'dec_load', V, [('undefined2*', 'p')], '把 *p 的 10 字节 BCD 单元载入算数寄存器 0xD000..。',
  'verified', tags=['bcd'])
F(0x01D6A4, 'dec_set_special', 'ushort*', [('ushort*', 'dst'), ('byte', 'v')],
  '把 dst 设为特殊值（v<0x10 时首字节 0xF0|v，否则 0xF3）；用于错误/未定义结果。',
  'verified', tags=['bcd'])
F(0x01D9EC, 'dec_copy_rev', 'void', [('undefined2*', 'dst'), ('undefined2*', 'src')],
  '倒序复制 10 字节 BCD 单元（dst 与 src 重叠时安全）。', 'verified', tags=['bcd'])
F(0x01D730, 'dec_inc5', V, [('undefined2*', 'a'), ('undefined2', 'b')],
  'BCD 运算后处理：对结果做 5 的 DAA 进位修正。', 'strong', tags=['bcd'])
F(0x01CBB2, 'dec_bin_result', 'ushort*', [('ushort*', 'a'), ('undefined2', 'b')],
  '二元运算收尾：把结果寄存器写回 *a 并清 0x40 标志位。', 'strong', tags=['bcd'])
F(0x01D7B0, 'dec_cmp_ex', 'undefined2*', [('undefined2*', 'a'), ('undefined2', 'b')],
  '比较并返回/归一化两个 BCD 单元。', 'strong', tags=['bcd'])
F(0x01C830, 'dec_bin_mul_core', V, [('undefined2', 'a'), ('undefined2*', 'b')],
  'opcode 9（乘法）核心入口：设 0xD01E=9 后跳到 0x1C8A6 公共尾部。', 'verified', tags=['bcd'])
F(0x01C86C, 'dec_bin_pow_core', V, [('undefined2', 'a'), ('undefined2*', 'b')],
  'opcode 6（乘方）核心入口：设 0xD01E=6 后跳到 0x1C8A6 公共尾部。', 'verified', tags=['bcd'])
F(0x01C042, 'dec_ieee_add', V, [], '浮点加法核心（按指数对齐并 DAA 规范化）。',
  'strong', tags=['bcd'])
F(0x01C670, 'dec_ieee_norm', V, [], '浮点规格化/舍入核心。', 'strong', tags=['bcd'])
F(0x01D620, 'dec_to_string', 'undefined2', [('undefined2', 'fmt'), ('undefined2*', 'out')],
  '按格式把数值转为字符串。', 'strong', tags=['format'])
F(0x01DA7A, 'dec_cmp_signed', 'undefined2', [('undefined2', 'a'), ('undefined2', 'b')],
  '带符号数值比较。', 'likely', tags=['bcd'])
F(0x016EFE, 'dec_copy_ret', 'undefined2*', [('undefined2*', 'dst'), ('undefined2*', 'src')],
  '复制 10 字节 BCD 单元并返回 dst。', 'verified', tags=['bcd'])
F(0x009060, 'base_clear', 'ushort', [('ushort', 'v'), ('undefined*', 'p')],
  '清 0xD16C 区（进制模式输入缓冲），返回参数。', 'likely', tags=['mode'])
F(0x008FC6, 'key_mod_clear', V, [], '清零按键修饰/历史状态（0xD116..0xD119）。',
  'strong', tags=['kbd'])
F(0x008FD0, 'key_hist_set', V, [('uchar', 'v')], '写按键历史 0xD119。', 'strong', tags=['kbd'])
F(0x008FE2, 'key_hist_clear', V, [], '清按键历史（0xD118/0xD148）。', 'strong', tags=['kbd'])
F(0x008FE6, 'set_input_key', V, [('undefined2', 'key')], '把当前键码写入 0xD10E。',
  'verified', tags=['kbd'])
F(0x00F932, 'key_dispatch_menu', V, [], '按键分派：满足条件时调用 0x20860 处理（菜单相关）。',
  'strong', tags=['kbd'])
F(0x00EA80, 'append_history', V, [('undefined2', 'k')],
  '把当前输入追加进历史记录区（0xD176），必要时滚动。', 'strong', tags=['editor'])
F(0x00D806, 'is_neg_char', 'bool', [('byte', 'c')], 'c >= 0xF0（双字节字符首字节）时返回 true。',
  'verified', tags=['charset'])
F(0x023A0C, 'line_col_count', 'uchar', [], '按当前行（0xD137）返回可用列数（10 或 6）。',
  'strong', tags=['text'])
F(0x024EF2, 'draw_spaced', V, [('ushort', 'row'), ('ushort', 'n')],
  '按行绘制带间距的文本（调用 0x246F4）。', 'likely', tags=['text'])
F(0x0253F0, 'beep', V, [], '响铃：蜂鸣器开 → 延时 0x640 → 关。', 'verified', tags=['hw'])
F(0x026A40, 'input_init', V, [],
  '编辑器初始化：清修饰键状态、清输入区/历史游标、设置行号，调用 0x2BD42/0x7E7E。',
  'strong', tags=['editor'])
F(0x028576, 'is_math_io', 'char', [],
  'Math 输入输出模式判断：0xD11E!=0 且 0xD111 bit7 时返回 1。',
  'strong', tags=['ui'])
F(0x029D94, 'is_special_editing', 'char', [],
  '特殊编辑状态判断（0x2880E 或 is_edit_state_6_9）。', 'strong', tags=['ui'])
F(0x02AA76, 'process_key', 'short', [('short', 'arg')],
  '主循环按键处理：读键并处理 ON(0xFC24)/菜单(0xFC25)/普通键，更新 0xD113。',
  'strong', tags=['kbd'])
F(0x0187DA, 'dec_ptr_by_idx', 'short', [('ushort', 'idx')],
  'BCD 单元指针：0x25C0 + (idx&0xFF)*10。', 'verified', tags=['bcd'])
F(0x01C880, 'dec_bin_and_core', V, [('undefined2', 'a'), ('undefined2*', 'b')],
  'opcode 7（逻辑与）核心入口。',
  'verified', tags=['bcd'])
F(0x01C858, 'dec_bin_or_core', V, [('undefined2', 'a'), ('undefined2*', 'b')],
  'opcode 5（逻辑或）核心入口。', 'likely', tags=['bcd'])
F(0x01C894, 'dec_bin_xor_core', V, [('undefined2', 'a'), ('undefined2*', 'b')],
  'opcode 4（逻辑异或）核心入口。',
  'likely', tags=['bcd'])
F(0x01C844, 'dec_bin_div_core', V, [('undefined2', 'a'), ('undefined2*', 'b')],
  'opcode 8（除法）核心入口：设 0xD01E=8 后跳到 0x1C8A6 公共尾部。',
  'likely', tags=['bcd'])
F(0x01C364, 'dec_load_regs', V, [('undefined2*', 'p')], '把 *p 载入算数寄存器 0xD000..0xD009。',
  'verified', tags=['bcd'])
F(0x01909A, 'dec_compare_low', 'void', [('undefined2*', 'a'), ('undefined2*', 'b')],
  '"a < b" 类比较（小整数走 0x1D2FE，否则 0x1CF7C）。', 'strong', tags=['bcd'])
F(0x019052, 'dec_get_small', 'byte', [('ushort*', 'p'), ('undefined2', 'b')],
  '取 p 处的小整数（必要时归一化，失败返回 3）。', 'strong', tags=['bcd'])
F(0x014BDA, 'dec_cmp_bool', 'undefined2*', [('undefined2*', 'a')],
  '复制 a 并比较（返回比较结果）。', 'strong', tags=['bcd'])
F(0x014B0A, 'level_index', 'ushort', [('byte', 'a'), ('byte', 'b')], '返回 row*5+col 形式的层级索引。',
  'likely', tags=['util'])
F(0x0108EC, 'eval_get_operand', 'byte', [], '求值器：取当前操作数（处理阶乘/括号等）。',
  'strong', tags=['eval'])
F(0x0108BA, 'eval_error', V, [('byte', 'code')], '求值错误处理：设置错误码并写结果。',
  'strong', tags=['eval'])
F(0x026226, 'strline_len', 'char', [('char*', 's')], '返回字符串中到扩展字符前的长度。',
  'likely', tags=['libc'])
F(0x020E5A, 'input_history_ptr', V, [], '按模式返回历史记录/输入区指针（0xD784 或 0xD180 等）。',
  'strong', tags=['editor'])
F(0x01B87E, 'dec_status_check', V, [], '检查 BCD 状态（0xD009），更新标志。', 'likely', tags=['bcd'])
F(0x013A1E, 'int_to_dec', V, [('undefined2*', 'dst'), ('undefined2', 'v')], '整数转 BCD 单元。',
  'likely', tags=['bcd'])
F(0x0179B0, 'dec_set_zero', V, [('undefined2', 'a')], '把算数寄存器组置零。', 'likely', tags=['bcd'])
F(0x0179D2, 'dec_normalize2', 'undefined2', [('undefined2', 'a'), ('undefined2', 'b')],
  'BCD 结果归一化/修正。', 'strong', tags=['bcd'])
F(0x01D94C, 'dec_set_from_fmt', 'undefined2', [('undefined2', 'a'), ('undefined2', 'b')],
  '按格式参数把数值装载为 BCD 单元。', 'likely', tags=['bcd'])
F(0x01D550, 'dec_exp_shift', 'undefined2*', [('undefined2*', 'a'), ('ushort', 'b')],
  'BCD 指数移位/缩放。', 'likely', tags=['bcd'])
F(0x01CA7E, 'dec_unary_op', 'undefined2*', [('undefined2*', 'a'), ('undefined2', 'b')],
  '一元 BCD 运算（opcode 0xD01D）。', 'likely', tags=['bcd'])
F(0x016EAC, 'stat_fill_cells', V, [], '按统计表填充 0xD392 区。', 'likely', tags=['stat'])
F(0x016F5A, 'stat_cell_read', V, [('undefined8*', 'p')], '读取统计表单元格。', 'likely', tags=['stat'])
F(0x016F10, 'stat_layout', V, [('undefined8*', 'p')], '按模式返回统计表布局。', 'likely', tags=['stat'])
F(0x016F44, 'stat_layout2', V, [('undefined8*', 'p')], '按模式返回统计表布局（变体）。', 'likely', tags=['stat'])
F(0x009346, 'screen_mode_blank', 'undefined2', [('undefined2', 'p')],
  '设置屏幕模式 0xF031=0x16 并清状态位，返回参数。', 'strong', tags=['gfx'])
F(0x00909E, 'base_submode', 'ushort', [], '进制模式返回 0xD123 相关状态。', 'likely', tags=['mode'])
F(0x0090B4, 'stack_depth', 'ushort', [], '返回 SP 相对 0xE3E4 的栈深度。', 'verified', tags=['hw'])
F(0x0090C0, 'cursor_stack_fill', V, [], '把 0xDBD0 起的 16 字节填为 0x0F..0x00。', 'verified', tags=['editor'])
F(0x0090CE, 'ram_check', 'char', [],
  'RAM 有效性检查：检查 0xDBD0 区、对比度范围、变量区与复数值区；检查失败返回 1（触发全清）。',
  'verified', tags=['boot'])
F(0x01D134, 'dec_round', 'undefined2*', [('undefined2*', 'a'), ('undefined2', 'b')],
  'BCD 舍入/格式化辅助。', 'likely', tags=['format'])
F(0x01D668, 'dec_type_of', 'undefined', [('undefined*', 'p')], '返回 BCD 单元类型字节。',
  'likely', tags=['bcd'])

# ===========================================================================
# 8. BCD 寄存器组与十进制数学库（第二批，2026-10 核对汇编）
# ---------------------------------------------------------------------------
# 寄存器组（各 10 字节，首 2 字节为类型+符号，2..8 为尾数，末 2 字节为指数）：
#   X = 0xD000（主累加器）  Y = 0xD010（辅助）  Z = 0xD030（第三）
#   W = 0xD050（返回槽）
# 类型字节：0x00 = 0（[b]00 00 …[b]），0x10 位 = 负号，0x80 位 = 尾数全零（零），
#           0x01..0x0A = 1..10 的单字节小整数（dec_get_small 直接返回）。
# 以上布局由 0x01DA06 的 dec_copy（LEA [param_2] / L QR8,[EA+] 连续 10 字节）
# 与 0x01AF14 中直接写入 0x6197723675790101 的常数块相互印证。
# ===========================================================================

# ---- 寄存器组搬运（字节级核对：每条语句对应 10 字节块复制）----
F(0x019C56, 'dec_g_Y_to_X', V, [],
  'X ← Y（0xD010 → 0xD000，含 0xD018 → 0xD008）。与 0x19CB0 的 X←Y 为 Ghidra '
  '按 8 字节/2 字节拆分出的两个重叠视图。', 'verified', tags=['bcd'])
F(0x019C68, 'dec_g_W_to_X', V, [],
  'X ← W（0xD050 → 0xD000，含 0xD058 → 0xD008）。', 'verified', tags=['bcd'])
F(0x019C7A, 'dec_g_Z_to_Y', V, [], 'Y ← Z（0xD030/0xD038 → 0xD010/0xD018）。',
  'verified', tags=['bcd'])
F(0x019C8C, 'dec_g_X_to_Z', V, [], 'Z ← X（0xD000/0xD008 → 0xD030/0xD038）。',
  'verified', tags=['bcd'])
F(0x019CB0, 'dec_g_X_to_Y', V, [], 'Y ← X（0xD010/0xD018 ← 0xD000/0xD008）。',
  'verified', tags=['bcd'])
F(0x019CC2, 'dec_g_X_to_W', V, [], 'W ← X（0xD050/0xD058 ← 0xD010/0xD018）。',
  'verified', tags=['bcd'])
F(0x019CD4, 'dec_g_W_to_Y', V, [], 'Y ← W（0xD010/0xD018 ← 0xD050/0xD058）。',
  'verified', tags=['bcd'])
F(0x019C32, 'dec_g_Z4_to_Y', V, [], 'Y ← Z 的第 4 个 8 字节块（0xD03C/0xD044 → 0xD010/0xD018）。',
  'verified', tags=['bcd'])
F(0x019C44, 'dec_g_X_to_Z4', V, [], 'Z 的第 4 块 ← X（0xD03C/0xD044 ← 0xD000/0xD008）。',
  'verified', tags=['bcd'])
F(0x01AFB8, 'dec_swap_XY', V, [], '交换 X 与 Y（0xD000↔0xD010，0xD002↔0xD012 共 10 字节）。',
  'verified', tags=['bcd'])
F(0x01B004, 'dec_swap_XW', V, [], '交换 X 与 W（0xD000↔0xD050，0xD002↔0xD052 共 10 字节）。',
  'verified', tags=['bcd'])
F(0x01B050, 'dec_swap_YZ', V, [], '交换 Y 与 Z（0xD010↔0xD030，0xD012↔0xD032 共 10 字节）。',
  'verified', tags=['bcd'])

# ---- 类型/状态判断 ----
F(0x01B3BE, 'dec_is_nan', 'bool', [],
  '返回 0xD009 > 9：X 的类型为 E/F（错误、无穷等特殊值），十进制数学库拒绝继续运算。',
  'verified', tags=['bcd'])
F(0x01B3B6, 'dec_is_nan_Y', 'bool', [], '返回 0xD019 > 9：Y 的类型为 E/F（特殊值）。',
  'verified', tags=['bcd'])
F(0x01B3D0, 'dec_check_nan_X', 'bool', [],
  '若 X 为特殊值返回 1；否则清除 X 标志位 0x40（内部结果标志）并返回 0。'
  '所有二元/一元入口（0x1CA7E、0x1CE3E 等）第一步都调用它。', 'verified', tags=['bcd'])
F(0x01B3E4, 'dec_check_nan_XY', 'ushort', [],
  '检查 X 与 Y：返回值为高字节携带状态（非 0 表示特殊值/错误），'
  '同时把 0xD009、0xD019 的 0x40 位搬进 LI 位。', 'strong', tags=['bcd'])

# ---- 十进制数学库入口（写成小数运算，由 X、Y、W 寄存器传递）----
F(0x01CE3E, 'decm_add', V, [('undefined2*', 'save'), ('byte', 'angle')],
  '【加减法入口 ±】保存现场到 save(*)、0xD05E=save，按 angle 设置角度模式（0 用 0xD11D），'
  '装载 X←Y，再按 0xD01F 分派：<9 走 0x1AB54（+），==9 走 0x1AC2C（−），>9 走 0x1A98A（特殊值加减）。',
  'verified', tags=['float'])
F(0x01CE4E, 'decm_arith', V, [('byte', 'angle'), ('undefined2', 'saved_d01e')],
  '【加减法入口】与 decm_add 相同但现场已由调用者压栈（0xD01E 通过 ER4 恢复），'
  '不写 0xD05C/0xD05E。', 'strong', tags=['float'])
F(0x01CEA4, 'decm_mul', V, [('undefined2*', 'save'), ('undefined2*', 'p')],
  '【乘法入口 ×】载入 X←*p，调用 0x19A56（乘法核心），角度取 0xD11D，'
  '结果规格化并写回 *save。', 'verified', tags=['float'])
F(0x01CEE8, 'decm_div', V, [('undefined2*', 'save'), ('undefined2*', 'p')],
  '【除法入口 ÷】与 decm_mul 相同，但角度参数固定为 5（度，角度参数不参与乘除）。',
  'verified', tags=['float'])
F(0x01CA7E, 'decm_pow', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '【乘方入口 x^y】设置操作码 0x13 后进入 0x1CAA6 的公共序列。', 'strong', tags=['float'])
F(0x01CA92, 'decm_nroot', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '【乘方根入口 x^(1/y)】设置操作码 0x12 后进入 0x1CAA6 的公共序列。',
  'likely', tags=['float'])
F(0x01CAA6, 'decm_power_common', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '乘方/开方公共序列：装载 X←*a，`xln x`（0x19B28）后按 0xD01F 选 `e^x`（0x1B1E8）'
  '或乘方核心（0x1B1CA 等），结果写回 *b。', 'strong', tags=['float'])
F(0x01CACE, 'decm_sin', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '【sin】装载 X←*a，按 0xD01F（0..2 分别对应不同化简/象限路径）计算后写回 *b。',
  'strong', tags=['float'])
F(0x01CAE2, 'decm_cos', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '【cos】与 decm_sin 共用序列，仅 0xD01F 初值不同。', 'strong', tags=['float'])
F(0x01C95E, 'decm_exp10', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '【10^x】设置操作码 0xF、装载 X←*a；0xD01E<0xE 时按 10 / 其他分支（0x19958 / 0x19A72），'
  '否则 0x1B09C 处理大指数。', 'strong', tags=['float'])
F(0x01CF0C, 'decm_ln', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '【ln】装载 X←*a 后直接调用 0x1A008（自然对数核心），写回 *b。', 'verified', tags=['float'])
F(0x01CF28, 'decm_log10', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '【log】先交换 X/Y（0x1AFB8）再调用 0x19FF8（常用对数核心），写回 *b。',
  'strong', tags=['float'])
F(0x01D8F0, 'decm_round10', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '【x10^x / Rnd 等一元辅助】按 0xD01E 选择 0x1BBA8 或 0x195EA，结果写回 *b。',
  'likely', tags=['float'])
F(0x01D246, 'decm_tan', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '【tan】把操作码设为 2 并以 (a,b) 调用 0x1D280。调用点：0x15C22（求值器运算符）、'
  '0x20318（格式化/化简路径）。', 'verified', tags=['float'])
F(0x01D25A, 'decm_recip', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '【1/x】把操作码设为 1 并以 (a,b) 调用 0x1D280。调用点 0x10C9C、0x10E14 后均紧跟 dec_div，'
  '即先求倒数再相乘实现除法。', 'strong', tags=['float'])
F(0x01D280, 'decm_unary_dispatch', V, [],
  '一元三角函数/倒数分派：按 0xD01E（1=1/x，2=tan）改写为对应的二元运算后继续。',
  'likely', tags=['float'])
F(0x01D26E, 'decm_unary', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '【一元求值入口】操作码 0（按 0xD01D 子操作码：取负/取绝对值等）→ 0x19D76，'
  '负零判断用 X/Y 交换。', 'likely', tags=['float'])

# ---- 数学常量装载（字节核对：尾数 + 2 字节指数）----
F(0x01972C, 'dec_const_ln10', V, [],
  'X ← ln(10) = 2.3025850929940456840。XREF：仅 0x01DA24（1DA02 尾部的锁存函数）。',
  'verified', tags=['float'])
F(0x01974A, 'dec_const_pi', V, [],
  'X ← π = 3.141592653589793238（0xD000=0x1592653589800100，指数 0x0314）。'
  'XREF：0x1965A、0x1CC34、0x1DA3A（三角函数/对数的角度换算）。', 'verified', tags=['float'])
F(0x01AEC2, 'dec_load_like_gnu', V, [],
  '按 0xD02F（角度模式：<5 为弧度派生值、==5 为度）装载 "9" 或 π/180 的常量块到 X。'
  '供 0x1AB54/0x1AC2C 的加减法做角度换算。', 'likely', tags=['float'])
F(0x01AF14, 'dec_load_deg_factor', V, [],
  '按 0xD02F 装载 "1" 或 180/π 的换算系数到 Y（度模式）。', 'likely', tags=['float'])

# ---- 十进制运算核心（尾部 0x1B000 段，按 0xD01E 操作码共享）----
F(0x0197E0, 'decc_pow_split', V, [],
  '乘方核心共用尾巴：0xD01F=9、0xD01C=0，把 A 拆成整数部分与小数部分，'
  '相似数消去后调用 0x1B558。', 'likely', tags=['float'])
F(0x019A56, 'decc_load_Y', V, [],
  '把 Y（0xD010）载入运算暂存并做 DAA 进位整理，供乘法/除法核心使用。', 'strong', tags=['float'])
F(0x019A72, 'decc_log_path', V, [], 'log/exp 小数分支的公共处理（0x1B09C 调用）。',
  'likely', tags=['float'])
F(0x019B28, 'decc_xln', V, [], '计算 x·ln(x) 型中间量（乘方公共序列调用），结果写回运算寄存器。',
  'likely', tags=['float'])
F(0x019D76, 'decc_unary_sign', 'byte', [],
  '一元运算结果整理：把 X、Y 统一成同号/取绝对值的中间态，失败返回非 0。',
  'likely', tags=['float'])
F(0x01B09C, 'decc_exp_large', V, [],
  'e^x 大指数分支：按 0xD01C 分段，调用 0x1B1BC。', 'likely', tags=['float'])
F(0x01B1BC, 'decc_mul_path', V, [], '乘法核心中按 0xD01C 取值范围拆分的公用尾巴。',
  'likely', tags=['float'])
F(0x01B1CA, 'decc_sin_path', V, [], '三角函数化简路径之一（±π/2 象限调整后调用）。',
  'likely', tags=['float'])
F(0x01B1E8, 'decc_exp_path', V, [], 'e^x 的级数展开路径。', 'likely', tags=['float'])
F(0x01B43A, 'decc_add_align', V, [],
  '加法对齐核心：按指数差对齐尾数（DAS 十进制减），处理交换律换位，最后调用 0x1C028。',
  'strong', tags=['float'])
F(0x01B44C, 'decc_sub_align', V, [], '减法对齐核心：与 0x1B43A 对称，结果取补。',
  'strong', tags=['float'])

# ---- 十进制加减核心（R8..R15 寄存器隐式传递操作数）----
F(0x01C30C, 'decc_add8', 'undefined2',
  [('byte', 'r0'), ('byte', 'r1'), ('byte', 'r2'), ('byte', 'r3')],
  '8 字节 BCD 加法：ADD/ADDC + DAA 链，操作数在 R0..R7 与 R8..R15，'
  '结果留在 R0..R7（Ghidra 记为 unaff_R8..R15）。', 'verified', tags=['bcd'])
F(0x01C338, 'decc_sub8', 'undefined2',
  [('byte', 'r0'), ('byte', 'r1'), ('byte', 'r2'), ('byte', 'r3')],
  '8 字节 BCD 减法：SUB/SUBC + DAS 链。', 'verified', tags=['bcd'])
F(0x01C330, 'decc_sub8_mb', 'undefined2',
  [('byte', 'r0'), ('byte', 'r1'), ('byte', 'r2'), ('byte', 'r3')],
  '8 字节 BCD 减法（多字节复用入口：首字节 DAS 后 BC AL 跳入 0x1C33E 的 SUBC 链）。',
  'strong', tags=['bcd'])
F(0x01C304, 'decc_add8_mb', 'undefined2',
  [('byte', 'r0'), ('byte', 'r1'), ('byte', 'r2'), ('byte', 'r3')],
  '8 字节 BCD 加法（多字节复用入口，对应 0x1C30C 的 ADDC 链）。', 'strong', tags=['bcd'])
F(0x01C392, 'dec_store', V, [], '把算数寄存器（0xD000..）写回 *0xD05C 指定的 BCD 单元。',
  'verified', tags=['bcd'])
F(0x01C796, 'dec_tail_233', 'ushort', [('ushort', 'x')],
  '尾数修正：去掉尾数尾部，按 DAT_ram_d00a 的精度位数做 DAA/DAS 规范化，返回修正后的尾数。',
  'strong', tags=['bcd'])
F(0x01C4EE, 'dec_tail_round', V, [], '按精度设置（0xD00A）截断尾数并舍入（FUN 0x1C7C8 系列）。',
  'likely', tags=['bcd'])
F(0x01C506, 'dec_tail_round2', V, [], '尾数截断/舍入的变体（不同精度路径）。',
  'likely', tags=['bcd'])
F(0x01C18C, 'dec_int_convert', V, [], '浮点→整数/科学计数中间表示转换（X、Y 寄存器）。',
  'likely', tags=['bcd'])
F(0x01C028, 'dec_normalize_y', V, [], '运算后把 Y 规格化（调用 0x1C30C/0x1C338 修正尾数）。',
  'likely', tags=['bcd'])
F(0x019890, 'decc_zero_neg', V, [],
  '取负：X←Z，以 0 减去 X（0xD01D=0，0x1B43A 对齐加法）后写回。', 'strong', tags=['float'])
F(0x019958, 'decc_dummy', V, [],
  '空操作占位：依次做 X→W、X→Y（不动数值），被 0x1C95E 的 10^x 分支调用。',
  'likely', tags=['float'])
F(0x01B426, 'decc_sub', V, [], '减法核心入口：0xD01C=2 后调用 0x1B44C（对齐减法）。',
  'strong', tags=['float'])
F(0x01B43A, 'decc_add_align', V, [],
  '加法对齐核心：按指数差对齐尾数（DAS 十进制减），处理交换律换位，最后调用 0x1C028。',
  'strong', tags=['float'])
F(0x01B44C, 'decc_sub_align', V, [], '减法对齐核心：与 0x1B43A 对称，结果取补。',
  'strong', tags=['float'])
F(0x01B522, 'decc_round', V, [], '十进制数学层舍入/规整过程 3（0x1AC2C 使用）。',
  'likely', tags=['float'])
F(0x01B536, 'decc_pack', V, [], '十进制数学层打包/对齐过程 2（0x1890/加减对齐使用）。',
  'likely', tags=['float'])
F(0x01B558, 'decc_unpack', V, [], '十进制数学层拆分/规整过程 1（乘方/指数核心使用）。',
  'likely', tags=['float'])
F(0x01B99A, 'decc_scale_x', V, [],
  '按 in_XR0 的高字节（指数）缩放：0x1F 置 99/上限表值，否则查 0x1BB2 起的 10 字节常量表。',
  'strong', tags=['float'])
F(0x01B9FC, 'decc_packZ', V, [], '把 Z 的 10 字节尾数按指数重新打包到 0xD03C 起的暂存区。',
  'likely', tags=['float'])
F(0x01B892, 'decc_Y_sub_Z', V, [], 'Y ← Y − Z（尾数 0x1C330 十进制减）。', 'strong', tags=['float'])
F(0x01B8BC, 'decc_X_sub_Y', V, [], 'X ← X − Y。', 'strong', tags=['float'])
F(0x01B8E6, 'decc_Y_add_Z', V, [], 'Y ← Y + Z（尾数 0x1C304 十进制加）。', 'strong', tags=['float'])
F(0x01B910, 'decc_X_add_Y', V, [], 'X ← X + Y。', 'strong', tags=['float'])
F(0x01B93A, 'decc_carry_out', V, [], '加减后的进位/借位处理（按精度 0xD00E 修正尾数）。',
  'likely', tags=['float'])
F(0x01B858, 'decc_nop', V, [], '空操作（仅 PUSH/POP 寄存器后返回）。', 'verified', tags=['float'])
F(0x01B87E, 'decc_reload', V, [], '重新装载当前运算寄存器（0x0D000 系列），无可见效果。',
  'verified', tags=['float'])

# ---- 二元运算的分层入口（函数名按 0x1CE4E 的 R4/R5 操作码表）----
#   R4 = 1..3 表示档位 1/2/3；R5 = 9..11 表示 9=乘方族、10=三角函数族、11=加减族
F(0x01CDF6, 'decm_bin_pow1', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '二元入口：档位 2 + 乘方族（R4=2,R5=9）。调用点 0x14222。', 'verified', tags=['float'])
F(0x01CE1A, 'decm_bin_family8_3', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '二元入口：档位 3 + 第 8 族（R4=3,R5=8）。调用点 0x167B6。', 'verified', tags=['float'])
F(0x01CE2C, 'decm_bin_div2', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '二元入口：档位 2 + 除法族（R4=2,R5=8）。调用点 0x16720、0x18F62。', 'verified', tags=['float'])
F(0x01CD2C, 'decm_round_entry', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '取整入口：载入 X←*a；类型为 1/6（小整数/内部结果）时先清 X 再对齐相加，否则 0x19890 取负；'
  '最后写回 *b。Ghidra 把紧随其后的 8 个操作码封装并入该函数体。', 'strong', tags=['float'])

# ===========================================================================
# 9. 表达式求值器（0x10000 段的嵌套“内部块”：多个入口共用同一栈帧）
# ---------------------------------------------------------------------------
# 0x10000 是求值主例程，0x100BC/0x1010C/0x10118/0x10158/0x101F2/0x10302/0x104AC
# 等都出现在其 XREF 中，是从主循环体里切出的标签，共用 __fp 帧与局部槽位。
# 因此这些条目的参数列表按 Ghidra 原文记录（一般是寄存器别名或空）。
# ===========================================================================
F(0x010000, 'eval_expr', 'undefined2', [('byte**', 'pp'), ('undefined2*', 'slots')],
  '表达式求值主例程。先用 0xD4C8（token_at）/0x179C2 预扫描表达式，把 0x52/0x51/0x77..0x79'
  ' 记进标志位（Surveying 的度/弧度/工程记数标记）；随后 0x8FEC 载入首操作数，'
  ' 0x1D780 做二元入口初始化，进入运算循环。', 'strong', tags=['eval'])
F(0x0100BC, 'eval_loop_shift', 'undefined2', [],
  '求值循环的一段（XREF 仅 0x10670）：设置当前令牌位 -7[FP]=1 并推进操作数栈。',
  'likely', tags=['eval'])
F(0x01010C, 'eval_loop_a', 'undefined2', [], '求值循环分支 A（被 0x10118/0x10674/0x10882 跳入）。',
  'likely', tags=['eval'])
F(0x010118, 'eval_loop_b', 'undefined2', [], '求值循环分支 B（被 0x1010C 跳入，内部跳到 0x10158）。',
  'likely', tags=['eval'])
F(0x010158, 'eval_loop_c', 'undefined2', [],
  '求值循环分支 C：读取 R9（当前层级/优先级），为空时把操作数槽置 0。', 'likely', tags=['eval'])
F(0x0101F2, 'eval_loop_d', 'undefined2', [], '求值循环分支 D（跳入 0x10302/0x104AC）。',
  'likely', tags=['eval'])
F(0x010302, 'eval_loop_e', 'undefined2', [], '求值循环分支 E（调用 kbd_wait_key 的空闲等待段）。',
  'likely', tags=['eval'])
F(0x0104AC, 'eval_loop_f', 'undefined2', [], '求值循环分支 F（调用 0x105E2/0x10674）。',
  'likely', tags=['eval'])
F(0x0105E2, 'eval_rotate', 'undefined2', [],
  '操作数寄存器轮换：把 0xD020/0xD010 系列轮转（用于连续二元运算的暂存）。', 'likely', tags=['eval'])
F(0x010674, 'eval_rotate2', 'undefined2', [], '操作数寄存器轮换的变体。', 'likely', tags=['eval'])
F(0x010882, 'eval_shift_op', 'undefined2', [],
  '移位类运算：复制操作数后调用 0x1C830（乘）与 0x1C858（或）做移位合成。', 'likely', tags=['eval'])
F(0x01094A, 'eval_cmp_op', 'undefined2', [],
  '比较类运算（<,>,=,≤,≥）：把操作数乘/复制后与 1 比较，按三种结果写回。',
  'strong', tags=['eval'])
F(0x010B3E, 'eval_logic_op', 'undefined2', [], '逻辑类运算（And/Or/Xor/Not 的求值段）。',
  'likely', tags=['eval'])
F(0x010C4E, 'eval_recip', 'undefined2', [], '求倒数段：调用 0x1D25A（1/x）后接 0x1CF68（除法）。',
  'strong', tags=['eval'])
F(0x010DF4, 'eval_recip2', 'undefined2', [], '求倒数段的变体（不同操作数字节对齐）。',
  'likely', tags=['eval'])
F(0x010F6A, 'eval_pow_op', 'undefined2', [],
  '乘方/开方求值段：调用 0x1CA7E/0x1CAA6 与 0x1CACE（sin）/0x1CAE2（cos）等一元/二元核心。',
  'strong', tags=['eval'])
F(0x011DCC, 'eval_nroot_op', 'byte', [('undefined2*', 'x')],
  '开方求值段：先检查操作数类型为 4，再调用 0x1C86C/0x1CA7E 组合开方。',
  'likely', tags=['eval'])
F(0x01B86C, 'dec_shift_left4', 'ushort', [('byte', 'r0'), ('byte', 'r1')],
  '把 R0..R7 整体左移 4 位（SLLC 链）：尾数规格化/指数调整时使用。', 'verified', tags=['bcd'])
F(0x01B846, 'dec_shift_right4', 'ushort', [('byte', 'r0'), ('byte', 'r1'), ('byte', 'r2')],
  '把 R0..R7 整体右移 4 位（SRLC 链），操作数比 0x1B86C 多一个字节。',
  'verified', tags=['bcd'])
F(0x01D780, 'dec_bin_init', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '二元运算初始化：载入 X←*a、保存 *b 到 0xD05C；若 X 带 0x40 内部标志则先清掉并写回。',
  'verified', tags=['bcd'])
F(0x0194C6, 'dec_set_y1', V, [], 'Y ← 1.0（0xD010=0x0101，其余清零），同时把 0xD012/0xD014 清 0。',
  'verified', tags=['bcd'])
F(0x015EEA, 'token_class_ex', V, [('byte', 'ki'), ('char', 'ko')],
  '在 0xD4C8 取到字符后，把它编码成令牌类别：调用 0x179C2 记录原码并返回类别。',
  'strong', tags=['eval'])
F(0x0152C8, 'dec_cmp_Y_one', V, [('undefined2*', 'p')],
  '以 *p 与常量 1.0（0x1B76）比较，空操作返回。', 'strong', tags=['bcd'])
F(0x015316, 'dec_mul_ER4', V, [('undefined2*', 'p')],
  'X ← X × *p：以 ER4 中的左操作数调用二元乘法 0x1CF54。', 'strong', tags=['bcd'])
F(0x0152FA, 'dec_pow_ER10', V, [], '调用二元乘方 0x1CF90（左操作数在 ER10，右操作数在 ER2）。',
  'strong', tags=['bcd'])
F(0x013A12, 'dec_copy_a', V, [('undefined2*', 'dst')], 'BCD 单元复制（0x1DA02 的薄封装）。',
  'verified', tags=['bcd'])
F(0x01438E, 'dec_copy_b', V, [('undefined2*', 'dst')], 'BCD 单元复制（另一处薄封装）。',
  'verified', tags=['bcd'])
F(0x0143B4, 'dec_copy_c', V, [('undefined2*', 'dst')], 'BCD 单元复制（另一处薄封装）。',
  'verified', tags=['bcd'])
F(0x014B1A, 'level_index_1', V, [], '调用 level_index(1,? 见 0x14B0A)。', 'likely', tags=['util'])
F(0x014034, 'vec_dot_step', V, [],
  '矩阵/向量累加一步：复制元素、乘到 10 字节单元并累加（与 0x14378/0x1439E 配套）。',
  'likely', tags=['matrix'])
F(0x013CD8, 'dec_set_special_ret', 'undefined2', [('byte', 'v')],
  '把 XR8 指向的单元设为特殊值并返回 v（0x1D6A4 的薄封装）。', 'likely', tags=['bcd'])

# ---- UI / 键盘 ----
F(0x02082C, 'key_hist_hi', 'byte', [], '返回 0xD118 的高 4 位（按键历史编码的高半字节）。',
  'verified', tags=['kbd'])
F(0x020834, 'key_hist_lo', 'byte', [], '返回 0xD118 的低 4 位（按键历史编码的低半字节）。',
  'verified', tags=['kbd'])
F(0x020EE6, 'str_emit_backtick', V, [], '向格式化输出追加反引号字符（文本内嵌格式标记）。',
  'likely', tags=['text'])
F(0x020F92, 'str_emit_backtick2', V, [], '向格式化输出追加反引号（另一处调用点）。',
  'likely', tags=['text'])
F(0x0208F2, 'text_clear_panel', V, [], '清空文本面板区域。', 'likely', tags=['text'])

# ---- nX-U8 位操作辅助 ----
F(0x02196A, 'nxsb_test', 'short', [('byte', 'bit')],
  'nX-U8 墓碑函数：R1=0，ADD ER0,ER8，RT。即测试 *ER8 的指定位（结果在 R9 零标志），'
  '并保留 clockless 语义；Ghidra 因缺失数据流分析，把它识别成“(ushort)param_1 + unaff_ER8”。'
  '全 ROM 共 50 处 BL 调用。', 'verified', tags=['hw'])
F(0x021970, 'nxsb_clear', V, [],
  'nX-U8 墓碑函数：R3=0，ADD ER2,ER8，RT。即写 0 并丢弃结果（清除 *ER2 的位 / 空写）。'
  '全 ROM 共 39 处 BL 调用。', 'verified', tags=['hw'])
F(0x02084C, 'key_hist_clear_lo', V, [('byte', 'v')],
  '0xD118 ← v | 0xD118 & 0xF0（替换低半字节），并清 0xD148。', 'verified', tags=['kbd'])
F(0x01EB86, 'is_equation_mode', 'char', [],
  '返回 (0xD111 == 0x45) && (0xD114 == 1)：方程/函数（EQUA）模式的编辑状态判断。',
  'verified', tags=['mode'])
F(0x020D10, 'stat_view_event', V, [],
  'STAT 模式视图按键事件（0xD114==6 时按 0xD115 分派）。', 'likely', tags=['stat'])

# ---- BCD 寄存器搬运/比较 ----
F(0x019C9E, 'dec_g_X_to_Z2', V, [],
  'Z ← X 的重叠视图（0xD000/0xD008 → 0xD010/0xD018）。', 'verified', tags=['bcd'])
F(0x01AFDE, 'dec_swap_XZ', V, [],
  '交换 X 与 Z（0xD000↔0xD032，0xD002↔0xD032，共 10 字节）。', 'verified', tags=['bcd'])
F(0x01AF5A, 'dec_prepare_compare', V, [],
  '比较前规整：X 为特殊值时直接返回；尾数 ≥ 0x10 时先规格化（0x1C30C 加法/DAA）再调用 0x1C670。'
  '供 0x1A1D0/0x1A232/0x1AB54/0x1D7B0 等比较路径调用。', 'strong', tags=['bcd'])
F(0x01C40A, 'dec_set_Y_1e0', V, [],
  '置 Y = 10^0（Y 清零、0xD010=0x100 且 0xD018=0x100），并调用 0x1C506 整理尾数。',
  'strong', tags=['bcd'])
F(0x01BFE8, 'dec_set_Y_1e0_x', V, [],
  '置 Y = 10^0（与 0x1C40A 相同但不检查 X 类型），调用 0x1C022。', 'strong', tags=['bcd'])
F(0x01C152, 'dec_g_X_to_Y_copy', V, [],
  'Y ← X 的完整 10 字节复制（X 为特殊值时直接返回），供取负/一元运算使用。',
  'strong', tags=['bcd'])
F(0x01C022, 'dec_neg_Y_inplace', V, [],
  'Y ← −Y：先交换 X/Y，取反后换回。', 'strong', tags=['bcd'])

# ---- 应用/统计 ----
F(0x01530C, 'dec_copy_step', V, [('undefined2*', 'dst')],
  '复制 dst 的下一个 10 字节单元（dst+10）。', 'verified', tags=['bcd'])
F(0x01439E, 'dec_copy_step2', V, [], 'BCD 单元复制一步（ER2 为源）。', 'likely', tags=['bcd'])
F(0x018108, 'dec_type_byte', 'byte', [('ushort', 'idx')],
  '返回第 idx 个 BCD 单元的首字节（类型/符号，0x187DA 取指针后的封装）。',
  'verified', tags=['bcd'])
F(0x018112, 'dec_to_str_idx', 'char*', [('ushort', 'idx')],
  '把第 idx 个 BCD 单元格式化为字符串（0x187DA 取指针后调用 0x1D620）。',
  'strong', tags=['bcd'])
F(0x017A48, 'dec_load_callee', V, [],
  '按 0xD05E（运算参数 B 指针）载入 BCD 单元到 X，并把 0xD01E 置为操作码。',
  'strong', tags=['bcd'])
F(0x017DCC, 'dec_arg_load', V, [],
  '按 0x187DA 得到的单元指针载入一个 BCD 操作数。', 'likely', tags=['bcd'])
F(0x01821E, 'dec_arg_copy', V, [],
  '复制/交换两个 BCD 操作数（0x187DA 指针 + memcpy_bytes）。', 'likely', tags=['bcd'])
F(0x017F78, 'dec_unary_calc', V, [],
  '一元运算的分发：按 0x187DA 取单元指针后调用 0x1C18C/0x1C30C 完成计算。',
  'likely', tags=['bcd'])
F(0x012832, 'stat_sub_loop', V, [], 'STAT 子模式主循环（读键 + 十进制运算分派）。',
  'likely', tags=['stat'])
F(0x012650, 'stat_table_loop', V, [], 'STAT 表格编辑循环（调用 0x16EF0 系列表格函数）。',
  'likely', tags=['stat'])
F(0x012316, 'stat_aux', 'undefined2', [], 'STAT 模式的辅助计算（读 0xD164/0xD165 统计标志）。',
  'likely', tags=['stat'])
F(0x0129F6, 'table_cell_calc', V, [], 'TABLE 模式单元格计算（十进制运算调用）。',
  'likely', tags=['mode'])
F(0x019C0E, 'dec_g_X_to_W2', V, [],
  'W ← X 的重叠视图（0xD018 → 0xD038），取负结果搬移用。', 'verified', tags=['bcd'])
F(0x01A920, 'decc_int_low_word', 'ushort', [],
  '返回 X 尾数低 16 位并规整（0x1A4F6/0x1A79A 中对位数的提取）。',
  'verified', tags=['bcd'])
F(0x01A79A, 'decc_int_entry', V, [],
  'D05A=0 后调用 0x1A7A4：先清 X/Y，再按操作码走 0x1C81A/0x1C18C；清 0xD05A 的入口。',
  'strong', tags=['bcd'])
F(0x01A7A4, 'decc_int_prep', V, [],
  '重载 X 并按 0xD008 类型为操作数准备 0xD000/0xD010：0 与 0x20 两种初值。',
  'strong', tags=['bcd'])
F(0x01BE46, 'stat_calc_proc', V, [], 'STAT 统计计算过程（大量十进制加减核心调用）。',
  'likely', tags=['stat'])
F(0x01D89E, 'dec_unary_sin', V, [], '一元入口（sin 路径，调用 0x1C364 载入后进入 0x1D280）。',
  'likely', tags=['bcd'])
F(0x01D900, 'dec_unary_cos', V, [], '一元入口（cos 路径）。', 'likely', tags=['bcd'])
F(0x0177D0, 'str_parse_number', V, [],
  '把输出缓冲中的数字串解析成 BCD 数值（0x15ECE 读出字符 → 0x177DA 解析）。',
  'likely', tags=['eval'])

# ===========================================================================
# 10. 应用模式（模式循环 / 结果格式化 / 表格）
# ---------------------------------------------------------------------------
# 0x14C5E 是 0x280B0（BASE-N）与 0x13368（矩阵，经 0x28594）共同调用的通用
# “模式主循环 + 电源/菜单分派”例程，其余 0x14E38..0x15A62 是它的子过程，
# 互相调用形成一棵调用树；下表的名称反映它们在树中的位置与主要工作。
# ===========================================================================
F(0x014C5E, 'apps_mode_main', 'undefined2', [('undefined2', 'arg')],
  '应用模式主例程：按 0xD112/0xD111 的模式号建立界面、进入按键循环，'
  '处理 ON/菜单键并调用各子过程。0x280B0（BASE-N）与 0x13368（矩阵）都调用它。',
  'strong', tags=['mode'])
F(0x014FF8, 'apps_display_update', 'undefined2', [('undefined2', 'arg')],
  '结果/表达式显示刷新子过程（调用 decm_add/dec_to_string 的格式化路径，'
  '经 0x14C5E 与 0x15650 调用）。', 'strong', tags=['mode'])
F(0x015180, 'apps_input_line', 'undefined2', [],
  '输入行编辑子过程：检查 0xD111 == 0x4B（矩阵模式）后进入矩阵编辑分支。',
  'strong', tags=['mode'])
F(0x015396, 'apps_matrix_edit', 'undefined2', [('undefined2', 'arg')],
  '矩阵模式编辑子过程（同样检查 0xD111 == 0x4B），被 0x14FF8/0x15180 调用。',
  'strong', tags=['mode'])
F(0x01532E, 'apps_key_handler', 'undefined2', [],
  '按键处理子过程：调用 0x152FA（乘方）/0x1513C（比较）等十进制运算后交给 0x15628。',
  'strong', tags=['mode'])
F(0x014E38, 'apps_submenu', 'undefined2', [('undefined2', 'arg')],
  '子菜单/选项卡处理子过程（被 0x14C5E 与 0x15384/0x158EE/0x159C6/0x15A62 调用）。',
  'strong', tags=['mode'])
F(0x014ECE, 'apps_view_scroll', 'undefined2', [('undefined2', 'arg')],
  '视图滚动/翻页子过程（不读键，只处理显示缓冲区）。', 'likely', tags=['mode'])
F(0x015650, 'apps_help_view', 'undefined2', [('undefined2', 'arg')],
  '帮助/说明视图子过程：先切换到空屏（screen_mode_blank）再显示文本。',
  'likely', tags=['mode'])
F(0x015828, 'apps_menu_loop', 'undefined2', [],
  '菜单循环子过程：反复读键（kbd_wait_key）并按 0x15180 分支。', 'likely', tags=['mode'])
F(0x015A28, 'apps_dialog_loop', 'undefined2', [],
  '对话/提示框循环子过程（调用 log 相关十进制入口）。', 'likely', tags=['mode'])
F(0x015A62, 'apps_result_view', 'undefined2', [('undefined2', 'arg')],
  '结果显示视图子过程（调用 int_to_dec / dec_copy 等）。', 'likely', tags=['mode'])
F(0x0158EE, 'apps_prompt', 'undefined2', [],
  '单行提示子过程（只调用 kbd_wait_key 等待一次按键）。', 'likely', tags=['mode'])
F(0x0159C6, 'apps_message', 'undefined2', [], '消息框子过程（等待按键后返回）。',
  'likely', tags=['mode'])
F(0x013368, 'apps_matrix_main', 'undefined2', [('undefined2', 'arg')],
  '矩阵模式（0xD112 == 5）主例程：矩阵行列数检查与运算调用，再转 0x14C5E。',
  'strong', tags=['mode'])
F(0x028594, 'mode_4b_matrix_impl', V, [], '矩阵模式循环的实现（调用 0x13368）。',
  'strong', tags=['mode'])
F(0x0280B0, 'mode_45_base_impl', V, [], 'BASE-N 进制模式循环的实现（调用 0x14C5E）。',
  'strong', tags=['mode'])
F(0x01FE60, 'menu_get_key', 'short', [('char', 'k')],
  '显示菜单（0x8CC0 设置行号）并循环 read_key，直到 key_is_value 判定为有效菜单键，'
  '返回键码。调用点 0x285E4/0x24B7E/0x28138 等。', 'strong', tags=['kbd'])
F(0x008CC0, 'menu_draw', V, [('char', 'first')],
  '菜单绘制：设置当前行 0xD137=0x0E，按 first 选择 ROM 0x62A8/0x6686 表绘制菜单项。',
  'strong', tags=['ui'])
F(0x013CF2, 'apps_row_calc', V, [], '表格/矩阵按行计算（十进制累加）。',
  'likely', tags=['mode'])
F(0x015838, 'apps_cell_edit', V, [], '单元格编辑子过程。', 'likely', tags=['mode'])
F(0x0134F8, 'apps_mat_size', V, [('undefined2', 'arg')], '矩阵尺寸调整（列记忆 0xD149）。',
  'likely', tags=['matrix'])
F(0x013494, 'apps_mat_row', V, [], '矩阵行操作（增删行）。', 'likely', tags=['matrix'])
F(0x01369A, 'dec_cmp_path1', V, [],
  '比较路径 1：以 0xD752 与 0xD6BC 为操作数调用 0x1DA7A/0x1D620，'
  '按结果调整操作数槽（0x13584 的另一半）。', 'likely', tags=['bcd'])
F(0x013564, 'apps_mat_check', V, [('undefined2', 'arg')], '矩阵行列数校验。',
  'likely', tags=['matrix'])
F(0x013BFA, 'apps_tbl_read', V, [], 'TABLE 模式表格读取。', 'likely', tags=['mode'])
F(0x018D16, 'vec_compute', 'undefined2', [],
  '向量/复数运算过程：大量调用 decm_pow/decm_sin/decm_cos 等十进制数学入口。',
  'strong', tags=['matrix'])
F(0x0219FE, 'stat_ui_loop', V, [],
  'STAT 模式菜单/编辑界面循环（stat_layout/stat_cell_read/str_parse_number）。',
  'strong', tags=['stat'])
F(0x02153C, 'stat_editor', V, [], 'STAT 编辑界面（大量十进制运算入口）。',
  'strong', tags=['stat'])
F(0x021140, 'stat_view_loop', V, [], 'STAT 视图循环（与 0x2153C 类似的运算分派）。',
  'likely', tags=['stat'])
F(0x021E9C, 'stat_table_edit', V, [], 'STAT 表格编辑（stat_table_clear/stat_cell_read）。',
  'likely', tags=['stat'])
F(0x022A8C, 'stat_analysis', V, [], 'STAT 数据处理（1-VAR/2-VAR 统计量计算）。',
  'likely', tags=['stat'])
F(0x026700, 'str_format_frac', V, [], '分数格式化（a/b 与 d/c 两种显示）。',
  'likely', tags=['format'])
F(0x0263C8, 'str_format_frac_impl', V, [], '分数显示的辅助实现。', 'likely', tags=['format'])

# ---- 缓冲清空 / 状态复位 ----
F(0x014308, 'memzero_A0', V, [('undefined*', 'p')], '把 p 处 0xA0（160）字节清零（工作表）。',
  'verified', tags=['util'])
F(0x014B56, 'memzero_C8', V, [('undefined*', 'p')], '把 p 处 200 字节清零。',
  'verified', tags=['util'])
F(0x015AFE, 'clear_work_area', V, [], '把 0xD6B2 起 0x140 字节清零（应用模式工作表）。',
  'verified', tags=['apps'])
F(0x00C34C, 'clear_replay_buf', V, [], '清零回放区 0xD248（200 字节）。', 'verified', tags=['mode'])
F(0x025258, 'ratio_reset', V, [],
  'RATIO 模式（0xD111 == 0x88）下清 0xD152 标志与回放保存区 0xD84C（200 字节）。',
  'strong', tags=['mode'])
F(0x01E6B6, 'stat_state_reset', V, [],
  '把统计/编辑状态复位：0xD114=1、0xD115=0、0xD116=1、0xD117=0。', 'strong', tags=['stat'])
F(0x02623C, 'stat_table_reset', V, [], '统计表复位：调用 0x96E8 与 0x8FC6（清修饰键/状态）。',
  'strong', tags=['stat'])
F(0x016C3A, 'stat_entry_ptr', 'ushort*', [],
  '返回统计表第 R10 项的指针（0xD05E + R10*2 读出的指针）。', 'strong', tags=['stat'])
F(0x013A98, 'nop_return', V, [], '空函数（直接返回），作为调用轴上的占位。',
  'verified', tags=['util'])
F(0x019CF8, 'dec_g_Y_to_Z', V, [], 'Z ← Y（0xD030/0xD038 ← 0xD010/0xD018）。',
  'verified', tags=['bcd'])
F(0x01C4C6, 'decc_carry_round', V, [],
  '进位后处理：Y 为正规数时对 X 的尾数按 DEC 加 5 并整理尾数（0x1C506）；否则 X→Y 搬移。',
  'strong', tags=['float'])
F(0x01949E, 'dec_load_union', V, [],
  'X ← (X ∪ Y)：把 X 的类型/符号与 Y 的尾数合并成内部运算表示。', 'likely', tags=['bcd'])
F(0x01A1D0, 'decc_arith_core', V, [],
  '加减法核心公共段：按 X/Y 是否为零选择 0x1C042/0x1AF5A 或 0x19C8C..0x1B050 的规范化路径。',
  'strong', tags=['float'])
F(0x015ECE, 'eval_token_scan', 'ushort', [],
  '求值预扫描：从输入区取下一个字符（0xD4C8 → 0x179C2 → 0x15EEA），返回令牌编码。',
  'strong', tags=['eval'])
F(0x016820, 'stat_2var_calc', V, [], '双变量统计计算（Σxy、回归系数等）。', 'likely', tags=['stat'])
F(0x012506, 'stat_1var_calc', V, [], '单变量统计计算（Σx、Σx²、σ 等）。', 'likely', tags=['stat'])

# ---- log / ln / exp 核心 ----
F(0x019FF8, 'decc_log10_core', V, [],
  '常用对数核心：0xD01E=0x0E、0xD05B=0x10，调用 0x19DD6 做对数近似，'
  '再按 0xD009 & 0xF0 == 0x20 分支（X 已是 10 的幂则直接取指数）。', 'strong', tags=['float'])
F(0x01A008, 'decc_ln_core', V, [],
  '自然对数核心：与 0x19FF8 同构，仅 0xD01E=0x0F、0xD05B=0（自然对数）。',
  'strong', tags=['float'])
F(0x019DD6, 'decc_log_series', V, [], '对数级数展开：log 核心的公共近似段。',
  'likely', tags=['float'])
F(0x019EDA, 'decc_neg_process', V, [],
  '取负过程：0xD01E=0x0B，调用 0x1A7A4/0x19C68/0x1AFB8 后按 0xD01E 选择 0x1BE46 与 0x1AF5A 分支。',
  'strong', tags=['float'])
F(0x019EE4, 'decc_abs_process', V, [], '取绝对值过程（与 0x19EDA 同构，0xD01E=0x0D）。',
  'likely', tags=['float'])
F(0x01A98A, 'decc_add_special', V, [],
  '加减法的特殊值分支（decm_add 在 0xD01F>9 时进入）：处理零/特殊值/无穷的组合。',
  'strong', tags=['float'])
F(0x01AD12, 'decc_add_special2', V, [], '特殊值加法的第二段（0x1A98A 的后续分支）。',
  'likely', tags=['float'])
F(0x0194C6, 'dec_set_y1', V, [], 'Y ← 1.0（0xD010=0x0101，其余清零）。', 'verified', tags=['bcd'])
F(0x019768, 'dec_init_work', V, [],
  '工作寄存器初始化：X←W、X=1.0，依次调用 0x1B426/0x19C0E/0x1C152/… 建立计算上下文（无调用者，'
  '推测由启动/模式切换直接进入）。', 'likely', tags=['bcd'])
F(0x01DBC6, 'apps_matrix_view', V, [],
  '矩阵查看/编辑界面（初始化 0xD6B2 工作区与若干暂存指针，调用 clear_work_area）。',
  'likely', tags=['matrix'])

# ---- 光标 / 列表（0xD134 页、0xD135 列、0xD136 行）----
F(0x0096E8, 'cursor_home', V, [],
  '把光标三元组复位：0xD134=0xD135=0xD136=1，0xD16A=1（列表回到位置 1,1）。',
  'strong', tags=['ui'])
F(0x00B032, 'cursor_draw_list', V, [],
  '按 0xD134/0xD135/0xD136 绘制列表光标（0x8966 查字形、0x8B80/0x8D7E 画框）。',
  'strong', tags=['ui'])
F(0x028294, 'cursor_update_list', V, [],
  '按三元组更新列表光标（0x8ED0 取条目地址、0x20C64/0x29D00 画选中项）。',
  'strong', tags=['ui'])
F(0x02B00A, 'list_ui_loop', V, [('byte*', 'input')],
  '列表式界面主循环（0xD116 状态、调用 0xB032 画光标、process_key 读键）。',
  'strong', tags=['ui'])
F(0x00B434, 'matrix_cell_draw', V, [],
  '矩阵/表格单元绘制：按 0xD112 行号、0xD134.. 列号定位并绘制单元格内容。',
  'strong', tags=['matrix'])
F(0x01F25A, 'stat_edit_move', V, [('undefined2*', 'v')],
  'STAT 编辑光标移动：0xD114==6 时载入数值并按 0xD115 切换编辑列。',
  'strong', tags=['stat'])
F(0x00B3AC, 'cursor_home_ui', V, [], '光标复位并立即重绘（0x96E8 的封装）。', 'likely', tags=['ui'])
F(0x0251EC, 'stat_list_reset', V, [], 'STAT 列表光标复位封装（0x96E8）。', 'likely', tags=['stat'])
F(0x01E732, 'menu_cursor_reset', V, [], '菜单光标复位（0x96E8 的薄封装）。', 'likely', tags=['ui'])

# ---- 小型判定 / 访问器 ----
F(0x00C2CC, 'is_menu_key_80', 'char', [('byte', 'k')],
  'k 为 0xC0/0xA7/0xA6（菜单导航相关扩展键）时返回 1。', 'likely', tags=['kbd'])
F(0x00CCDA, 'key_hist_swap_nibbles', V, [],
  '把 0xD118 的高 4 位与低 4 位互换（回车后把“上/下”标志移到低半字节）。',
  'strong', tags=['kbd'])
F(0x00CDD0, 'is_display_busy', 'char', [],
  '返回 (0x24E10() != 0) && (0xD122 != 0)：显示/计算进行中标志。', 'likely', tags=['ui'])
F(0x00CD40, 'edit_field_step', V, [('byte*', 'p')],
  '编辑项字段递增：p+5 小于 p+4 时自增，否则调用 0x253F0 回绕到 p+4。',
  'strong', tags=['editor'])
F(0x00AF52, 'input_cols', 'byte', [],
  '返回输入区可用列数：当前行 0xD137 == 10 时为 5，否则为 7。', 'strong', tags=['editor'])
F(0x00F918, 'is_ascii_digit', 'char', [('byte*', 'p')], 'p 处字节为 0x30..0x39 时返回 1。',
  'verified', tags=['util'])
F(0x00FBD4, 'error_set_location', V, [('byte', 'q'), ('byte', 'r')],
  '记录错误位置（0xD158/0xD159），调用 0x20DF4 重绘，并把 0xD137 暂存到 0xD133。',
  'likely', tags=['eval'])
F(0x00B58E, 'addr_norm', 'undefined*', [('undefined*', 'p')],
  '把显示地址规范化：0xD139==0 时返回 0xF800 区地址，否则返回 0xDDD4 区地址。',
  'strong', tags=['display'])
F(0x00B90A, 'nop_rt', V, [], '空函数（仅 return），用作调用占位。', 'verified', tags=['util'])
F(0x00921E, 'return_one', 'short', [], '恒返回 1。', 'verified', tags=['util'])
F(0x00D82A, 'return_zero_d', 'short', [], '恒返回 0。', 'verified', tags=['util'])
F(0x010E46, 'return_ff', 'short', [], '恒返回 0xFF。', 'verified', tags=['util'])

# ---- 显示驱动 ----
F(0x007E7E, 'fb_clear_rows', V, [('byte', 'n')],
  '把帧缓冲 0xDDD4 的前 n 行清零（每行 24 字节，行地址 = 0xDDD4 + n*24）。',
  'strong', tags=['display'])
F(0x008C98, 'lcd_set_status_x', V, [], '置位 LCD 状态寄存器 0xF811 的 bit0。',
  'verified', tags=['display'])
F(0x008CA8, 'get_ram_base', 'byte', [], '返回 0xF050（LCD/键盘外设基址的低字节）。',
  'verified', tags=['hal'])
F(0x008CAE, 'kbd_ko_set', 'undefined2', [('undefined2', 'v')],
  '把键盘输出 0xF044 设为 0x80、0xF045 设为 0xFF（KO 全拉低），返回参数。',
  'verified', tags=['kbd'])
F(0x008CEE, 'ui_state_init', V, [],
  '界面状态复位：0xD114=1、清 0xD0F7/0xD13A/0xD13F/0xD10E(设 0xFC26)、0xD142/0xD164/0xD165，'
  '0xD139=1，并调用 0x9304 建立显示。', 'strong', tags=['ui'])
F(0x008482, 'char_print_zero', V, [('undefined*', 'p')],
  '以 0 为参数调用 0x849C（字形查表，对应字符码 0）。', 'likely', tags=['display'])

# ---- 常量装载 / 寄存器片段搬运 ----
F(0x0194DC, 'dec_set_Y_one', V, [],
  'Y ← 1（0xD010=0x0100，尾数 0x1111 填满，指数固定）。', 'strong', tags=['bcd'])
F(0x0194F6, 'dec_set_Y_9e0', V, [], 'Y ← 9×10^0（0xD010=0x9900，指数 0x0900）。',
  'strong', tags=['bcd'])
F(0x019510, 'dec_set_Y_1e0_a', V, [], 'Y ← 1×10^0（0xD010=0x0102，指数 0x0200）。',
  'strong', tags=['bcd'])
F(0x01952A, 'dec_set_Y_1e0_b', V, [], 'Y ← 1.0（0xD010=0x0102，指数 0x0180）。',
  'strong', tags=['bcd'])
F(0x019BEA, 'dec_g_Q_to_Y', V, [], 'Y ← Q（0xD046/0xD04E → 0xD010/0xD018）。',
  'verified', tags=['bcd'])
F(0x019BFC, 'dec_g_Y_to_Q', V, [], 'Q ← Y（0xD010/0xD018 → 0xD046/0xD04E）。',
  'verified', tags=['bcd'])
F(0x019C20, 'dec_g_Z4_to_X', V, [], 'X ← Z 的第 4 块（0xD03C/0xD044 → 0xD000/0xD008）。',
  'verified', tags=['bcd'])
F(0x019CE6, 'dec_g_Z4_to_X2', V, [], 'X ← Z（0xD030/0xD038 → 0xD000/0xD008）。',
  'verified', tags=['bcd'])
F(0x019D14, 'dec_exp_entry', V, [], 'e^x 入口：0xD01E=6 后调用 0x1A15A。', 'likely', tags=['float'])
F(0x019F72, 'decm_log_entry', V, [], 'log 入口：0xD01E=0x0E、Y←1，调整指数后调用 0x19FF8（log10 核心）。',
  'strong', tags=['float'])
F(0x019A48, 'dec_bcd_sub16', 'undefined2', [('byte', 'lo'), ('byte', 'hi')],
  '16 位 BCD 减 0x10：DAS 链，返回高/低字节拼接。', 'likely', tags=['bcd'])
F(0x019A4C, 'dec_bcd_sub32', 'undefined2',
  [('byte', 'a0'), ('byte', 'a1'), ('byte', 'b0'), ('byte', 'b1')],
  '32 位 BCD 减法（两个 16 位半），DAS 链。', 'likely', tags=['bcd'])
F(0x0182E8, 'dec_is_big', 'char', [('short', 'idx')],
  '返回第 idx 个 BCD 单元偏移 8 处的字节 > 0x0E（大数/特殊值判断）。',
  'verified', tags=['bcd'])
F(0x015ECA, 'token_classify', 'ushort', [('ushort', 'tok')],
  '以 (低字节, 高字节) 调用 0x15EEA 重新分类令牌，返回原令牌。', 'strong', tags=['eval'])
F(0x015E4E, 'is_token_3', 'char', [('ushort', 'tok')],
  '先 0x15ECA 分类，再返回 (低字节 == 3)。', 'strong', tags=['eval'])
F(0x015F76, 'neg_u16', 'ushort', [('ushort', 'v')], '16 位取负（0xFFFF - v + 1）。',
  'verified', tags=['util'])
F(0x0160E8, 'bit_reverse8', V, [('byte', 'v')],
  '字节位反转：循环左移直到最高位为 1（结果留在参数寄存器）。', 'likely', tags=['util'])
F(0x017F6A, 'evaluator_abort', 'short', [],
  '求值器的失败出口（返回 0；Ghidra 标注了多处不可达块）。', 'likely', tags=['eval'])

# ---- 输出字符串封装 ----
F(0x020EB4, 'str_emit_1A', V, [], '追加记号字符 0x1A（换行/分隔符）。', 'likely', tags=['text'])
F(0x020EBC, 'str_emit_1B', V, [], '追加记号字符 0x1B。', 'likely', tags=['text'])
F(0x020EC2, 'str_emit_1B1A', V, [], '追加记号序列 0x1B 0x1A。', 'likely', tags=['text'])
F(0x020EC8, 'str_emit_1B1E', V, [], '追加记号序列 0x1B 0x1E。', 'likely', tags=['text'])
F(0x020ECE, 'str_emit_1D31', V, [], '追加 ROM 0x1D31 处的记号串。', 'likely', tags=['text'])
F(0x020ED4, 'str_emit_1D35', V, [], '追加 ROM 0x1D35 处的记号串。', 'likely', tags=['text'])
F(0x020EDA, 'str_emit_1D37', V, [], '追加 ROM 0x1D37 处的记号串。', 'likely', tags=['text'])
F(0x020EE0, 'str_emit_1D39', V, [], '追加 ROM 0x1D39 处的记号串。', 'likely', tags=['text'])
F(0x020EEC, 'str_emit_1D3D', V, [], '追加 ROM 0x1D3D 处的记号串。', 'likely', tags=['text'])
F(0x020F32, 'str_emit_1D1A', V, [], '追加 ROM 0x1D1A 处的记号串。', 'likely', tags=['text'])
F(0x020F38, 'str_emit_1C', V, [], '追加记号字符 0x1C。', 'likely', tags=['text'])
F(0x020F3E, 'str_emit_19', V, [], '追加记号字符 0x19。', 'likely', tags=['text'])
F(0x020F44, 'str_emit_1D4D', V, [], '追加 ROM 0x1D4D 处的记号串。', 'likely', tags=['text'])
F(0x020F4A, 'str_emit_1D4F', V, [], '追加 ROM 0x1D4F 处的记号串。', 'likely', tags=['text'])
F(0x020F50, 'str_emit_1C19x2_1B', V, [], '追加记号序列 0x1C 0x19 0x1C 0x19 0x1B。',
  'likely', tags=['text'])
F(0x020F56, 'str_emit_1F', V, [], '追加记号字符 0x1F。', 'likely', tags=['text'])
F(0x020F5C, 'str_emit_181F1D1A', V, [], '追加记号序列 0x18 0x1F 0x1D 0x1A。',
  'likely', tags=['text'])
F(0x020F62, 'str_emit_t', V, [], '追加 ASCII "t"。', 'verified', tags=['text'])
F(0x020F68, 'str_emit_1D61', V, [], '追加 ROM 0x1D61 处的记号串。', 'likely', tags=['text'])
F(0x020F6E, 'str_emit_mode_tag', V, [],
  '按 0xD14E 追加 0x99 或 0x65（两种状态标签）。', 'likely', tags=['text'])
F(0x020F80, 'str_emit_1D67', V, [], '追加 ROM 0x1D67 处的记号串。', 'likely', tags=['text'])
F(0x020F86, 'str_emit_plus', V, [], '追加 ASCII "+"。', 'verified', tags=['text'])
F(0x020F8C, 'str_emit_minus', V, [], '追加 ASCII "-"。', 'verified', tags=['text'])
F(0x020F98, 'str_emit_lparen', V, [], '追加 ASCII "("。', 'verified', tags=['text'])
F(0x020F9E, 'str_emit_rparen', V, [], '追加 ASCII ")"。', 'verified', tags=['text'])
F(0x020FA4, 'str_emit_1D73', V, [], '追加 ROM 0x1D73 处的记号串。', 'likely', tags=['text'])
F(0x020FAA, 'str_emit_1D77', V, [], '追加 ROM 0x1D77 处的记号串。', 'likely', tags=['text'])
F(0x020FB0, 'str_emit_1D7C', V, [], '追加 ROM 0x1D7C 处的记号串。', 'likely', tags=['text'])
F(0x020FB6, 'str_emit_1D81', V, [], '追加 ROM 0x1D81 处的记号串。', 'likely', tags=['text'])
F(0x020FBE, 'str_emit_1D86', V, [], '追加 ROM 0x1D86 处的记号串。', 'likely', tags=['text'])
F(0x020FC6, 'str_emit_1D8B', V, [], '追加 ROM 0x1D8B 处的记号串。', 'likely', tags=['text'])
F(0x020FCE, 'str_emit_1D90', V, [], '追加 ROM 0x1D90 处的记号串。', 'likely', tags=['text'])
F(0x020FD6, 'str_emit_1D97', V, [], '追加 ROM 0x1D97 处的记号串。', 'likely', tags=['text'])
F(0x020FDE, 'str_emit_1D9E', V, [], '追加 ROM 0x1D9E 处的记号串。', 'likely', tags=['text'])
F(0x020FE6, 'str_emit_xeq', V, [], '追加 ASCII "x="（ROM 0x1DA4）。', 'verified', tags=['text'])
F(0x020FEE, 'str_emit_1DA7', V, [], '追加 ROM 0x1DA7 处的记号串。', 'likely', tags=['text'])
F(0x020FF6, 'str_emit_xlt', V, [], '追加 ASCII "x<"（ROM 0x1DAA）。', 'verified', tags=['text'])
F(0x020FFE, 'str_emit_1DAD', V, [], '追加 ROM 0x1DAD 处的记号串。', 'likely', tags=['text'])
F(0x021006, 'str_emit_ltx', V, [], '追加 ASCII "<x"（ROM 0x1DB0）。', 'verified', tags=['text'])
F(0x02100E, 'str_emit_1DB3', V, [], '追加 ROM 0x1DB3 处的记号串。', 'likely', tags=['text'])
F(0x021016, 'str_emit_ltxlt', V, [], '追加 ASCII "<x<"（ROM 0x1DB6）。', 'verified', tags=['text'])
F(0x02101E, 'str_emit_1DBA', V, [], '追加 ROM 0x1DBA 处的记号串。', 'likely', tags=['text'])
F(0x021026, 'str_emit_and', V, [], '追加 ASCII " and "（ROM 0x1DBE）。', 'verified', tags=['text'])

# ---- 键盘历史 / 判定 ----
F(0x02083C, 'key_hist_set_hi', V, [('byte', 'v')],
  '0xD118 ← 0xD118 & 0x0F | v << 4（替换高半字节），并清 0xD148。',
  'verified', tags=['kbd'])
F(0x020860, 'key_hist_write', V, [('byte', 'v')], '0xD118 ← v，并清 0xD148。',
  'verified', tags=['kbd'])
F(0x020702, 'list_sep_char', 'byte', [], '返回列表分隔符：0xD11C == 0 时为 0x2C（,），否则 0x2E（.）。',
  'strong', tags=['editor'])
F(0x01FBD2, 'history_cursor_rel', 'char', [('char', 'p')],
  '0xD155 ← (char)p − 0xD144，返回 p（历史游标相对位置）。', 'likely', tags=['editor'])
F(0x020DE2, 'key_flag_clear_b7', V, [], '若 0xD110 的 bit7 置位，则清 bit7 与 bit3。', 'strong', tags=['kbd'])
F(0x01F10E, 'is_digit_key', 'char', [('byte', 'k')],
  'k 为 3、4、9、0x0B、0x0C 时返回 1（数字键盘的若干键）。', 'likely', tags=['kbd'])
F(0x01EDCC, 'is_key_3e_1e_1f', 'char', [('byte', 'k'), ('byte', 'k2')],
  'k/k2 组合为 0x3E、0x1E、0x1F 时返回 1（方向/运算键判定）。', 'likely', tags=['kbd'])
F(0x020D2A, 'is_stat_edit4', 'char', [],
  '返回 (0xD114 & 0x80) != 0 && 0xD115 == 2：STAT 编辑状态判断。', 'likely', tags=['stat'])
F(0x01EB6E, 'is_stat_edit3', 'char', [],
  '返回 (0xD114 & 0x10) == 0 && 0x20D10() == 0：STAT 编辑状态判断（另一个位）。',
  'likely', tags=['stat'])
F(0x01FFD0, 'is_mode_high', 'char', [],
  '返回 0x20D10() == 0 && (0xD111 & 0x80) != 0。', 'likely', tags=['ui'])
F(0x01FFE8, 'enter_mode_18', V, [], '光标复位后把 0xD114 置 0x18（进入某种编辑状态）。',
  'likely', tags=['ui'])
F(0x01FFF6, 'index_wrap', V, [('byte', 'v')], '调用 0x14BDA（row*5+col 索引封装）。',
  'likely', tags=['util'])
F(0x01E820, 'draw_item_by_mode', V, [('ushort', 'i')],
  '按模式选择绘制：0xD111 == 0x89（0xA7 取反）时调用 0x2A048，否则 0x266E0。',
  'likely', tags=['ui'])
F(0x020D48, 'draw_cursor_field', V, [('byte', 'col')],
  '在 (col, 0xD156) 处绘制光标字段，0xD13E==0 时用 0x19 标记否则 0x9F。',
  'strong', tags=['ui'])
F(0x020D9E, 'draw_arrow_down', V, [], '在 0x15E 处绘制下箭头记号。', 'strong', tags=['ui'])
F(0x020DB0, 'draw_arrow_up', V, [], '在 0x395E 处绘制上箭头记号。', 'strong', tags=['ui'])
F(0x01E668, 'keycode_norm', 'ushort', [('ushort', 'k')],
  '把扩展键码规范化：低于 0xFC10 或不在 0xFC19.. 区间时返回 0xFC00。', 'likely', tags=['kbd'])
F(0x01EBE0, 'token_line_index', 'byte', [('byte*', 'p')],
  '计算 p 处字符在 0x37A4 表格中的行号（>0x0E 返回 5）。', 'likely', tags=['editor'])
F(0x01FCA4, 'str_emit_lparen_or_1D3D', V, [('undefined2', 'v'), ('byte', 'c')],
  'c == 0 时追加 ")"，否则追加 ROM 0x1D3D 记号串。', 'likely', tags=['text'])
F(0x020D76, 'draw_line_end', V, [], '按当前列数（0x23A0C）在行尾绘制占位。', 'likely', tags=['ui'])
F(0x020A38, 'dec_type_to_str', V, [('undefined2*', 'p'), ('char*', 'out')],
  '按 BCD 类型字节（0x1D800）输出对应的特殊值字符串。', 'likely', tags=['format'])
F(0x020E7A, 'history_base_ptr', 'undefined*', [],
  '按模式返回历史/输入区基址：0xD111 == 0x0C 时为 0xD784，否则按 0xD111 < 4 选择。',
  'strong', tags=['editor'])
F(0x01F99C, 'ram_clear_all', V, [],
  '把 0xD000 起 0x13E4 字节清零并复位若干状态（整机 RAM 数据区清空）。',
  'strong', tags=['boot'])
F(0x020CC2, 'ratio_key_check', V, [],
  'RATIO 模式（0xD111 == 0x88）的按键检查：调用 0x1EB86 并按 0xD13E 分支。',
  'likely', tags=['mode'])

# ---- UI 辅助 ----
F(0x00AF3A, 'is_key_1f_23', 'ushort', [],
  '当前键 0xD10E 为 0x1F 或 0x23 时返回 1（高字节携带原键码）。', 'likely', tags=['kbd'])
F(0x00AF62, 'char_ptr_next', 'byte*', [('byte*', 'p')],
  '返回下一个字符指针：p 处为双字节字符（>=0xF0）时 p+2，否则 p+1。', 'verified', tags=['editor'])
F(0x00B1C4, 'dec_abs_diff', 'undefined2', [('undefined2', 'v')],
  '计算 |0xD00E - v|（16 位，DAS 链）。', 'strong', tags=['bcd'])
F(0x00B3DC, 'input_mark_hash', V, [],
  '在输入区历史记录尾部插入 # 记号（0x25388 查找），按 0xD10E bit7 选择偏移 10 或 0x14。',
  'likely', tags=['editor'])
F(0x00B7D6, 'ratio_input_restore', V, [],
  'RATIO 模式（0xD111 == 0x88）下恢复输入区：保存 0xD180 到 0xD248、按 Math 设置拷贝历史。',
  'likely', tags=['mode'])
F(0x00B800, 'ratio_input_save', V, [('char*', 'p')],
  '把 p 拷贝到输入区 0xD180 并调用 0x25258（回放保存）。', 'strong', tags=['mode'])
F(0x00BD42, 'mul_signed16', 'undefined2', [('undefined2', 'a'), ('undefined2', 'b')],
  '带符号 16 位乘法（0x246F4 取绝对值后乘、按符号取补）。', 'strong', tags=['util'])
F(0x022DFE, 'menu_edit_entry', V, [('undefined2', 'key')],
  '菜单录入入口：调用编辑器（0xE21E），结果为 2 时把返回值写入 0xD10E。',
  'strong', tags=['menu'])
F(0x0246F4, 'divmod_signed16', 'undefined2', [('undefined2', 'a'), ('undefined2', 'b')],
  '带符号除法：0x246B4 取绝对值做除/取余，再按符号修正。', 'strong', tags=['util'])
F(0x0246B4, 'divmod_unsigned16', 'undefined2', [('undefined2', 'a'), ('undefined2', 'b')],
  '16 位无符号除法/取余（C 级 H 除法指令的软件封装）。', 'strong', tags=['util'])

# ---- 数值显示 / 比较 ----
F(0x01D37E, 'dec_cmp_status', 'byte', [('undefined2*', 'a'), ('undefined2', 'b')],
  '比较 *a 与 b：装载 a 后调用 0x19D76 归一化，失败返回 0xF0。',
  'strong', tags=['bcd'])
F(0x0201FE, 'fmt_exp_set', V, [('undefined2*', 'x'), ('undefined2', 'y')],
  '格式化前处理：把 *x 偏移 7 处的指数记号夹到 0x99，调用 0x1D7B0 后再 0x1D37E。',
  'likely', tags=['format'])
F(0x0202B8, 'fmt_check', 'ushort', [('undefined2*', 'x')],
  '调用 0x2021C 检查格式；返回 -1 时只保留高字节。', 'strong', tags=['format'])
F(0x02021C, 'fmt_number_core', 'undefined2*', [('undefined2*', 'x')],
  '数值格式化主例程：处理指数档位（-5 偏移）、调用 0x20000/0x201FE 生成数字串。',
  'strong', tags=['format'])
F(0x0209CA, 'edit_clamp_offset', V, [('byte*', 'p')],
  'p+0x12 处的偏移为负时把 p+0x14 的计数钳位（编辑缓存的越界修正）。',
  'likely', tags=['editor'])
F(0x020A80, 'line_wrap', 'char', [('byte', 'n')],
  '行号推进：把 (n + 0xD140) 与 0x3F 比较，溢出时换行并清 0xD140，返回溢出量。',
  'strong', tags=['text'])
F(0x020C20, 'echo_input', V, [],
  '回显输入区：清屏后把 0x9D52（输入区字符串）绘制到屏幕。', 'strong', tags=['editor'])
F(0x020C64, 'render_editor_line', V, [('byte', 'mode')],
  '绘制编辑器行：按模式调用 0x23780 生成内容，清 0x40-当前行 的剩余行，再绘制。',
  'strong', tags=['editor'])
F(0x020DC2, 'draw_status_cell', V, [('byte', 'n')],
  '按 0xD126/0xD152 在 (n, 0x1D/0x21) 处绘制状态单元格。', 'likely', tags=['ui'])
F(0x021122, 'dec_digit_count', 'char', [('undefined2*', 'p'), ('undefined2', 'b')],
  '返回 *p 在 b 下的有效位数（0x1D37E 结果为 0 时用 p+4 的指数-0x10）。',
  'likely', tags=['format'])
F(0x021134 + 0x00, 'input_clear8', V, [('undefined2', 'k'), ('undefined*', 'p')],
  '以键值 8 调用 0x9060（清输入缓冲），返回。', 'strong', tags=['editor'])
F(0x021250, 'fmt_pow10_digit', V, [('undefined2', 'x'), ('undefined2', 'd')],
  '把数字 d 转成 10 的幂形式后在 BCD 中相乘（d+0xAA / d+0xA0 影射）。',
  'likely', tags=['format'])
F(0x020A58, 'edit_normalize_pos', 'undefined2', [('undefined2', 'v')],
  '编辑位置规范化：参数高低字节不同时逐位调整。', 'likely', tags=['editor'])
F(0x023780, 'edit_render_content', 'char', [('undefined2*', 'out')],
  '生成编辑器行内容（调用 0xC85A/0xDAA4/0xE5D6/0xE698 等编辑辅助），返回状态。',
  'strong', tags=['editor'])
F(0x02682E, 'draw_result_line', V, [],
  '绘制结果行：按 0xD116 选择 0xD08E(+mult16) 或 0x25362，再逐字符绘制（处理换行）。',
  'strong', tags=['text'])

# ---- 角度换算 / 十进制三角函数 / 复数 ----
F(0x019602, 'dec_deg_rad_convert', V, [],
  '角度换算：按 0xD02F 的角度模式（弧度/度/ град）换算 X 与 Y；度模式直接装载 π 常量后归一化。',
  'strong', tags=['float'])
F(0x01CBE0, 'decm_bin_angle', V, [('undefined2*', 'a'), ('byte', 'angle')],
  '带角度参数的二元入口：载入角度模式（0xD11D）后按 0xD01E 选择加减/乘除/三角路径。',
  'strong', tags=['float'])
F(0x01916C, 'complex_eval', V, [],
  '复数运算包：用 0x678 字节栈帧保存实部/虚部，调用十进制乘除与 0x1D37E 比较后输出。',
  'likely', tags=['complex'])
F(0x01D39E, 'dec_to_polar', 'undefined', [('ushort*', 'p')],
  '直角坐标→极坐标：把 *p 与 *(p+5) 两个 BCD 数转为模与辐角（用 0x1CF90/0x1D134 等）。',
  'likely', tags=['complex'])

# ---- 变量表 ----
F(0x018130, 'var_add_const', V, [('ushort', 'idx'), ('undefined2', 'c')],
  '对第 idx 个变量单元调用 0x1D730（加常量 c）。', 'strong', tags=['vars'])
F(0x018244, 'var_fill_triple', V, [('ushort', 'idx')],
  '把 [0x1B, lo]、[lo, hi]、[hi, 0x1B] 三个值依次复制到变量表（0x1821E）。',
  'likely', tags=['vars'])
F(0x018264, 'var_init_slot', V, [('ushort', 'idx')],
  '若第 idx+0x0101 个变量的类型字节为 4，则调用 0x18244 填充三项。',
  'likely', tags=['vars'])
F(0x018280, 'var_init_matrix', V, [],
  '按 3 层三角布局初始化变量槽（循环调用 0x18264，列号步进 3）。',
  'likely', tags=['vars'])
F(0x0182B8, 'var_zero_block', V, [('ushort', 'idx')],
  '把第 idx、idx+1、idx+2 个变量单元分别置 0、0、1。', 'strong', tags=['vars'])
F(0x0183EE, 'var_init_1', V, [],
  '变量初始化批次 1：对索引 6、9、0x603、0x903 调用 0x18334（设置初值 0x0C/0x0F/…）。',
  'likely', tags=['vars'])
F(0x018416, 'var_init_2', V, [],
  '变量初始化批次 2：对索引 0x61E、0x91E 调用 0x183AE。', 'likely', tags=['vars'])
F(0x01842E, 'var_init_3', V, [],
  '变量初始化批次 3：按索引表（0xB08、0x1818、…）调用 0x17F78/0x17F82/0x17D1A。',
  'likely', tags=['vars'])
F(0x0184B6, 'var_init_4', V, [],
  '变量初始化批次 4：调用 0x17DCC/0x17F78/0x18334 及 0x184F2、0x18264 设置若干槽位。',
  'likely', tags=['vars'])
F(0x0181F6, 'var_scale', V, [], '按 0x187DA 取单元指针并做带有常量的运算（0x18723 系列）。',
  'likely', tags=['vars'])

# ---- 小辅助 ----
F(0x0179F4, 'dec_load_strip_flag', V, [('undefined2*', 'p')],
  '载入 *p 到 X 并清除 0x40 内部标志（0xD009 &= 0xBF），再经 0x19C9E/0x19370 归一化。',
  'strong', tags=['bcd'])
F(0x017B40, 'copy10', V, [],
  '复制源指针处的 10 字节到目标指针（与 0x1DA02 等价，偏移 1 的变体）。',
  'verified', tags=['util'])
F(0x017CEC, 'nop_17cec', V, [], '空函数（直接返回）。', 'verified', tags=['util'])
F(0x017CFE, 'nop_17cfe', V, [], '空函数（直接返回，Ghidra 标注了全局重叠）。', 'verified', tags=['util'])

# ---- 编辑区（0xD0xx）----
F(0x00D048, 'var_unit_init', V, [('byte*', 'p')],
  '把 p 处 10 字节清零，再写入类型头 {0x06, 0x55, 0x36, …, 0x01, 0x04}（新的 BCD 单元初值）。',
  'verified', tags=['bcd'])
F(0x00D08E, 'input_char_count', 'short', [('byte*', 'p')],
  '统计输入区 p 的逻辑字符数（0x04 或 >=0xF0 的双字节字符计 1 个）。',
  'verified', tags=['editor'])
F(0x00D4F6, 'emit_num_by_mode', 'undefined2', [('undefined2', 'p'), ('byte', 'c')],
  'c == 0 时输出 ROM 0x1DA7 记号，否则 ROM 0x1D77 记号。', 'likely', tags=['text'])
F(0x00D510, 'emit_num_by_mode2', 'undefined2', [('undefined2', 'p'), ('byte', 'c')],
  'c == 0 时输出 "x="（0x1DA4），否则 ROM 0x1D73 记号。', 'likely', tags=['text'])
F(0x00D52A, 'emit_num_by_mode3', 'undefined2', [('undefined2', 'p'), ('byte', 'c')],
  'c == 0 时输出 ROM 0x1DAD 记号，否则 ROM 0x1D81 记号。', 'likely', tags=['text'])
F(0x00D812, 'key_code_lookup', 'undefined2', [('ushort', 'k')],
  '按扩展键码查 ROM 表（0xFC4E..0xFC5F 段）得到键值。', 'strong', tags=['kbd'])
F(0x00D82E, 'cursor_move_draw', V, [('undefined2', 'd')],
  '按方向 d 移动光标（±1）并三次重绘（0x22B82）。', 'strong', tags=['ui'])
F(0x00DA7C, 'history_recall', 'undefined2', [('byte', 'n')],
  '历史回调：取 0x26594 状态，必要时按 0xD144 偏移取历史条目。', 'likely', tags=['editor'])
F(0x00DC78, 'edit_area_reset', V, [],
  '清 0xD31A 起 0x6E 字节；EQN/BASE 模式下再清表达式副本 0xD612（100 字节）。',
  'strong', tags=['editor'])
F(0x00DCB0, 'line_index_calc', 'short', [],
  '按 0xD0F6 与当前显示行计算行表地址（mul16 ×10 − 0x2C00）。', 'likely', tags=['editor'])
F(0x00DCD0, 'token_insert_check', V, [],
  '若当前令牌为 1 且字符为 0xC8/0x18，调用 0x26924 处理插入。',
  'likely', tags=['editor'])
F(0x00DDB0, 'editor_key_step', V, [('byte', 'flag')],
  '编辑器按键步进：按令牌类型 1/8/9/0x0A 与 flag 决定光标处理。',
  'likely', tags=['editor'])

# ---- 编辑器小步 ----
F(0x00EA12, 'input_mark_hash_loop', V, [],
  '循环调用 0xB3DC（输入区插入 # 记号）直到返回非 0。', 'likely', tags=['editor'])
F(0x00EBD8, 'dec_swap_ptr', V, [('undefined2*', 'p')],
  '交换输入区指针参数的 10 字节内容与临时单元（三步 dec_copy）。', 'likely', tags=['bcd'])

# ---- 状态栏 / 输入区（0x9xxx）----
F(0x009222, 'statusbar_exit_mark', V, [], '调用 0x9218 写下 0x80（状态栏退出标记）。',
  'strong', tags=['ui'])
F(0x00933A, 'lcd_mode_16', 'undefined2', [('undefined2', 'v')],
  '0xD114 的 bit4 未置位时把 LCD 模式 0xF031 置 0x16，再调用 0x9358 清状态。',
  'strong', tags=['display'])
F(0x009462, 'emit_xlt_by_mode', 'undefined2', [('undefined2', 'p'), ('byte', 'c')],
  'c == 0 时输出 "x<"（0x1DA4 段），否则 ROM 0x1D7C 记号。', 'likely', tags=['text'])
F(0x00959C, 'emit_ltx_by_mode', 'undefined2', [('undefined2', 'p'), ('byte', 'c')],
  'c == 0 时输出 " and "，否则 ROM 0x1D9E 记号。', 'likely', tags=['text'])
F(0x0095B6, 'cursor_column_calc', V, [('char*', 'out')],
  '按栈帧里的列偏移计算 *out 与光标列（0x15+0x10−0x14−3）。', 'likely', tags=['editor'])
F(0x00971E, 'skip_input_line', V, [],
  '跳过输入缓冲区中的一行（按双字节字符前进），调用 0x23A0C 取列数。',
  'strong', tags=['editor'])
F(0x009B90, 'dec_fmt_1b6c', 'undefined2', [('undefined2', 'v')],
  '调用 0x1D620 以固定格式 0x1B6C 把 v 格式化。', 'strong', tags=['format'])
F(0x009E1E, 'edit_state_set0', V, [], '调用 0xC438(0)（置编辑状态 0）。', 'likely', tags=['ui'])

# ---- 键表查询 / 空指针保护 ----
F(0x008E80, 'key_filter_lookup4', 'undefined2', [('undefined2', 'k')],
  '在 ROM 0x5896 的键码表中查找 k：找到返回 0，遇 0 结束返回 k。',
  'strong', tags=['kbd'])
F(0x008F9A, 'dec_copy_checked', V, [('undefined2*', 'dst'), ('undefined2*', 'src')],
  '空指针安全的两参 dec_copy（任一为空则跳过）。', 'verified', tags=['bcd'])
F(0x008FDE, 'key_hist_clear0', V, [], '调用 0x8FD0(0)（清按键历史值 0）。', 'strong', tags=['kbd'])

# ---- 模式判定 / 小工具（0x23xx-0x26xx）----
F(0x023598, 'is_mode_E', 'char', [],
  'EQUA 模式判定：0xD111 == 0x45（字符 E）时返回 1 或 0（依 0xD112 < 4），0xD111 == 0xC4 时返回 1。',
  'strong', tags=['mode'])
F(0x0239E6, 'key_hi_plus', 'ushort', [('ushort', 'k')],
  '返回 CONCAT11(k>>8 + 0xD143, 0xB5 < (0xD143 + k))。', 'likely', tags=['kbd'])
F(0x023BB4, 'input_cols2', 'byte', [],
  '返回输入区可用列数（0xD137 == 10 时为 5，否则 7）——0xAF52 的副本。',
  'strong', tags=['editor'])
F(0x023C9A, 'mode_switch_hist', V, [('char', 'v')],
  '写按键历史 v，调用 0x1FF9E，并把 0xD116 置 3。', 'likely', tags=['mode'])
F(0x023E58, 'is_second_byte', 'undefined2', [('byte*', 'p')],
  'p 指向双字节字符的第二字节（p < 0xF0 且 p[-1] >= 0xF0）时返回 1。',
  'strong', tags=['editor'])
F(0x023EE0, 'key_filter_d116', 'ushort', [('ushort', 'k')],
  '0xD116 bit6 置位且 k 非 0/0x23 时返回 k，否则返回 CONCAT11(k>>8,1)。',
  'likely', tags=['kbd'])
F(0x024104, 'edit_state_set', V, [('byte', 'v')],
  '设置编辑状态 0xD114（变化时 0xD115=1），并把 v 写入按键历史。',
  'strong', tags=['ui'])
F(0x024A14, 'is_v2_02', 'char', [('byte', 'v')], 'v == 2 时返回 1。', 'verified', tags=['util'])
F(0x024E10, 'is_ratio_edit', 'char', [],
  '0xD111 == 0xC1 且 0x20D10() == 0、0xD117 bit4 为 0、0xD127 为 0 时返回 1。',
  'likely', tags=['mode'])
F(0x025362, 'return_4', 'byte', [], '恒返回 4。', 'verified', tags=['util'])
F(0x0262B0, 'max_u16', 'undefined2', [('undefined2', 'a'), ('undefined2', 'b')],
  '返回 a、b 中较大者。', 'verified', tags=['util'])
F(0x02646C, 'is_mode_0c', 'char', [],
  '0xD111 == 0x0C 且 0xD114 == 1 时返回 1。', 'strong', tags=['mode'])
F(0x026594, 'is_d015_1_3', 'char', [],
  '0xD015 为 1 或 3 时返回 1（编辑/撤销状态的当前值判定）。', 'strong', tags=['ui'])
F(0x026892, 'is_mode_4a', 'char', [],
  '0xD111 == 0x4A（EQUA）且 0xD114 == 1 时返回 1。', 'strong', tags=['mode'])
F(0x026A1C, 'is_idle_editing', 'char', [],
  '0xD0F5 == 0、0xD113 == 0、0xD116 == 1 时返回 1（空闲编辑态）。',
  'strong', tags=['ui'])
F(0x026FC0, 'keycode_norm2', 'ushort', [('ushort', 'k')],
  '低于 0xFC28 或超出 0xFC2C.. 时返回 0xFC00。', 'likely', tags=['kbd'])
F(0x026FD8, 'key_is_cmp', 'ushort', [('byte*', 'p')],
  'p 以 0x19 开头且 0x1ECE2 判定为比较键时返回 CONCAT11(hi,1)。',
  'likely', tags=['kbd'])
F(0x024EDA, 'dec_type_byte2', 'byte', [('undefined2*', 'p')],
  '返回 BCD 类型字节：>0x0E 时取 p[1]。', 'strong', tags=['bcd'])

# ---- 应用模式（0x27xx-0x2Axx）----
F(0x0279E0, 'mode_c_enter', V, [('undefined2', 'a')],
  '调用 0x2B4FC；返回 0x0A 时再调用 0x9E4C（下一模式入口）。', 'likely', tags=['mode'])
F(0x027BBC, 'input_buf_clear', V, [], '清输入区 0xD180（200 字节）。', 'strong', tags=['editor'])
F(0x027E62, 'mode_select_0', V, [], '调用 0x27E84(0)（选择第 0 项/退出）。', 'likely', tags=['mode'])
F(0x0281FC, 'cursor_step_repaint', V, [('byte', 'v')],
  '光标步进一次并前后重绘（0x1F9D4 两次）。', 'likely', tags=['ui'])
F(0x028224, 'token_pair_class', 'undefined2', [('byte*', 'p')],
  '返回 CONCAT11(c,c)：按 0xAF74 分类，若为 3 且下一字符 0x1A 则改为 7。',
  'likely', tags=['eval'])
F(0x028496, 'check_line_edit', V, [], '当前行 0xD137 == 10 时调用 0x29D94（特殊编辑判断）。',
  'likely', tags=['editor'])
F(0x02880E, 'is_edit_flag_16', 'char', [],
  '0xD114 bit4 置位且 0xD116 == 1 时返回 1。', 'strong', tags=['ui'])
F(0x0288C6, 'mode_enter_eb42', V, [], '调用 0x22DFE(0xEB42)（进入菜单/模式入口）。',
  'likely', tags=['menu'])
F(0x0288D0, 'is_key_allowed', 'char', [('byte', 'k')],
  'k 为 2、4、8、0x0A、0x0C 及 >= 0x0C 以外的值时返回 1（按键白名单）。',
  'likely', tags=['kbd'])
F(0x029314, 'echo_input_row', V, [],
  '在行 0x0E 回显输入区：清屏、绘制 0xD180 字符串、写按键历史 0x0D。',
  'strong', tags=['editor'])
F(0x029AEA, 'draw_column_labels', V, [('byte', 'n')],
  '在 (0x113/0x13D/0x167/0x191, 0x30) 处按 n 绘制列标签。', 'likely', tags=['ui'])
F(0x029D5C, 'matrix_item_ptr', 'undefined2', [('ushort', 'i')],
  '返回矩阵/表格第 i 项的 16 位值（0xD12B 索引到 ROM 0x62A4 表）。',
  'strong', tags=['matrix'])
F(0x029DAE, 'input_cols3', 'byte', [],
  '返回输入区可用列数（0xD133 == 10 时为 6，否则 0x0B）。', 'strong', tags=['editor'])
F(0x02A020, 'strcat_raw', 'char*', [('char*', 'dst'), ('char*', 'src')],
  '把 src 追加到 dst 末尾（无长度检查），返回 dst。', 'verified', tags=['libc'])

F(0x02A048, 'draw_scaled_char', V, [('ushort', 'ch'), ('char', 'wide')],
  '取点阵指针后按缩放系数绘制字符 ch：宽字符时纵向步长减半（8 行 -> 4 行）。',
  'strong', tags=['ui'])
F(0x02A318, 'format_pattern_a', V, [('byte*', 'dst')],
  '构造格式符 1 的 10 字节描述：3 字节签名 + 5 字节参数 + 显示位置 0x104。',
  'strong', tags=['format'])
F(0x02A428, 'format_pattern_b', V, [('byte*', 'dst')],
  '构造格式符 2 的 10 字节描述：3 字节签名 + 5 字节参数 + 显示位置 0x104。',
  'strong', tags=['format'])
F(0x02A462, 'cursor_mode_take', 'byte', [],
  '读取并返回光标/编辑模式 0xD137，随后置为 10（与 fill_screen 的 0x400 参数对应）。',
  'strong', tags=['ui'])
F(0x02A886, 'is_frac_sep', 'byte', [('char', 'ch')],
  '字符为 3（分数/混合数标记）时返回 1，否则 0。', 'likely', tags=['parser'])
F(0x02A892, 'page2_triangle_redraw', V, [],
  '列表模式 0xD112 为 1..3 时按 4 字节步长刷新对应三角形/矩阵条目（table 0x1A70）。',
  'likely', tags=['ui','matrix'])
F(0x02A960, 'disp_field_width', 'ushort', [('byte*', 'dst')],
  '若目标字段高位半字节为 2 或 8（宽值）则宽度字节置 1，否则 0。',
  'likely', tags=['ui'])
F(0x02A9CC, 'fmt_buf_init', 'byte*', [('byte*', 'buf')],
  '按 0xD13F 写格式化缓冲区[0]=0x88/0xAC、[1]=0，返回 buf。',
  'likely', tags=['format'])
F(0x02A9EA, 'is_list_render_ctx', 'byte', [('char', 'mode')],
  '渲染上下文判定：模式 2 直接为真，否则要求调用点为列表元素 4。',
  'likely', tags=['ui'])
F(0x02AA5C, 'key_jump_20', 'undefined2', [('undefined2', 'er0'), ('char', 'flag')],
  '按键 0x20 的处理入口：flag 为 0 走 0x2100E，否则走 0x20FC6。',
  'likely', tags=['key'])
F(0x02AB8A, 'key_jump_1e', 'undefined2', [('undefined2', 'er0'), ('char', 'flag')],
  '按键 0x1E 的处理入口：flag 为 0 走 0x21006，否则走 0x20FBE。',
  'likely', tags=['key'])
F(0x02ABA4, 'render_sel_label', V, [('ushort', 'i')],
  '把光标模式置 8，并按 0xD111 从 ROM 0x24C 或 0x67EA 表绘制第 i 个标签。',
  'likely', tags=['ui'])
F(0x02ABE2, 'disp_busy', 'byte', [],
  '返回显示忙标志（0xD110 的 bit7）。', 'strong', tags=['ui'])
F(0x02ABEE, 'editor_pos_limit', 'ushort', [],
  '返回编辑行可容纳的字符数 = 0xD156 + 0xD00C。', 'likely', tags=['editor'])
F(0x02AC54, 'print_signed', V, [('char', 'n')],
  '编辑模式下把数值 n 按正负号打印（-1 时打印 n-1 的补码）。',
  'strong', tags=['editor'])

F(0x02A84C, 'lcd_scan_keys', 'byte', [('byte*', 'out')],
  '逐行扫描键盘矩阵（最多 8 行，0xF046 行走位），找到首个按下键后返回 1；未按下返回 0。',
  'strong', tags=['key'])

F(0x02844E, 'dec_bcd_to_hex_bcd', V, [],
  '对 0xD05A 指向的 3 组 10 字节 BCD 依次转成十六进制：组1->二进制，组2/组3->十六进制。',
  'likely', tags=['bcd'])
F(0x029B2C, 'wait_dir_key', 'byte', [],
  '循环读键直到方向键（0x24-0x27），按 0x24/0x25 返回 1，0x26/0x27 返回 0。',
  'strong', tags=['key'])
F(0x02A0EA, 'bcd_print_u8', V, [('byte', 'n')],
  '把 8 位无符号数 n 转成十进制字符串（省略前导 0）写入 ER0 指向的显示串。',
  'strong', tags=['bcd','display'])
F(0x02B8AC, 'kdf_chain_count', 'ushort', [('ushort', 'idx')],
  '沿 0x42BA 表（每项 2 字节，类型 7 为终止）最多走 10 步，返回 (终止类型<<8)|步数。',
  'likely', tags=['setup'])
F(0x02BD42, 'input_reset', V, [],
  '输入编辑未锁定时清 D13E，并通过 0x20D48/0x20D76 复位待处理输入 D15C/D15D。',
  'likely', tags=['editor'])

F(0x007E9C, 'var_table0_clear', V, [('byte', 'count')],
  '把 0xDDEC 起的变量区前 count*0x18 字节清零。', 'likely', tags=['hal'])
F(0x00B822, 'setup_enter_E', V, [],
  '进入设置菜单项 E：调用 0x251EC 初始化后置界面状态 0xD114=0x17。',
  'likely', tags=['setup'])
F(0x00B830, 'key_is_14_02', 'byte', [],
  '当键值 0xD10E 为 0x14 或 0x22 时返回高位字节<<8|1，否则返回高位字节<<8。',
  'strong', tags=['key'])
F(0x00B89C, 'diag_entry', V, [],
  '以常量 0xEB42 调用 0x22DFE（自检入口）。', 'likely', tags=['diag'])

F(0x00BD52, 'fmt_print_number', V, [('byte', 'n')],
  '把 0..99 的 n 转成显示串：十位前插 0xFB 符号，数字字符基址为 0x30（0xD137==0x0E 时为 0x44）。',
  'strong', tags=['ui','display'])
F(0x00C056, 'set_key_edge', 'undefined2', [('undefined2', 'er0'), ('char', 'flag')],
  '按 flag 选择 0x20EC2 或 0x20F6E 设置按键边沿，返回 er0。', 'likely', tags=['key'])
F(0x00C070, 'is_alpha_reg', 'byte', [('byte', 'ch')],
  '仅在 0x28576 为真且字符落在 0x1A..0x1F（变量 A-F）时返回 1。', 'likely', tags=['key'])
F(0x00C090, 'wait_release', 'byte', [('byte*', 'out')],
  '等待键盘释放在 5 个 10ms 间隔内确认，并把当前扫描码低 8 位清零写入 out。',
  'strong', tags=['key'])
F(0x00C1FC, 'key_vartype', 'byte', [('byte*', 'key'), ('byte*', 'type')],
  '取 key[0] 低 4 位查 ROM 0xA0 表，换算后写入 type 并返回 0。', 'likely', tags=['key'])
F(0x00C2E2, 'key_is_1a_04', 'byte', [],
  '当键值 0xD10E 为 0x04 或 0x20 时返回高位字节<<8|1，否则返回高位字节<<8。',
  'strong', tags=['key'])
F(0x00C3D0, 'next_size_3n1', 'ushort', [('ushort', 'limit')],
  '从 1 开始按 3n+1 递增直到不小于 limit，返回下一个（或当前）值。',
  'strong', tags=['util'])
F(0x00C5A8, 'call_mode_ee2a', V, [],
  '直接跳入 0xEE2A（主循环）。', 'strong', tags=['boot'])

F(0x00CCF0, 'copy_prefixed', V, [('char*', 'src')],
  '按首字节给出的总长 n（n+1 字节）把 src 原样复制到 ER0 指向的缓冲区。',
  'likely', tags=['strlib'])
F(0x00CD20, 'menu_close', V, [],
  '以 0 调用 0x22BF4（关闭菜单层）。', 'likely', tags=['ui'])
F(0x00CD26, 'set_cursor_visible', 'undefined2', [('undefined2', 'er0'), ('char', 'flag')],
  '按 flag 选择 0x20ED4 或 0x20F86 切换光标可见性，返回 er0。', 'likely', tags=['ui'])
F(0x00CDB6, 'draw_input_prompt', V, [],
  '按输入区列数（0x29DAE）调用 0xFB98 绘制输入提示。', 'strong', tags=['editor'])
F(0x00DC4C, 'set_eol_marker', 'undefined2', [('undefined2', 'er0'), ('char', 'flag')],
  '按 flag 选择 0x20EDA 或 0x20F8C 设置行尾标记，返回 er0。', 'likely', tags=['ui'])
F(0x00ED28, 'restore_input_line', V, [],
  '从 ROM 0xD84C 复制回编辑行（0xD180 或其影子缓冲），提示符模式下走 0xADCE。',
  'likely', tags=['editor'])
F(0x00F2EC, 'get_token_class', 'byte', [('byte*', 'tok')],
  '取 token 的首字节查 0x37A4 表得类别；非单一 token 时返回 5。',
  'strong', tags=['parser'])
F(0x00F3A6, 'can_recall', 'byte', [],
  '判断当前模式（0xD111）与状态（0xD114/0xD116）下是否允许回放历史记录。',
  'likely', tags=['editor'])
F(0x00F3E4, 'copy_edit_line', V, [('undefined2', 'er0')],
  '以 er0 为源调用 0xC9F2（编辑行复制）。', 'likely', tags=['editor'])
F(0x00F716, 'is_line_start', 'byte', [],
  '判断光标是否位于行首（宏键/输入状态相关）。', 'likely', tags=['editor'])

F(0x00FB98, 'draw_token_text', V, [('byte*', 'tok')],
  '把 token 转成可显示文本（0xD4C8），再按行缓冲排版并绘制；复杂 token 走 0x2035C。',
  'likely', tags=['editor'])
F(0x00FBF0, 'diag_entry_c4', V, [],
  '以常量 0xEB13 调用 0x22DFE（自检入口）。', 'likely', tags=['diag'])
F(0x00FBFE, 'menu_gate', 'byte', [],
  '菜单门槛检查：弹栈返回。注意位于 0xFC00 保留区（ROM 中为 0xFF 填充）之前的最后一个函数。',
  'likely', tags=['ui'])
F(0x010DC2, 'dec_add_self', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '对 a、b 各复制一份并调用 0x1D780（BCD 加法核心）自加。', 'likely', tags=['bcd'])
F(0x010E34, 'get_ptr_ffd8_4', 'short', [],
  '读取 0x3:0xFFDC 处 16 位值（微函数：XR12=4 跳入 0x10E4A）。', 'verified', tags=['util'])
F(0x010E3A, 'get_ptr_ffd8_2', 'short', [],
  '读取 0x3:0xFFDA 处 16 位值（微函数：XR12=2 跳入 0x10E4A）。', 'verified', tags=['util'])
F(0x010E40, 'get_ptr_ffd8_1', 'short', [],
  '读取 0x3:0xFFD9 处 16 位值（微函数：XR12=1 跳入 0x10E4A）。', 'verified', tags=['util'])
F(0x010E4A, 'read_ptrtab_ffd8', 'short', [],
  '返回 0x3:0xFFD8+XR12 处的 16 位值（XR12 由各微入口设置）。', 'verified', tags=['util'])
F(0x010F1A, 'dec_copy_to_slot', V, [('undefined2*', 'r')],
  '把 r 复制到 0xB4 处调用块的参数槽。', 'likely', tags=['bcd'])
F(0x010F28, 'dec_copy_10_slot', V, [],
  '按 10 字节/组把局部寄存器区复制到 0xD392 起的槽位。', 'likely', tags=['bcd'])
F(0x010F3A, 'dec_copy_10_slot_ng', V, [],
  '同 0x10F28，但先置 0xD142=1（带符号/激活标记）。', 'likely', tags=['bcd'])
F(0x011088, 'dec_copy_const', V, [('byte', 'idx')],
  '把 ROM 0x353A + idx*10 的 10 字节 BCD 常量复制到 0x3C 处调用块参数槽。',
  'likely', tags=['bcd'])
F(0x0111BC, 'dec_op_pow_mul', V, [],
  '乘方/乘除混合序列 A：x^y 与乘积，结果写回局部 BCD 槽。', 'likely', tags=['bcd'])
F(0x011228, 'dec_op_pow_core', V, [],
  '公共片段：对 0xB4/0xA0 处操作数做 0x1C86C（乘方族）与 0x1CA7E（三角函数）运算。',
  'likely', tags=['bcd'])
F(0x01125E, 'dec_op_pow_mul_b', V, [],
  '乘方/乘除混合序列 B：与 A 对称（交换 0x8C/0xAA 操作数）。', 'likely', tags=['bcd'])
F(0x01141C, 'dec_op_mixed', V, [],
  '混合运算序列：以常数 2 与局部 BCD 槽做乘方并相加。', 'likely', tags=['bcd'])
F(0x011992, 'dec_set_prec', V, [('byte', 'n')],
  '设置 BCD 精度：n 不为 1 时取 3，随后调用 0x1D6A4/0x1D800 归一化。',
  'likely', tags=['bcd'])

F(0x0143AE, 'copy_to_slot3', V, [('undefined2*', 'src')],
  '把 src 的 10 字节复制到调用块的活跃 BCD 槽（内联跳入 0x13A16 -> 0x1DA02）。',
  'verified', tags=['bcd'])
F(0x0143B4, 'copy_slot4_to_slot3', V, [('undefined2*', 'src')],
  '把 src 复制到 0x14 处槽位再复制到活跃 BCD 槽。', 'likely', tags=['bcd'])
F(0x0143CC, 'matrix_op', 'undefined2', [('byte*', 'expr'), ('undefined2*', 'dst')],
  '矩阵运算入口（R4=4）：按 expr 首字节类型分派到 0x13CF2 的共享矩阵内核。',
  'strong', tags=['matrix'])
F(0x014B0A, 'matrix_cell_index', 'short', [],
  '返回矩阵单元格顺序号 = (R12*5 + R13)*10 + R4（R12/R13/R4 为矩阵行列）。',
  'verified', tags=['matrix'])
F(0x014B2E, 'memcpy100', V, [('byte*', 'dst'), ('byte*', 'src')],
  '向后复制 200 字节（0x22DC4）。', 'verified', tags=['libc'])
F(0x014B42, 'memcpy25', V, [('byte*', 'dst'), ('byte*', 'src')],
  '向后复制 0x32 字节（0x22DC4）。', 'verified', tags=['libc'])
F(0x014EFC, 'matrix_index', 'ushort', [],
  '返回 R12*10 + ER6（矩阵行列编址）。', 'verified', tags=['matrix'])
F(0x014F08, 'const_idx_16', 'short', [('short', 'i')],
  '返回 i-0xCC（ROM 常量 0xEC 区索引）。', 'likely', tags=['util'])
F(0x01529E, 'dec_div_slots', V, [],
  '对两个 BCD 槽执行 0x1CF68（除法）后收尾复制。', 'likely', tags=['bcd'])
F(0x0152B2, 'dec_div_slot_const', V, [('undefined2*', 'd')],
  'd 除以参数复制槽中的操作数（0x1CF68），再调用 0x1909A。', 'likely', tags=['bcd'])
F(0x0152D4, 'dec_pow_slots', V, [('undefined2*', 'a')],
  '构造操作数 0x??1B 并调用 0x1CF90（乘方族）。', 'likely', tags=['bcd'])
F(0x0152E4, 'dec_pow_const_1b76', V, [],
  '以 ROM 常量 0x1B76 调用 0x1CF90（乘方族）。', 'likely', tags=['bcd'])
F(0x0152F0, 'dec_pow_slot_const', V, [],
  '以槽位操作数调用 0x1CF90（乘方族）。', 'likely', tags=['bcd'])
F(0x015302, 'copy_to_slot28', V, [('undefined2*', 'src')],
  '把 src 复制到调用块 +0x28 的槽。', 'verified', tags=['bcd'])
F(0x015320, 'call_1909a_slot', V, [('undefined2*', 'a')],
  'a 与调用块 +0x3C 的槽做 0x1909A 运算。', 'likely', tags=['bcd'])

F(0x015B66, 'check_size_family', 'undefined2', [('char', 'which')],
  'which 为 0 时调用 0x1369A，否则调用 0x13584（矩阵/向量尺寸族检查）。',
  'likely', tags=['matrix'])
F(0x015D3C, 'is_digit_at', 'short', [('byte*', 'p')],
  'p[0] 为数字（0x30..0x39）、小数点 0x2E 或负号 0x2D 时返回 低字节|0x100，否则 低字节<<8。',
  'verified', tags=['parser'])
F(0x015E30, 'reject_type_2_3_8', 'short', [('ushort', 'tok')],
  '调用 0x15ECA 分类后，类型 2/3/8 返回 (高字节<<8)|1，否则 高字节<<8。',
  'likely', tags=['eval'])
F(0x015E64, 'check_type1_codes', 'byte', [('ushort', 'tok')],
  '类型 1 令牌的一串保留码检查（0x6A/0x6B/0x85/0x86/0x92 等）。',
  'likely', tags=['eval'])
F(0x0160FC, 'set_bit_hi', 'char', [('char', 'v')],
  'v 置位 (0x80 >> (R4-5)) 后返回。', 'verified', tags=['matrix'])
F(0x01610A, 'clear_bit_hi', 'char', [('char', 'v')],
  'v 清位 (0x80 >> (R4-5)) 后返回。', 'verified', tags=['matrix'])

F(0x0161BE, 'matrix_transpose_inplace', V, [('byte*', 't')],
  '对 (param_1+0x14) 处的矩阵原地转置（0x161DE 算法）。', 'likely', tags=['matrix'])
F(0x0163C8, 'copy_with_dims', V, [('undefined2*', 'src'), ('undefined2*', 'dst')],
  '先 0x8FEC 复制，若当前为模式 2（统计），再按 0x1D900 的维度信息补复制。',
  'likely', tags=['matrix'])
F(0x016B5C, 'is_paren_range', 'byte', [('byte', 'c'), ('char', 'flag')],
  'c 为左/右括号码（0x7D-0x82、0x87-0x8E、0x93-0x94）且 flag 为 0 时返回 1。',
  'likely', tags=['parser'])
F(0x016BE8, 'matrix_copy_to_slot', V, [],
  'R11 有效时把矩阵操作数复制到当前槽。', 'likely', tags=['matrix'])
F(0x016C16, 'matrix_opnd_advance', V, [],
  '把 R11 递减后的操作数槽复制到下一步（0xD111==0xC4 时多减 1）。',
  'likely', tags=['matrix'])
F(0x016EEC, 'copy_from_ER12_to', 'undefined2*', [('undefined2*', 'dst')],
  '把 ER12 指向的 10 字节复制到 dst 并返回 dst。', 'verified', tags=['bcd'])
F(0x016EF4, 'copy_to_ER12', 'undefined2*', [('undefined2*', 'src')],
  '把 src 的 10 字节复制到 ER12 指向处并返回 src。', 'verified', tags=['bcd'])
F(0x016F4A, 'copy_cond_ext', 'undefined2*', [('undefined2*', 'src')],
  '把 src 的 10 字节复制到 ER10；0xD111==0xC4（向量模式）时再复制 +0x10 的 10 字节。',
  'likely', tags=['matrix'])
F(0x016F50, 'copy_opnd', 'undefined2*', [('undefined2*', 'src')],
  '以当前操作数槽为目标的 0x16F4A 包装。', 'likely', tags=['matrix'])
F(0x016F62, 'matrix_prec', 'byte', [],
  '按 ER12 处操作数首字节高半字节映射精度档（0xF->7、9->3、6->1、2/8/0->0）。',
  'strong', tags=['matrix'])

F(0x0179C2, 'advance_token_ptr', 'undefined2', [('undefined2', 'v')],
  '调用 0xAF62 跳过当前 token（<0xF0 为 1 字节，否则 2 字节），返回 v。',
  'verified', tags=['parser'])
F(0x0179E2, 'dec_bin_op_d05c', V, [('undefined*', 'a'), ('undefined*', 'b')],
  '设置 _D05C=a、_D05E=b 后调用 0x17A1A（十进制运算核心）。', 'verified', tags=['bcd'])
F(0x017BD6, 'dec_normalize_both', V, [],
  '对当前 _D05C/_D05E 两个操作数依次调用 0x1C35C/0x19CC2/0x1C042/0x1C18C/0x19C56/0x1BE46 规整。',
  'likely', tags=['bcd'])
F(0x017E78, 'eval_result_init', V, [('undefined2', 'v')],
  '用 0x17F6A 的结果初始化求值结果（16 字节结构填两处）。', 'likely', tags=['eval'])
F(0x017F1A, 'unpack_nibbles', V, [],
  '按 R11 低半字节/R10 拆解操作数为 BCD 结果。', 'likely', tags=['eval'])
F(0x017F4A, 'nibble_pair', 'byte', [],
  'R10<10 直接调用 0x17F6A，否则先左移 4 位再调用。', 'likely', tags=['eval'])
F(0x017F8C, 'dec_bin_op2', V, [('undefined2', 'a'), ('undefined2', 'b')],
  '以 0x187DA 解引用两操作数后调用 0x17A1A（十进制运算核心）。', 'likely', tags=['bcd'])
F(0x01813C, 'dec_store_pair', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '把 a、b 分别存到 _D05C 句柄的 +0x1E / +0x1F 槽。', 'likely', tags=['bcd'])
F(0x01815C, 'dec_bin_to_bcd', V, [('undefined2*', 'a')],
  '二进制整数转 BCD（按 0x1D668 取得串长选择 1/4/0x40 路径）。',
  'likely', tags=['bcd'])

F(0x018B8C, 'compare_bcd_slots', 'byte', [('undefined2*', 'a'), ('undefined2*', 'b')],
  '比较两个 BCD 槽：任一方为特殊值（首字节 >= 0xF0）时按特殊规则返回标志。',
  'likely', tags=['bcd'])
F(0x018BD8, 'special_flag_or', 'byte', [],
  '两槽首个操作数都不是特殊值时返回 0，否则返回其标志字节。', 'likely', tags=['bcd'])
F(0x018BF2, 'set_ops_3_0', V, [],
  '把 +0x3C 槽设为 3、+0x32 槽设为 0。', 'likely', tags=['bcd'])
F(0x018C0A, 'dec_div_slots_local', V, [],
  '对局部 BCD 槽执行 0x1CF90/0x1CF68 除法序列。', 'likely', tags=['bcd'])
F(0x018C2A, 'dec_div_slots_local_b', V, [],
  '同 0x18C0A 的对称变体。', 'likely', tags=['bcd'])
F(0x018C4A, 'dec_pow_int_ratio', 'ushort', [('undefined2*', 'a')],
  '求 1.0 与 a 的幂（0x1CF90 乘方族并调用 0x1898E），返回结果标志。',
  'likely', tags=['bcd'])
F(0x018C8A, 'dec_div_ratio', V, [('undefined2*', 'a')],
  'a 与副本互相调用 0x1898E（求商/比例）。', 'likely', tags=['bcd'])
F(0x018CB6, 'dec_inv_inplace', V, [('undefined2*', 'a')],
  '对 a 原地调用 0x1898E（求倒数）。', 'likely', tags=['bcd'])
F(0x018CC0, 'dec_func_dispatch', 'ushort', [('undefined2*', 'a'), ('undefined2*', 'b')],
  '按 b[5] 与 0x179F4 的结果分派求值：1 走 0x18C4A，2 走 0x18CB6，其他走 0x18C8A。',
  'likely', tags=['bcd'])
F(0x0187E6, 'is_edit_locked', 'byte', [],
  '判断是否处于只读/锁定编辑：读取 0x3:0xFFD9 的值并检查 0xD114/0xD11E/0xD111/0xD13C。',
  'likely', tags=['editor'])

F(0x01909A, 'dec_add_or_round', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '两操作数首字节都 < 10 时调用 0x1D2FE（整数加法），否则 0x1CF7C（混合运算）。',
  'verified', tags=['bcd'])
F(0x01EB9E, 'dec_pow_then_div', V, [('undefined2*', 'a')],
  'a 先复制到局部，与外部参数做 0x1CF90（乘方）再以 0x1CF54 收尾。',
  'likely', tags=['bcd'])
F(0x01EBC8, 'key_is_11_04', 'byte', [],
  '当键值 0xD10E 为 0x0D 或 0x21 时返回高位字节<<8|1，否则返回高位字节<<8。',
  'strong', tags=['key'])
F(0x01ECE2, 'is_ws_scan', 'byte', [('byte*', 'p')],
  'p[0]==0xC9 且 p[1]==0x1A 时返回 (高字节<<8)|1，否则 高字节<<8。',
  'verified', tags=['parser'])
F(0x01EDE6, 'var_slot_write', V, [],
  '把 (参数字节<<3)+0xDBE6 处的变量字节写成 0x9D22 的返回值减 0xD144。',
  'likely', tags=['var'])
F(0x01F1D6, 'draw_mode_header', V, [],
  '绘制模式标题：清 13 字节缓冲，置 0xD137=0xE，按 0x4D7C/0x5E10 绘制两段文本。',
  'likely', tags=['ui'])
F(0x01F45A, 'menu_item_kind', 'byte', [('byte', 'idx')],
  '查 0x42B8 表的菜单项类型（8 为子菜单等）。', 'likely', tags=['ui'])
F(0x01F4CA, 'is_stat_mode', 'byte', [],
  '统计/表格模式判定（0x29D94 或 0xD114 bit7 且非输入态）。', 'likely', tags=['ui'])
F(0x01F52E, 'draw_token_list', V, [('byte*', 'tok')],
  '按 token 类别（2/4 等）逐个绘制列表项。', 'likely', tags=['editor'])

F(0x01FF84, 'memcpy160', 'short', [('byte*', 'dst'), ('byte*', 'src')],
  '复制 0xA0 字节，成功返回 1。', 'verified', tags=['libc'])
F(0x02035C, 'font_class_of', 'byte', [('byte', 'ch')],
  '字符码分类表：0x18->0，0x2F->1，0x30..0x4F->+0x0B 等，用于字形/宽度查表。',
  'strong', tags=['display'])
F(0x0206B0, 'span_check_3', 'byte', [],
  '从 R10 开始每次减 3 检查是否越过 0（掩码区间判定）。', 'likely', tags=['parser'])
F(0x0206D0, 'span_check_3b', 'byte', [('char', 'mode')],
  'mode==2 时从 R10 取反开始每次减 3 检查区间。', 'likely', tags=['parser'])
F(0x0206E4, 'span_check_3c', 'byte', [('char', 'mode')],
  'mode==2 时用 R10 取反做 3 步掩码区间判定，命中返回 1。', 'likely', tags=['parser'])
F(0x01FC7C, 'set_sel_mode', V, [('undefined2', 'v')],
  '按 0xD116/0xD13E 决定选择模式（0 或 2）并调用 0x23CCE。', 'likely', tags=['ui'])
F(0x01FF2A, 'set_list_mode', V, [],
  '列表模式切换（按 0xD112 与入参比较，刷新缓冲）。', 'likely', tags=['ui'])
F(0x01FF9E, 'list_entry_fetch', V, [],
  '取列表项（0x8EF2）并在 0xD112 下标上做对比。', 'likely', tags=['ui'])

F(0x02207E, 'delay_1', 'undefined2', [('undefined2', 'v')],
  '调用 0x916A(1)（1ms 延时），返回 v。', 'verified', tags=['hal'])
F(0x02208E, 'delay_10', 'undefined2', [('undefined2', 'v')],
  '调用 0x916A(10)（10ms 延时），返回 v。', 'verified', tags=['hal'])
F(0x0221BC, 'fill_screen_mode', V, [('byte', 'mode')],
  '以 (1<<8)|mode 调用 fill_screen 后调用 0x22502 做后续处理。',
  'likely', tags=['display'])
F(0x022226, 'draw_menu_aa', V, [],
  '以 0xAA 为参数调用 0x221CC（菜单绘制）。', 'likely', tags=['ui'])
F(0x022250, 'draw_menu_cancel', V, [],
  '取消/返回菜单：先清显示，以 0x4DCE 调用 0x221AC，刷新屏幕并等待方向键。',
  'likely', tags=['ui'])
F(0x022278, 'draw_menu_clear', V, [],
  '清空缓冲并置 0xD137=0xE（Ghidra 截断处 halt_baddata）。', 'likely', tags=['ui'])
F(0x0222AE, 'draw_menu_status', V, [],
  '键盘 IO 初始化后按 0x22382 的结果绘制菜单状态行 0x21xx。', 'likely', tags=['ui'])
F(0x02250E, 'boot_key_poll', 'undefined2', [],
  '上电时轮询键盘 3 次，若扫描到 0x18 位则走 0xD0F5 初始化序列。',
  'likely', tags=['boot'])
F(0x023178, 'skip_token_loops', V, [],
  '反复 0x25388 查找控制字节 1 并跳过各 token。', 'likely', tags=['parser'])
F(0x02319E, 'menu_enter_off', V, [],
  '以 0 调用 0x27E84（关闭左侧菜单栏）。', 'likely', tags=['ui'])
F(0x023254, 'set_window_visible', 'undefined2', [('undefined2', 'er0'), ('char', 'flag')],
  '按 flag 选择 0x20FCE / 0x21016 显示/隐藏窗口，返回 er0。', 'likely', tags=['ui'])

F(0x023540, 'paste_line', V, [('byte*', 'src')],
  '把编辑行复制到 0xD144 备份区，按首 token 判断后调用 0x284CC（插入行）。',
  'likely', tags=['editor'])
F(0x023626, 'token_sym_code', 'ushort', [('ushort', 'tok')],
  'token 首字节 0x2E..0x33 等映射为固定双字节符号码（0xFB1A 等）。',
  'likely', tags=['parser'])
F(0x023A1C, 'dec_round_to', V, [('undefined2*', 'a'), ('undefined', 'n')],
  'a 按 n 位舍入（n>=0xF 时按 0xF），调用 0x1D6A4。', 'likely', tags=['bcd'])
F(0x023EF8, 'refresh_list', V, [('undefined2', 'er0')],
  '调用 0xED7C 刷新列表视图。', 'likely', tags=['ui'])
F(0x023F16, 'call_246b4', V, [('undefined2', 'er0'), ('undefined2', 'er2')],
  '以 er0/er2 调用 0x246B4。', 'likely', tags=['ui'])

F(0x025218, 'draw_cell_overlay', V, [('ushort', 'pos'), ('ushort', 'code')],
  '编辑模式 1 时按 0x2ABEE 得到的行宽换算坐标，调用 0x848A 叠加绘制单元格字符。',
  'likely', tags=['editor'])
F(0x0263C8, 'open_hex_view', V, [('undefined2', 'er0')],
  '按 0x28C10 选择子视图（2/3/6/7/E/J/K）并打开十六进制/进制视图。',
  'likely', tags=['ui'])
F(0x026328, 'diag_entry_eb05', V, [],
  '以常量 0xEB05 调用 0x22DFE（自检入口）。', 'likely', tags=['diag'])
F(0x0265A8, 'call_22b82', V, [('short', 'er0')],
  '以 er0 调用 0x22B82（主循环入口）。', 'likely', tags=['ui'])
F(0x027204, 'copy_result_hook', V, [('undefined2', 'er0')],
  '按 0x26A1C 的结果把编辑行复制到结果区。', 'likely', tags=['editor'])
F(0x027250, 'var_scalar_addr', V, [('byte', 'idx')],
  '计算变量槽地址 (idx<<3)+0xDBE6 并与 0xD144 比较/取用。', 'likely', tags=['var'])
F(0x027D90, 'restart_loop', V, [],
  '清缓冲并从 ROM 0xD2xx 复制提示串后跳回 0xEE2A 主循环。', 'likely', tags=['boot'])
F(0x02844E, 'dec_bcd_to_hex_bcd', V, [],
  '对 0xD05A 指向的 3 组 10 字节 BCD 依次转成十六进制。', 'likely', tags=['bcd'])
F(0x0284CC, 'insert_var_line', 'byte', [('char', 'type')],
  '类型 3 或 4 时返回 1（插入变量/等号行）。', 'likely', tags=['editor'])
F(0x0288A2, 'push_edit_cache', 'ushort', [('byte*', 'src')],
  '把编辑行复制到 0xD144，并对首 token 做 0x288D0 检查。', 'likely', tags=['editor'])
F(0x029594, 'find_table_row', 'ushort', [('char', 'c')],
  '在 0xD169 行表中按 (c - 0xD144) 查找匹配行，返回 (行号标志<<8)|行号。',
  'likely', tags=['table'])
F(0x0295D6, 'recalc_table', V, [],
  '根据统计/图形模式与 0x1EDCC 结果重算表格（清 0xD169 并调用 0xA326）。',
  'likely', tags=['table'])
F(0x029D00, 'set_col_areas', V, [],
  '按第 idx 列设置两个显示区域的起点（0xB11/0x0Bxx 与 0x30 列）。',
  'likely', tags=['display'])
F(0x029DBE, 'list_open_cursor', V, [],
  '列表打开：按 0x1EB86 选初始行 0x1B/0x18，0xE21E 返回 3 时复位。',
  'likely', tags=['ui'])
F(0x029E14, 'decrement_field', V, [('byte*', 'p')],
  'p[5] 递减（到 0 时先 0x253F0）。', 'likely', tags=['ui'])
F(0x02A974, 'is_menu_range', 'byte', [('ushort', 'tok')],
  '0x262BA 归一化后判断是否在 0x40..0x49 菜单码范围。', 'likely', tags=['parser'])
F(0x02A99C, 'buffer_reset_for_mode', V, [('undefined2', 'er0')],
  '按当前模式清行缓冲；模式 C1/2/C4/89 时连 0xD392 的 400 字节一起清。',
  'likely', tags=['ui'])
F(0x02AA0A, 'finish_edit_line', V, [('undefined2', 'er0')],
  '把编辑行转成文本（0x208F2）并按需截断，再调用 0x1EACE 收尾。',
  'likely', tags=['editor'])
F(0x02AB3E, 'draw_list_header', V, [],
  '按 0xD112 绘制列表表头（"=0" 等固定串）。', 'likely', tags=['ui'])
F(0x02B94E, 'append_until_ok', V, [],
  '循环以 0..0xF 追加参数直到 0xFBFE 成功。', 'likely', tags=['editor'])

F(0x00B156, 'wrap_9e4c', V, [('undefined2', 'er0')],
  '先 0xC056 设置键边沿，再调用 0x9E4C；第二参数非 0 时调用 0x20EC8。',
  'likely', tags=['editor'])
F(0x00B17E, 'wrap_12d3a', V, [('undefined2', 'er0')],
  '对返回值做 0x12D3A 处理（二进制转串并写回）。', 'likely', tags=['editor'])
F(0x00B1A4, 'wrap_29614', V, [('undefined2', 'er0')],
  '以 er0 调用 0x29614（主编辑循环）。', 'strong', tags=['editor'])
F(0x00B356, 'append_call_token', V, [('byte', 'code'), ('byte', 'len')],
  '在编辑行末尾追加函数调用 token（0x19 前缀）并复制 len 字节参数。',
  'likely', tags=['editor'])
F(0x0119A2, 'matrix_type_jump', V, [],
  '按 0xD112 在 0x19B6 跳表分派矩阵输入类型处理（Ghidra 未解出跳表）。',
  'likely', tags=['matrix'])
F(0x0127FA, 'var_load_to_reg', V, [('undefined2*', 'dst'), ('byte', 'idx')],
  '把变量槽 (idx<<3)+0xDBE6 的 BCD 载入 dst。', 'likely', tags=['var'])
F(0x012816, 'var_store_from_reg', V, [('byte', 'idx'), ('undefined2*', 'src')],
  '把 src 存入变量槽 (idx<<3)+0xDBE6。', 'likely', tags=['var'])

F(0x013910, 'set_constant_99', V, [('byte*', 'p')], '把 p[8]=0x99（矩阵单元常量）。',
  'verified', tags=['matrix'])

F(0x013A06, 'pow_ER4_ER2', V, [], '调用 0x1CF90（乘方族）：操作数 in_ER2。',
  'verified', tags=['bcd'])
F(0x013A0A, 'copy_ER8_from_ER4', V, [], '把 ER4 的 10 字节复制到 ER8。',
  'verified', tags=['bcd'])
F(0x013A8A, 'nop_rt_2', V, [], '空函数（仅 return）。', 'verified', tags=['util'])
F(0x013AAC, 'select_var_base', 'undefined2*', [('undefined2*', 'p')],
  'R8/R9 都非 0 时返回 0xD392（变量区基址），否则原样返回 p。',
  'verified', tags=['var'])
F(0x013AC4, 'matrix_cell_index4', 'short', [],
  '返回 (R12*4 + R13)*10 + ER4（4 列矩阵单元号）。', 'verified', tags=['matrix'])
F(0x013AD4, 'word_at', 'undefined2', [('byte*', 'p')],
  '返回 p[R6*2] 处的 16 位值。', 'verified', tags=['util'])
F(0x013B5E, 'call_13af0', V, [('undefined2', 'er0'), ('undefined2', 'er2')],
  '以原参数调用 0x13AF0。', 'likely', tags=['bcd'])
F(0x013BF2, 'call_13b6c', V, [('undefined2', 'er0'), ('undefined2', 'er2')],
  '以原参数调用 0x13B6C。', 'likely', tags=['bcd'])
F(0x014028, 'copy_slot_via_14386', V, [],
  '通过 0x14386 把当前操作数复制到槽位。', 'likely', tags=['bcd'])
F(0x014314, 'matrix_row_of', 'undefined2', [('byte*', 't')],
  'R5 = t[0]>>4（矩阵/单元类型高位），R2 = 3。', 'verified', tags=['matrix'])
F(0x014378, 'pow_ER6_ER2', V, [], '调用 0x1CF90（乘方族）：操作数 in_ER2。',
  'verified', tags=['bcd'])
F(0x014380, 'pow_ER8_ER2', V, [], '调用 0x1CF90（乘方族）：操作数 in_ER2。',
  'verified', tags=['bcd'])
F(0x014386, 'pow_ER12_ER2', V, [], '调用 0x1CF90（乘方族）：操作数 in_ER2。',
  'verified', tags=['bcd'])
F(0x014396, 'copy_ER6_from_ER4', V, [], '把 ER4 的 10 字节复制到 ER6。',
  'verified', tags=['bcd'])
F(0x018FD2, 'set_radians_mode', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '0x1CD2C 归一化后以常量 0x3416（弧度模式值）调用 0x1C86C。',
  'likely', tags=['bcd'])

F(0x01A15A, 'decc_dispatch', V, [],
  '十进制运算分派：0xD05A<12 时按 0xD01E 操作码选择核心（<5 0x1C4EE、5 0x1C4C6、6 0x1C18C、'
  '7 0x1C042、8 0x1C4A6、>=9 0x1C478）；否则走 0x1A61A 的通用路径。'
  '由 0x1CFA4 二进制核心在 0x1B3E4 后调用，0x19D14（e^x）也直接调用。',
  'strong', tags=['bcd'])
F(0x01A61A, 'decc_generic', V, [],
  '通用十进制运算：按 0xD01E 分派至 0x1C4EE/0x1C670 等，并处理指数修正。',
  'likely', tags=['bcd'])
F(0x01AB54, 'decc_addinit', V, [],
  '加法/乘法尾数错位对齐（DAA 链调整 X 尾数与 0xD02C 对齐量），供 0x1CE4E 在阶段<9 时调用。',
  'strong', tags=['bcd'])
F(0x01AC2C, 'decc_rounded_add', V, [],
  '带舍入的加减法：置 Y=1.0 后做尾数对齐与进位（DAA/SUBC 链），供 0x1CE4E 在阶段==9 时调用。',
  'strong', tags=['bcd'])
F(0x01A6C8, 'decc_entry_7', V, [],
  '以 0xD01E=7 调用 0x1A6F0 后进入运算分派（0x1D2FE 整数加法使用）。',
  'likely', tags=['bcd'])

F(0x01D6CA, 'dec_cmp_special', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '带特殊值处理的比较：先 0x1C35C 载入 b，再按 D009/D019 的特殊标志分支。',
  'likely', tags=['bcd'])
F(0x01DA2E, 'dec_to_special', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '把 0xD05C/0xD05E 送入 0x1974A（特殊值构造）后收尾。', 'likely', tags=['bcd'])
F(0x01DA48, 'dec_from_integer', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '整数到 BCD 的转换：0x1C364 载入后调用 0x19C8C/0x19EB2。', 'likely', tags=['bcd'])
F(0x01DA62, 'is_simple_bcd', 'byte', [('byte*', 'p')],
  'p[0] 低半字节 < 10 且 p[9] 高半字节为 0 时返回 0（简单整数），否则返回 1。',
  'verified', tags=['bcd'])
F(0x01D9A8, 'dec_bin_to_bcd_ctx', V, [],
  '二进制到 BCD 上下文转换（0x1C364 后按标志选择路径）。', 'likely', tags=['bcd'])
F(0x01C384, 'dec_load_Y_from', V, [('byte*', 'p')],
  '从 p+1 的 9 字节载入 Y（0xD010 起）。', 'verified', tags=['bcd'])
F(0x01C3B8, 'dec_store_result', V, [],
  '把 X（0xD010 起）写回 _D05E 指向的输出缓冲。', 'strong', tags=['bcd'])
F(0x01C42C, 'dec_build_const', V, [],
  '构造特殊常量（D010=0x600、D018=0x100）并调用 0x1C506。', 'likely', tags=['bcd'])
F(0x01C450, 'dec_round_final', V, [],
  '最终舍入：尾数加 5 并按 DAA 链规整（0x1AC2C/0x1AE22 使用）。', 'strong', tags=['bcd'])
F(0x01C00A, 'dec_fixup_types', V, [],
  '按 D009/D019 的类型标志修正 X（0x1AFB8 或 0x19CB0）。', 'likely', tags=['bcd'])
F(0x01C2D6, 'dec_pack_X', V, [],
  '把 X 的尾数与指数打包到 P（0xD020）。', 'likely', tags=['bcd'])
F(0x01CDE4, 'decc_op', 'byte', [('undefined2*', 'a'), ('undefined2*', 'b')],
  '十进制运算入口：设置 _D05C/_D05E 后以操作码 (char)param_2 调用 0x1CE4E，返回是否成功。',
  'strong', tags=['bcd'])

F(0x013F3E, 'dec_pair_copy', V, [],
  '把 ER6+ER8 处的 BCD 复制到 ER4+ER8 处并调用 0x1D730 写回结果。',
  'verified', tags=['bcd'])
F(0x013FF2, 'dec_convert_check', 'byte', [],
  '调用 0x13B5E 转换后按 0x13CD8 返回结果标志。', 'likely', tags=['bcd'])
F(0x014008, 'dec_shift_ratio', V, [],
  '把 ER4+R8 处 BCD 复制到 ER12 后执行两次 0x14028 移位。', 'likely', tags=['bcd'])
F(0x014034, 'dec_percent_chain', V, [],
  '百分数换算核心（R8..R11 为四组比例常量）：复制 R8 偏移操作数并乘/加。',
  'likely', tags=['bcd'])

F(0x00947C, 'stats_x2_minus_y2_div', V, [],
  '统计变量运算：t = x*x（0x1881C），u = y*y（0x18858），返回 t/u（0x1CF68 除法）。'
  '用于标准差的 x²、y²、xy 累积。', 'strong', tags=['app'])

F(0x00BC08, 'draw_insert_marks', V, [('char', 'ch')],
  '行内插入态标记：0xD015==1 时按光标列计算三处位置并调用 0x1F9D4/0xEA36 绘制插入符。',
  'likely', tags=['editor'])
F(0x00C2FA, 'get_line_kind', 'ushort', [],
  '按当前键值/光标状态返回编辑行类型码（4 为普通行等）。', 'likely', tags=['editor'])

F(0x00BC7A, 'stats_head_draw', V, [],
  '绘制统计表头：按 0xD112 选 "r="/"c=" 并绘制 a=/b=/r=/c= 列标题。',
  'strong', tags=['app'])
F(0x01E750, 'wait_valid_key', 'short', [('char', 'mask')],
  '先 0x8CC0 绘制菜单态，然后循环读键直到 0x8DF6 判定有效。',
  'likely', tags=['key'])
F(0x00ED7C, 'draw_tokens', V, [('byte*', 'tok')],
  '按 token 首字节高半字节分派绘制：0→0x20710、2/8→0x2B4FC、4→0xE698，并做换行/截断。',
  'strong', tags=['editor'])

F(0x00C358, 'stats_matrix_draw', V, [],
  '清屏后按 0xD163 起始行绘制统计矩阵单元（0x3950 表）并刷新屏幕。',
  'strong', tags=['app'])
F(0x00C690, 'stats_table_draw', V, [],
  '清屏后按 0xD163 起始行绘制统计表格（0x398E 表与行号 0x6474）并显示统计量。',
  'strong', tags=['app'])

F(0x00CDE8, 'table_insert_row', V, [],
  '统计表插入行：按每行单元数 0x8F48 与光标行 0xD0F6 计算插入位置，'
  '0x9A3A 搬移后续行、memzero 清空新行并更新计数。', 'strong', tags=['app'])

F(0x00D0AE, 'check_balanced_expr', V, [],
  '扫描编辑行检查括号平衡：遇到 0x2A（(）与 0x2A886（分数 3）成对计数，'
  '0x24A14（分数 2）计数，遇 0x1C 且已平衡时结束。', 'strong', tags=['editor'])
F(0x00D108, 'commit_line', V, [],
  '确认输入行：经 0x8D94 检查后按 0xD114/0xD115 状态调用 0x1E6B6/0x26A40/0x27A7A 刷新显示。',
  'likely', tags=['editor'])
F(0x00D172, 'edit_cmd_dispatch', V, [('char', 'arg')],
  '按当前 token 的按键码（0x18/P/Q/S/0xC8/0x38 等）分派编辑命令：'
  '0x1FBD2 替换 token、0x1E2D2 切换矩阵/统计单元，并通过 param_3 返回状态码。',
  'strong', tags=['editor'])

F(0x00D898, 'stats_denominator_calc', V, [],
  '统计分母 Σ 计算：对 0xD7FC/0xD806/0xD810/0xD81A 四组操作数做'
  '平方（0x1CF90）与除法（0x1CF68），写入 0xD842.. 的统计槽。',
  'strong', tags=['app'])
F(0x00D9BC, 'kbd_input_handle', V, [],
  '处理输入态按键：按 0xD114/0xD116 与当前模式（E/J/K/0x0C）决定分支。',
  'likely', tags=['key'])

F(0x00DAA4, 'edit_value_adjust', V, [('byte*', 'tok')],
  '按参数模式（0/1/2/3）调整编辑值：模式 0 走 0x2A074，模式 1..3 用 0x1D550 做'
  '常量加减，结果写回 token 缓冲。', 'likely', tags=['editor'])
F(0x00DCFA, 'table_loop', V, [('short', 'arg')],
  '统计/表格模式主循环：置 0xD114=0x17、0xD116=3，读键（0x2AA76）后按'
  '0x2D/0x30/0x26/0x2E 等键处理，调用 0x1323A/0x1FE60 更新表格。',
  'strong', tags=['app'])
F(0x00DDE8, 'list_draw_rows', V, [],
  '按行数 0xD676 逐行绘制列表项（0x9E4C），当前行用 0x20EE6/0x20EEC 高亮，'
  '附加标记取自 0xD677。', 'strong', tags=['ui'])

F(0x009118, 'boot_lcd_init', V, [],
  '上电 LCD 初始化：0xD0F5 为 0 时清缓冲、0x8ACE 写 0x1625/0x1680/0x560A'
  '时序参数、延时 0x1000 后配置 0xF031/0xF03D/0xF00A 并启动显示。',
  'strong', tags=['boot'])
F(0x00BABE, 'stats_cell_key', 'char', [],
  '统计表按键选择单元格：数字键 1..4（按 4 列）选列，方向键在 0xAF4 上限内移动，'
  '返回 0x5DAA 表对应的单元格类型。', 'strong', tags=['app'])
F(0x00BB82, 'table_count_update', V, [('byte', 'delta')],
  '更新统计行的计数/累加：遍历行的起止区间并给匹配项加 delta，'
  '同时累加 0xD00E/0xD010。', 'likely', tags=['app'])

F(0x0095D6, 'stats_headers_draw', V, [],
  '按模式（0x0C=统计、0x88=表格、其它）绘制表头：0x5B14/0x7E14/0x5D0C 等'
  '固定文本串与 0x0A60 区标题。', 'strong', tags=['app'])

F(0x0098C6, 'stats_cursor_move', V, [],
  '统计表光标移动：按方向键（0xD116 bit5）在 1..行数 0xD154 间移动并调用'
  '0x2AC7C 刷新当前行。', 'strong', tags=['app'])

F(0x00AFAE, 'name_buffer_load', V, [],
  '按模式取编辑行长度（0x9B6E），检查 0x22CA0/0x2696E/0x9DC8 后把 0x178 处'
  '的编辑行复制到 0xD180 缓冲（矩阵/列表变量命名）。', 'likely', tags=['editor'])

F(0x00C002, 'convert_guard', V, [],
  '转换保护：无比例键/历史时把编辑行转入极坐标（0x1D39E），成功后进入'
  '0x1FC30 的显示编辑器。', 'likely', tags=['editor'])

F(0x00C1C6, 'token_balance_check', V, [],
  'token 平衡检查：类别 2 时求 0x1ECFA(0) 偏移后的串长，为 0 则调用'
  '0xD0AE 扫描括号平衡。', 'likely', tags=['editor'])
F(0x00CF94, 'input_key_filter', V, [],
  '输入态按键过滤：0xD116==1 时屏蔽/清零 0xD10E 的部分键（0x36/0x31/0xFC3B 区）。',
  'likely', tags=['key'])

F(0x010E9C, 'details_reset', V, [],
  '设置模式复位：清 0xD122/0xD123；亮度 0xD153 不在 11..31 时复位为 0x14'
  '并调用 0x9304；清 0xD125，把 0xD12B 限制为 >=1。', 'likely', tags=['setup'])
F(0x010E80, 'defaults_load', V, [],
  '把 ROM 0xFFC0 起的 24 字节默认设置复制到 0xD11A..0xD131。',
  'verified', tags=['setup'])

F(0x010CCC, 'dec_xy_pair_arith', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '对 (a,b) 先做 0x10DC2 加法，再按 0x179F4 的操作数类型调用'
  '0x1887A/0x18858/0x1881C，最后以 0x179E2 做二进制/BCD 混合运算。',
  'likely', tags=['bcd'])

F(0x013572, 'dec_swap_temp', V, [],
  '交换 0xD752 与 0xD6BC 两个 BCD 暂存单元。', 'strong', tags=['bcd'])
F(0x01384A, 'xor_words', 'ushort', [('ushort', 'a')],
  '把 a 与 ER8 按 16 位异或并返回。', 'verified', tags=['util'])
F(0x013814, 'hash_mix32', 'ushort', [('ushort', 'a'), ('ushort', 'b')],
  '32 位混合散列：对 a/b 做乘 0x20 与 0x1384A 异或折叠。', 'likely', tags=['util'])
F(0x013A90, 'dec_round_word', 'ushort', [('undefined', 'n')],
  '调用 0x1D6A4 对当前操作数按 n 位舍入，返回 (高字节<<8)|n。', 'likely', tags=['bcd'])

F(0x013096, 'boot_splash', V, [],
  '开机画面：清屏、0x2A048(0x108) 绘制标识、延时 8000 后恢复 0xD137。',
  'strong', tags=['boot'])
F(0x0131CC, 'table_open', V, [('undefined2*', 'a'), ('char', 'flag')],
  '打开表格：初始化行缓冲（0xD784 或 0xD6B2），必要时清历史并调用 0xEA80'
  '载入行数据。', 'likely', tags=['app'])

F(0x0130E6, 'table_init_var', 'undefined2', [('undefined2', 'er0')],
  '表格变量初始化：把 4 组 BCD 置入 0xD392 缓冲，比较为 1 时返回 3，'
  '否则做格式换算并调用 0x131CC 打开表格行。', 'likely', tags=['app'])

F(0x01323A, 'table_load_row', 'byte', [('undefined2', 'er0')],
  '把 0xD392 缓冲的 BCD 装入行结构，按 0xD112 选择操作数列，比较后'
  '调用 0xEA80 载入表格行；0 为成功、3 为空行。', 'strong', tags=['app'])

F(0x013858, 'dec_nth_root', V, [],
  '开方核心：取 0xD310 常数（2）、按 0x1CF68 迭代试乘，成功后经 0xF250'
  '与 0x1E6D0 收尾。', 'likely', tags=['bcd'])
F(0x01391A, 'dec_root_prep', 'ushort', [('undefined2*', 'a'), ('undefined2', 'b')],
  '开方的操作数准备：复制 a 到局部并按 0x1D900/0x1D620 处理符号/指数。',
  'likely', tags=['bcd'])

F(0x0136F6, 'list_build_rows', V, [],
  '生成列表视图的行数据（清 0xD676/0xD677 计数），供 0xDDE8 逐行绘制。',
  'likely', tags=['ui'])

F(0x013584, 'dec_cmp_path2', V, [],
  '比较路径 2：以 0xD752/0xD6BC 为操作数调用 0x1DA7A/0x1D620（0x1369A 的另一半）。',
  'likely', tags=['bcd'])

F(0x014B92, 'matrix_swap_rows', V, [],
  '交换由 0x14B0A 计算的两个矩阵行的单元格（每行 R9 个 10 字节单元）。',
  'strong', tags=['matrix'])
F(0x014C1C, 'dec_cmp_swap', 'undefined2', [('undefined2*', 'a')],
  '以 a 与外部操作数做 0x1DA7A 比较，必要时交换并调用 0x1D654（带符号比较收尾）。',
  'likely', tags=['bcd'])

F(0x014196, 'matrix_cell_mul_add', V, [('short', 'off')],
  '矩阵单元累加：载入两单元（0x1DA02）、乘（0x1CF90）后加（0x1CF54）。',
  'likely', tags=['matrix'])
F(0x01431C, 'matrix_cell_check', 'byte', [('undefined2', 'a'), ('byte', 'b')],
  '矩阵单元类型检查（0x14314 得类型 9），对两个单元分别校验后再调用 0x1406A。',
  'likely', tags=['matrix'])

F(0x01406A, 'matrix_print_elem', 'undefined2', [('byte*', 'expr'), ('byte*', 'dst')],
  '矩阵单元打印/求值：单元类型 9（矩阵）时按行或元素循环调用 0x1CF68（除法）'
  '与 0x14196（乘加），得到 3 个 10 字节单元写回 dst。', 'strong', tags=['matrix'])
F(0x0141E0, 'matrix_elem_add', 'undefined2', [],
  '把两个矩阵单元复制到局部后调用 0x1431C 做类型检查与 0x1406A 求值。',
  'likely', tags=['matrix'])

F(0x01447A, 'memmove_blocks', V, [('byte*', 'dst'), ('char', 'up')],
  '把 0xD932 处的数据按 0x28 字节块上/下移动 param_2 块（矩阵行插入/删除）。',
  'strong', tags=['matrix'])
F(0x014668, 'matrix_elem_is_valid', 'byte', [('undefined2', 'a'), ('char', 'strict')],
  '矩阵单元有效性：类型为 1 直接有效；strict 时再用 0x1CBB2/0x1D89E 检查指数范围。',
  'likely', tags=['matrix'])

F(0x0143DC, 'matrix_ones', 'byte', [('ushort', 'size')],
  '把矩阵填充为单位阵：按行列循环 0x1D780（置位）与 0x10C4E（1=x/x），'
  '依次经 0x144BC/0x14534/0x145D8/0x146B8/0x14A64 归一化。',
  'strong', tags=['matrix'])
F(0x0145D8, 'matrix_row_check', 'undefined2', [('undefined *', 'base'), ('ushort', 'idx')],
  '矩阵行检查：对每个单元做 0x14668 有效性验证。', 'likely', tags=['matrix'])
F(0x014A64, 'matrix_copy', 'undefined2', [('undefined *', 'base'), ('ushort', 'idx')],
  '矩阵整体复制/整理（单位阵构造后的收尾步骤）。', 'likely', tags=['matrix'])

F(0x0144BC, 'matrix_wait_map', 'undefined2', [('undefined *', 'base'), ('ushort', 'idx')],
  '矩阵按行扫描（0x93BA 读键等待），在矩阵数据中定位/映射单元。', 'likely', tags=['matrix'])
F(0x014534, 'matrix_row_scan', 'undefined2', [('undefined *', 'base'), ('ushort', 'idx')],
  '逐行比较矩阵单元（0x1D5B6）定位目标行。', 'likely', tags=['matrix'])

F(0x0148FC, 'matrix_del_rows', 'undefined2', [('ushort', 'y'), ('ushort', 'range')],
  '矩阵删除连续行：按范围逐行搬移后续单元格（0x14B0A 寻址）。',
  'strong', tags=['matrix'])
F(0x014966, 'matrix_insert_rows', 'undefined2', [('ushort', 'y'), ('ushort', 'pos'), ('char', 'n')],
  '矩阵插入行：把 pos 之后的单元格整体后移 n 行。', 'strong', tags=['matrix'])
F(0x0149AE, 'matrix_ins_fill', 'undefined2', [('ushort', 'pos'), ('char', 'n')],
  '矩阵插入后填充空行（0x93BA 读键等待、逐单元清零）。', 'likely', tags=['matrix'])
F(0x014A14, 'matrix_row_fill', 'undefined2', [('ushort', 'pos'), ('ushort', 'range')],
  '矩阵行区间填充：对范围内的行调用 0x14B0A 寻址并清理。', 'likely', tags=['matrix'])

F(0x0146B8, 'matrix_add_common', V, [('undefined *', 'base'), ('ushort', 'idx')],
  '矩阵运算公共分派：按操作数类型核对行列、单位阵/特殊阵并行调用'
  '0x149AE/0x148FC/0x14A14 等行操作。', 'likely', tags=['matrix'])

F(0x0155F4, 'matrix_rhs_mul', V, [],
  '右端项乘算：以常量 0x1B80 与操作数做 0x1909A，随后 0x1671C/0x152FA/0x15628 收尾。',
  'likely', tags=['matrix'])
F(0x015616, 'matrix_div_28', V, [],
  '把操作数除以调用块 +0x28 处的 BCD（0x1CF68 除法）。', 'likely', tags=['matrix'])
F(0x015628, 'matrix_div_add', V, [],
  '把操作数除以调用块 +0x0A 并加上 +0x1E 处操作数（0x1CF68/0x1909A）。',
  'likely', tags=['matrix'])
F(0x015636, 'matrix_mul_add', V, [],
  '把操作数乘以调用块 +0x0A 并加上 +0x1E 处操作数（0x1CF54/0x1909A）。',
  'likely', tags=['matrix'])
F(0x015B0E, 'matrix_size_scan', 'undefined2', [('byte', 'n')],
  '按维度 n 扫描矩阵存储（每单元 0x28 字节），累加匹配单元，'
  'n==2 时改走 0x15B66。', 'likely', tags=['matrix'])

F(0x015BAC, 'matrix_func_ext', 'byte', [('byte', 'fn'), ('undefined2*', 'x')],
  '扩展矩阵函数：x 经 0x1D800 归一化后按函数号 fn 选择 0x1D246/0x1C880/0x1C86C'
  '等核心求值，返回状态（0 成功、3/8 为特殊值）。', 'strong', tags=['matrix'])

F(0x015D72, 'token_encode', V, [('byte*', 'tok'), ('byte*', 'out')],
  '把 token 编码成显示/存储串：按类型 0x15F86 展开，0xD112==9 时加 0x60 前缀，'
  '否则按 0x15FFC 的长度信息压缩编码。', 'strong', tags=['parser'])

F(0x015FFC, 'bcd_mul_table', V, [],
  '以 ROM 0x315A 的 9 组 16 位常量做 BCD 乘法/进位链（按 R4..R8 半字节展开）。',
  'likely', tags=['bcd'])

F(0x015E98, 'token_is_complex', 'undefined2', [('ushort', 'tok'), ('undefined2', 'ctx')],
  '令牌是否为复合结构：0x15ECA 分类后，类型 3/4/5/6/7/8 返回 1（其余 0）。',
  'strong', tags=['parser'])
F(0x015F86, 'token_norm', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '令牌值归一化：按 0x1D5B6 比较结果调用 0x1D730，再以 0x1D66E/0x1C844 做 10 进制对齐。',
  'likely', tags=['parser'])

F(0x0160CE, 'store_cell_if_ne', V, [('char', 'v')],
  'R9 != R10 时把 v 的低半字节写到 base+R10+0x28 的单元格。', 'verified', tags=['matrix'])
F(0x0160D2, 'store_cell_if_lt', V, [('char', 'v')],
  'R10 != 0xF 时把 v 的低半字节写到 base+R10+0x28 的单元格。', 'verified', tags=['matrix'])
F(0x01611A, 'matrix_advance', 'undefined2', [('undefined2', 'v')],
  '矩阵运算推进：0x16BE8 复制、0x16F10 处理 +0x14、0x16C16 推进操作数并返回 v。',
  'likely', tags=['matrix'])
F(0x01646C, 'matrix_cmp_propagate', 'undefined2', [('undefined2*', 'a'), ('undefined2', 'b')],
  'a+10 与 b 比较，若相等再与 ER12+0x1E 比较（矩阵单元差传递），返回 a。',
  'likely', tags=['matrix'])
F(0x016B4A, 'emit_noop_guard', V, [], 'R5 非 0 或 R4>200 时直接返回（禁止打印/范围守卫）。',
  'verified', tags=['util'])
F(0x016C4E, 'store_mat_word', V, [('undefined2', 'v')],
  'R10<0x18 时把 v 写入矩阵区 0x???0 + R10*2（基址 0x3060 区）。', 'verified', tags=['matrix'])
F(0x016C70, 'check_r5_pair', V, [],
  'R5 为 0xFE 或 0xFA 时保留，否则返回（单元类型守卫）。', 'verified', tags=['matrix'])
F(0x016D4E, 'mat_digits_loop', V, [('char', 'v'), ('ushort', 'n')],
  '从 0xD05E 起的 n 项逐项调用 0x16CC8 处理（数字/单元转换循环）。',
  'likely', tags=['matrix'])
F(0x016D7C, 'nibble_unpack', V, [],
  '把 EA 指向的打包半字节解成字节写到 ER12（R10 控制展开长度）。', 'verified', tags=['util'])

F(0x0161DE, 'matrix_transpose_core', 'byte', [('undefined2*', 'a'), ('undefined2*', 'b')],
  '矩阵转置核心：0x1DA7A 比较后按 0xD11A 标志交换/移动单元，返回 3 表示失败。',
  'likely', tags=['matrix'])
F(0x01637A, 'matrix_apply_const', 'char', [('char', 'flag'), ('undefined2*', 'b')],
  '按标志把常量 0x3150 作用于矩阵单元（0x1D620 比较后写回），返回 3 或 0。',
  'likely', tags=['matrix'])
F(0x0166BA, 'matrix_func_byte', 'undefined2', [('ushort', 'fn'), ('undefined2*', 'x')],
  '矩阵单元函数：按 fn（0xFE26 区/其它）换算索引后调用 0x1C830 求值。',
  'likely', tags=['matrix'])

F(0x016820, 'matrix_eval_tree', 'undefined2', [('ushort', 'tok'), ('byte*', 'out')],
  '矩阵/向量表达式求值树：按 token 码（0xFE26/0xFBxx 区）递归下降，'
  '调用 0x166BA/0x167E0/0x16F64 等完成求值。', 'strong', tags=['matrix'])
F(0x016B80, 'matrix_walk', V, [('ushort', 'tok')],
  '遍历表达式序列：0x15EEA 分类后按括号/单元令牌调用 0x16820 求值（cVar5 控制模式）。',
  'likely', tags=['matrix'])
F(0x016B84, 'matrix_walk_b', V, [('ushort', 'tok')],
  '遍历表达式序列（模式 1 的变体）。', 'likely', tags=['matrix'])
F(0x016B88, 'matrix_walk_c', V, [('ushort', 'tok')],
  '遍历表达式序列（无模式预示的变体）。', 'likely', tags=['matrix'])

F(0x0167E0, 'matrix_eval_u8', V, [('ushort', 'tok')],
  '单字节矩阵元素求值：按 tok 的编码区（0xFEXX 等）调整索引并调用 0x16820。',
  'likely', tags=['matrix'])
F(0x016CC8, 'mat_cmp_elem', 'undefined2', [('ushort', 'a'), ('ushort', 'b')],
  '矩阵单元比较并推进（0x16B4A 守卫），返回比较结果标志。', 'likely', tags=['matrix'])
F(0x016D00, 'mat_digits_eval', 'undefined2', [('undefined2', 'v')],
  '数字序列求值：逐项 0x16C3A/0x16CC8 处理，遇结束标记返回。', 'likely', tags=['matrix'])
F(0x016F64, 'matrix_prec_limit', 'byte', [('byte', 'v')],
  '按单元类型高位确定可保留的精度档（0xF 直接返回，0/0xFF 特殊处理）。',
  'likely', tags=['matrix'])
F(0x016FCE, 'mat_opnd_copy', V, [],
  '复制并调整矩阵操作数（+0x0A/+0x14 槽）供 0x171F0 使用。', 'likely', tags=['matrix'])

F(0x016712, 'dec_add5_bcd', V, [('undefined2*', 'a'), ('undefined2', 'b')],
  '以 0x1CE3E 运算后按 5 位十进制调整（尾数字节 -5），再循环 0x16EF4/0x1C858。',
  'likely', tags=['bcd'])
F(0x01671C, 'dec_op5_bcd', V, [('undefined2*', 'a'), ('undefined2', 'b')],
  '以 0x1CE2C 运算后的 5 位十进制调整版本（与 0x16712 对称）。',
  'likely', tags=['bcd'])

F(0x01708C, 'key_af_dispatch', 'undefined2', [('undefined2', 'a')],
  '以键码 0xAF 分派到 0x17150（菜单方向键类按键）。', 'likely', tags=['key'])
F(0x017150, 'key_af_handler', 'undefined2', [('undefined2', 'k'), ('undefined2', 'ctx')],
  '键码 0xAF 处理：按 0xD111/0xD114 状态分派（列表/表格方向键、0x170AE 子处理）。',
  'likely', tags=['key'])
F(0x0170AE, 'key_af_lists', V, [('undefined2', 'k')],
  '0x17150 的子分派：按 0xD114 bit6 与键值选择列表操作。', 'likely', tags=['key'])
F(0x017566, 'matrix_key_hook', V, [('undefined2', 'k')],
  '0xD114 bit5 的矩阵按键回调（0x1767C/0x17680/0x177A4 共用）。',
  'likely', tags=['key'])

F(0x01767C, 'matrix_edit_key', 'undefined2', [('undefined2', 'k')],
  '矩阵编辑按键（R7>=3）：经 0x16820 解析后操作矩阵行/列。', 'likely', tags=['matrix'])
F(0x017680, 'matrix_edit_key_b', 'undefined2', [('undefined2', 'k')],
  '矩阵编辑按键变体（0xD114 bit7 时直接返回）。', 'likely', tags=['matrix'])
F(0x0177A4, 'matrix_key_walk', V, [('undefined2', 'k')],
  '矩阵模式按键：0x16B80 遍历表达式后转 0x17566（R7>=3 时生效）。',
  'likely', tags=['matrix'])
F(0x0177DA, 'matrix_entry', V, [('byte*', 'src'), ('undefined2', 'flags')],
  '矩阵输入入口：按 0xD111==6 设置 0xD13D，解析输入并生成矩阵单元。',
  'likely', tags=['matrix'])

F(0x0171F0, 'matrix_value_calc', 'ushort', [('ushort', 'k'), ('ushort*', 'a')],
  '矩阵单元求值主分派（9KB）：R7<3 直接返回 2；按键值/单元类型调用'
  '0x16820/0x16CC8/0x1767C/0x17680 等，返回单元状态。', 'likely', tags=['matrix'])
F(0x0178EE, 'stat_table_calc', V, [],
  '统计表计算（2.8KB）：从 0xD5EC 读取行数据按 0xD114 状态计算统计量。',
  'likely', tags=['app'])

F(0x017A1A, 'dec_bin_arith', V, [],
  '十进制运算核心（0x17A 段）：按 _D05C/_D05E 操作数类型调用 0x17E8E/0x17B4E，'
  '由 0x179E2、decm_mul/decm_div 等调用。', 'strong', tags=['bcd'])
F(0x017A78, 'dec_bin_arith_b', V, [],
  '十进制运算核心变体（被 0x1874A 调用）。', 'likely', tags=['bcd'])
F(0x017B4E, 'dec_load_and_run', V, [('undefined2', 'b'), ('undefined2*', 'a')],
  '载入操作数（0x187DA）后按 _D05E 首字节分派 0x17BD6/0x19CC2/0x1C364/0x19C0E。',
  'strong', tags=['bcd'])

F(0x017BEE, 'dec_calc_main', V, [('char', 'a0'), ('char', 'a1'), ('char', 'a2'), ('char', 'a3')],
  '十进制计算主流程：按 4 字节参数设置 _D05C/_D05E 后进入结果缓冲区遍历。',
  'likely', tags=['bcd'])
F(0x017D1A, 'dec_get_word', 'undefined2', [('undefined2', 'a'), ('undefined2', 'b')],
  '取操作数（0x187DA）并按 0xD05C/0xD05E 归一化。', 'likely', tags=['bcd'])
F(0x017DF4, 'dec_op_setup', V, [('undefined2', 'a'), ('undefined2', 'b')],
  '运算准备：从 0x187DA 结果设置 _D05E/_D05C。', 'likely', tags=['bcd'])

F(0x017E8E, 'dec_core_17e8e', 'undefined2', [('char', 'a'), ('char', 'b'), ('char', 'c'), ('char', 'd')],
  '十进制运算核心（被 0x17A1A 等调用）：以 0x187DA 解引用操作数后运算并写回。',
  'likely', tags=['bcd'])
F(0x017F82, 'dec_compare_offset', V, [('undefined2', 'a'), ('undefined2', 'b')],
  '比较偏移值：按 0x187DA 解引用三个操作数后调用 0x1C35C/0x1B3BE 比较。',
  'likely', tags=['bcd'])

F(0x018300, 'matrix_check_vals', 'byte', [('undefined2', 'a')],
  '逐单元 0x17F78/0x17F8C 求值，比较相邻单元（0x1B/0x1C 常量）。',
  'likely', tags=['matrix'])
F(0x018334, 'matrix_check_vals_b', 'byte', [('undefined2', 'a')],
  '相邻单元 0x1D 常量与 0x17F78 求值并比较。', 'likely', tags=['matrix'])
F(0x0183AE, 'matrix_check_vals_c', 'byte', [('undefined2', 'a'), ('undefined2', 'b')],
  '对 a 与 a+1/a+2 三个单元求值（0x17F78/0x17DCC）。', 'likely', tags=['matrix'])
F(0x0183D4, 'matrix_cell_probe', 'byte', [('undefined2', 'a')],
  '取 a+1 处单元类型（0x18108）作检查。', 'likely', tags=['matrix'])
F(0x018496, 'matrix_probe_1800', 'byte', [],
  '依次检查 0x1800/0x1803 两个单元的探测结果。', 'likely', tags=['matrix'])
F(0x0184F2, 'matrix_cell_type_b', 'byte', [('undefined2', 'a')],
  '单元类型判定（0x18108/0x182B8/0x18112）。', 'likely', tags=['matrix'])
F(0x01851A, 'matrix_scan_all', 'byte', [],
  '扫描矩阵全部单元（0x18300/0x18334/0x184F2 组合）。', 'likely', tags=['matrix'])

F(0x01865C, 'matrix_scan_1865c', 'byte', [],
  '矩阵扫描流程（0x13C）经 0x1813C 等单元检查。', 'likely', tags=['matrix'])
F(0x0186A0, 'matrix_scan_186a0', 'byte', [],
  '矩阵扫描流程（0x186A0）经 0x18130 等单元检查。', 'likely', tags=['matrix'])
F(0x0186A8, 'matrix_scan_186a8', 'byte', [],
  '矩阵扫描流程变体。', 'likely', tags=['matrix'])
F(0x0186EC, 'matrix_scan_186ec', 'byte', [],
  '矩阵扫描流程变体（0x18496 探测）。', 'likely', tags=['matrix'])
F(0x01874A, 'matrix_scan_1874a', 'byte', [],
  '矩阵扫描流程变体（调用 0x17A78）。', 'likely', tags=['matrix'])
F(0x01887A, 'dec_add_slot', 'undefined2', [('undefined2*', 'a'), ('undefined2', 'b')],
  '把 a 与 b 槽做十进制加法（0x1D620/0x19C0E 路径）。', 'likely', tags=['bcd'])
F(0x0188B6, 'matrix_cell_op', 'undefined2', [('undefined2*', 'a'), ('undefined2*', 'b')],
  '矩阵单元二运算：清除 0x40 标志后按类型调用 0x16712/0x1671C 等。',
  'likely', tags=['matrix'])
F(0x018930, 'matrix_cell_cmp', 'undefined2', [('undefined2*', 'a'), ('undefined2*', 'b')],
  '矩阵单元比较（0x1DA7A/0x1D620 链）。', 'likely', tags=['matrix'])
F(0x0189F6, 'matrix_cell_add', 'undefined2', [('undefined2*', 'a'), ('undefined2*', 'b')],
  '矩阵单元相加（0x1D730/0x1D780 链）。', 'likely', tags=['matrix'])
F(0x018A26, 'matrix_cell_is_zero', 'byte', [],
  '矩阵单元是否为零/空（0x17B4E 检查）。', 'likely', tags=['matrix'])

F(0x01801A, 'matrix_copy_ext', 'undefined2', [('undefined2*', 'a'), ('undefined2*', 'b')],
  '矩阵扩展复制：按单元类型复制并转换（大函数，0x1DA02/0x1D94C 链）。',
  'likely', tags=['matrix'])
F(0x018198, 'matrix_prep_opnd', 'undefined2', [('undefined2', 'a'), ('undefined2', 'b')],
  '矩阵运算操作数准备（0x187DA 解引用后归一化）。', 'likely', tags=['matrix'])
F(0x018A72, 'matrix_div', 'undefined2', [('undefined2*', 'a'), ('undefined2*', 'b')],
  '矩阵单元除法（0x18B8C 比较后 0x1CF68）。', 'likely', tags=['matrix'])
F(0x018A96, 'matrix_pow', 'undefined2', [('undefined2*', 'a'), ('undefined2*', 'b')],
  '矩阵单元乘方（0x18B8C 比较后 0x1CF90 链，用于矩阵幂）。', 'likely', tags=['matrix'])

F(0x01959E, 'bcd_mul22', 'undefined2', [('byte', 'n'), ('char', 'v')],
  'BCD 乘 22：按 n>>4 次数做 DAA 链（v*0x16 累加）。', 'verified', tags=['bcd'])
F(0x0195C8, 'bcd_div22', 'undefined2', [('ushort', 'a'), ('char', 'b')],
  'BCD 除 22：DAS 链减法循环。', 'verified', tags=['bcd'])
F(0x0195EA, 'dec_unary_abs', V, [],
  '一元运算收尾（0x19C8C/0x1BBA8/0x19C7A/0x1AFB8/0x1C4C6 链，即取绝对值）。',
  'likely', tags=['bcd'])
F(0x019D4A, 'dec_scan_digits', 'byte', [],
  '扫描 0xD002 起尾数字节，返回首个非零半字节位置。', 'likely', tags=['bcd'])
F(0x019EB2, 'dec_y_exponent', 'byte', [],
  '把 Y 指数（0xD039）调整到 0xD00B 并返回标志位。', 'likely', tags=['bcd'])
F(0x019ECE, 'dec_raw_entry', V, [],
  '原始运算入口（0x19C9E + 0x19D14（e^x 入口））。', 'likely', tags=['bcd'])
F(0x019F7C, 'dec_exp_last', V, [],
  '置 _D01E=0xF 后调用 0x19ECE，X 复制到 Y 再调用 0x19D14。', 'likely', tags=['bcd'])
F(0x019FBE, 'dec_small_add', 'byte', [],
  '小整数快速加法（两个操作数首字节都 <10 时）。', 'likely', tags=['bcd'])

F(0x0190B8, 'table_calc_cell', 'undefined2', [],
  '统计表单元格计算（按 0xD0F6 行与 0xD121 标志取值后换算）。',
  'likely', tags=['app'])
F(0x01911A, 'dec_cell_normalize', 'undefined2', [('undefined2*', 'a'), ('undefined2*', 'b')],
  '单元格归一化：按 0x1D5B6/0x1D668 类型分派。', 'likely', tags=['bcd'])
F(0x019370, 'dec_light_normalize', 'byte', [],
  '轻量归一化：尾数为 0x0E 时按 0x1AFB8 再规整（供 0x179F4 调用）。',
  'likely', tags=['bcd'])
F(0x019542, 'dec_special_check', 'byte', [],
  '特殊值检查：D009/D019 >= 0xF 时返回 0xF0（溢出/非法）。', 'likely', tags=['bcd'])

F(0x0193BA, 'dec_align_mant', V, [],
  '尾数对齐（DAA/SLLC 链）：按 D009 尾数档位循环 0x19CB0/0x1AFB8/0x1B86C。',
  'strong', tags=['bcd'])
F(0x019980, 'dec_normalize_x', V, [],
  'X 规整主流程：按尾数高位档 0x19A48/0x19C56/0x19CF8 逐段处理特殊值。',
  'strong', tags=['bcd'])

F(0x019D6E, 'dec_shift_mant', 'byte', [],
  '按 X 尾数首位非零半字节左移尾数（8 字节循环），返回移位数。',
  'likely', tags=['bcd'])

F(0x01A356, 'or_words_r8', 'undefined2', [], '返回 (param2|R9, param1|R8) 的按位或结果。',
  'verified', tags=['util'])
F(0x01A954, 'dec_set_ln', V, [], '置 _D01E=0xE（ln）并初始化 Y=3、D01D=0。',
  'strong', tags=['bcd'])
F(0x01A976, 'dec_unary_neg', V, [], '一元收尾（0x19C8C/0x1C152/0x19C7A/0x1C18C，即取负）。',
  'likely', tags=['bcd'])
F(0x01AD04, 'dec_add_low', V, [], 'D009<0xF 时进入 0x1AD2E（低位加法路径）。',
  'verified', tags=['bcd'])
F(0x01AFA4, 'dec_fix_mant_hi', V, [], 'X 尾数高位 >4 时加 5 并按 DAA 修订（尾数规整）。',
  'verified', tags=['bcd'])

F(0x01A232, 'dec_cmp_core', 'undefined2', [],
  '十进制比较核心（DAA 链，2.1KB）：P 寄存器与第 2 操作数逐位比较，'
  '由 0x1A1D0/0x1D26E/0x1D280 调用。', 'likely', tags=['bcd'])
F(0x01A36A, 'dec_arith_neg', 'undefined2', [],
  '十进制算术变体（2.9KB，0x1A1D0/0x1CC9A/0x1D26E 调用，处理负号/补码）。',
  'likely', tags=['bcd'])
F(0x01A466, 'dec_arith_dual', 'undefined2', [],
  '十进制算术变体（1.9KB，0x17A78/0x17D1A/0x19DD6 调用，双操作数）。',
  'likely', tags=['bcd'])

F(0x01AD2E, 'dec_align_shift', V, [],
  '按运算阶段 0xD01F（8/9/其它）与操作码 0xD01E 做尾数对齐/移位（1.8KB）。',
  'likely', tags=['bcd'])
F(0x01AE22, 'dec_round_add', V, [],
  '舍入加法：0x19C68 规整后 0x1C450 加 5 并按 D02D 处理进位（1.4KB）。',
  'likely', tags=['bcd'])

F(0x01AE3E, 'dec_round_keep', V, [],
  '舍入保留：按 D02A/D02B 对齐位置与前导尾数加 1/舍入处理（1.1KB）。',
  'likely', tags=['bcd'])
F(0x01A6F0, 'decc_set_state', V, [],
  '设置 0xD05A=5（或 0x0A/8 特殊路径）并按 0x19D76 判定，0x1A6C8 的初始化。',
  'likely', tags=['bcd'])
F(0x01A6FA, 'decc_state_check', V, [],
  '0x1A15A 的入口：按 D009/D019 类型设置 0xD05A 并选择规整路径。',
  'likely', tags=['bcd'])
F(0x01A4F6, 'decc_int_arith', V, [],
  '整数路径（D008 类型 0x20）：DAA 尾数运算（2.3KB），0x1D214 在 R4>=3 时调用。',
  'likely', tags=['bcd'])

F(0x01B02A, 'dec_swap_xp', V, [], '交换 X 与 P（0xD000<->0xD020）。', 'verified', tags=['bcd'])
F(0x01B076, 'dec_swap_xy', V, [], '交换 Y 与 W（0xD010<->0xD050）的低字节。', 'verified', tags=['bcd'])
F(0x01B342, 'dec_fix_integral', V, [], '若尾数低半字节非 0，调用 0x1C30C 取整规整。', 'likely', tags=['bcd'])
F(0x01B35A, 'dec_fix_frac', V, [], '若尾数低半字节 >4，调用 0x1C30C 调整。', 'likely', tags=['bcd'])
F(0x01B388, 'dec_fix_zero_frac', V, [], '清除尾数低字节后调用 0x1C670。', 'verified', tags=['bcd'])
F(0x01B3A0, 'dec_is_special', 'byte', [], 'X 类型高位非 0 且非 0x20 时返回 1（特殊值判断）。',
  'verified', tags=['bcd'])
F(0x01B418, 'dec_entry_ok', V, [], 'D009<0xF 时调用 0x1B44C。', 'verified', tags=['bcd'])

F(0x01B56C, 'dec_round_big', V, [], '舍入大流程（8.7KB）：按精度与阶段做长尾数循环舍入。',
  'likely', tags=['bcd'])
F(0x01B9D0, 'dec_set_y_prec', V, [], '按 R0 的位数 1..10 设置 Y 的尾数常量。', 'likely', tags=['bcd'])
F(0x01BA86, 'dec_scale_y', V, [], '按 D00B 移位缩放 Y（0xD030 区，1.4KB）。', 'likely', tags=['bcd'])
F(0x01BB1E, 'dec_scale_xy', V, [], '按 D00B 缩放 X/Y（1.2KB）。', 'likely', tags=['bcd'])

F(0x01BBA8, 'dec_abs_core', V, [], '取绝对值核心（2.2KB，0x195EA/0x19980/0x1D8F0 调用）。',
  'likely', tags=['bcd'])
F(0x01BBB2, 'dec_neg_core', V, [], '取负核心（2.2KB，0x1AB54/0x1B1BC/0x1B1CA 调用）。',
  'likely', tags=['bcd'])
F(0x01BC64, 'dec_carry_fix', V, [], '末位超过 4 时的进位修正（1.3KB）。', 'likely', tags=['bcd'])
F(0x01BD08, 'dec_ln_core', V, [], 'ln 计算核心（3.9KB，0x19B28 的 x·ln x 路径）。',
  'likely', tags=['bcd'])
F(0x01BDC2, 'dec_log_core', V, [], 'log 计算核心（1.6KB，0x1B09C 调用）。',
  'likely', tags=['bcd'])

F(0x01C05A, 'dec_core_add', V, [], '算术核心：加法变体（3.7KB，0x1C00A 进入）。',
  'likely', tags=['bcd'])
F(0x01C082, 'dec_core_sub', V, [], '算术核心：减法变体（3.2KB）。', 'likely', tags=['bcd'])
F(0x01C170, 'dec_core_mul', V, [], '算术核心：乘法（7.1KB）。', 'likely', tags=['bcd'])
F(0x01C1A4, 'dec_core_mul_b', V, [], '算术核心：乘法变体（6.3KB）。', 'likely', tags=['bcd'])
F(0x01C3DA, 'dec_core_div', V, [], '算术核心：除法（6.1KB，0x1AB54 等调用 0x1C3DA）。',
  'likely', tags=['bcd'])
F(0x01C478, 'dec_core_op9', V, [], '算术核心：运算档 9（6.1KB，0x1A15A 选择）。', 'likely', tags=['bcd'])
F(0x01C4A6, 'dec_core_op8', V, [], '算术核心：运算档 8（6.0KB，0x1A15A 选择）。', 'likely', tags=['bcd'])

F(0x01C9D8, 'dec_mul_via_bcd', 'undefined2', [('undefined2*', 'a'), ('undefined2*', 'b')],
  '通过 0x17A1A 与 0x19A56 组合实现乘法（另一条乘法路径，返回状态）。',
  'likely', tags=['bcd'])
F(0x01CC9A, 'dec_abs_wrap', V, [],
  '取绝对值包装：0x1A36A 后把 P 写回 X 并收尾（0x1C392/0x1C3B8/0x1C3C8）。',
  'likely', tags=['bcd'])

F(0x01D02E, 'dec_call_0179d2', V, [('undefined2', 'a'), ('undefined2', 'b')],
  '以 0x179D2 的结果为左操作数调用 0x1D17E。', 'likely', tags=['bcd'])
F(0x01D044, 'dec_call_17a48', V, [],
  '以 0x17A48/0x179D2 的结果调用 0x1D17E（2.4KB 分派）。', 'likely', tags=['bcd'])
F(0x01D13C, 'dec_call_1d17e_a', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '设置 _D05C/_D05E 后以 0x17A48 结果调用 0x1D17E。', 'likely', tags=['bcd'])
F(0x01D150, 'dec_call_1d17e_b', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '设置 _D05C/_D05E 后直接以 a 调用 0x1D17E。', 'likely', tags=['bcd'])
F(0x01D160, 'dec_call_1d17e_c', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '0x1D150 的变体（含不可达块，返回 0x1D17E 结果）。', 'likely', tags=['bcd'])
F(0x01D170, 'dec_call_1d17e_d', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '设置后 0x1C364 载入再按 0x1B3D0 选择 0x1C81A/0x19EDA 的入口。',
  'likely', tags=['bcd'])
F(0x01D17E, 'dec_unary_dispatch', V, [('undefined2*', 'a')],
  '一元运算分派：0x1C364 载入后按 R4 选择 0x19EDA 等核心（0x1D02E..0x1D160 共用）。',
  'strong', tags=['bcd'])
F(0x01D1C6, 'dec_entry_x', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '入口状态 3（D05A=3）：0x1C364/0x1B3A0/0x1A79A 路径（get_* 系列调用）。',
  'strong', tags=['bcd'])
F(0x01D1DA, 'dec_entry_y', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '入口状态 2（D05A=2）：0x1A4F6 整数路径（或 0x1A79A）。', 'strong', tags=['bcd'])
F(0x01D1EE, 'dec_entry_z', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '入口状态 1（D05A=1）：0x1A4F6 整数路径。', 'strong', tags=['bcd'])
F(0x01D202, 'dec_entry_w', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '入口状态 0（D05A=0）：0x1A4F6 整数路径。', 'strong', tags=['bcd'])
F(0x01D2FE, 'dec_int_add', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '整数加法：0x1C35C 载入、0x1B3E4 判定后 0x1A6C8（D01E=7）。',
  'strong', tags=['bcd'])
F(0x01D32E, 'dec_copy_pair', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '复制 a/b 到局部后调用 0x1D780。', 'likely', tags=['bcd'])
F(0x01D368, 'dec_type_flag', 'byte', [('undefined2*', 'a'), ('undefined2*', 'b')],
  '0x1C364 载入后 0x19D6E 判定，若有效返回 0xF0。', 'likely', tags=['bcd'])
F(0x01D530, 'dec_to_bcd_a', V, [('undefined2', 'a'), ('byte', 'b')],
  '转换入口 A（0x1B3BE 后按低半字节 1..4 选择 0x1B342/0x1B35A/0x1B388）。',
  'likely', tags=['bcd'])
F(0x01D540, 'dec_to_bcd_b', V, [('undefined2', 'a'), ('byte', 'b')],
  '转换入口 B（与 A 对称，起始值 1）。', 'likely', tags=['bcd'])
F(0x01D654, 'dec_round_scaled', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '带 0xD03A 缩放的舍入（0x1C35C/0x1B3BE 链）。', 'likely', tags=['bcd'])
F(0x01D80E, 'dec_bcd_to_bin', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  'BCD 转二进制整数（1.5KB，0x1C364 载入后循环折算）。', 'likely', tags=['bcd'])
F(0x01DD68, 'table_nav_key', V, [], '统计表导航键（0xD013/D014 行游标）处理。',
  'likely', tags=['app'])
F(0x01DE40, 'stat_draw', V, [], '统计/表格绘制（4.7KB，按 0x50BE/D137/D139）。',
  'likely', tags=['app'])

F(0x00CD6A, 'edit_ctx_check', V, [],
  '初始化编辑上下文（0xC3EC）并按 0x1E668 与键值判断是否需要 0xFBFE。',
  'likely', tags=['editor'])
F(0x012D3A, 'eval_to_bcd_slot', V, [('undefined2', 'v')],
  '把求值结果（0x1D7B0）写回调用块槽（0x129F6 准备）。', 'likely', tags=['eval'])
F(0x015384, 'matrix_op_dispatch', V, [('undefined2', 'a')],
  '检查 +0x14 单元后分派 0x14E38/0x14ECE（矩阵运算路径）。', 'likely', tags=['matrix'])
F(0x016FB4, 'matrix_fix_operand', V, [('char', 't')],
  'R6==0xFF 且 t 为 3/8 时把常量 0x1B62 复制到操作数槽。', 'likely', tags=['matrix'])

F(0x01E0A0, 'token_replace_all', V, [('char*', 's')],
  '把编辑串中所有控制字节 3 的分量替换为 s（0x25388 查找、0x203C2/0x203D6 复制）。',
  'likely', tags=['strlib'])
F(0x01E680, 'draw_splash_32', V, [],
  '清屏、0x821E(0x100,0x1AB4) 与 0x2A048(0x32) 绘制后刷新（短路/提示画面）。',
  'strong', tags=['ui'])
F(0x01E96A, 'matrix_set_dims', V, [('byte', 'n')],
  '设置矩阵单元的行列数（0x2F08 表）并清零 0x8ED0 返回的存储。',
  'strong', tags=['matrix'])
F(0x020EF2, 'prompt_string', 'char*', [],
  '按 0xD11C/0xD128/0xD13F 返回提示分隔串（";" 或 0x1D41 常量）。',
  'likely', tags=['ui'])
F(0x0261EA, 'token_class_of', 'undefined', [('byte*', 'tok')],
  '单一 token 时返回 0x15E4E 的类别判定结果。', 'likely', tags=['parser'])
F(0x026332, 'list_close_entry', V, [],
  '调用 0xE21E，返回 3 时清 0xD10E，随后 0x1F6C6 刷新。', 'likely', tags=['ui'])

F(0x02465C, 'draw_edit_string', V, [('char*', 's')],
  '按 0xED7C 绘制编辑串；以 "=" 开头时调整列偏移（0x821E）。',
  'likely', tags=['editor'])
F(0x0266E0, 'draw_field_y', V, [('char', 'x')],
  '在 (x, 0xA0+R) 处绘制字段（0x2682E 给出 R）。', 'likely', tags=['ui'])
F(0x026906, 'cell_draw_pair', V, [('ushort', 'pos'), ('ushort', 'code')],
  '对 pos 与 pos+1 两个单元格调用 0x1F9D4 绘制。', 'likely', tags=['ui'])
F(0x026BBA, 'matrix_ensure_dims', V, [('byte*', 'dim')],
  '单元行列数与矩阵表不一致时调用 0x1E96A 重建。', 'strong', tags=['matrix'])

F(0x008660, 'fb_write_op', V, [('ushort', 'mask'), ('byte*', 'dst')],
  '帧缓冲位写：按 0xD138 模式（0/4/其它）把 mask 与 dst 位合并写入。',
  'strong', tags=['display'])
F(0x00EA36, 'draw_insert_cursor', V, [('ushort', 'dirMask')],
  '按方向掩码在光标两侧绘制插入符（0xEA36 与 0xBC08 配合）。',
  'likely', tags=['editor'])
F(0x01E058, 'draw_list_item', V, [('byte*', 'label')],
  '绘制列表项：0x20F80/0x20F98 边框与 0x9E4C 文本，按标志高亮。',
  'likely', tags=['ui'])
F(0x01E0E2, 'find_table_row2', 'byte', [('char', 'c')],
  '在 0xD169 行表中查找字符 c（记录首次/再次命中）。', 'likely', tags=['app'])
F(0x01E27E, 'lcd_contrast_step', V, [],
  '按 0xF310/0xD0F7 状态调整 0xF816 对比度寄存器并刷新。', 'likely', tags=['display'])
F(0x01E2D2, 'matrix_switch_cell', V, [('ushort', 'sel')],
  '切换矩阵/统计单元：0x1ECFA 后建立 0xD000 值并调用 0x1FC7C/0x25D7C/0x27250。',
  'likely', tags=['matrix'])

F(0x01E6D0, 'matrix_cell_scale', V, [('undefined2', 'k')],
  '对矩阵单元按参数做逐字节缩放（0x13858 开方后的收尾）。', 'likely', tags=['matrix'])
F(0x01E76E, 'table_value_edit', V, [('undefined2', 'v')],
  '按 0xD015 状态修改/打印数值（0x2AC54 的正负号版本）。', 'likely', tags=['editor'])
F(0x01EE0C, 'draw_cursor_line', V, [],
  '按行缓冲与 0xD137 光标位置绘制行/列指示。', 'likely', tags=['display'])
F(0x020DF4, 'redraw_line_syntax', V, [],
  '重绘行并做语法高亮（0x28576/0x1F10E/0xAF74 链）。', 'likely', tags=['editor'])
F(0x0214DE, 'mat_cell_extract', V, [('ushort', 'sel')],
  '从矩阵单元提取数值（0x2196A 位测试后 0x1C35C 等）。', 'likely', tags=['matrix'])

F(0x021976, 'mat_cell_ctx', V, [('ushort', 'sel')],
  '矩阵单元上下文（0x21134 后处理 +0x3C/+0x28 槽）。', 'likely', tags=['matrix'])
F(0x022006, 'boot_key_scan', V, [('undefined2', 'k')],
  '开机键扫描：0xF046=1 后 0x2207E(5ms) 轮询，0xF040==0x7B 时调整键码。',
  'strong', tags=['boot'])
F(0x0231C0, 'mode_switch_entry', V, [('char', 'm')],
  '模式切换入口：记录 0xD11E，按 0xD111/0xD114 选择 0x2A99C 等复位流程。',
  'likely', tags=['ui'])
F(0x023518, 'is_noop_mode', 'byte', [('undefined2', 'k')],
  '判断当前模式是否无需处理（0xD117 bit4 / 0x1EB86）。', 'likely', tags=['ui'])
F(0x0235B8, 'stat_cell_edit', V, [],
  '统计表单元格编辑：按 0xD169 与 0xDDB0 状态调用 0xFB98/0xD806/0xDDB0。',
  'likely', tags=['app'])

F(0x023B70, 'kdf_chain_42ba', 'ushort', [('byte', 'idx')],
  '沿 0x42BA 表遍历（最多 10 步），返回终止项值。', 'likely', tags=['setup'])
F(0x02446E, 'kdf_chain_42b8', 'ushort', [('byte', 'idx')],
  '沿 0x42B8 表遍历（最多 10 步），返回终止项值。', 'likely', tags=['setup'])
F(0x023CCE, 'mode_state_init', V, [('char', 'm'), ('char', 'flag')],
  '按模式 m 初始化 0xD012..0xD017/0xD138/0xD169 状态并设置 0xD137。',
  'strong', tags=['ui'])
F(0x023E02, 'key_28_handler', V, [],
  '键码 0x28 处理：按 0xD1xx 状态分支（0x1F574 读键）。', 'likely', tags=['key'])
F(0x0244B2, 'draw_fraction_bars', V, [],
  '按 0xD112 绘制分数/等号结构（0x152D/0x155D/0x158D 等固定位置）。',
  'likely', tags=['display'])
F(0x02452C, 'call_eb40', V, [], '以 0xEB40/0xEB3E 调用 0x26A1C 等（按 0x26892 选择）。',
  'likely', tags=['ui'])
F(0x024622, 'fill_grid', V, [('char', 'v')],
  '双层循环把网格区域填充为 v（行 × 列）。', 'likely', tags=['ui'])

F(0x024DB4, 'draw_empty_line', V, [], '绘制空行缓冲（"1:" 前缀、0xD137=0xE）并刷新。',
  'likely', tags=['editor'])
F(0x025276, 'menu_eb15_loop', V, [], '以 0xEB15 启动 0xE21E 的菜单循环（返回 3 时继续）。',
  'likely', tags=['ui'])
F(0x026184, 'var_slot_init', V, [],
  '按 0x1D800 结果初始化变量槽（0xD118/0xD166/0xD14E）并调用 0x23780。',
  'likely', tags=['var'])
F(0x02627A, 'is_matrix_list', 'byte', [], '判断 0xE 模块下是否处于列表/矩阵视图。',
  'likely', tags=['matrix'])
F(0x0262BA, 'menu_code_map', 'ushort', [('byte', 'k')],
  '把菜单键码（0x77/0x78/0x79 等）映射成菜单项码（0x45/0x46/0x47）。',
  'strong', tags=['ui'])
F(0x026362, 'token_insert_pos', 'byte', [('byte*', 'tok')],
  '按 token 类别计算插入位置并调用 0xC9F2/0x1F12E/0xD172。', 'likely', tags=['editor'])

F(0x0268AA, 'mat_cell_apply', V, [('byte*', 'p')],
  '矩阵单元应用：按 0x27284 的输入把值写入单元（含类型转换）。', 'likely', tags=['matrix'])
F(0x026924, 'edit_word_insert', V, [('byte*', 'src')],
  '把编辑词插入 0xD144 编辑行（0xAF74/0xD4C8/0x15E98/0x2A886/0x2A9EA 校验）。',
  'likely', tags=['editor'])
F(0x026F24, 'stat_grid_clear', V, [],
  '统计网格重绘：清屏后从 0xD163 起逐行清空（0x400 缓冲）。', 'strong', tags=['app'])
F(0x02719C, 'stat_table_page', V, [],
  '绘制统计表格页：清屏、0xBC7A 表头、按 0xD163 分页。', 'strong', tags=['app'])
F(0x02781C, 'list_paint', V, [],
  '列表绘制（按 0xD114/0xD115/0xD116 状态与 0x28576）。', 'likely', tags=['ui'])
F(0x027A7A, 'list_refresh', V, [],
  '列表刷新：0x20D10 检查后按 0xD114 状态重绘当前列表。', 'likely', tags=['ui'])
F(0x027DEE, 'draw_ram_banner', V, [],
  '按 0x38A8 表取行数后绘制（内存/变量列表横幅）。', 'likely', tags=['ui'])

F(0x0283C6, 'draw_cursor_box', V, [],
  '按光标行列（R0 低/高字节）计算位置并画四角（0xBC-0xBF）光标框。',
  'strong', tags=['ui'])
F(0x028244, 'input_line_sync', V, [('byte**', 'p')],
  '同步编辑行：0x20D10 检查后按 0xD114/0xD116 选择 0x9B98/0x203C2 复制。',
  'likely', tags=['editor'])
F(0x0284EC, 'list_cursor_move', V, [],
  '列表光标移动：按 0xC640 行数与 0xD154 当前位置更新。', 'likely', tags=['ui'])
F(0x028824, 'stat_row_prep', V, [],
  '统计行准备：清 0x20 字节与缓冲，按 0xD134 取行偏移（0xDCFA 使用）。',
  'likely', tags=['app'])
F(0x029358, 'table_shape_draw', V, [],
  '按 0xD132/0xD167/0xD168 绘制表格形状与数据（0xF746 使用）。', 'likely', tags=['app'])
F(0x02A074, 'matrix_set_value', V, [('byte', 'idx')],
  '按单元数据计算索引并把值写入矩阵单元（0x1D550，0xC85A/0xDAA4 使用）。',
  'likely', tags=['matrix'])
F(0x02B8E8, 'table_nav_switch', V, [('undefined2', 'k')],
  '表格导航切换：0x1EB86/0x26892/0xEC04/0x8E6E 判断后按 0xD10E 处理。',
  'likely', tags=['app'])
F(0x02B97C, 'table_edit_enter', V, [('undefined2', 'k')],
  '进入表格编辑：0x9972 初始化后 0x177DA 建立矩阵单元，0x23C9A 更新。',
  'likely', tags=['app'])

F(0x009972, 'draw_input_line', V, [('undefined*', 'p')],
  '绘制输入行：按 0xD111/0xD115/0xD116 选择 0x203C2 复制行内容（0xE5A 区）。',
  'likely', tags=['editor'])
F(0x00B848, 'cell_pos_calc', 'ushort', [('byte', 'a'), ('byte', 'b')],
  '按行列差（下溢归 0）计算单元格位置（0x262B0 取大）。', 'likely', tags=['matrix'])
F(0x00B8A6, 'table_add_row', V, [('ushort', 'v')],
  '统计表追加行：0xD0F6 行数 × 行宽（10/20）搬移，0x1D1C6 换算，0x23D28 收尾。',
  'strong', tags=['app'])
F(0x00F1E0, 'memmove_range', V, [('ushort', 'to')],
  '把 from..to 区间搬移（交换上下界后 0xF2C2 计算偏移），用于行/列移动。',
  'likely', tags=['util'])
F(0x00F250, 'interpolate_18', V, [],
  '18 点插值：循环 0x1D9A8 与倍乘（0x13858 开方迭代使用）。', 'likely', tags=['bcd'])
F(0x00F30E, 'table_cell_addr', V, [],
  '按 0xD0F6 与每行单元数计算表格单元格地址（0xDCB0/0x8F48）。',
  'likely', tags=['app'])

F(0x00F672, 'bcd_compare_print', V, [('char', 'mode')],
  '比较两个 BCD 并打印结果：0x2A428 构造格式、0x1C894/0x1D620 比较。',
  'likely', tags=['bcd'])
F(0x010B12, 'eval_diff_abs', 'ushort', [],
  '求两个操作数之差的绝对值（0x1D89E 取值后相减并取补）。', 'likely', tags=['eval'])
F(0x010E58, 'matrix_seed_dims', V, [('short', 'er0')],
  '从 0xFFF8 表逐项 0x22492 载入矩阵维度（6 项写入 +0x0B 起）。',
  'likely', tags=['matrix'])
F(0x011140, 'dec_op_seq_c', V, [],
  '矩阵单元运算序列 C（0xB4/0xA0 操作数 0x1C86C 链）。', 'likely', tags=['matrix'])

F(0x011B6E, 'stat_func_v', 'byte', [], '统计函数族 V（0x12650 循环驱动）。', 'likely', tags=['app'])
F(0x011BD6, 'stat_func_w', 'byte', [], '统计函数族 W（0x12650 循环驱动）。', 'likely', tags=['app'])
F(0x011C3E, 'stat_func_x', 'byte', [], '统计函数族 X（0x12650 循环驱动）。', 'likely', tags=['app'])
F(0x011CA6, 'stat_func_y', 'byte', [], '统计函数族 Y（0x12650 循环驱动）。', 'likely', tags=['app'])
F(0x011D0E, 'stat_func_z', 'byte', [], '统计函数族 Z（0x12650 循环驱动）。', 'likely', tags=['app'])
F(0x011A08, 'stat_wrap_v', 'byte', [('undefined2', 'a')], '统计函数 V 的包装（0x11B6E + 0x11F50）。',
  'likely', tags=['app'])
F(0x011A30, 'stat_wrap_w', 'byte', [('undefined2', 'a')], '统计函数 W 的包装（0x11BD6 + 0x11F50）。',
  'likely', tags=['app'])
F(0x011A62, 'stat_wrap_z', 'byte', [('undefined2', 'a')], '统计函数 Z 的包装（0x11D0E + 0x11F50）。',
  'likely', tags=['app'])
F(0x011ACA, 'stat_wrap_x', 'byte', [('undefined2', 'a')], '统计函数 X 的包装（0x11C3E + 0x11F50）。',
  'likely', tags=['app'])
F(0x011B14, 'stat_wrap_x2', 'byte', [('undefined2', 'a')], '统计函数 X 的包装变体。',
  'likely', tags=['app'])
F(0x011B46, 'stat_wrap_y', 'byte', [('undefined2', 'a')], '统计函数 Y 的包装（0x11CA6 + 0x11F50）。',
  'likely', tags=['app'])

F(0x011F50, 'stat_entry_common', 'byte', [('undefined2', 'a')],
  '统计函数公共入口：0x1D5B6 比较后调用 0x11D76/0x11EF4 等序列。',
  'likely', tags=['app'])
F(0x011D76, 'stat_seq_1', V, [], '统计运算序列 1（局部 BCD 槽）。', 'likely', tags=['app'])
F(0x011EF4, 'stat_seq_2', V, [], '统计运算序列 2（局部 BCD 槽）。', 'likely', tags=['app'])
F(0x012008, 'stat_load_row_a', V, [], '统计载入行 A（0x8F34/0x8EF2 取行数据）。',
  'likely', tags=['app'])
F(0x01204A, 'stat_load_row_b', V, [], '统计载入行 B（0x8F34/0x8EF2）。', 'likely', tags=['app'])
F(0x0124AE, 'stat_menu_blk', V, [], '统计菜单块（0x129F6/0x12832 后按 R12 选择）。',
  'likely', tags=['app'])

F(0x00975A, 'table_cell_edit', V, [],
  '统计表单元格编辑循环（0xD114=1、0xD154=1，0x2AC7C 重绘，读键刷新）。',
  'strong', tags=['app'])
F(0x00ADCE, 'buffer_transfer', V, [],
  '缓冲区搬运：在 0xD180 与 0xE5A 区之间复制编辑行（0x9972/0xED28/0x24A20 使用）。',
  'likely', tags=['editor'])
F(0x00B1EC, 'table_key_dispatch', V, [],
  '表格模式按键分派（按 0xD015 与 0xD144 行内容）。', 'likely', tags=['app'])
F(0x00BDC2, 'draw_table_row', V, [],
  '绘制表格行（5.2KB）：按行类型绘制标签/数值（0x2BA30 列表调用）。',
  'likely', tags=['app'])
F(0x00C438, 'matrix_mode_key', V, [],
  '矩阵模式按键处理（按 0xD114==0x12 与键值分派，0xCDE8 插入行等）。',
  'likely', tags=['matrix'])

F(0x00C640, 'table_row_count', 'byte', [],
  '返回当前表格/列表的行数（0x20E7A 句柄非空时遍历 0xB3DC）。', 'strong', tags=['app'])
F(0x00C726, 'table_cell_key', V, [],
  '统计单元格按键（按 0xD112 列与 0xD136 类型分派）。', 'likely', tags=['app'])
F(0x00C85A, 'table_nav_row', V, [('byte*', 'p')],
  '表格行导航（0x2A074 写值、0xDAA4 配合），4.2KB。', 'likely', tags=['app'])
F(0x00C9F2, 'insert_word_at', V, [('undefined2*', 'a')],
  '在编辑位置插入词元并重排 token（4.2KB，0xF3E4/0x22CA0 调用）。',
  'strong', tags=['editor'])
F(0x00CED6, 'row_value_edit', V, [],
  '行值编辑：memcpy 0xD144 后循环 0xAF74 解析 token（0x29614 使用）。',
  'likely', tags=['editor'])
F(0x00D544, 'hist_loop', V, [('short', 'arg')],
  '历史/计算循环（0xB342/0xA16E/0x22A8C/0x2AA76 组合）。', 'likely', tags=['ui'])

F(0x00D548, 'matrix_dispatch', V, [],
  '矩阵模式主分派（5.4KB，0x14C5E/0x14E38/0x14ECE 等矩阵编辑调用）。',
  'likely', tags=['matrix'])
F(0x00E442, 'token_list_draw', V, [],
  '令牌列表绘制（4.7KB，0xC85A/0xDAA4/0x1E99E 使用）。', 'likely', tags=['editor'])
F(0x00EE2A, 'main_loop', V, [],
  '主循环（7.4KB）：按 0xD111 模式分派 0x9D94/0x29B58/0xD968/0xDC66/0xB810 等。',
  'strong', tags=['boot'])
F(0x00F952, 'matrix_print_fmt', V, [],
  '矩阵打印格式（4.8KB，0x15828 调用）。', 'likely', tags=['matrix'])
F(0x0106A0, 'eval_func_args', V, [],
  '函数参数求值（2.8KB，0x100BC/0x1010C/0x10118 调用）。', 'likely', tags=['eval'])

F(0x01074C, 'eval_compare_op', V, [], '比较运算求值（0x10B3E 逻辑段后 0x1D9EC 链）。',
  'likely', tags=['eval'])
F(0x010764, 'eval_conv_op', V, [], '转换/取整求值（0x1D66E 初始 + 参数槽）。', 'likely', tags=['eval'])
F(0x0107F4, 'eval_round_op', V, [], '数值取整/舍入求值（0x1D66E(1) 链）。', 'likely', tags=['eval'])
F(0x010806, 'eval_round_op_b', V, [], '数值取整/舍入求值变体（1..n 参数）。', 'likely', tags=['eval'])
F(0x01109E, 'matrix_eval_all', V, [('undefined2*', 'a')],
  '矩阵整体求值（1.1KB）：按单元类型 4 分派 0x112CA/0x1125E/0x111BC/0x11140/0x11474。',
  'likely', tags=['matrix'])
F(0x0112CA, 'matrix_cell_pow', V, [], '矩阵单元乘方（0x113..）。', 'likely', tags=['matrix'])
F(0x011474, 'matrix_cell_int', V, [], '矩阵单元取整操作。', 'likely', tags=['matrix'])
F(0x0114F6, 'matrix_cell_chain', V, [], '矩阵单元链式求值（0x12650 循环）。', 'likely', tags=['matrix'])
F(0x0115E2, 'matrix_eval_wrap', V, [('undefined2*', 'a')],
  '矩阵求值包装：0x1109E 后把结果整理写回（0x1D6A4 收尾）。', 'likely', tags=['matrix'])

F(0x012098, 'mat_cell_binary_a', V, [], '矩阵单元二元运算 A（2.3KB，0x1D730/0x1CF54 链）。',
  'likely', tags=['matrix'])
F(0x0121AC, 'mat_cell_binary_b', V, [], '矩阵单元二元运算 B（2.7KB）。', 'likely', tags=['matrix'])
F(0x013AEA, 'matrix_core_a', V, [], '矩阵单元运算核心 A（2KB）。', 'likely', tags=['matrix'])
F(0x013AF0, 'matrix_core_b', V, [], '矩阵单元运算核心 B（2.2KB，0x13B5E 调用）。',
  'likely', tags=['matrix'])
F(0x013B6C, 'matrix_core_c', V, [], '矩阵单元运算核心 C（2.4KB，0x13BF2/0x13BFA 调用）。',
  'likely', tags=['matrix'])
F(0x013C02, 'matrix_core_d', V, [], '矩阵单元运算核心 D（3.6KB，0x14C5E 调用）。',
  'likely', tags=['matrix'])

F(0x016068, 'matrix_eval_big', 'byte', [('undefined2', 'a')],
  '矩阵求值大流程（2KB，0x16D9C 使用）。', 'likely', tags=['matrix'])
F(0x016D9C, 'matrix_eval_dispatch', V, [('undefined2', 'a')],
  '矩阵求值分派（3.1KB，0x170AE/0x171F0 使用）。', 'likely', tags=['matrix'])
F(0x01E11C, 'context_save_restore', V, [('undefined2', 'p')],
  '编辑上下文保存/恢复（0x26A40 与 +7 标志）。', 'likely', tags=['editor'])
F(0x01E1B6, 'stat_edit_loop', V, [],
  '统计编辑循环（0xD114=6、0xD115=1，0x1EBF8 刷新）。', 'strong', tags=['app'])
F(0x01E37C, 'stat_cell_edit2', V, [],
  '统计单元格编辑（按 0x1EF72 的输入分派）。', 'likely', tags=['app'])
F(0x01E3E0, 'mode_menu_draw', V, [],
  '模式菜单绘制（3.8KB，0x27E84 调用）。', 'likely', tags=['ui'])

F(0x01E842, 'var_list_draw', V, [], '变量列表绘制（1.9KB，0x23338 调用）。', 'likely', tags=['ui'])
F(0x01E99E, 'table_row_paint', V, [], '表格行绘制（3.4KB，0xC85A/0xDAA4/0x23648 调用）。',
  'likely', tags=['app'])
F(0x01EACE, 'edit_line_commit', V, [], '编辑行提交（0x2682E 后按状态刷新，0x94DA/0xD3A2/0x2AA0A 调用）。',
  'likely', tags=['editor'])
F(0x01EBF8, 'stat_edit_redraw', V, [], '统计编辑重绘（buffer_clear、0xD137=0xE，0x9D52）。',
  'likely', tags=['app'])
F(0x01ECFA, 'token_scan', 'byte', [('byte', 'mode')],
  'token 扫描（1.4KB）：按类别 2/3/4 移动，返回下一个 token 偏移。',
  'strong', tags=['parser'])
F(0x01EF72, 'edit_value_pick', V, [], '编辑值拾取（3.9KB，0xC0DA/0x1E76E 使用）。',
  'likely', tags=['editor'])

F(0x01F12E, 'token_replace_range', V, [('byte*', 'a')],
  'token 区间替换（1.4KB，0x22BF4 调用；含合并子入口与原文本丢失的一处 0x7F）。',
  'likely', tags=['editor'])
F(0x01F6C6, 'mode_switch_refresh', V, [],
  '模式切换刷新（4.1KB，0x2452C/0x2557A/0x26332 等使用，含合并子入口）。',
  'strong', tags=['ui'])
F(0x01F8C8, 'input_line_editor', V, [('byte*', 'p')],
  '输入行编辑器（1.6KB，0xC438 调用）。', 'likely', tags=['editor'])
F(0x01FCBE, 'mode_paint', V, [], '按模式绘制主界面（1.3KB，0x2209E/0x288EE 调用）。',
  'likely', tags=['ui'])
F(0x01FE7E, 'menu_scroll', V, [], '菜单滚动（1.3KB，0x975A/0x2B00A 使用）。', 'likely', tags=['ui'])

F(0x020000, 'eval_expr_main', V, [], '表达式求值主流程（4.1KB，0x2021C 入口）。',
  'strong', tags=['eval'])
F(0x0202C6, 'draw_token_rich', V, [('undefined2', 'a')], '复杂 token 绘制（2KB，0x2B4FC 调用）。',
  'likely', tags=['display'])
F(0x020710, 'draw_token_plain', V, [('byte*', 'tok')], '普通 token 绘制（3.1KB，0xED7C 调用）。',
  'likely', tags=['display'])
F(0x0208A6, 'parse_number_str', 'char*', [('char*', 's')],
  '解析以 "1" 开头的数字串（0x208A6，0x256E0/0x29E38/0x2B4FC 使用）。',
  'likely', tags=['parser'])
F(0x0209EE, 'draw_cell_value', V, [('byte*', 'p')],
  '绘制单元格值（按 +0x12/+0x14 数据）。', 'likely', tags=['app'])
F(0x020AA8, 'matrix_edit_hook', V, [], '矩阵编辑钩子（1.9KB，0xD117 bit4 判断）。',
  'likely', tags=['matrix'])
F(0x020B94, 'table_cell_key2', V, [('undefined2', 'k')],
  '表格单元按键（0xD111==E/0xD112==4 时 0x284EC）。', 'likely', tags=['app'])

F(0x02102E, 'matrix_entry_main', V, [], '矩阵输入主流程（3.5KB，0x280B0 调用）。',
  'likely', tags=['matrix'])
F(0x021280, 'stat_entry_main', V, [], '统计编辑主流程（1.9KB，0x21342 调用）。',
  'likely', tags=['app'])
F(0x021342, 'stat_edit_main', V, [], '统计编辑主体（2.8KB，0x2153C 调用）。',
  'likely', tags=['app'])
F(0x02253E, 'table_edit_main', V, [], '表格编辑主流程（3.4KB，0x23088/0x2BA30 调用）。',
  'likely', tags=['app'])
F(0x02292E, 'table_key_router', V, [('undefined2', 'k')],
  '表格/统计按键路由（2.9KB，0x247BE 调用；含 0x22980 跳表）。',
  'strong', tags=['app'])
F(0x022B82, 'stat_edit_entry', V, [], 'STAT 编辑入口（1.4KB，0xC0DA/0xD3A2/0xD82E 使用）。',
  'likely', tags=['app'])
F(0x022BF4, 'menu_open', V, [('char', 'which')],
  '打开/关闭菜单层（1.4KB，0xC9F2/0xCD20/0x23BD6 使用，含合并子入口）。',
  'strong', tags=['ui'])
F(0x022CA0, 'token_paste_check', V, [('byte*', 'p')],
  '粘贴前 token 检查（1.9KB，0xAFAE 使用）。', 'likely', tags=['editor'])

F(0x023088, 'base_mode_loop', V, [], '进制（BASE-N）编辑循环（1.1KB，0x14C5E 调用）。',
  'likely', tags=['mode'])
F(0x02326E, 'stat_func_call', V, [], '统计函数调用分派（1.3KB，0x15A62 调用）。',
  'likely', tags=['app'])
F(0x023338, 'var_editor', V, [], '变量编辑器（3.7KB，0x24728 调用）。', 'likely', tags=['editor'])
F(0x023648, 'table_calc_draw', V, [], '表格计算与绘制（3.1KB，0xDAA4/0x23780 使用）。',
  'likely', tags=['app'])
F(0x023A3E, 'wizard_flow', V, [], '向导流程（1.5KB，无外部调用者）。', 'likely', tags=['ui'])
F(0x023BD6, 'menu_layer', V, [], '菜单层处理（1.7KB，0x9972/0xED28 调用，含合并子入口）。',
  'strong', tags=['ui'])
F(0x023D28, 'table_commit', V, [], '表格提交/重算（2.5KB，0xB8A6 调用）。', 'likely', tags=['app'])
F(0x023E78, 'var_menu', V, [], '变量/矩阵菜单（1.1KB，0x28C10 调用）。', 'likely', tags=['ui'])

F(0x024128, 'wizard_edit', V, [], '向导编辑流程（4.7KB，0x286D4 调用）。', 'likely', tags=['ui'])
F(0x024582, 'stat_matrix_rebuild', V, [], '统计矩阵重建（1KB，0xF746 调用）。', 'likely', tags=['app'])
F(0x024728, 'var_edit_entry', V, [], '变量编辑入口（1.2KB，0x26248/0x2950C 调用）。',
  'likely', tags=['editor'])
F(0x0247BE, 'table_mode_main', V, [], '表格模式主循环（3.6KB，0x975A 调用）。', 'likely', tags=['app'])
F(0x024A20, 'stat_matrix_main', V, [], '统计矩阵主流程（6.4KB，无外部调用者）。',
  'likely', tags=['app'])
F(0x024F00, 'mode_loop_common', V, [], '模式公共循环（5.2KB，0x23088/0x278B6/0x2BA30 使用）。',
  'likely', tags=['mode'])

F(0x025408, 'matrix_edit_loop', V, [], '矩阵编辑循环（3.3KB，0x14FF8 调用）。', 'likely', tags=['matrix'])
F(0x02557A, 'list_mode_loop', V, [], '列表模式循环（3.2KB，0x1F4EC/0x263C8 调用）。', 'likely', tags=['ui'])
F(0x0256E0, 'stat_main_loop', V, [], '统计数据主循环（12KB，0x975A/0xA16E 调用）。',
  'strong', tags=['app'])
F(0x025D7C, 'row_buffer_init', V, [('short*', 'p')],
  '行缓冲初始化（2.1KB，0x9DC8/0xEE2A/0x1DD68 使用）。', 'likely', tags=['editor'])
F(0x026002, 'draw_scroll_grid', V, [], '绘制可滚动网格（1KB）。', 'likely', tags=['app'])
F(0x0260AC, 'edit_field_draw', V, [], '编辑字段绘制（1.4KB，0x1F8C8 调用）。', 'likely', tags=['editor'])
F(0x026248, 'var_edit_loop', V, [], '变量编辑循环（1.2KB）。', 'likely', tags=['editor'])
F(0x02648E, 'token_del_merge', V, [('char*', 'p')],
  'token 删除/合并（1.7KB，0xD2E8 调用）。', 'likely', tags=['editor'])
F(0x026610, 'stat_row_edit', V, [('byte', 'k')],
  '统计行编辑（1.7KB，0x1F25A/0x22A8C 使用）。', 'likely', tags=['app'])
F(0x026784, 'edit_menu_loop', V, [], '编辑菜单循环（1.4KB）。', 'likely', tags=['ui'])
F(0x02696E, 'token_array_find', 'byte', [('char*', 's')],
  '在 token 数组中查找（1.1KB，0xAFAE 使用）。', 'likely', tags=['parser'])

F(0x00C0DA, 'draw_insert_marks2', V, [('byte*', 'p')],
  '行内插入态标记（"h" 分支偏移 2/12）：0xBC08 的配套绘制。', 'likely', tags=['editor'])
F(0x00C3EC, 'edit_ctx_init', V, [('byte*', 'ctx')],
  '初始化 12 字节编辑上下文（0xD180/0xD16C/0xD111/0x29D94/0x28576/0xF716/0x20D10）。',
  'strong', tags=['editor'])
F(0x010EDE, 'mat_slot_copy_a', V, [], '矩阵槽复制 A（0xBE/0xB4 偏移，0x11A62 使用）。',
  'likely', tags=['matrix'])
F(0x010EE8, 'mat_slot_copy_b', V, [], '矩阵槽复制 B（0xC8/0xB4 偏移）。', 'likely', tags=['matrix'])
F(0x0139F2, 'pow_ER4_ER6', V, [], '调用 0x1CF90（乘方族）：ER4/ER6 操作数。', 'verified', tags=['bcd'])
F(0x0139FA, 'pow_ER8_ER12', V, [], '调用 0x1CF90（乘方族）：ER8/ER12 操作数。', 'verified', tags=['bcd'])
F(0x013A8A, 'nop_rt_2', V, [], '空函数（仅 return）。', 'verified', tags=['util'])
F(0x018914, 'nop_rt_3', V, [], '空函数（仅 return）。', 'verified', tags=['util'])
F(0x02113E, 'nop_rt_4', V, [], '空函数（仅 return）。', 'verified', tags=['util'])
F(0x000200, 'bad_entry', V, [], '启动向量区内的无效指令（halt_baddata，Ghidra 仅解析出 101 字节）。',
  'verified', tags=['boot'])
F(0x013ECA, 'call_13cf2', V, [('undefined2', 'er0'), ('undefined2', 'er2')],
  '以原参数调用 0x13CF2（矩阵运算）。', 'likely', tags=['matrix'])
F(0x0143A6, 'copy_from_ER2_to_ER8', V, [], '把 ER2 的 10 字节复制到 ER8（活跃槽）。',
  'verified', tags=['bcd'])
F(0x01898E, 'dec_ratio_core', V, [('undefined2*', 'a'), ('undefined2*', 'b')],
  '比例/除法核心（1KB，0x18C8A/0x18CB6 调用）。', 'likely', tags=['bcd'])

F(0x00A326, 'edit_loop_main', V, [('short', 'arg')],
  '编辑主循环（3.5KB，0x295D6 调用）：读键并分派 0x23A0C/0x24EF2/0x28576 等。',
  'strong', tags=['editor'])
F(0x01F4EC, 'list_toggle', V, [], '列表开关（0xEC04 判定后 0x2557A）。', 'likely', tags=['ui'])
F(0x01F9D4, 'draw_cell_at', V, [('ushort', 'pos'), ('ushort', 'code')],
  '在 (pos, row) 处绘制单元格字符（0x2ABEE 行宽约束）。', 'strong', tags=['editor'])
F(0x01FBE4, 'draw_prompt_pair', V, [], '绘制输入/提示对（0x203C2/0x20E5A）。', 'likely', tags=['ui'])
F(0x01FC30, 'display_editor', V, [('byte**', 'p')],
  '显示编辑器（0xD116=0x80，0xD9BC 后 0x20E5A 复制等）。', 'likely', tags=['editor'])
F(0x01FD88, 'token_class_scan', V, [('byte*', 'p')], '按 token 类别遍历（0x1ECFA 链）。',
  'likely', tags=['parser'])
F(0x01FDC2, 'edit_line_guard', V, [('byte*', 'p')],
  '编辑行守卫：0xD144 备份后按首字节 0x2F/0xA5 等判断是否允许。', 'likely', tags=['editor'])
F(0x01FE22, 'key_state_chain', V, [], '按键状态链（0xB830/0xAF3A/0xC2E2/0x1EBC8 判定）。',
  'likely', tags=['key'])
F(0x02532C, 'draw_row_scroll', V, [], '按 0xD137 与行缓冲偏移绘制滚动行（0x256E0 使用）。',
  'likely', tags=['app'])

F(0x015FCC, 'bcd_pack_r4', V, [], 'BCD 打包：按 R4..R9 半字节组拼（0x15D72 使用）。',
  'likely', tags=['bcd'])
F(0x016E9C, 'mat_set_dims_ptr', V, [], '按索引复制矩阵维度（0x2F08 表，0x22A8C 使用）。',
  'likely', tags=['matrix'])
F(0x016EA4, 'mat_load_cell_ptr', V, [('byte*', 'p')],
  '按 p[0] 低半字节载入矩阵单元维度到 0xD100（0x24A20 使用）。', 'likely', tags=['matrix'])
F(0x026FFA, 'table_calc_page', V, [], '表格计算页绘制（3.4KB，0x28C10 调用）。', 'likely', tags=['app'])
F(0x027284, 'table_edit_main2', V, [], '表格编辑主流程（9.4KB，0x2781C 等调用）。',
  'strong', tags=['app'])
F(0x027742, 'stat_mode_entry', V, [], '统计模式入口（0x2AA76 调用）。', 'likely', tags=['app'])
F(0x0278B6, 'table_view_main', V, [], '表格视图主流程（2KB，0x13CF2 调用）。', 'likely', tags=['app'])

F(0x027AF6, 'table_value_draw', V, [], '按 0xD112 列号绘制表格数值（1.2KB）。', 'likely', tags=['app'])
F(0x027E84, 'sidebar_menu', V, [], '左侧菜单栏绘制（4.6KB，0x2319E/0x263C8 调用）。', 'likely', tags=['ui'])
F(0x02864A, 'edit_key_handler', V, [('undefined2', 'k')], '编辑按键处理（1.2KB）。', 'likely', tags=['editor'])
F(0x0286D4, 'wizard_main', V, [], '向导主流程（1.9KB，0x280B0 调用）。', 'likely', tags=['ui'])
F(0x0288EE, 'list_mode_main', V, [], '列表模式主流程（2.6KB，0x2AA76 调用）。', 'likely', tags=['ui'])
F(0x028C10, 'menu_router_main', V, [], '菜单/视图路由（7.2KB，0x263C8 调用）。', 'strong', tags=['ui'])
F(0x0293D2, 'list_view_main', V, [], '列表视图主流程（2.7KB，0x23A3E 调用）。', 'likely', tags=['ui'])

F(0x029614, 'editor_main', V, [('undefined2', 'a')],
  '编辑器主流程（11KB，0xB1A4 调用），最大化/最小化子入口均在体内。',
  'strong', tags=['editor'])
F(0x029BA8, 'stat_mode_main', V, [], '统计模式主循环（3.6KB，0x27284 调用）。',
  'likely', tags=['app'])
F(0x029E38, 'stat_calc_main', V, [], '统计计算主流程（3.1KB，0x9C40/0x1E842 调用）。',
  'likely', tags=['app'])
F(0x02A13C, 'table_menu_flow', V, [], '表格菜单流程（1.3KB，0x27284 调用）。', 'likely', tags=['app'])
F(0x02A1CE, 'table_edit_flow', V, [], '表格编辑流程（2.8KB，0x1F25A/0x2B00A 调用）。',
  'likely', tags=['app'])
F(0x02A340, 'table_paste', V, [('undefined2*', 'a')],
  '表格粘贴（1.3KB，0xCED6/0x23BD6 调用）。', 'likely', tags=['app'])
F(0x02A472, 'table_copy', V, [('byte*', 'p')],
  '表格复制（3.9KB，0xDCFA/0x1E1B6 调用）。', 'likely', tags=['app'])
F(0x02A6A0, 'table_clear', V, [], '表格清除（3.8KB，0x15650 调用）。', 'likely', tags=['app'])
F(0x02AC7C, 'row_refresh', V, [], '刷新当前行（1.3KB，0x975A/0x98C6 使用）。', 'likely', tags=['app'])
F(0x02AD7A, 'table_restore', V, [], '表格恢复/撤销（1.3KB，无外部调用者）。', 'likely', tags=['app'])
F(0x02AE46, 'table_delete', V, [], '表格删除（4.1KB，0x15650 调用）。', 'likely', tags=['app'])
F(0x02B198, 'matrix_calc_main', V, [], '矩阵计算主流程（6.8KB，0x256E0 调用）。',
  'likely', tags=['matrix'])
F(0x02B434, 'matrix_store', V, [], '矩阵存储（1.7KB，无外部调用者）。', 'likely', tags=['matrix'])
F(0x02B4FC, 'token_to_text', 'char', [('byte*', 'tok')],
  '把 token 转成可显示文本（9KB，0xED7C/0x23780 使用）。', 'strong', tags=['parser'])
F(0x02BA30, 'menu_numeric_from_table', 'undefined2', [('byte', 'k')],
  '表格/列表菜单数字键处理（2.4KB，0x13CF2 调用）。', 'likely', tags=['app'])
F(0x02BBA6, 'table_edit_flow2', V, [], '表格编辑流程变体（3.8KB，0xDCFA/0x1F25A 调用）。',
  'likely', tags=['app'])

# ===========================================================================
# 全局变量
# ===========================================================================
GLOBALS = {
 'd000': ('dec_accum0', 'undefined8', 'BCD 运算累加器（0xD000..0xD009）'),
 'd002': ('dec_accum1', 'undefined2', 'BCD 运算寄存器 1'),
 'd004': ('dec_accum2', 'undefined2', 'BCD 运算寄存器 2'),
 'd006': ('dec_accum3', 'undefined2', 'BCD 运算寄存器 3'),
 'd008': ('dec_accum4', 'undefined2', 'BCD 运算寄存器 4'),
 'd009': ('dec_flags', 'byte', 'BCD 运算状态（间接结果标志）'),
 'd00a': ('dec_accum6', 'undefined2', 'BCD 运算寄存器 6'),
 'd00b': ('dec_accum7', 'byte', 'BCD 运算寄存器 7'),
 'd00c': ('dec_accum8', 'undefined8', 'BCD 运算寄存器 8'),
 'd00e': ('dec_temp_a', 'undefined2', 'BCD 临时寄存器 A'),
 'd010': ('dec_regY', 'undefined8', 'BCD 寄存器 Y（10 字节，与 X 同构，0xD010..0xD019）'),
 'd011': ('dec_regY_1', 'byte', '寄存器 Y 第 1 字节（类型/符号）'),
 'd012': ('dec_regY_mant', 'undefined8', '寄存器 Y 尾数（0xD012..0xD019）'),
 'd020': ('dec_regP', 'undefined8', 'BCD 寄存器 P（中间结果，0xD020..0xD029）'),
 'd022': ('dec_regP_mant', 'undefined8', '寄存器 P 尾数（0xD022..0xD029）'),
 'd02a': ('dec_align_tmp', 'undefined2', '对齐运算尾数暂存（0xD02A..0xD031）'),
 'd02e': ('dec_round_flag', 'byte', '舍入结果标志（5=需要再舍入/进一位，0x80=已处理）'),
 'd01e': ('dec_opcode', 'ushort', 'BCD 运算操作码：0=取负/取整 1=1/x 2=tan 4=xor 5=or 6=乘方/exp 7=and 8=除 9=乘 0x0E=log 0x0F=10^x 0x11/0x12=开方 0x13=乘方'),
 'd01f': ('dec_phase', 'byte', '运算阶段/分支选择（9=对齐、10=规整、12=特殊值）'),
 'd01c': ('dec_stage', 'byte', '运算阶段号'),
 'd01a': ('dec_scale', 'byte', '运算缩放/指数修正量'),
 'd02f': ('angle_mode', 'byte', '角度模式：0..4 弧度制各档，5=度制'),
 'd10e': ('input_key', 'undefined2', '最近按键码（KI/KO 组合；0xFCxx 为扩展键）'),
 'd140': ('key_hist_c', 'byte', '按键历史 C'),
 'd148': ('key_hist_d', 'byte', '按键历史 D'),
 'd018': ('dec_regY_tail', 'undefined8', '寄存器 Y 尾数后半 + 指数（0xD018..0xD01F）'),
 'd019': ('dec_flags_Y', 'byte', '寄存器 Y 类型/标志（0x10=负，0x80=零；>9 为特殊值）'),
 'd050': ('dec_regW', 'undefined8', 'BCD 寄存器 W（返回槽，0xD050..0xD059）'),
 'd058': ('dec_regW_tail', 'undefined8', '寄存器 W 尾数后半 + 指数（0xD058..0xD05F）'),
 'f310': ('int_ctrl4', 'byte', '中断控制 4'),
 'ddec': ('line_buf', 'byte[0x18]', '行缓冲（屏幕行缓存）'),
 '38a8': ('mode_count', 'byte', '模式总数'),
 '5a92': ('keytab_menu', 'ushort[64]', '系统/设置菜单键位白名单表'),
 '775c': ('keytab_comp', 'ushort[64]', 'COMP 模式键位映射表'),
 '62e2': ('keytab_stat', 'ushort[64]', 'STAT 模式键位映射表'),
 '3668': ('keytab_table', 'ushort[64]', 'TABLE 模式键位映射表'),
 '3bf2': ('keytab_cplx', 'ushort[64]', '复数线性模式键位映射表'),
 '0a10': ('keytab_shift', 'ushort[64]', 'SHIFT 修饰键位表'),
 '198e': ('keytab_alpha', 'ushort[64]', 'ALPHA 修饰键位表'),
 '582c': ('keytab_filter1', 'ushort[64]', '按键白名单 1'),
 '52e8': ('keytab_filter2', 'ushort[64]', '按键白名单 2'),
 '386c': ('keytab_filter3', 'ushort[64]', '按键白名单 3'),
 '5896': ('keytab_filter4', 'ushort[64]', '按键白名单 4'),
 '7dda': ('keytab_filter5', 'ushort[64]', '按键白名单 5'),
 '4a84': ('mode_names', 'ushort[5][2]', '五个菜单页面的标题字符串指针表'),
 '3a4a': ('diag_info', 'byte[8][16]', '自检页信息表'),
 '42a6': ('expr_op_table', 'byte[10][12]', '表达式运算符描述表'),
 '42b8': ('expr_op_a', 'ushort', '表达式运算符子字段 A'),
 '42ba': ('expr_op_b', 'ushort', '表达式运算符子字段 B'),
 '42bc': ('expr_op_c', 'ushort', '表达式运算符子字段 C'),
 '42be': ('expr_op_d', 'ushort', '表达式运算符子字段 D'),
 'd0ef': ('gfx_tmp', 'byte', '图形临时'),
 'd160': ('input_saved', 'byte', '输入保存标记'),
 'd014': ('irq_pending_shadow', 'byte', '中断待处理快照'),
 'd015': ('edit_state', 'byte', '编辑器/撤销状态'),
 'd016': ('display_dirty', 'byte', '显示脏标志'),
 'd01d': ('calc_state_a', 'byte', '计算状态 A'),
 'd01e': ('dec_opcode', 'byte', 'BCD 运算操作码（6/7/8/9）'),
 'd01f': ('calc_state_b', 'byte', '计算状态 B'),
 'd020': ('calc_state_c', 'byte', '计算状态 C'),
 'd028': ('calc_state_d', 'byte', '计算状态 D'),
 'd030': ('calc_state_e', 'byte', '计算状态 E'),
 'd032': ('calc_state_f', 'byte', '计算状态 F'),
 'd038': ('calc_state_g', 'byte', '计算状态 G'),
 'd03a': ('dec_tmp_flag', 'byte', 'BCD 运算临时标志'),
 'd05a': ('dec_work_a', 'byte', 'BCD 工作区'),
 'd05c': ('dec_param_a', 'undefined2', 'BCD 运算参数 A 指针'),
 'd05e': ('dec_param_b', 'undefined2', 'BCD 运算参数 B 指针'),
 'd0f4': ('base_addr', 'undefined2', '计算器 RAM 基址（由 0x8CA8 计算）'),
 'd0f5': ('diag_mode', 'byte', '诊断/自检画面标志'),
 'd0f6': ('var_scroll', 'byte', '变量列表滚动位置'),
 'd0f7': ('display_ctrl', 'byte', '显示控制（bit0 刷新）'),
 'd110': ('status_bits', 'byte', '状态栏图标开关位'),
 'd111': ('calc_mode', 'byte', '计算器模式字（2=COMP,3=TABLE,6=STAT,0x45=BASE,0x4A=EQUA,0x4B=MATRIX,0x88=RATIO 等）'),
 'd112': ('calc_submode', 'byte', '模式子状态（矩阵 5=编辑，STAT 见 0xD115）'),
 'd149': ('mat_cols', 'byte', '矩阵列数记忆') ,

 'd112': ('sub_mode', 'byte', '子模式编号（各模式下含义不同）'),
 'd113': ('input_layout', 'byte', '输入布局 / 键盘映射选择'),
 'd114': ('edit_state2', 'byte', '编辑/计算状态'),
 'd115': ('stat_state', 'byte', 'STAT 模式状态'),
 'd116': ('key_modifiers', 'byte', '按键修饰状态（SHIFT/ALPHA 等）'),
 'd117': ('key_history_flags', 'byte', '按键历史标志'),
 'd118': ('key_hist_a', 'byte', '按键历史 A'),
 'd119': ('key_hist_b', 'byte', '按键历史 B'),
 'd11a': ('menu_sel_a', 'byte', '菜单选择 A'),
 'd11c': ('menu_toggle', 'byte', '菜单切换位'),
 'd11d': ('menu_sel_b', 'byte', '菜单选择 B'),
 'd11e': ('menu_io', 'byte', 'Math 输入输出设置'),
 'd121': ('var_list_open', 'byte', '变量列表打开标志'),
 'd122': ('menu_state_a', 'byte', '菜单状态 A'),
 'd123': ('menu_state_b', 'byte', '菜单状态 B'),
 'd124': ('menu_state_c', 'byte', '菜单状态 C'),
 'd125': ('menu_state_d', 'byte', '菜单状态 D'),
 'd126': ('history_recall', 'byte', '历史记录调阅标志'),
 'd127': ('menu_state_e', 'byte', '菜单状态 E'),
 'd129': ('prev_line', 'byte', '上一显示行'),
 'd12a': ('key_state_a', 'byte', '按键状态 A'),
 'd12b': ('menu_sel_c', 'byte', '菜单选择 C'),
 'd132': ('input_disp_mode', 'byte', '输入显示模式'),
 'd133': ('saved_line', 'byte', '保存的行号'),
 'd134': ('list_page', 'byte', '列表页号（光标三元组页，1 起）'),
 'd135': ('list_col', 'byte', '列表列号（光标三元组 X，1 起）'),
 'd136': ('list_row', 'byte', '列表行号（光标三元组 Y，1 起）'),
 'd137': ('cur_line', 'byte', '当前显示行（输入行号 / 状态行）'),
 'd138': ('cursor_visible', 'byte', '光标可见标志'),
 'd139': ('draw_target', 'byte', '绘图目标缓冲（0=E3D4 子缓冲，1=DDD4 主缓冲）'),
 'd13a': ('key_flags', 'byte', '键盘状态位'),
 'd13d': ('stat_var_num', 'byte', 'STAT 变量号'),
 'd13e': ('history_dirty', 'byte', '历史记录脏标志'),
 'd13f': ('disp_mode', 'byte', '显示模式（固定/科学/普通/分数）'),
 'd141': ('kbd_repeat', 'byte', '按键重复标志'),
 'd142': ('stat_sel', 'byte', 'STAT 模式选择'),
 'd144': ('input_ptr', 'undefined8', '输入区指针（当前编辑位置）'),
 'd146': ('input_end_ptr', 'undefined8', '输入区结束指针'),
 'd149': ('ratio_unit', 'byte', 'RATIO 单位选择'),
 'd14c': ('output_fmt', 'byte', '输出数字格式'),
 'd14e': ('mixed_fraction', 'byte', '带分数显示标志'),
 'd150': ('last_key', 'undefined2', '最近按键码'),
 'd152': ('ratio_flags', 'byte', 'RATIO 模式标志'),
 'd153': ('contrast', 'byte', 'LCD 对比度'),
 'd154': ('menu_index', 'byte', '当前菜单项索引'),
 'd155': ('history_cursor', 'byte', '历史记录游标'),
 'd156': ('history_key', 'byte', '历史记录按键偏移'),
 'd158': ('hl_line', 'byte', '高亮行'),
 'd159': ('hl_col', 'byte', '高亮列'),
 'd15c': ('stored_a', 'byte', '暂存 A'),
 'd15d': ('stored_b', 'byte', '暂存 B'),
 'd161': ('mode_index', 'byte', '模式索引（MENU 中）'),
 'd162': ('mode_group', 'byte', '模式组'),
 'd164': ('stat_rows', 'byte', 'STAT 行数'),
 'd165': ('stat_cols', 'byte', 'STAT 列数'),
 'd167': ('hl_row2', 'byte', '高亮行 2'),
 'd168': ('hl_col2', 'byte', '高亮列 2'),
 'd169': ('input_active', 'byte', '输入激活标志'),
 'd180': ('input_buf', 'char[200]', '输入区（0xC8 字节）'),
 'd248': ('replay_buf', 'char[200]', '回放区（0xC8 字节）'),
 'd310': ('rand_seed', 'byte[10]', '随机数种子'),
 'd31a': ('var_M', 'dec10', '变量 M'),
 'd324': ('var_Ans', 'dec10', '变量 Ans'),
 'd32e': ('var_A', 'dec10', '变量 A'),
 'd338': ('var_B', 'dec10', '变量 B'),
 'd342': ('var_C', 'dec10', '变量 C'),
 'd34c': ('var_D', 'dec10', '变量 D'),
 'd356': ('var_E', 'dec10', '变量 E'),
 'd360': ('var_F', 'dec10', '变量 F'),
 'd36a': ('var_x', 'dec10', '变量 x'),
 'd374': ('var_y', 'dec10', '变量 y'),
 'd37e': ('var_PreAns', 'dec10', '变量 PreAns'),
 'd388': ('var_at', 'dec10', '变量 @'),
 'd392': ('stat_data', 'byte[0x83E]', 'STAT 数据区'),
 'd400': ('stat_data2', 'byte[0x640]', 'TABLE/STAT 数据区'),
 'd522': ('calc_buf', 'char[200]', '计算缓冲区（按 = 时复制输入区）'),
 'd5ea': ('calc_buf_len', 'byte', '计算缓冲区长度'),
 'd612': ('expr_copy', 'char[100]', '表达式副本'),
 'd6bc': ('tmp_str_a', 'char', '临时字符串 A 起始（0xD6BC..）'),
 'd6b2': ('app_work_area', 'byte[0x140]', '应用模式工作表（0xD6B2..0xD7F1，由 0x15AFE 清零）'),
 'd6ee': ('tmp_str_b', 'char', '临时字符串 B 起始'),
 'd84c': ('replay_save', 'char[200]', '回放保存区'),
 'd8a0': ('pack_buf', 'char[200]', '两两拼合（压缩写入）缓冲区'),
 'dbd0': ('diag_status', 'byte[13]', '诊断/系统状态字节（0x0F..0x00 倒序初值）'),
 'ddd4': ('screen_fb', 'byte[0x600]', '主帧缓冲（64 行 × 24 字节）'),
 'e3d4': ('screen_alt', 'byte[0x600]', '辅助帧缓冲（绘制 4 行文本等）'),
 'f000': ('_dsr', 'byte', 'DSR 数据段寄存器值（0 = 段 0）'),
 'f004': ('chip_ctrl', 'byte', '芯片控制寄存器'),
 'f008': ('stpacp', 'byte', 'STPACP（待机接受）寄存器'),
 'f009': ('sbycon', 'byte', 'SBYCON（待机控制）寄存器'),
 'f00a': ('int_src_ctrl', 'byte', '中断源控制'),
 'f010': ('int_mask', 'ushort', '可屏蔽中断使能掩码'),
 'f012': ('int_ctrl2', 'byte', '中断控制 2'),
 'f014': ('int_pending', 'ushort', '中断待处理标志'),
 'f018': ('int_ctrl3', 'byte', '中断控制 3'),
 'f020': ('timer_interval', 'ushort', '定时器间隔/重装值'),
 'f022': ('timer_counter', 'ushort', '定时器计数器'),
 'f024': ('timer_ctrl', 'undefined2', '定时器控制'),
 'f028': ('port_ctrl', 'byte', '端口控制'),
 'f030': ('lcd_range', 'byte', '屏幕范围寄存器'),
 'f031': ('lcd_mode', 'byte', '屏幕模式寄存器'),
 'f032': ('lcd_contrast', 'byte', '对比度寄存器'),
 'f033': ('port_a', 'byte', '端口 A'),
 'f034': ('port_b', 'byte', '端口 B'),
 'f035': ('port_c', 'byte', '端口 C'),
 'f036': ('port_d', 'byte', '端口 D'),
 'f039': ('port_e', 'byte', '端口 E'),
 'f03d': ('port_h', 'byte', '端口 H'),
 'f042': ('kbd_filter', 'byte', '键盘输入滤波（0xF042）'),
 'f044': ('kbd_komask', 'ushort', '键盘输出掩码（0xF044）'),
 'f046': ('kbd_ko', 'ushort', '键盘输出 KO（0xF046）'),
 'f048': ('timer_aux', 'undefined8', '定时器辅助寄存器'),
 'f049': ('io_flag_x', 'byte', 'I/O 标志 X'),
 'f04a': ('io_flag_y', 'byte', 'I/O 标志 Y'),
 'f04b': ('io_flag_z', 'byte', 'I/O 标志 Z'),
 'f04c': ('io_flag_w', 'byte', 'I/O 标志 W'),
 'f220': ('ext_io1', 'ushort', '外部寄存器 0xF220'),
 'f222': ('ext_io2', 'ushort', '外部寄存器 0xF222'),
 'f224': ('ext_io3', 'byte', '外部寄存器 0xF224'),
 'f800': ('lcd_vram', 'byte[0x800]', 'LCD 显存（64+1 行 × 32 字节）'),
 'f810': ('lcd_cursor_col', 'byte', '光标列（LCD）'),
 'f811': ('lcd_status_x', 'byte', 'LCD 状态 X'),
 'f812': ('lcd_status_y', 'byte', 'LCD 状态 Y'),
 'f815': ('buzzer', 'byte', '蜂鸣器控制位'),
 'f816': ('lcd_refresh_req', 'byte', 'LCD 刷新请求'),
}


def sorted_funcs():
    return [(a, FUNCS[a]) for a in sorted(FUNCS)]


if __name__ == '__main__':
    import collections
    c = collections.Counter(v['conf'] for v in FUNCS.values())
    names = [v['name'] for v in FUNCS.values()]
    dup = [n for n, k in collections.Counter(names).items() if k > 1]
    print('entries:', len(FUNCS), dict(c))
    print('duplicate names:', dup)
    for a, v in sorted_funcs():
        if not v['note']:
            print('missing note:', hex(a), v['name'])