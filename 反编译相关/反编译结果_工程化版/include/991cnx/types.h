#ifndef _991CNX_TYPES_H
#define _991CNX_TYPES_H
/* Ghidra 反编译结果使用的类型与辅助宏。
 * 仅为让整理后的源码保持可读、可解析，不保证与原机 ABI 一致。 */
#include <stdint.h>
#include <stddef.h>

typedef uint8_t   undefined;
typedef uint8_t   undefined1;
typedef uint16_t  undefined2;
typedef uint8_t   undefined3;
typedef uint32_t  undefined4;
typedef uint64_t  undefined5;
typedef uint64_t  undefined6;
typedef uint64_t  undefined7;
typedef uint64_t  undefined8;
typedef uint8_t   uchar;
typedef uint16_t  ushort;
typedef uint32_t  uint;
typedef uint64_t  ulonglong;
typedef int64_t   longlong;
typedef uint8_t   bool;
typedef uint8_t   byte;
typedef int8_t    sbyte;
typedef uint32_t  uint3;
typedef uint32_t  uint5;
typedef uint32_t  uint6;
typedef uint64_t  uint7;
typedef int32_t   int3;
typedef int32_t   int5;
typedef int32_t   int6;
typedef int64_t   int7;
typedef void      code;      /* 函数指针转换：(*(code *)addr)() */
/* 常量 RAM 地址访问 */
#define RAM8(addr)  (*(volatile uint8_t  *)(uintptr_t)(addr))
#define RAM16(addr) (*(volatile uint16_t *)(uintptr_t)(addr))

/* BCD 浮点数：首字节 = 类型/符号，中间 7 字节 = 15 位十进制有效数字，
 * 末 2 字节 = 指数与符号（详见 docs/内存映射.md）。 */
typedef uint8_t   dec10[10];

#ifndef true
#define true  1
#define false 0
#endif

