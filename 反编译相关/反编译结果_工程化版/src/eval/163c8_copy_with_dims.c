/*
 * 表达式求值 / 163c8_copy_with_dims.c
 * 地址范围: 0x163C8 - 0x16B88
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 先 0x8FEC 复制，若当前为模式 2（统计），再按 0x1D900 的维度信息补复制
 * @addr 0x163C8
 * @module eval
 * @proto int copy_with_dims(undefined2* src, undefined2* dst)
 * @confidence likely
 * @note 先 0x8FEC 复制，若当前为模式 2（统计），再按 0x1D900 的维度信息补复制。
 * @tag matrix
 */
int copy_with_dims(undefined2* src, undefined2* dst)

{
  int cVar1;
  undefined *puVar2;
  
  puVar2 = dst;
  var_get_value(src,dst);
  if (calc_mode == '\x02') {
    cVar1 = dec_unary_cos(dst,puVar2);
    matrix_apply_const(cVar1,puVar2);
  }
  return 0;
}

/**
 * @brief a+10 与 b 比较，若相等再与 ER12+0x1E 比较（矩阵单元差传递），返回 a
 * @addr 0x1646C
 * @module eval
 * @proto undefined2 matrix_cmp_propagate(undefined2* a, undefined2 b)
 * @confidence likely
 * @note a+10 与 b 比较，若相等再与 ER12+0x1E 比较（矩阵单元差传递），返回 a。
 * @tag matrix
 */
undefined2 matrix_cmp_propagate(undefined2* a, undefined2 b)

{
  undefined2 uVar1;
  short unaff_ER12;
  
  uVar1 = dec_cmp((undefined2 *)(a + 10),b);
  if ((char)uVar1 == '\x01') {
    dec_cmp((undefined2 *)(unaff_ER12 + 0x1e),b);
  }
  return a;
}

/**
 * @brief 矩阵单元函数
 * @addr 0x166BA
 * @module eval
 * @proto undefined2 matrix_func_byte(ushort fn, undefined2* x)
 * @confidence likely
 * @note 矩阵单元函数：按 fn（0xFE26 区/其它）换算索引后调用 0x1C830 求值。
 * @tag matrix
 */
undefined2 matrix_func_byte(ushort fn, undefined2* x)

{
  undefined2 uVar1;
  byte bVar2;
  short sVar3;
  char cVar4;
  char cVar5;
  undefined2 *unaff_ER12;
  
  uVar1 = dec_cmp_signed(unaff_ER12,x);
  cVar5 = (char)(fn >> 8);
  cVar4 = (char)fn;
  if ((cVar5 == -2) && (cVar4 == '&')) {
    dec_bin_mul_core(uVar1,0x1b94);
  }
  bVar2 = (byte)(cVar4 - 1U) >> 1;
  if (cVar5 != -2) {
    bVar2 = bVar2 + 0x77;
  }
  sVar3 = (ushort)bVar2 * (CONCAT11(10,bVar2) >> 8);
  bVar2 = (byte)sVar3;
  uVar1 = CONCAT11((char)((ushort)sVar3 >> 8) + '0' + (0x81 < bVar2),bVar2 + 0x7e);
  if ((fn & 1) == 0) {
    dec_bin_and_core(unaff_ER12,uVar1);
  }
  else {
    dec_bin_pow_core(unaff_ER12,uVar1);
  }
  if ((cVar5 == -2) && (cVar4 == '%')) {
    uVar1 = 0x1b94;
    dec_bin_div_core(unaff_ER12,0x1b94);
  }
  dec_cmp_ex(unaff_ER12,uVar1);
  return;
}

/**
 * @brief 单字节矩阵元素求值
 * @addr 0x167E0
 * @module eval
 * @proto int matrix_eval_u8(ushort tok)
 * @confidence likely
 * @note 单字节矩阵元素求值：按 tok 的编码区（0xFEXX 等）调整索引并调用 0x16820。
 * @tag matrix
 */
int matrix_eval_u8(ushort tok)

