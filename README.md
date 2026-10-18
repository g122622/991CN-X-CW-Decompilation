![封面](readme_assets/cover.png)

## 简介

这是一个整理 Casio CW i 代和 CW ii 代机型研究的存储库：反编译、ROP、模拟器与资料。

仓库目前**最主要的产出一套可重建的 fx-991CN X 逆向工程**：
ROM 中的 1311 个函数全部完成命名（含参数名与判定依据），从原始 Ghidra 输出到
`src/` / `include/` / `docs/` 的生成流水线可一键重跑，并且函数地址与名字已经用外部
真实符号（casio-main 的 `labels.txt`）和用户说明书逐条核对过。

## 目录

| 目录 | 内容 |
|------|------|
| [反编译相关/反编译结果_工程化版](反编译相关/反编译结果_工程化版) | **工程化版逆向结果**：按模块拆分的 C 源码、头文件、索引文档与重建工具链（见下文） |
| [反编译相关/反编译结果](反编译相关/反编译结果) | Ghidra 导出的原始 C 文本与汇编文本（工程化版的输入） |
| [反编译相关/参考-casio-main](反编译相关/参考-casio-main) | 来自 casio-main 的真实符号表、注释反汇编、内存表、代码分析笔记 |
| [反编译相关/nX-U8 处理器](反编译相关/nX-U8%20处理器) | nX-U8 CPU 的芯片手册、寄存器说明等附加资料 |
| [反编译相关/rom](反编译相关/rom) | 真机 ROM（rom.bin 等） |
| [反编译相关/tools](反编译相关/tools) | 早期探索脚本（对齐、ROM 重组、函数表导出等） |
| [反编译相关](反编译相关) | 目录导航、Ghidra 反编译入门、Ghidra 的 nX-U8 语言模块 |
| [ROP](ROP) / [rop_disas](rop_disas) | ROP 教程、标签与示例程序、ROP 汇编器 |
| [模拟器及资源](模拟器及资源) | 真机模拟器（子模块）、字体、字符表、真机 ROM |
| [官方说明书](官方说明书) | fx-991CN X 用户说明书 PDF 与 MinerU 解析出的 Markdown 版 |
| [991CN X 教程 V2.0](991CN%20X%20教程%20V2.0) | 计算器玩法与底层原理教程 |

## 工程化版逆向结果

```text
反编译相关/反编译结果_工程化版/
├── 原始反编译结果/     Ghidra 原始 .c / .汇编.txt（未改动）
├── src/                175 个源文件，按模块分目录（boot/bcd/eval/apps/...）
├── include/991cnx/     与 src 对应的头文件
├── docs/               函数索引、全局变量索引、模块索引、命名方法、符号对照
└── toolchain/          重建流水线与校验脚本
```

当前状态（由 `docs/还原进度.md` 自动生成）：

| 项目 | 数量 |
|------|------|
| 函数 | 1311 / 1311 已命名（verified 253、strong 334、likely 724） |
| 全局符号 | 196 |
| 源文件 | 175（16 个模块） |
| 与参考反汇编逐字节一致 | 59914 / 59988 条（99.88%），其余均可解释 |

### 文档入口

- [命名与还原方法](反编译相关/反编译结果_工程化版/docs/命名与还原方法.md)：流水线、置信度定义、关键还原结论
- [casio-main 符号对照](反编译相关/反编译结果_工程化版/docs/casio-main符号对照.md)：与真实符号逐条对照、地址修正、两路汇编核对
- [说明书与逆向对照](反编译相关/反编译结果_工程化版/docs/说明书与逆向对照.md)：设置项、数值范围、错误类型与代码的对应
- [函数索引](反编译相关/反编译结果_工程化版/docs/函数索引.md)（1311 条）/ [全局变量索引](反编译相关/反编译结果_工程化版/docs/全局变量索引.md)（196 条）/ [模块索引](反编译相关/反编译结果_工程化版/docs/模块索引.md)
- [还原进度](反编译相关/反编译结果_工程化版/docs/还原进度.md)
- [反编译结果已知缺陷](反编译相关/反编译结果_工程化版/docs/反编译结果已知缺陷.md)：Ghidra 文本的过度简化、指令写窄、活名污染等及处理方式

### 重建工程

需要 Python 3.8+。在 `反编译相关/反编译结果_工程化版/toolchain/` 下依次执行：

```bash
python index_build.py      # 生成 index.json（地址、调用关系、RAM 引用）
python build_project.py    # 重新生成 src/、include/、docs/
python tests/check_split.py     # 检查每个函数文本的地址与尾部注释
python calibrate.py             # 与 casio-main 真实符号对照 + 两路汇编核对
python tests/check_asm_parity.py  # 汇编文本重组成 ROM 后与参考逐字节比较
```

命名都在 `toolchain/naming_db.py`（`FUNCS[地址]`、`GLOBALS[地址]`）中维护，
改完后重跑上述命令即可整体更新。

## 下载所有内容

请遵循以下步骤获取这个仓库的所有内容到你的电脑上。

0. 安装 [Git](https://git-scm.com/)；
1. 选一个合适的位置，执行

       git clone https://github.com/Physics365/991CN-X-CW-Decompilation.git --recursive
2. 从@qiufuyu123 的[云盘](https://casio.123a.club/)或专门的[LFS仓库](https://github.com/Physics365/991CN-X-CW-Decompilation_Files)下载你所需的 LFS 文件

3. 完事。

## 致谢/参考

* [百度贴吧 fx-es(ms)吧](https://tieba.baidu.com/fx-es(ms))：故事的开始
* [Universal Casio Forum](https://casiocalc.org)：卡西欧计算器论坛
* [CASIO calculators exploits](https://casiocalc.wikidot.com)：卡西欧计算器漏洞利用
* 百度贴吧用户 [@EwTE_H](https://tieba.baidu.com/home/main?id=tb.1.ba0c2f47.avRm7aRqck4QgwYYgIf3eA&fr=pb&ie=utf-8)：适用于 Ghidra 的 nX-U8 语言
* casio-main（真实符号表、注释反汇编、内存表）：见 [参考-casio-main](反编译相关/参考-casio-main) 内的 README
* [MinerU](https://mineru.net)：用于把官方说明书 PDF 转成 Markdown