/* Ghidra 的位拼接宏（按“高字节在前”拼接） */
#define CONCAT11(a,b)  ((uint16_t)((((uint16_t)(uint8_t)(a)) << 8)  | (uint8_t)(b)))
#define CONCAT12(a,b)  ((uint32_t)((((uint32_t)(uint8_t)(a)) << 8)  | (uint8_t)(b)))
#define CONCAT13(a,b)  ((uint32_t)((((uint32_t)(uint8_t)(a)) << 16) | (uint16_t)(b)))
#define CONCAT14(a,b)  ((uint32_t)((((uint32_t)(uint8_t)(a)) << 24) | (uint32_t)(b)))
#define CONCAT15(a,b)  ((uint64_t)((((uint64_t)(uint8_t)(a)) << 32) | (uint32_t)(b)))
#define CONCAT16(a,b)  ((uint64_t)((((uint64_t)(uint8_t)(a)) << 40) | (uint64_t)(b)))
#define CONCAT17(a,b)  ((uint64_t)((((uint64_t)(uint8_t)(a)) << 48) | (uint64_t)(b)))
#define CONCAT21(a,b)  ((uint32_t)((((uint32_t)(uint16_t)(a)) << 16) | (uint16_t)(b)))
#define CONCAT22(a,b)  ((uint32_t)((((uint32_t)(uint16_t)(a)) << 16) | (uint16_t)(b)))
#define CONCAT24(a,b)  ((uint64_t)((((uint64_t)(uint32_t)(a)) << 16) | (uint16_t)(b)))
#define CONCAT26(a,b)  ((uint64_t)((((uint64_t)(uint16_t)(a)) << 32) | (uint32_t)(b)))
#define CONCAT31(a,b)  ((uint32_t)((((uint32_t)(uint8_t)(a)) << 24) | (uint32_t)(b)))
#define CONCAT35(a,b)  ((uint64_t)((((uint64_t)(uint8_t)(a)) << 40) | (uint64_t)(b)))
#define CONCAT41(a,b)  ((uint64_t)((((uint64_t)(uint8_t)(a)) << 32) | (uint32_t)(b)))
#define CONCAT42(a,b)  ((uint64_t)((((uint64_t)(uint16_t)(a)) << 32) | (uint32_t)(b)))
#define CONCAT44(a,b)  ((uint64_t)((((uint64_t)(uint32_t)(a)) << 32) | (uint32_t)(b)))
#define CONCAT51(a,b)  ((uint64_t)((((uint64_t)(uint8_t)(a)) << 48) | (uint64_t)(b)))
#define CONCAT52(a,b)  ((uint64_t)((((uint64_t)(uint8_t)(a)) << 40) | (uint64_t)(b)))
#define CONCAT53(a,b)  ((uint64_t)((((uint64_t)(uint8_t)(a)) << 32) | (uint64_t)(b)))
#define CONCAT61(a,b)  ((uint64_t)((((uint64_t)(uint8_t)(a)) << 56) | (uint64_t)(b)))
#define CONCAT62(a,b)  ((uint64_t)((((uint64_t)(uint16_t)(a)) << 48) | (uint64_t)(b)))
#define CONCAT71(a,b)  ((uint64_t)((((uint64_t)(uint8_t)(a)) << 56) | (uint8_t)(b)))
/* 零扩展 / 截断 */
#define ZEXT12(a)  ((uint16_t)(uint8_t)(a))
#define ZEXT13(a)  ((uint32_t)(uint8_t)(a))
#define ZEXT14(a)  ((uint32_t)(uint8_t)(a))
#define ZEXT23(a)  ((uint32_t)(uint16_t)(a))
#define ZEXT24(a)  ((uint32_t)(uint16_t)(a))
#define ZEXT26(a)  ((uint64_t)(uint16_t)(a))
#define ZEXT28(a)  ((uint64_t)(uint16_t)(a))
#define CONCAT32(a,b)  ((uint32_t)((((uint32_t)(uint8_t)(a)) << 16) | (uint16_t)(b)))
#define CONCAT33(a,b)  ((uint64_t)((((uint64_t)(uint16_t)(a)) << 16) | (uint16_t)(b)))
#define CONCAT34(a,b)  ((uint64_t)((((uint64_t)(uint8_t)(a)) << 16) | (uint16_t)(b)))
#define CONCAT43(a,b)  ((uint64_t)((((uint64_t)(uint8_t)(a)) << 32) | (uint32_t)(b)))
#define SUB21(a,b) ((uint16_t)((uint8_t)(a) - (uint16_t)(b)))
#define SUB41(a,b) ((uint32_t)((uint8_t)(a) - (uint32_t)(b)))
/* 标志位 */
#define CARRY1(a,b)   ((uint8_t)((((a) & 1) + ((b) & 1)) >= 2))
#define CARRY2(a,b)   ((uint16_t)((((a) & 1) + ((b) & 1)) >= 2))
#define SBORROW1(a,b) ((uint8_t)((int8_t)(a) < (int8_t)(b)))
#define SBORROW2(a,b) ((uint16_t)((int16_t)(a) < (int16_t)(b)))
#define SCARRY1(a,b)  ((uint8_t)(((int8_t)(a) + (int8_t)(b)) < 0))
#define SCARRY2(a,b)  ((uint16_t)(((int16_t)(a) + (int16_t)(b)) < 0))

/* 参数聚合：Ghidra 用 64/72 位整数一次性传递多个小参数 */
static inline uint64_t pack64(uint32_t a, uint32_t b) { return ((uint64_t)a << 32) | b; }
static inline uint32_t pack32(uint16_t a, uint16_t b) { return ((uint32_t)a << 16) | b; }
/* 结构体/数组整体赋值（原机为块复制） */
static inline void memcpy_sym(void *dst, const void *src, size_t n) { (void)dst; (void)src; (void)n; }

/* Ghidra 内建伪函数 */
static inline void halt_baddata(void) {}
static inline void nop(void) {}
static inline void enable_maskable_interrupts(void) {}
static inline void disable_maskable_interrupts(void) {}
static inline uint8_t daa(uint8_t v) { return v; }
static inline uint8_t das(uint8_t v) { return v; }

#endif