{
  char cVar1;
  byte bVar2;
  short sVar3;
  ushort uVar4;
  ushort uVar5;
  undefined2 *unaff_ER12;
  
  cVar1 = (char)tok;
  bVar2 = (byte)((ushort)tok >> 8);
  if (0xe2 < bVar2) {
    tok = (ushort)(byte)(bVar2 + 1) << 8;
  }
  sVar3 = (ushort)(byte)((char)((ushort)tok >> 8) + 0x23) * 3;
  uVar5 = CONCAT11(-(0x12 < (byte)sVar3) - (char)((ushort)sVar3 >> 8),'\x12' - (byte)sVar3);
  dec_cmp_signed(unaff_ER12,sVar3);
  uVar4 = uVar5;
  dec_bcd_to_bin(unaff_ER12,uVar5);
  if (cVar1 == -0x3c) {
    dec_cmp_signed(unaff_ER12 + 5,uVar4);
    dec_bcd_to_bin(unaff_ER12 + 5,uVar5);
  }
  return 0;
}

/**
 * @brief 矩阵/向量表达式求值树
 * @addr 0x16820
 * @module eval
 * @proto undefined2 matrix_eval_tree(ushort tok, byte* out)
 * @confidence strong
 * @note 矩阵/向量表达式求值树：按 token 码（0xFE26/0xFBxx 区）递归下降，调用
 *       0x166BA/0x167E0/0x16F64 等完成求值。
 * @tag matrix
 */
undefined2 matrix_eval_tree(ushort tok, byte* out)

