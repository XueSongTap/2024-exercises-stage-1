#include <stdio.h>
#include <stdlib.h>

// RISC-V 汇编内联汇编函数，用于计算两个整数的最大公因数
int
gcd (int a, int b)
{
  int result; // 用于保存计算结果

  // >>> 替换 PLACEHOLDER 为合适的指令完成注释的功能

  __asm__ volatile (
      // 用于循环条件判断的标签
      "loop:\n\t"
      // 判断 a 和 b 是否相等，如果相等，则跳出循环
      "PLACEHOLDER\n\t"
      // 判断 b 是否小于 a,跳到 a_greater
      "PLACEHOLDER\n\t"
      // 如果 a 小于 b，则执行 b = b - a
      "sub %2, %2, %1\n\t"
      "jal x0, loop\n\t"
      // 如果b小于a，则执行 a = a - b
      "a_greater:\n\t"
      "sub %1, %1, %2\n\t"
      "jal x0, loop\n\t"
      // 循环结束标签
      "end:\n\t"
      // 最终结果存储在 %0 中
      "mv %0, %1\n\t"
      : "=r"(result) // 使用寄存器约束符号 "="，表示输出使用该寄存器
      : "r"(a), "r"(b) // 输入寄存器
  );

  // <<<
  return result;
}

int
main (int argc, char *argv[])
{
  if (argc != 3)
    {
      fprintf (stderr, "Usage: %s <integer1> <integer2>\n", argv[0]);
      return 1;
    }

  int a = atoi (argv[1]);
  int b = atoi (argv[2]);

  printf ("GCD of %d and %d is %d\n", a, b, gcd (a, b));
  return 0;
}
