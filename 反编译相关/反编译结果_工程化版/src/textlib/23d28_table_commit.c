/*
 * 行打印与文本 / 23d28_table_commit.c
 * 地址范围: 0x23D28 - 0x23F16
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 表格提交/重算（2.5KB，0xB8A6 调用）
 * @addr 0x23D28
 * @module textlib
 * @proto void table_commit(void)
 * @confidence likely
 * @note 表格提交/重算（2.5KB，0xB8A6 调用）。
 * @tag app
 */
int table_commit(uintptr_t _a2, int _a1)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined *puVar7;
  char cVar8;
  char cVar9;
  short unaff_ER14;
  
  uVar3 = frame_enter();
  *(undefined *)(unaff_ER14 + -0x1d) = 0;
  uVar4 = next_size_3n1((byte)_a1);
  *(char *)(unaff_ER14 + -0x15) = (char)uVar4;
  uVar5 = mul16(uVar4 & 0xff,*(ushort *)(unaff_ER14 + 0x10));
  do {
    *(undefined2 *)(unaff_ER14 + -0x18) = uVar5;
    if (*(byte *)(unaff_ER14 + -0x15) == 0) {
LAB_rom_023dfc:
      frame_leave();
      return 0;
    }
    uVar4 = (ushort)*(byte *)(unaff_ER14 + -0x15);
    while (*(ushort *)(unaff_ER14 + -0x1c) = uVar4, (char)((uVar4 < _a1) << 7) < '\0') {
      uVar6 = kbd_wait_key();
      if ((char)uVar6 != '\0') {
        *(undefined *)(unaff_ER14 + -0x1d) = 1;
        goto LAB_rom_023dfc;
      }
      puVar7 = (undefined *)(*(short *)(unaff_ER14 + -0x18) + uVar3);
      bVar2 = (byte)uVar5;
      cVar9 = (char)((ushort)uVar5 >> 8);
      uVar6 = CONCAT11(((char)((ushort)puVar7 >> 8) - cVar9) - ((byte)puVar7 < bVar2),
                       (byte)puVar7 - bVar2);
      *(undefined2 *)(unaff_ER14 + -0x1a) = uVar6;
      uVar6 = dec_to_string(uVar6,(undefined2 *)(*(short *)(unaff_ER14 + -0x18) + uVar3));
      if ((char)uVar6 == '\x04') {
        memcpy_bytes((undefined *)(unaff_ER14 + -0x14),puVar7,*(short *)(unaff_ER14 + 0x10));
        do {
          memcpy_bytes(puVar7,*(undefined **)(unaff_ER14 + -0x1a),*(short *)(unaff_ER14 + 0x10));
          puVar7 = *(undefined **)(unaff_ER14 + -0x1a);
          bVar1 = (byte)puVar7;
          cVar8 = (char)((ushort)puVar7 >> 8);
          *(ushort *)(unaff_ER14 + -0x1a) =
               CONCAT11((cVar8 - cVar9) - (bVar1 < bVar2),bVar1 - bVar2);
          if ((char)((CONCAT11((cVar8 - cVar9) - (bVar1 < bVar2),bVar1 - bVar2) < uVar3) << 7) <
              '\0') break;
          uVar6 = dec_to_string(*(undefined2 *)(unaff_ER14 + -0x1a), (uintptr_t)0)
                                 (undefined2 *)(unaff_ER14 + -0x14));
        } while ((char)uVar6 == '\x04');
        memcpy_bytes(puVar7,(undefined *)(unaff_ER14 + -0x14),*(short *)(unaff_ER14 + 0x10));
      }
      *(short *)(unaff_ER14 + -0x18) =
           *(short *)(unaff_ER14 + -0x18) + *(short *)(unaff_ER14 + 0x10);
      uVar4 = *(short *)(unaff_ER14 + -0x1c) + 1;
    }
    bVar2 = *(byte *)(unaff_ER14 + -0x15) / 3;
    *(byte *)(unaff_ER14 + -0x15) = bVar2;
    uVar5 = mul16((ushort)bVar2,*(ushort *)(unaff_ER14 + 0x10));
  } while( true );
}

