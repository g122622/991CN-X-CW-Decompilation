/*
 * 输入编辑器 / 0adce_buffer_transfer.c
 * 地址范围: 0x0ADCE - 0x0B3DC
 * 由 toolchain/build_project.py 自动生成；请勿手工修改。
 */
#include "991cnx/all.h"

/**
 * @brief 缓冲区搬运
 * @addr 0x0ADCE
 * @module editor
 * @proto void buffer_transfer(void)
 * @confidence likely
 * @note 缓冲区搬运：在 0xD180 与 0xE5A 区之间复制编辑行（0x9972/0xED28/0x24A20 使用）。
 * @tag editor
 */
int buffer_transfer(uintptr_t _a2, int _a1)

{
  byte *pbVar1;
  byte bVar2;
  bool bVar3;
  byte *pbVar4;
  ushort uVar5;
  undefined extraout_R1;
  byte *pbVar6;
  byte *pbVar7;
  byte *pbVar8;
  short unaff_ER14;
  
  pbVar4 = (byte *)frame_enter();
  *(byte *)(unaff_ER14 + -3) = key_modifiers & 0x40;
  pbVar6 = pbVar4;
  pbVar7 = _a1;
  do {
    uVar5 = token_pair_class((char *)pbVar6);
    bVar2 = (byte)uVar5;
    if (((-(ushort)(bVar2 < 7) & 0x100) != 0 || bVar2 == 7 && (char)-(ushort)(bVar2 < 7) == '\0') &&
       ((-(ushort)(bVar2 == 0) & 0x100) == 0)) {
      uVar5 = (uVar5 & 0xff) - 1;
                    // WARNING: Could not emulate address calculation at 0x00ae08
                    // WARNING: Treating indirect jump as call
      ((void)0);
      return 0;
    }
    *pbVar7 = *pbVar6;
    pbVar8 = pbVar7 + 1;
    if (*(char *)(unaff_ER14 + 0x12) == '\0') {
      if (_a1 + *(byte *)(unaff_ER14 + 0x10) + 1 == pbVar8) {
        bVar2 = *pbVar6;
        if ((bVar2 == 0x1e) || (bVar2 == 0x1a)) {
          pbVar6 = pbVar6 + 1;
        }
        else if (bVar2 == 0x1d) {
          pbVar6 = pbVar6 + -1;
        }
        if (*pbVar6 == 0x1f) {
          pbVar6 = prev_char_ptr(pbVar4,pbVar6);
        }
        goto LAB_rom_00ae82;
      }
    }
    else if (((*(char *)(unaff_ER14 + -3) != '\0') && (input_end_ptr == pbVar8)) &&
            (input_ptr == pbVar4)) {
      input_ptr = pbVar6 + 1;
    }
    bVar2 = *pbVar6;
    *(byte *)(unaff_ER14 + -2) = bVar2;
    bVar3 = is_neg_char(bVar2);
    pbVar1 = pbVar6 + 1;
    if (CONCAT11(extraout_R1,bVar3) != 0) {
      *pbVar8 = pbVar6[1];
      pbVar8 = pbVar7 + 2;
      pbVar1 = pbVar6 + 2;
    }
    pbVar6 = pbVar1;
    pbVar7 = pbVar8;
  } while (*(char *)(unaff_ER14 + -2) != '\0');
  if (*(char *)(unaff_ER14 + 0x12) == '\0') {
LAB_rom_00ae82:
    history_cursor = (char)pbVar6 - (char)pbVar4;
  }
  frame_leave();
  return 0;
}

/**
 * @brief 返回输入区可用列数
 * @addr 0x0AF52
 * @module editor
 * @proto byte input_cols(void)
 * @confidence strong
 * @note 返回输入区可用列数：当前行 0xD137 == 10 时为 5，否则为 7。
 * @tag editor
 */
byte input_cols(void)

{
  undefined uVar1;
  
  uVar1 = 7;
  if (cur_line == '\n') {
    uVar1 = 5;
  }
  return uVar1;
}

/**
 * @brief 返回下一个字符指针
 * @addr 0x0AF62
 * @module editor
 * @proto byte* char_ptr_next(byte* p)
 * @confidence verified
 * @note 返回下一个字符指针：p 处为双字节字符（>=0xF0）时 p+2，否则 p+1。
 * @tag editor
 */
byte* char_ptr_next(byte* p)

{
  byte *pbVar1;
  
  if ((char)((*p < 0xf0) << 7) < '\0') {
    pbVar1 = p + 1;
  }
  else {
    pbVar1 = p + 2;
  }
  return pbVar1;
}

/**
 * @brief 返回 p 处词法单元分类，编辑器据���区分数字/运算符/括号
 * @addr 0x0AF74
 * @module editor
 * @proto ushort token_class(char* p)
 * @confidence strong
 * @note 返回 p 处词法单元分类，编辑器据���区分数字/运算符/括号。
 * @tag editor
 */
ushort token_class(char* p)

{
  int cVar1;
  char cVar2;
  
  cVar1 = char_class();
  if ((((cVar1 == '\x01') && (cVar2 = p[1], cVar2 != '\x1a')) && (cVar2 != '\x1d')) &&
     (cVar2 != '\x1f')) {
    if (*p == '\x18') {
      cVar1 = '\r';
    }
    else if (*p == -0x38) {
      cVar1 = '\0';
    }
    else {
      cVar1 = '\n';
    }
  }
  return CONCAT11(cVar1,cVar1);
}

