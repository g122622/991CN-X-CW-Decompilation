/*
 * 界面状态机 / 08d7a_return_zero.c
 * 地址范围: 0x08D7A - 0x090B4
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 恒返回 0（多个代码分支的公共出口）
 * @addr 0x08D7A
 * @module ui_state
 * @proto short return_zero(void)
 * @confidence verified
 * @note 恒返回 0（多个代码分支的公共出口）。
 * @tag util
 */
short return_zero(void)

{
  return 0;
}

/**
 * @brief 按模式/编辑状态返回当前输入变体（COMPLEX/进制等）并写 *out
 * @addr 0x08D94
 * @module ui_state
 * @proto char* input_variant(undefined* out)
 * @confidence strong
 * @note 按模式/编辑状态返回当前输入变体（COMPLEX/进制等）并写 *out。
 * @tag ui
 */
char* input_variant(undefined* out)

{
  undefined extraout_R1;
  
  *out = '\0';
  if ((calc_mode == 6) || (calc_mode == 7)) {
    if ((key_modifiers == 3) || (key_modifiers == 0)) {
      if (edit_state2 == '\x01') goto LAB_rom_008dbe;
      if (sub_mode == '\x04') {
        *out = calc_mode;
        stat_state_reset();
        return CONCAT11(extraout_R1,2);
      }
    }
  }
  else if ((((calc_mode == 0x45) || (calc_mode == 0x4b)) || (calc_mode == 0x4a)) ||
          (calc_mode == 0xc)) {
    if (edit_state2 == '\x01') goto LAB_rom_008df2;
    goto LAB_rom_008dbe;
  }
  if ((key_modifiers & 0x40) != 0) {
LAB_rom_008df2:
    return (ushort)calc_mode << 8;
  }
LAB_rom_008dbe:
  return CONCAT11(calc_mode,1);
}

/**
 * @brief 恒返回 0
 * @addr 0x08E32
 * @module ui_state
 * @proto byte return_false(void)
 * @confidence verified
 * @note 恒返回 0。
 * @tag util
 */
byte return_false(void)

{
  return 0;
}

/**
 * @brief 0xD111==0x88 且 0xD114==0x12 时返回 1
 * @addr 0x08E6E
 * @module ui_state
 * @proto char is_ratio_mode(void)
 * @confidence strong
 * @note 0xD111==0x88 且 0xD114==0x12 时返回 1。
 * @tag ui
 */
char is_ratio_mode(void)

{
  if ((calc_mode == -0x78) && (edit_state2 == '\x12')) {
    return 1;
  }
  return 0;
}

/**
 * @brief 计算统计表单元格地址
 * @addr 0x08ED0
 * @module ui_state
 * @proto short stat_cell_addr(ushort rc, char col)
 * @confidence verified
 * @note 计算统计表单元格地址：0xD392 + ((行-1)*4 + (列-1) + 页*16) * 10。
 * @tag stat
 */
short stat_cell_addr(ushort rc, char col)

{
  return (short)(&stat_data +
                (ushort)(byte)(col + -1 + ((char)((ushort)rc >> 8) + -1) * '\x04' +
                              (char)rc * '\x10') * 10);
}

/**
 * @brief 带滚动偏移的统计表单元格地址计算
 * @addr 0x08EF2
 * @module ui_state
 * @proto undefined2 stat_cell_addr_ex(ushort rc, short* addr)
 * @confidence strong
 * @note 带滚动偏移的统计表单元格地址计算。
 * @tag stat
 */
undefined2 stat_cell_addr_ex(ushort rc, short* addr)

{
  byte bVar1;
  undefined2 uVar2;
  short sVar3;
  byte bVar4;
  
  uVar2 = stat_table_base(addr);
  bVar4 = (byte)(rc >> 8);
  if ((char)(((byte)uVar2 < bVar4) << 7) < '\0') {
    sVar3 = 0;
    uVar2 = CONCAT11((char)((ushort)uVar2 >> 8),2);
  }
  else {
    bVar1 = stat_table_width();
    if ((sub_mode == '\x01') && ((char)rc == '\x02')) {
      rc = 1;
    }
    uVar2 = 0xa00;
    sVar3 = ((ushort)(byte)(bVar4 - 1) * (ushort)bVar1 & 0xff) * 10 + (rc & 0xff) * 10 +
            *addr;
  }
  *addr = sVar3;
  return uVar2;
}

/**
 * @brief 返回当前页 *out=0xD400，函数值 = 0xD0F6（页号）
 * @addr 0x08F34
 * @module ui_state
 * @proto byte stat_table_base(ushort* out)
 * @confidence verified
 * @note 返回当前页 *out=0xD400，函数值 = 0xD0F6（页号）。
 * @tag stat
 */
byte stat_table_base(ushort* out)

{
  undefined uVar1;
  
  uVar1 = var_scroll;
  *out = 0xd400;
  return uVar1;
}

/**
 * @brief 按模式返回统计/表格宽度
 * @addr 0x08F48
 * @module ui_state
 * @proto char stat_table_width(void)
 * @confidence strong
 * @note 按模式返回统计/表格宽度：0x88 模式 2 或 3，C 模式 1..3，其余 1/2。
 * @tag stat
 */
char stat_table_width(void)

{
  char cVar1;
  
  cVar1 = '\x02';
  if (calc_mode == -0x78) {
    if ((history_recall != '\0') && ((ratio_flags & 0x80) == 0)) {
      cVar1 = '\x03';
    }
  }
  else if (calc_mode != '\f') {
    cVar1 = '\x01';
    if (sub_mode != '\x01') {
      cVar1 = '\x02';
    }
    if (var_list_open != '\0') {
      cVar1 = cVar1 + '\x01';
    }
  }
  return cVar1;
}

