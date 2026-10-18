# casio-main 真实符号与本工程命名的对照

参考来源：`参考-casio-main/labels.txt`（真实符号）、`_disas_commented.txt`（按真实地址的
注释反汇编）、`代码分析.txt`、`内存表.txt`。运行 `python toolchain/calibrate.py` 会打印
同一张对照表（并写 `toolchain/casio_labels.json`），末尾附两路汇编的逐字节核对结果
（`python toolchain/tests/check_asm_parity.py` 是独立版本，可作 CI 检查）。

> **地址可信度**：`labels.txt` 是从另一机型（注释写 “ES PLUS”）的标签自动转换的。
> 58 条符号逐条落到本 ROM 上，绝大多数地址与指令逐字节一致；但 3 处地址在本 ROM
> 中落在函尾填充或陷阱上，见 §4。

## 1. 已确认一致并采用的名字

| 地址 | casio-main 符号 | 本工程名 | 依据 |
|------|-----------------|----------|------|
| 007EAC | `fill_screen` | `fill_screen` | 一致；r1 bit0/1/2 = 清 DDD4 / 实屏 / E3D4 |
| 00821E | `line_print`（r0:col,r1:row,er2） | `line_print` | `_disas_commented` 与 `代码分析.txt` 均给逐指令注释 |
| 008FB8 | `memzero` | `memzero` | 一致 |
| 00916A | `delay` | `delay` | 写 F00A/F022/F024/F014/F008/F009 后写 F020=interval |
| 009A3A | `_memmove_nn` | `memmove` | 一致 |
| 00D070 | `_strcpy_nn` | `strcpy` | `代码分析.txt` 给完整伪代码（er0=dst, er2=src） |
| 00F1A8 | `_memset_n` | `memset` | 一致 |
| 010E58 | `get_serial_num` | `get_serial_num` | 从 0xFFF8 表取 6 项序列号转字符 |
| 0203B8/C2/D6 | `smart_strlen_n` / `smart_strcpy_nn` / `smart_strcat_nn` | `strlen_checked` / `strcpy_checked` / `strcat_checked` | 空指针安全版本 |
| 022040 | `diagnostic_mode` | `diagnostic_mode` | 显示 “DIAGNOSTIC / Press AC” |
| 02209E | `diagnostic` | `diagnostic` | 诊断主流程 |
| 022140 | `diag_check_key` | `diag_check_key` | 自检按键检查 |
| 0221AC | `line_print_font14_col0` | `line_print_font14_col0` | r0:row, er2:char* |
| 0221BC | `diag_scr_fill_ws` | `fill_screen_mode` | 填充后等待 SHIFT |
| 0221CA | `diag_scr_ckb1_ws` | `diag_fill_55aa` | 棋盘格 1 |
| 022226 | `diag_scr_ckb2_ws` | `diag_scr_ckb2_ws` | 棋盘格 2（0xAA） |
| 022250 | `diag_scr_version` | `diag_scr_version` | 版本页绘制 |
| 022278 | `diag_print_ver` | `diag_print_ver` | 打印版本号 |
| 0222AE | `diag_print_pd` | `diag_print_pd` | 被 diag_checksum 调用 |
| 0222D4 | `diag_checksum` | `diag_checksum` | 校验和页主循环 |
| 022382 | `store_reg_to_stack` | `store_reg_to_stack` | r0..r15 -> [er14-16] |
| 022392 | `diag_calc_checksum` | `diag_calc_checksum` | 段 0/1/2 累加，与 0xFFF6 的 A8 04 比较 |
| 022492 | `hex_byte` | `hex_byte` | R0=0xAB -> ER0="AB" |
| 022DC4 | `_memcpy_nn` | `memcpy_bytes` | 栈上传长度 |
| 024E36 | `main` | `main` | 一致 |
| 02536A | `_strlen_n` | `strlen` | 一致 |
| 026226 | `byte_strlen_n` | `strline_len` | strlen，返回字节并跳过行首格式字节 |
| 027BC8 | `diag_8_keytest` | `diag_8_keytest` | 8 键测试页 |
| 02A020 | `_strcat_nn` | `strcat_raw` | 一致 |
| 009D22 / 009D2A | `ENTER` / `LEAVE` | `frame_enter` / `frame_leave` | 语义一致（原注释只提“备份寄存器、设 ER14”） |