{
  bool bVar1;
  int bVar2;
  int bVar3;
  byte extraout_R1;
  byte extraout_R1_00;
  byte extraout_R1_01;
  char cVar6;
  undefined2 uVar4;
  undefined extraout_R1_02;
  undefined extraout_R1_03;
  ushort uVar5;
  undefined extraout_R1_04;
  undefined extraout_R1_05;
  int bVar7;
  undefined uVar8;
  byte bVar9;
  byte unaff_R4;
  char cVar10;
  undefined uVar11;
  undefined unaff_R6;
  ushort *unaff_ER12;
  
  bVar2 = (byte)(tok >> 8);
  bVar1 = bVar2 < 0xfe;
  if ((bVar2 == 0xfe) || (bVar1 = bVar2 < 0xfa, bVar2 == 0xfa)) {
    cVar10 = bVar1 << 7;
    matrix_prec_limit(7);
    if (cVar10 < '\0') goto LAB_rom_016874;
    bVar2 = matrix_func_byte(tok,out);
    uVar8 = (undefined)((ushort)out >> 8);
    cVar10 = calc_mode;
  }
  else {
    if ((char)tok == -0x51) {
      tok = 0xa8;
    }
    cVar10 = '\x01';
LAB_rom_01684c:
    uVar5 = tok << 8;
    bVar7 = (byte)tok;
    bVar2 = (bVar7 < 0x93) << 7 | (bVar7 == 0x93) << 6;
    if (((((bVar7 == 0x93) || (bVar2 = (bVar7 < 0x94) << 7 | (bVar7 == 0x94) << 6, bVar7 == 0x94))
         || (bVar2 = (bVar7 < 0x92) << 7 | (bVar7 == 0x92) << 6, bVar7 == 0x92)) ||
        ((bVar2 = (bVar7 < 0x85) << 7 | (bVar7 == 0x85) << 6, bVar7 == 0x85 ||
         (bVar2 = (bVar7 < 0x86) << 7 | (bVar7 == 0x86) << 6, bVar7 == 0x86)))) ||
       ((bVar2 = (bVar7 < 0x6a) << 7 | (bVar7 == 0x6a) << 6, bVar7 == 0x6a ||
        ((bVar2 = (bVar7 < 0x6b) << 7 | (bVar7 == 0x6b) << 6, bVar7 == 0x6b ||
         (bVar2 = (bVar7 < 0xab) << 7 | (bVar7 == 0xab) << 6, bVar7 == 0xab)))))) {
      matrix_prec_limit(0);
      bVar7 = extraout_R1;
joined_s0x0168ce:
      uVar5 = (ushort)bVar7 << 8;
      if ((char)bVar2 < '\0') goto LAB_rom_016874;
LAB_rom_0168d0:
      bVar2 = (byte)(uVar5 >> 8);
      if (((char)((bVar2 < 0x80) << 7) < '\0') ||
         (((0x82 < bVar2 &&
           (((char)((bVar2 < 0x8b) << 7) < '\0' ||
            (((0x8e < bVar2 && (bVar2 != 0x94)) &&
             (((char)((bVar2 < 0xa0) << 7) < '\0' ||
              ((0xaf < bVar2 && (((char)((bVar2 < 200) << 7) < '\0' || (0xca < bVar2)))))))))))) ||
          (cVar10 = cVar10 + -1, cVar10 != '\0')))) goto LAB_rom_016914;
      uVar5 = (ushort)bVar2;
      stat_layout((undefined8 *)(unaff_ER12 + 10));
      out = unaff_ER12;
      matrix_opnd_advance();
      tok = uVar5 & 0xff;
      goto LAB_rom_01684c;
    }
    cVar6 = (bVar7 < 0x6c) << 7;
    if (bVar7 >= 0x6c) {
      bVar2 = (bVar7 < 0x8e) << 7;
      if (((bVar7 < 0x8f) || (bVar2 = (bVar7 < 0x91) << 7, bVar7 == 0x91)) ||
         ((0xab < bVar7 && (bVar2 = (bVar7 < 0xc0) << 7, (char)bVar2 < '\0')))) {
LAB_rom_0168c4:
        uVar5 = 7;
LAB_rom_0168c6:
        uVar5 = (ushort)(byte)((byte)uVar5 | 3);
LAB_rom_0168c8:
        matrix_prec_limit((byte)uVar5 | 1);
        bVar7 = extraout_R1_00;
        goto joined_s0x0168ce;
      }
      if (bVar7 == 0xc9) {
        bVar2 = (cVar10 == '\0') << 7;
        if (cVar10 == '\x01') goto LAB_rom_0168c6;
        bVar7 = *(byte *)unaff_ER12 >> 4;
        out = (ushort *)CONCAT11(bVar7,(char)out);
        bVar2 = (bVar7 < 6) << 7;
        if (bVar7 == 6) {
          return;
        }
        goto LAB_rom_0168c8;
      }
      bVar2 = (bVar7 < 0xca) << 7;
      if (bVar7 == 0xca) goto LAB_rom_0168c4;
      if ((0xdc < bVar7) && (bVar2 = (bVar7 < 0xe7) << 7, bVar7 < 0xe8)) goto LAB_rom_0168c6;
      bVar2 = (bVar7 < 0xd7) << 7;
      if (bVar7 >= 0xd7) goto LAB_rom_0168c4;
      bVar2 = (bVar7 < 0xd4) << 7;
      if (bVar7 >= 0xd4) goto LAB_rom_0168c8;
      bVar2 = (bVar7 < 200) << 7;
      if (((bVar7 == 200) || (bVar2 = (bVar7 < 0xaa) << 7, bVar7 == 0xaa)) ||
         (bVar2 = (bVar7 < 0xa5) << 7, bVar7 == 0xa5)) goto LAB_rom_0168c6;
      goto LAB_rom_0168d0;
    }
    matrix_prec_limit(0xff);
    uVar5 = (ushort)extraout_R1_01 << 8;
    if (cVar6 < '\0') goto LAB_rom_016874;
LAB_rom_016914:
    cVar6 = (char)(uVar5 >> 8);
    if (cVar6 == '`') {
LAB_rom_016af4:
      uVar8 = (undefined)((ushort)out >> 8);
      bVar2 = (byte)(uVar5 >> 8);
      if ((0xdc < bVar2) && (bVar2 < 0xe8)) {
        cVar10 = calc_mode;
        bVar2 = matrix_eval_u8(CONCAT11(bVar2,calc_mode));
        goto LAB_rom_016abe;
      }
      if ((calc_mode == -0x3c) && (bVar2 < 0xd7)) {
        if (bVar2 < 0xd4) {
          if (bVar2 == 0xc0) {
            uVar5 = 0xa700;
          }
          else {
            if (0xa9 < bVar2) goto LAB_rom_016b46;
            if (bVar2 < 0xa6) {
              if (bVar2 == 0x74) {
                uVar5 = 0xa200;
              }
              else {
                if ((bVar2 != 0x69) && (bVar2 != 0x68)) goto LAB_rom_016b46;
                uVar5 = (ushort)(byte)(bVar2 + 0x38) << 8;
              }
            }
            else {
              uVar5 = (ushort)(byte)(bVar2 - 3) << 8;
            }
          }
        }
        else {
          uVar5 = (ushort)(byte)(bVar2 - 0x2c) << 8;
        }
      }
      else {
LAB_rom_016b46:
        uVar5 = (ushort)(byte)(bVar2 + 0xa0) << 8;
      }
      bVar2 = 0xa8;
    }
    else {
      uVar5 = CONCAT11(cVar6,stat_var_num);
      bVar2 = (cVar6 == -0x6f) << 6;
      if (cVar6 == -0x6f) {
        bVar7 = bit_reverse8(stat_var_num);
        if ((bVar2 >> 6 & 1) == 1) {
          return;
        }
        bVar2 = set_bit_hi(bVar7);
        uVar5 = matrix_advance(CONCAT11(extraout_R1_03,bVar2));
        *(byte *)unaff_ER12 = unaff_R4 | 0x60;
LAB_rom_016a0e:
        uVar5 = CONCAT11((char)(uVar5 >> 8) + -0x7f,(char)uVar5);
      }
      else {
        bVar2 = *(byte *)unaff_ER12;
        bVar7 = *(byte *)(unaff_ER12 + 10);
        out = (ushort *)CONCAT11(bVar7,bVar2);
        if (bVar2 < 0x90) {
          if ((bVar2 < 0x80) && (0x5f < bVar2)) {
            if (cVar10 != -1) {
              out = (ushort *)(CONCAT11(bVar7,bVar2) & 0xff0f);
              if ((cVar6 == -0x7b) || (cVar6 == -0x7a)) {
LAB_rom_0169be:
                bVar2 = ((byte)out == 5) << 6;
                if ((byte)out < 5) {
                  bVar7 = bit_reverse8((byte)uVar5);
                  bVar3 = (byte)((ushort)out >> 8);
                  if ((bVar2 >> 6 & 1) != 0) {
                    return;
                  }
                  set_bit_hi(bVar7);
                  out = (ushort *)((ushort)bVar3 << 8);
                  uVar5 = CONCAT11(*(undefined *)unaff_ER12,unaff_R4) & 0xf0ff;
                  *(byte *)unaff_ER12 = (byte)(uVar5 >> 8) | (byte)uVar5;
                  uVar5 = stat_fill_cells();
                }
                bVar2 = (byte)(uVar5 >> 8);
                if ((bVar2 == 0x85) || (bVar2 == 0x86)) {
                  uVar5 = CONCAT11(bVar2 + 0x8b,(char)uVar5);
                }
                else {
                  if (bVar2 == 0x92) goto LAB_rom_016a0e;
                  if (0x58 < bVar2) {
                    if (bVar2 == 0x59) {
                      uVar5 = CONCAT11(0x6c,(char)uVar5);
                    }
                    uVar5 = CONCAT11((char)(uVar5 >> 8) + -0x67,(char)uVar5);
                  }
                }
              }
              else {
                bVar2 = cVar6 + 0x99;
                uVar5 = CONCAT11(bVar2,stat_var_num);
                if (bVar2 != 3) {
                  bVar7 = (bVar2 == 0x6e) << 6;
                  if (bVar2 < 0x6e) goto LAB_rom_0169be;
                  bVar2 = bit_reverse8(stat_var_num);
                  uVar8 = (undefined)((ushort)out >> 8);
                  if ((bVar7 >> 6 & 1) != 0) {
                    return;
                  }
                  set_bit_hi(bVar2);
                  uVar11 = *(undefined *)unaff_ER12;
                  stat_layout((undefined8 *)(unaff_ER12 + 10));
                  uVar5 = CONCAT11(*(undefined *)unaff_ER12,unaff_R4) & 0xf0ff;
                  *(byte *)unaff_ER12 = (byte)(uVar5 >> 8) | (byte)uVar5;
                  out = (ushort *)(CONCAT11(uVar8,uVar11) & 0xff0f);
                  uVar4 = stat_fill_cells();
                  uVar5 = CONCAT11((char)((ushort)uVar4 >> 8) + -0x67,(char)uVar4);
                }
LAB_rom_01699a:
                if (4 < (byte)out) {
                  bVar2 = clear_bit_hi((byte)uVar5);
                  uVar5 = CONCAT11(extraout_R1_02,bVar2);
                }
              }
              goto LAB_rom_016a8e;
            }
          }
          else {
            if ((cVar10 == '\x01') || ((bVar7 < 0x90 && ((0x7f < bVar7 || (bVar7 < 0x60))))))
            goto LAB_rom_016af4;
            if (cVar6 != -0x58) {
              out = (ushort *)0x3;
              goto LAB_rom_016874;
            }
            uVar5 = matrix_advance(uVar5);
            out = (ushort *)CONCAT11((char)out,(char)((ushort)out >> 8));
          }
        }
        else {
          if (cVar6 == -0x6d) goto LAB_rom_016af4;
          if (cVar10 != -1) {
            out = (ushort *)(CONCAT11(bVar7,bVar2) & 0xff0f);
            if (cVar6 != -0x6e) {
              uVar5 = CONCAT11(cVar6 + -0x68,stat_var_num);
              if ((char)(cVar6 + -0x68) == '\0') goto LAB_rom_01699a;
              uVar5 = CONCAT11(cVar6 + -0x67,stat_var_num);
            }
            goto LAB_rom_0169be;
          }
        }
        cVar10 = (char)(uVar5 >> 8);
        uVar8 = (undefined)uVar5;
        bVar2 = (byte)out;
        if (cVar10 == -0x6c) {
          uVar5 = CONCAT11(0x14,uVar8);
LAB_rom_016a6a:
          if (4 < (bVar2 & 0xf)) {
            bVar2 = clear_bit_hi((byte)uVar5);
            uVar5 = CONCAT11(extraout_R1_04,bVar2);
          }
        }
        else {
          if (cVar10 == -0x55) {
            uVar5 = CONCAT11(0xd,uVar8);
            goto LAB_rom_016a6a;
          }
          if (cVar10 == -0x58) {
            bVar7 = (byte)((ushort)out >> 8);
            if ((char)((bVar7 < 0x90) << 7) < '\0') {
              if ((bVar7 < 0x80) && (0x5f < bVar7)) {
                uVar5 = CONCAT11(0xac,uVar8);
              }
            }
            else {
              uVar5 = CONCAT11(0xab,uVar8);
            }
          }
          bVar3 = (byte)uVar5;
          uVar5 = CONCAT11((char)(uVar5 >> 8) + 'c',bVar3);
          bVar7 = ((bVar2 & 0xf) == 5) << 6;
          if ((bVar2 & 0xf) < 5) {
            bVar3 = bit_reverse8(bVar3);
            bVar9 = (byte)((ushort)out >> 8);
            if ((bVar7 >> 6 & 1) == 1) {
              return;
            }
            set_bit_hi(bVar3);
            out = (ushort *)((ushort)bVar9 << 8);
            uVar5 = CONCAT11(*(undefined *)unaff_ER12,bVar2) & 0xf00f;
            *(byte *)unaff_ER12 = (byte)(uVar5 >> 8) | (byte)uVar5;
            uVar5 = stat_fill_cells();
          }
        }
        bVar2 = (byte)((ushort)out >> 8);
        if (((0x8f < bVar2) || ((bVar2 < 0x80 && (0x5f < bVar2)))) && (4 < (bVar2 & 0xf))) {
          bVar2 = clear_bit_hi((byte)uVar5);
          uVar5 = CONCAT11(extraout_R1_05,bVar2);
        }
      }
LAB_rom_016a8e:
      uVar8 = (undefined)((ushort)out >> 8);
      stat_var_num = (byte)uVar5;
      bVar2 = 0x7e;
    }
    cVar10 = calc_mode;
    bVar7 = (byte)(uVar5 >> 8);
    if (((char)((bVar7 < 0x17) << 7) < '\0') || (0x1c < bVar7)) {
      uVar8 = (undefined)((ushort)(unaff_ER12 + 10) >> 8);
    }
    bVar2 = ((code *)(*(ushort *)
                        CONCAT11(CARRY1(bVar2,bVar7) + '1' + CARRY1(bVar2 + bVar7,bVar7),
                                 bVar2 + bVar7 + bVar7) & 0x6ab8))(unaff_R6);
  }
LAB_rom_016abe:
  if (bVar2 == 0) {
    uVar5 = CONCAT11(uVar8,*(undefined *)unaff_ER12) & 0xfff0;
    bVar7 = (byte)uVar5;
    if (cVar10 == -0x3c) {
      if (bVar7 != 0x80) {
        if (bVar7 == 0x40) goto LAB_rom_016ade;
        bVar2 = dec_get_small(unaff_ER12,uVar5);
      }
    }
    else if (bVar7 < 0x60) {
LAB_rom_016ade:
      bVar2 = 0;
      dec_cmp_ex(unaff_ER12,uVar5);
    }
  }
  out = (ushort *)(ushort)bVar2;
LAB_rom_016874:
  matrix_fix_operand((char)out);
  return;
}