/**
 * @brief 键码 0x28 处理
 * @addr 0x23E02
 * @module textlib
 * @proto void key_28_handler(void)
 * @confidence likely
 * @note 键码 0x28 处理：按 0xD1xx 状态分支（0x1F574 读键）。
 * @tag key
 */
int key_28_handler(void)

{
  undefined2 uVar1;
  byte bVar2;
  char cVar3;
  
  uVar1 = frame_enter();
  bVar2 = (byte)uVar1;
  cVar3 = (char)((ushort)uVar1 >> 8);
  if (bVar2 == 0x28 && (bool)(cVar3 + '\x04') == bVar2 < 0x28) {
    bVar2 = (status_bits ^ 4) & 0xf4;
  }
  else if (bVar2 == 0x29 && (bool)(cVar3 + '\x04') == bVar2 < 0x29) {
    bVar2 = (status_bits ^ 8) & 0xf8;
  }
  else if (bVar2 == 0x2b && (bool)(cVar3 + '\x04') == bVar2 < 0x2b) {
    bVar2 = (status_bits ^ 1) & 0xf1;
  }
  else if (bVar2 == 0x2c && (bool)(cVar3 + '\x04') == bVar2 < 0x2c) {
    if (input_layout == '\0') {
      status_bits = status_bits + 0x80;
    }
    bVar2 = status_bits & 0xf7;
    status_bits = bVar2;
    redraw_line_syntax();
  }
  else {
    bVar2 = status_bits & 0xf0;
  }
  status_bits = bVar2;
  frame_leave();
  return 0;
}

/**
 * @brief 变量/矩阵菜单（1.1KB，0x28C10 调用）
 * @addr 0x23E78
 * @module textlib
 * @proto void var_menu(void)
 * @confidence likely
 * @note 变量/矩阵菜单（1.1KB，0x28C10 调用）。
 * @tag ui
 */
int var_menu(void)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  byte bVar4;
  char cVar5;
  ushort uVar6;
  short unaff_ER14;
  
  uVar3 = frame_enter();
  bVar4 = (byte)(uVar3 >> 8);
  bVar1 = (byte)uVar3;
  bVar2 = (byte)*(undefined2 *)(unaff_ER14 + 0x10);
  cVar5 = (char)((ushort)*(undefined2 *)(unaff_ER14 + 0x10) >> 8);
  if (bVar2 == 0x1c && (bool)(cVar5 + '\x04') == bVar2 < 0x1c) {
    if (bVar4 < bVar1) {
      key_flag_clear();
    }
  }
  else if (bVar2 == 0x1d && (bool)(cVar5 + '\x04') == bVar2 < 0x1d) {
    if (bVar1 != 0) {
      bVar1 = (byte)((ushort)mode_count % (uVar3 & 0xff));
    }
    uVar6 = CONCAT11(-(mode_count < bVar1),mode_count - bVar1);
    uVar3 = (ushort)bVar4;
    if ((byte)(SBORROW2(uVar6,uVar3) ^ (short)(uVar6 - uVar3) < 0 | uVar6 == uVar3) != 0) {
      key_flag_clear();
    }
  }
  else if (bVar2 == 0x1e && (bool)(cVar5 + '\x04') == bVar2 < 0x1e) {
    if (mode_count == bVar4) {
      key_flag_clear();
    }
  }
  else if ((bVar2 == 0x1f && (bool)(cVar5 + '\x04') == bVar2 < 0x1f) && (bVar4 == 0)) {
    key_flag_clear();
  }
  frame_leave();
  return 0;
}

/**
 * @brief 调用 0xED7C 刷新列表视图
 * @addr 0x23EF8
 * @module textlib
 * @proto void refresh_list(undefined2 er0)
 * @confidence likely
 * @note 调用 0xED7C 刷新列表视图。
 * @tag ui
 */
int refresh_list(undefined2 er0)

{
  draw_tokens(er0);
  return 0;
}

/**
 * @brief 以 er0/er2 调用 0x246B4
 * @addr 0x23F16
 * @module textlib
 * @proto void call_246b4(undefined2 er0, undefined2 er2)
 * @confidence likely
 * @note 以 er0/er2 调用 0x246B4。
 * @tag ui
 */
int call_246b4(undefined2 er0, undefined2 er2)

{
  divmod_unsigned16(er0,er2);
  return 0;
}

