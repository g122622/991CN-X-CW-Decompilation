/*
 * 输入编辑器 / 27bbc_input_buf_clear.c
 * 地址范围: 0x27BBC - 0x28244
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 清输入区 0xD180（200 字节）
 * @addr 0x27BBC
 * @module editor
 * @proto void input_buf_clear(void)
 * @confidence strong
 * @note 清输入区 0xD180（200 字节）。
 * @tag editor
 */
int input_buf_clear(void)

{
  memzero(&input_buf,200);
  return 0;
}

/**
 * @brief 同步编辑行
 * @addr 0x28244
 * @module editor
 * @proto int input_line_sync(byte** p)
 * @confidence likely
 * @note 同步编辑行：0x20D10 检查后按 0xD114/0xD116 选择 0x9B98/0x203C2 复制。
 * @tag editor
 */
int input_line_sync(byte** p)

{
  undefined2 uVar1;
  
  *p = &input_buf;
  uVar1 = stat_view_event();
  if ((char)uVar1 == '\0') {
    if ((key_modifiers & 0x40) == 0) {
      uVar1 = expr_append_A();
      if (((calc_mode & 0x80) == 0) &&
         ((uVar1 = CONCAT11((char)((ushort)uVar1 >> 8),edit_state2), edit_state2 == 1 ||
          ((edit_state2 & 0x80) != 0)))) {
        uVar1 = strcpy_checked((char *)0xd248,&input_buf);
      }
    }
    else {
      input_ptr = input_end_ptr;
      uVar1 = input_end_ptr;
    }
  }
  return CONCAT11((char)((ushort)uVar1 >> 8),1);
}

