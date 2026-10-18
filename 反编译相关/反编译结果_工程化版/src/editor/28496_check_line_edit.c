/*
 * 输入编辑器 / 28496_check_line_edit.c
 * 地址范围: 0x28496 - 0x288A2
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 当前行 0xD137 == 10 时调用 0x29D94（特殊编辑判断）
 * @addr 0x28496
 * @module editor
 * @proto void check_line_edit(void)
 * @confidence likely
 * @note 当前行 0xD137 == 10 时调用 0x29D94（特殊编辑判断）。
 * @tag editor
 */
int check_line_edit(void)

{
  frame_enter();
  if (cur_line == '\n') {
    is_special_editing();
  }
  frame_leave();
  return 0;
}

/**
 * @brief 类型 3 或 4 时返回 1（插入变量/等号行）
 * @addr 0x284CC
 * @module editor
 * @proto byte insert_var_line(char type)
 * @confidence likely
 * @note 类型 3 或 4 时返回 1（插入变量/等号行）。
 * @tag editor
 */
byte insert_var_line(char type)

{
  char cVar1;
  undefined uVar2;
  
  cVar1 = is_frac_sep(type);
  if (cVar1 == '\0') {
    if (type == '\x04') {
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

/**
 * @brief 编辑按键处理（1.2KB）
 * @addr 0x2864A
 * @module editor
 * @proto int edit_key_handler(undefined2 k)
 * @confidence likely
 * @note 编辑按键处理（1.2KB）。
 * @tag editor
 */
int edit_key_handler(undefined2 k)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  
  bVar2 = frame_enter();
  bVar1 = true;
  bVar4 = (byte)k;
  cVar5 = (char)((ushort)k >> 8);
  bVar3 = list_row;
  if (bVar4 == 0x1c && (bool)(cVar5 + '\x04') == bVar4 < 0x1c) {
    if (1 < list_row) {
      bVar1 = false;
      list_row = list_row - 1;
    }
  }
  else if (bVar4 == 0x1d && (bool)(cVar5 + '\x04') == bVar4 < 0x1d) {
    bVar3 = *(byte *)((ushort)bVar2 * 2 + -0x2f07);
    if (list_row < bVar3) {
      bVar1 = false;
      list_row = list_row + 1;
    }
  }
  else {
    if (bVar4 != 0x1e || (bool)(cVar5 + '\x04') != bVar4 < 0x1e) {
      if (bVar4 == 0x1f && (bool)(cVar5 + '\x04') == bVar4 < 0x1f) {
        if (1 < list_row) {
          bVar1 = false;
          list_row = list_row - 1;
        }
        goto LAB_rom_02867a;
      }
      if (bVar4 != 0x2d || (bool)(cVar5 + '\x04') != bVar4 < 0x2d) goto LAB_rom_02867a;
    }
    bVar3 = *(byte *)((ushort)bVar2 * 2 + -0x2f07);
    if (list_row < bVar3) {
      bVar1 = false;
      list_row = list_row + 1;
    }
  }
LAB_rom_02867a:
  if (!bVar1) {
    key_hist_clear0(bVar3);
  }
  frame_leave();
  return 0;
}

/**
 * @brief 把编辑行复制到 0xD144，并对首 token 做 0x288D0 检查
 * @addr 0x288A2
 * @module editor
 * @proto ushort push_edit_cache(byte* src)
 * @confidence likely
 * @note 把编辑行复制到 0xD144，并对首 token 做 0x288D0 检查。
 * @tag editor
 */
ushort push_edit_cache(byte* src)

{
  byte *pbVar1;
  undefined2 uVar2;
  
  pbVar1 = prev_char_ptr(input_ptr,src);
  if (pbVar1 != (byte *)0x0) {
    uVar2 = token_class((char *)pbVar1);
    pbVar1 = (byte *)is_key_allowed((byte)uVar2);
    if ((char)pbVar1 == '\0') {
      return (ushort)pbVar1 & 0xff00;
    }
  }
  return CONCAT11((char)((ushort)pbVar1 >> 8),1);
}