/**
 * @brief R5 非 0 或 R4>200 时直接返回（禁止打印/范围守卫）
 * @addr 0x16B4A
 * @module eval
 * @proto int emit_noop_guard(void)
 * @confidence verified
 * @note R5 非 0 或 R4>200 时直接返回（禁止打印/范围守卫）。
 * @tag util
 */
int emit_noop_guard(void)

{
  byte unaff_R4;
  char unaff_R5;
  
  if (unaff_R5 != '\0') {
    return 0;
  }
  if (200 < unaff_R4) {
    return 0;
  }
  return 0;
}

/**
 * @brief c 为左/右括号码（0x7D-0x82、0x87-0x8E、0x93-0x94）且 flag…
 * @addr 0x16B5C
 * @module eval
 * @proto byte is_paren_range(byte c, char flag)
 * @confidence likely
 * @note c 为左/右括号码（0x7D-0x82、0x87-0x8E、0x93-0x94）且 flag 为 0 时返回 1。
 * @tag parser
 */
byte is_paren_range(byte c, char flag)

{
  if ((flag == '\0') &&
     (((0x7c < c && (c < 0x83)) ||
      ((0x86 < c && ((c < 0x8f || ((0x92 < c && (c < 0x95)))))))))) {
    return 1;
  }
  return 0;
}

