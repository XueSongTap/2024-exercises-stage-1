#include <stdio.h>
#include <stdlib.h>

// 使用内联汇编实现条件跳转逻辑的函数
int
conditional_jump (int a, int b)
{
  int result;

  // 内联汇编，实现条件跳转逻辑
  //
  // TIP:
  // 1. 如果a >= b，跳转到greater_equal标签
  // 2. 将b的值移动到结果中
  // 3. 无条件跳转到结束标签
  //
  // greater_equal标签
  // 1. 将a的值移动到结果中
  //
  // 结束标签
  // 输出操作数，result 用来存储返回值

  // >>> 替换 PLACEHOLDER 为合适的指令完成注释的功能
  __asm__ volatile (
      // 实现 a >= b,跳转到 greater_equal
      "PLACEHOLDER\n"
      "mv %0, %2\n"
      "j end\n"
      "greater_equal:\n"
      "mv %0, %1\n"
      "end:\n"
      : "=r"(result)
      : "r"(a), "r"(b));

  // <<<

  return result;
}

int
main (int argc, char *argv[])
{

  if (argc != 3)
    {
      printf ("Usage: %s <int a> <int b>\n", argv[0]);
      return 1;
    }

  int a = atoi (argv[1]);
  int b = atoi (argv[2]);

  // 调用函数并输出结果
  int result = conditional_jump (a, b);
  printf ("Result: %d\n", result);

  return 0;
}
