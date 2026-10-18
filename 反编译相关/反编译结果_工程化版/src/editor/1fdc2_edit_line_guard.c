/*
 * 输入编辑器 / 1fdc2_edit_line_guard.c
 * 地址范围: 0x1FDC2 - 0x1FDC2
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 编辑行守卫
 * @addr 0x1FDC2
 * @module editor
 * @proto int edit_line_guard(byte* p)
 * @confidence likely
 * @note 编辑行守卫：0xD144 备份后按首字节 0x2F/0xA5 等判断是否允许。
 * @tag editor
 */
int edit_line_guard(byte* p)

{
  char cVar1;
  byte *pbVar2;
  ushort uVar3;
  
  cVar1 = frame_enter();
  pbVar2 = prev_char_ptr(input_ptr,p);
  if (((((cVar1 != '\x11') && (cVar1 != '\x10')) && (*p != 0x2f)) &&
      ((*pbVar2 != 0xa5 &&
       (uVar3 = token_at(pbVar2),
       (byte)uVar3 != 0x2f || (bool)((char)(uVar3 >> 8) + '\x03') != (byte)uVar3 < 0x2f)))) &&
     ((*p != 0xc9 && ((*p != 0xca || (p[1] == 0x1d)))))) {
    token_class2(p);
  }
  frame_leave();
  return 0;
}

