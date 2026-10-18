/*
 * 输入编辑器 / 27204_copy_result_hook.c
 * 地址范围: 0x27204 - 0x27204
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 按 0x26A1C 的结果把编辑行复制到结果区
 * @addr 0x27204
 * @module editor
 * @proto void copy_result_hook(undefined2 er0)
 * @confidence likely
 * @note 按 0x26A1C 的结果把编辑行复制到结果区。
 * @tag editor
 */
int copy_result_hook(undefined2 er0)

{
  char cVar1;
  short sVar2;
  ushort uVar3;
  short sVar4;
  short unaff_ER14;
  
  sVar2 = frame_enter();
  cVar1 = is_idle_editing();
  if (cVar1 != '\0') {
    uVar3 = 0;
    while (*(byte *)(unaff_ER14 + -1) = (byte)uVar3,
          (char)(((byte)uVar3 < *(byte *)(unaff_ER14 + 0x10)) << 7) < '\0') {
      *(undefined *)(uVar3 * 3 + sVar2) = *er0;
      sVar4 = uVar3 * 3 + sVar2;
      *(undefined *)(sVar4 + 1) = er0[1];
      *(undefined *)(sVar4 + 2) = er0[2];
      er0 = (uintptr_t)er0 + 0x18;
      uVar3 = (ushort)(byte)(*(char *)(unaff_ER14 + -1) + 1);
    }
  }
  frame_leave();
  return 0;
}

