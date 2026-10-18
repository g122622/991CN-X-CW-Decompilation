/*
 * 应用模式 / 0c34c_clear_replay_buf.c
 * 地址范围: 0x0C34C - 0x0C34C
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 清零回放区 0xD248（200 字节）
 * @addr 0x0C34C
 * @module apps
 * @proto void clear_replay_buf(void)
 * @confidence verified
 * @note 清零回放区 0xD248（200 字节）。
 * @tag mode
 */
int clear_replay_buf(void)

{
  memzero((undefined *)0xd248,200);
  return 0;
}