## 2. 同址同义、保留本工程的功能性名字

| 地址 | casio-main | 本工程 |
|------|-----------|--------|
| 007F00 | `buffer_clear` | `clear_screen` |
| 0082EC / 0082F6 | `char_print_1byte` / `char_print` | `draw_char_fast` / `draw_char` |
| 0084D8 / 0085B8 | `char_get_14` / `char_get_l14` | `glyph_get_small` / `glyph_get_large` |
| 0086E0 | `buf1_to_buf2` | `fb_to_lcd` |
| 0086F8 / 008704 | `render_e3d4` / `render_ddd4` | `fb_alt_flush` / `fb_flush` |
| 008CA8 | `pd_value` | `get_ram_base` |
| 009060 | `assign_var` | `base_clear` |
| 00939A | `zero_KO` | `kbd_ko_disable` |
| 0093FE / 009402 | `_start`（向量[1]） | `reset_handler` / `reset_entry` |
| 00FBFE | `far_call_stub` | `menu_gate` |
| 01E680 | `diag_scr_888_ws` | `draw_splash_32` |
| 01F1D6 | `diag_serial_num` | `draw_mode_header` |
| 01F99C | `reset_routine` | `ram_clear_all` |
| 01FCBE | `diag_contrast` | `mode_paint` |
| 029D5C | `get_string_constant` | `matrix_item_ptr` |
| 02A048 | `line_print__call__` | `draw_scaled_char` |
| 008BF4 / 008C4A | `str_decompress_print__call__` / `__call1__` | `draw_text4` / `draw_text4x` |

## 3. labels.txt 中的数据标签

`d_0Dxxx` 标签与 `内存表.txt` 的布局一致，已用于全局变量注释：

| 地址 | 符号 | 说明 |
|------|------|------|
| 0xD10E | last function pressed | 最近按键 |
| 0xD110 | modifiers | bit0/bit2 = shift/alpha 按下 |
| 0xD111 | mode | COMP C1 / CMPLX C4 / BASE 02 / MATRIX 06 / VECTOR 07 / STAT 03 / TABLE 88 / EQN 45 / INEQ 4B / RATIO 4A |
| 0xD112 | submode | 子模式 |
| 0xD113 | cur_scr | 0/1/2 = 计算界面 / 模式选择 / 设置 |
| 0xD114 | input_mode | normal1, stat/table12, matrix13, vector14, eqn15, ratio17, ineq18 |
| 0xD11A / D11B | num_format / num_format_i | 8/9/0/4 = Fix/Sci/Norm1/Norm2 |
| 0xD11D | angle_unit | 4/5/6 = Deg/Rad/Gra |
| 0xD11E / D11F | isMathI / frac_result | 数学输入；假分数/带分数 |
| 0xD137 | font_size | 8 / 10(A) / 14(E) |
| 0xD139 | current_screen_buffer | 0 -> E3D4，否则 DDD4 |
| 0xD155 | cursor_position | 0..255 |
| 0xD180.. | input buf | 200 字节输入区 |
| 0xD248.. | cache buf | 200 字节回放区 |
| 0xD310..D319 | random seed | 10 字节随机种子 |
| 0xD31A.. | var_m, var_ans, var_a … | 每变量 10 字节，0x40..0x4F |
| 0xD392..D521 | calc_history | 400 字节历史（每条以 0x23 结尾） |
| 0xD522..D5E9 | undo | 200 字节撤销区 |
| 0xDBD0..DBDF | mem check | 0F0E0D…020100，复位时校验 |
| 0xDDD4 / 0xE3D4 | screen buffers | 各 384 字节 |

SFR（`labels_sfr.txt`，与本 ROM 一致的部分）：`0xF000 DSR`、`0xF008 STPACP`、
`0xF009 SBYCON`、`0xF020 定时器间隔`、`0xF022 计数器`、`0xF024/F025 控制`、
`0xF030..F033 屏幕范围/模式/对比度`、`0xF040 KI`、`0xF042 KI 滤波`、
`0xF044 KO 掩码`、`0xF046 KO`。

## 4. 地址修正与存疑项

1. **`0x821C line_print.col_0`**：本 ROM 该 2 字节是 `0000`（函数脱节的填充），
   紧跟 0x821E 的完整序言，且全 ROM 无 `BL 0x821C`；`0x821E` 才是 `line_print`。
   `_disas_commented.txt` 在这里也标了标签注释，与 labels.txt 一致，说明是转换遗留。