/**
 * @brief 遍历表达式序列
 * @addr 0x16B80
 * @module eval
 * @proto int matrix_walk(ushort tok)
 * @confidence likely
 * @note 遍历表达式序列：0x15EEA 分类后按括号/单元令牌调用 0x16820 求值（cVar5 控制模式）。
 * @tag matrix
 */
int matrix_walk(ushort tok)

{
  int cVar1;
  char cVar2;
  ushort *puVar3;
  byte bVar4;
  ushort unaff_ER4;
  char cVar5;
  char unaff_R10;
  char cVar6;
  byte bVar7;
  
  cVar5 = '\0';
  puVar3 = (ushort *)(tok & 0xff00);
  do {
    if (unaff_R10 == '\0') {
      return 0;
    }
    stat_entry_ptr();
    cVar2 = (char)(unaff_ER4 >> 8);
    bVar4 = (byte)unaff_ER4;
    if ((cVar2 == '\0') && (bVar4 == 0xdc)) {
      return 0;
    }
    cVar1 = token_class_ex(bVar4,cVar2);
    cVar6 = (cVar1 == '\0') << 6;
    if (cVar1 == '\0') {
      return 0;
    }
    emit_noop_guard();
    if ((cVar6 < '\0') && (cVar5 != '\0')) {
      if (cVar5 == '\x01') {
        cVar5 = '\x02';
      }
      else {
        bVar7 = (unaff_ER4 == 0) << 6;
        is_paren_range(bVar4,cVar2);
        if ((bVar7 >> 6 & 1) != 1) {
          if (bVar4 != 0x7d) {
            return 0;
          }
          cVar2 = return_ff();
          if (cVar2 == '\0') {
            return 0;
          }
        }
      }
    }
    unaff_R10 = unaff_R10 + -1;
    matrix_eval_tree(unaff_ER4,puVar3);
    if (cVar5 == '\x03') {
      return 0;
    }
  } while ((char)puVar3 == '\0');
  return 0;
}