/**
 * @brief 设置页号并清空 0xD400 处的 900 字节统计区
 * @addr 0x08F7C
 * @module ui_state
 * @proto undefined2 stat_table_clear(byte page)
 * @confidence verified
 * @note 设置页号并清空 0xD400 处的 900 字节统计区。
 * @tag stat
 */
undefined2 stat_table_clear(byte page)

{
  undefined2 uVar1;
  
  var_scroll = page;
  stat_table_reset();
  uVar1 = 900;
  memset((undefined *)0xd400,0,900);
  return uVar1;
}

/**
 * @brief 把 dst..dst+len 清零（调用 memset）
 * @addr 0x08FB8
 * @module ui_state
 * @proto void memzero(byte* dst, ushort len)
 * @confidence verified
 * @note 把 dst..dst+len 清零（调用 memset）。
 * @tag libc
 */
int memzero(byte* dst, ushort len)

{
  memset(dst,0,len);  // 调用memset填充0
  return 0;
}

/**
 * @brief 取第 idx 个变量（0xD31A + idx*10）到 dst
 * @addr 0x08FEC
 * @module ui_state
 * @proto short var_get_value(byte idx, byte* dst)
 * @confidence verified
 * @note 取第 idx 个变量（0xD31A + idx*10）到 dst；复数模式再取虚部（0xD612 区），否则清零余下部分。
 * @tag vars
 */
short var_get_value(byte idx, byte* dst)

{
  undefined uVar1;
  undefined *puVar2;
  undefined *puVar3;
  short sVar4;
  undefined8 uVar6;
  ushort uVar7;
  ulonglong uVar5;
  
  uVar7 = (ushort)idx;
  uVar1 = is_edit_locked();
  sVar4 = (uVar7 & 0xff) * 10;
  uVar5 = (ulonglong)
          CONCAT52((int5)(CONCAT16(uVar1,CONCAT24(10,(int)CONCAT62(ZEXT26(dst),10))) >> 0x10),
                   sVar4);
  puVar2 = (undefined *)(sVar4 + -0x2ce6);
  memcpy_bytes(dst,puVar2,10);
  if ((char)(uVar5 >> 0x30) != '\x01') {
    dec_normalize2((short)(uVar5 >> 0x10),puVar2);
  }
  sVar4 = (short)(uVar5 >> 0x20);
  puVar2 = (undefined *)((short)(uVar5 >> 0x10) + 10);
  uVar6 = CONCAT44((int)(uVar5 >> 0x20),CONCAT22(puVar2,(short)uVar5));
  if ((calc_mode == -0x3c) ||
     (((calc_mode == 'E' && (3 < sub_mode)) && (input_layout == '\x03')))) {
    puVar3 = (undefined *)((short)uVar5 + -0x29ee);
    memcpy_bytes(puVar2,puVar3,sVar4);
    if ((char)((ulonglong)uVar6 >> 0x30) != '\x01') {
      dec_normalize2((short)((ulonglong)uVar6 >> 0x10),puVar3);
    }
  }
  else {
    memset(puVar2,0,sVar4);
  }
  return sVar4;
}

/**
 * @brief 清 0xD16C 区（进制模式输入缓冲），返回参数
 * @addr 0x09060
 * @module ui_state
 * @proto ushort base_clear(ushort v, undefined* p)
 * @confidence likely
 * @note 清 0xD16C 区（进制模式输入缓冲），返回参数。
 * @tag mode
 */
ushort base_clear(ushort v, undefined* p)

{
  ushort uVar1;
  short sVar2;
  undefined8 uVar3;
  undefined uVar4;
  
  uVar4 = 0;
  sVar2 = (v & 0xff) * 10;
  uVar3 = CONCAT62(CONCAT24(10,(int)CONCAT62(ZEXT26(p),10)) >> 0x10,sVar2);
  memcpy_bytes((undefined *)(sVar2 + -0x2ce6),p,10);
  uVar1 = CONCAT11(uVar4,calc_mode);
  if ((calc_mode == 'E') || (calc_mode == -0x3c)) {
    uVar1 = (ushort)((ulonglong)uVar3 >> 0x20);
    memcpy_bytes((undefined *)((short)uVar3 + -0x29ee), (uintptr_t)0, (uintptr_t)0)
                   (undefined *)((short)((ulonglong)uVar3 >> 0x10) + 10),uVar1);
  }
  return uVar1;
}

/**
 * @brief 进制模式返回 0xD123 相关状态
 * @addr 0x0909E
 * @module ui_state
 * @proto ushort base_submode(void)
 * @confidence likely
 * @note 进制模式返回 0xD123 相关状态。
 * @tag mode
 */
ushort base_submode(void)

{
  if (calc_mode == -0x3f) {
    return menu_state_b;
  }
  return 0;
}

/**
 * @brief 返回 SP 相对 0xE3E4 的栈深度
 * @addr 0x090B4
 * @module ui_state
 * @proto ushort stack_depth(void)
 * @confidence verified
 * @note 返回 SP 相对 0xE3E4 的栈深度。
 * @tag hw
 */
ushort stack_depth(void)

{
  uintptr_t fp = 0;
  return CONCAT11((char)((ushort)&*(byte *)(uintptr_t)(fp + 0x0000) >> 8) + '\x1c',0x1c);
}