2. **`0x81A2 str_decompress_print`**：同样是填充 `0000`，实现在 0x81A4。
3. **`0x93EC`**：本 ROM 是 `RTI`（宏组件陷阱），不是例程；`0x93FE` 才是外部复位入口。
4. **`0x29D5C get_string_constant`**：labels.txt 自带 `XX INVALID COMMENT`（只有
   `[0xD12B]==0` 才有意义），与本工程“按 0xD12B 索引 ROM 表”的 `matrix_item_ptr` 吻合，待再确认。

## 5. 两路汇编的逐字节核对

`_disas_commented.txt` 是从低到高的**方向扫描**（已解码位置跳过），Ghidra 只沿控制流
解码，两者在“哪些字节是指令”上本就会不同。核对方法：把 `991CN X.汇编.txt` 的每行
字节重组成 ROM，再与参考逐行比较（`tests/check_asm_parity.py`）：

- 参考 59988 条，本工程覆盖 **59914 条（99.88%）**；
- 剩余 74 条全部可解释：向量表（参考把前 4 字节当 SP）、参考方向扫描误判的 `RTI`、
  以及 Ghidra 合并 4 字节指令 / 用 `DSR<-` 旁路 2 字节已知的情况。

比对中确认 Ghidra 有三类“写窄/写残”，已在 `toolchain/rawasm.py` 的 `asm_view()` 中
用参考补齐（纯数据视图，不改动原始文本）：

| 类型 | 例子 | 处理 |
|------|------|------|
| 单字节 `??` 起头的 4 字节指令 | 0xD85E `01 F2 82 2B` | 补成完整 BL |
| 已解码 2 字节 + 高字节另起 `??` 行 | 0x92C8 `08 E3` + `50 92`、0x9408 `AF 90` | 加宽为 4 字节并丢弃残行 |
| 指令与标签并成一行的 `addr` | 0xD84C `011a02  addr LAB_...`、0xD860 | 以参考的编码/助记符为准 |

`代码分析.txt` 的逐函数分解（gadget 偏移、栈参、副作用）也已采纳，补充了
`memcpy_bytes`（栈传 len）、`diag_calc_checksum`（段 0/1/2 + F004）、`hex_byte`
（高低半字节分别输出）等说明。

## 6. `f4a4570`（Sleigh 语言模块）的用途

该提交给的是 Ghidra 的 **nxu8 处理器描述**（`nxu8.slaspec` / `nxu8.cspec`），其中
`callfixup` 明确写出：

- `ENTER`(0x9D22) = `PUSH QR8; PUSH XR4; MOV ER14, SP`，
- `LEAVE`(0x9D2A) = `MOV SP, ER14; POP XR4; POP QR8; POP PC`，

与 §1 的结论一致，可作为帧指针辅助的独立佐证。用该语言模块在 Ghidra 中重新反编译
可以补上 `unaff_ER14` 的可变长栈帧（本工程 `parse.py` 用文本修补解决同一问题，
故未采用）。本仓库不附 Ghidra 工程二进制；复现时把提交中的语言文件夹放进
`Ghidra/Processors/nxu8`，再用 `analyzeHeadless` 导入 ROM 即可。

## 7. 原文中被人工改名的“活名”

`991CN X.ghidra原始.c` 里有几个名字是改名者在编辑时写进调用点的，不是 Ghidra 的
函数声明。生成时由 `build_project.OLD_ACTIVE_NAMES` 还原到真实函数，否则会与命名库
中同名的另一个函数混淆：

| 原文活名 | 真实目标 | 说明 |
|----------|----------|------|
| `delay(...)` | 0x94DA（本工程 `editor_action`） | 原文只有 1 个实参；0x916A 才是 `delay` |
| `stat_analysis` | 0x22A8C（本工程 `stat_analysis`） | 手工插入的统计分析调用 |
| `mode_06_stat_loop` | 0xD968（本工程 `mode_06_stat_loop`） | 手工插入的模式 6 循环引用 |

注意这两个活名与命名库里 0x22A8C / 0xD968 的**函数本身**同名，属于“同一函数在
别处被按名调用”，生成器只在调用位置处理，不会把两个地址混到一起。