/**
 * @brief 遍历表达式序列（模式 1 的变体）
 * @addr 0x16B84
 * @module eval
 * @proto int matrix_walk_b(ushort tok)
 * @confidence likely
 * @note 遍历表达式序列（模式 1 的变体）。
 * @tag matrix
 */
int matrix_walk_b(ushort tok)

{
  int cVar1;
  char cVar2;
  ushort *puVar3;
  byte bVar4;
  ushort unaff_ER4;
  char cVar5;
  char unaff_R10;
  char cVar6;
  byte bVar7;
  
  cVar5 = '\x01';
  puVar3 = (ushort *)(tok & 0xff00);
  do {
    if (unaff_R10 == '\0') {
      return 0;
    }
    stat_entry_ptr();
    cVar2 = (char)(unaff_ER4 >> 8);
    bVar4 = (byte)unaff_ER4;
    if ((cVar2 == '\0') && (bVar4 == 0xdc)) {
      return 0;
    }
    cVar1 = token_class_ex(bVar4,cVar2);
    cVar6 = (cVar1 == '\0') << 6;
    if (cVar1 == '\0') {
      return 0;
    }
    emit_noop_guard();
    if ((cVar6 < '\0') && (cVar5 != '\0')) {
      if (cVar5 == '\x01') {
        cVar5 = '\x03';
      }
      else {
        bVar7 = (unaff_ER4 == 0) << 6;
        is_paren_range(bVar4,cVar2);
        if ((bVar7 >> 6 & 1) != 1) {
          if (bVar4 != 0x7d) {
            return 0;
          }
          cVar2 = return_ff();
          if (cVar2 == '\0') {
            return 0;
          }
        }
      }
    }
    unaff_R10 = unaff_R10 + -1;
    matrix_eval_tree(unaff_ER4,puVar3);
    if (cVar5 == '\x03') {
      return 0;
    }
  } while ((char)puVar3 == '\0');
  return 0;
}