/**
 * @brief 按模式取编辑行长度（0x9B6E），检查 0x22CA0/0x2696E/0x9DC8 后把…
 * @addr 0x0AFAE
 * @module editor
 * @proto void name_buffer_load(void)
 * @confidence likely
 * @note 按模式取编辑行长度（0x9B6E），检查 0x22CA0/0x2696E/0x9DC8 后把 0x178 处的编辑行复制到
 *       0xD180 缓冲（矩阵/列表变量命名）。
 * @tag editor
 */
int name_buffer_load(void)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  char cVar4;
  undefined2 unaff_ER14;
  
  frame_enter();
  bVar1 = input_max_len();
  bVar3 = (byte)unaff_ER14;
  cVar4 = (char)((ushort)unaff_ER14 >> 8);
  cVar2 = token_paste_check((undefined *)CONCAT11(cVar4 + -1 + (199 < bVar3),bVar3 + 0x38));
  if (cVar2 != '\0') {
    cVar2 = token_array_find(CONCAT11(cVar4 + -2 + (0x8f < bVar3),bVar3 + 0x70));
    if ((cVar2 != '\0') &&
       ((cVar2 = is_math_io(), cVar2 == '\0' ||
        (cVar2 = input_context_switch((short *)CONCAT11(cVar4 + -2 + (0x93 < bVar3),bVar3 + 0x6c)),
        cVar2 != '\0')))) {
      memcpy_bytes(&input_buf,(undefined *)CONCAT11(cVar4 + -2 + (0x8f < bVar3),bVar3 + 0x70), (uintptr_t)0)
                     (ushort)bVar1);
    }
  }
  frame_leave();
  return 0;
}

/**
 * @brief 先 0xC056 设置键边沿，再调用 0x9E4C
 * @addr 0x0B156
 * @module editor
 * @proto void wrap_9e4c(undefined2 er0)
 * @confidence likely
 * @note 先 0xC056 设置键边沿，再调用 0x9E4C；第二参数非 0 时调用 0x20EC8。
 * @tag editor
 */
int wrap_9e4c(undefined2 er0)

{
  undefined2 uVar1;
  short unaff_ER14;
  
  uVar1 = frame_enter();
  set_key_edge(uVar1,*(char *)(unaff_ER14 + 0x10));
  append_number_str(er0);
  if (*(char *)(unaff_ER14 + 0x10) != '\0') {
    str_emit_1B1E();
  }
  frame_leave();
  return 0;
}

/**
 * @brief 对返回值做 0x12D3A 处理（二进制转串并写回）
 * @addr 0x0B17E
 * @module editor
 * @proto int wrap_12d3a(undefined2 er0)
 * @confidence likely
 * @note 对返回值做 0x12D3A 处理（二进制转串并写回）。
 * @tag editor
 */
int wrap_12d3a(undefined2 er0)

{
  frame_enter();
  eval_to_bcd_slot(er0);
  frame_leave();
  return 0;
}

/**
 * @brief 以 er0 调用 0x29614（主编辑循环）
 * @addr 0x0B1A4
 * @module editor
 * @proto void wrap_29614(undefined2 er0)
 * @confidence strong
 * @note 以 er0 调用 0x29614（主编辑循环）。
 * @tag editor
 */
int wrap_29614(undefined2 er0)

{
  frame_enter();
  editor_main(er0);
  frame_leave();
  return 0;
}

/**
 * @brief 在编辑行末尾追加函数调用 token（0x19 前缀）并复制 len 字节参数
 * @addr 0x0B356
 * @module editor
 * @proto void append_call_token(byte code, byte len)
 * @confidence likely
 * @note 在编辑行末尾追加函数调用 token（0x19 前缀）并复制 len 字节参数。
 * @tag editor
 */
int append_call_token(byte code, byte len)

{
  byte bVar1;
  char *pcVar2;
  undefined2 uVar3;
  char *pcVar4;
  
  pcVar2 = (char *)frame_enter();
  bVar1 = strline_len(pcVar2);
  pcVar2 = pcVar2 + bVar1;
  if (len == 0) {
    *pcVar2 = '\x19';
    pcVar2 = pcVar2 + 1;
  }
  else {
    pcVar4 = (char *)CONCAT11((0x7f < code) + -0x2f,(uintptr_t)code + 0x80);
    uVar3 = is_ws_scan(pcVar4);
    if ((char)uVar3 != '\0') {
      *pcVar2 = '\x19';
      pcVar2 = pcVar2 + 1;
    }
    bVar1 = 0;
    do {
      *pcVar2 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      pcVar2 = pcVar2 + 1;
      bVar1 = bVar1 + 1;
    } while ((char)((bVar1 < len) << 7) < '\0');
  }
  *pcVar2 = '\0';
  frame_leave();
  return 0;
}

/**
 * @brief 在输入区历史记录尾部插入 # 记号（0x25388 查找），按 0xD10E bit7 选择…
 * @addr 0x0B3DC
 * @module editor
 * @proto void input_mark_hash(void)
 * @confidence likely
 * @note 在输入区历史记录尾部插入 # 记号（0x25388 查找），按 0xD10E bit7 选择偏移 10 或 0x14。
 * @tag editor
 */
int input_mark_hash(void)

{
  byte *pbVar1;
  undefined *puVar2;
  byte bVar3;
  
  pbVar1 = (byte *)frame_enter();
  bVar3 = 10;
  puVar2 = history_base_ptr();
  if (puVar2 != (undefined *)0x0) {
    if ((*pbVar1 & 0x80) != 0) {
      bVar3 = 0x14;
    }
    strchr((char *)(pbVar1 + bVar3 + 3),'#');
  }
  frame_leave();
  return 0;
}

