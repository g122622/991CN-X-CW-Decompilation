/*
 * 启动与主流程 / 00000_reset_vector.c
 * 地址范围: 0x00000 - 0x00200
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief ROM 首地址
 * @addr 0x00000
 * @module boot
 * @proto void reset_vector(void)
 * @confidence verified
 * @note ROM 首地址：B 0x9402（复位入口）。Ghidra 把该跳转反编译成了自递归函数，这里按真实语义改写为对
 *       reset_entry 的调用。
 * @tag boot
 */
void reset_vector(void)

{
  /* ROM 0x0000: B 0x9402 —— 复位入口 */
  reset_entry((byte *)0);
  return;
}

/**
 * @brief 启动向量区内的无效指令（halt_baddata，Ghidra 仅解析出 101 字节）
 * @addr 0x00200
 * @module boot
 * @proto void bad_entry(void)
 * @confidence verified
 * @note 启动向量区内的无效指令（halt_baddata，Ghidra 仅解析出 101 字节）。
 * @tag boot
 */
int bad_entry(void)

{
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}