/**
 * @brief 遍历表达式序列（无模式预示的变体）
 * @addr 0x16B88
 * @module eval
 * @proto void matrix_walk_c(ushort tok)
 * @confidence likely
 * @note 遍历表达式序列（无模式预示的变体）。
 * @tag matrix
 */
int matrix_walk_c(ushort tok)

{
  int cVar1;
  char cVar2;
  ushort *puVar3;
  byte bVar4;
  ushort unaff_ER4;
  char unaff_R10;
  char cVar5;
  byte bVar6;
  
  puVar3 = (ushort *)(tok & 0xff00);
  do {
    if (unaff_R10 == '\0') {
      return 0;
    }
    stat_entry_ptr();
    cVar2 = (char)(unaff_ER4 >> 8);
    bVar4 = (byte)unaff_ER4;
    if ((cVar2 == '\0') && (bVar4 == 0xdc)) {
      return 0;
    }
    cVar1 = token_class_ex(bVar4,cVar2);
    cVar5 = (cVar1 == '\0') << 6;
    if (cVar1 == '\0') {
      return 0;
    }
    emit_noop_guard();
    if (cVar5 < '\0') {
      bVar6 = (unaff_ER4 == 0) << 6;
      is_paren_range(bVar4,cVar2);
      if ((bVar6 >> 6 & 1) != 1) {
        if (bVar4 != 0x7d) {
          return 0;
        }
        cVar2 = return_ff();
        if (cVar2 == '\0') {
          return 0;
        }
      }
    }
    unaff_R10 = unaff_R10 + -1;
    matrix_eval_tree(unaff_ER4,puVar3);
    if ((char)puVar3 != '\0') {
      return 0;
    }
  } while( true );
}

