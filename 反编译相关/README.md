# 反编译相关

本目录存储 fx-991CN X（及同族机型）的 Ghidra 反编译资源、原始输出与工程化后的逆向结果。

## 目录导航

| 路径 | 说明 |
|------|------|
| **反编译结果_工程化版/** | 工程化版逆向结果：按模块拆分的 C 源码、头文件、索引文档、重建工具链。**从这里开始** |
| 反编译结果/ | Ghidra 导出的原始 C / 汇编文本（工程化版的输入，不参与编译） |
| 参考-casio-main/ | 来自 casio-main 的真实符号表、按地址注释的反汇编、内存表、代码分析笔记 |
| nX-U8 处理器/ | CPU 芯片手册（nX-U8100 指令手册与数据手册）、寄存器说明 |
| rom/ | 真机 ROM（rom.bin、rom_emu.bin 等） |
| tools/ | 早期探索脚本（对齐、ROM 重组、函数表导出） |
| data/、disas.txt、keyboard_io_map.png | 早期整理的数据、汇编转储与键盘 IO 对照图 |
| `Ghidra 的 nX-U8 语言.zip` | 适用于 Ghidra 的 nX-U8 处理器语言模块（LFS 文件，克隆时需拉取 LFS） |
| rename_functions.py、函数名还原记录.md | 早期基于人工注释的改名脚本与记录（已由工程化版 toolchain 取代） |

## 用 Ghidra 反编译

1. 前往 [Ghidra 的发布页](https://github.com/NationalSecurityAgency/ghidra/releases)下载打包好的 Ghidra ZIP 文件；
2. 解压到合适的位置，把 `Ghidra 的 nX-U8 语言.zip` 解压出的语言目录重命名为 `nxu8`，
   放到 `<你的 Ghidra 目录>/Ghidra/Processors/` 下；
3. 用 `rom/rom.bin` 新建工程，处理器选 `nxu8`，开始分析；
4. 入门教程见[《用 Ghidra 分析卡西欧源代码》](https://tieba.baidu.com/p/8938265174)。

> 该语言模块来源为原作者的
> [f4a4570 提交](https://github.com/Physics365/991CN-X-CW-Decompilation/commit/f4a4570bf1dfc8557e7ba9a59fba33a877cdf8f7)
> （`nxu8.slaspec` / `nxu8.cspec`）。其中 `ENTER`(0x9D22) / `LEAVE`(0x9D2A) 的
> `callfixup` 与本工程对帧指针辅助的结论一致。

## 工程化版（推荐入口）

```text
反编译结果_工程化版/
├── 原始反编译结果/   Ghidra 原始 C 与汇编（保存原样）
├── src/              175 个函数源文件，按 16 个模块分目录
├── include/991cnx/   头文件
├── docs/             函数索引、全局变量索引、模块索引、命名方法、符号对照、已知缺陷
└── toolchain/        重建流水线与校验脚本
```

1311 个函数已全部命名。重建方法见
[命名与还原方法](反编译结果_工程化版/docs/命名与还原方法.md)，与外部真实符号的核对见
[casio-main 符号对照](反编译结果_工程化版/docs/casio-main符号对照.md)，Ghidra 文本的已知
缺陷与处理见[反编译结果已知缺陷](反编译结果_工程化版/docs/反编译结果已知缺陷.md)。

## nX-U8 处理器附加资料

本仓库所关注的计算器均使用 nX-U8 CPU，指令集等技术信息见「nX-U8 处理器」目录
（含 nX-U8100 指令手册中英文版与数据手册）。