/* 固件主函数（0x24E36）。
 * 固件 main 返回 void，不符合宿主 C 的 main 约定，因此 all.h 不声明它；
 * 这里用 extern 声明后由 firmware_entry 调用。 */
#include "991cnx/all.h"
extern void main(byte *input);

void firmware_entry(void)
{
  main((byte *)0);
}
