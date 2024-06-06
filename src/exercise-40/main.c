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
      //blt 指令是有符号的比较小于指令，如果第一个操作数小于第二个操作数，跳转到指定的标签。
      // %0, %1, %2 分别表示用于输出的操作数位置。
      // greater_equal 标签是一个条件跳转的目标标签，如果 a 大于等于 b，则跳转到此处。
      //       
      "blt %2, %1, greater_equal\n"   // 如果 a < b，跳转到 greater_equal 标签
      "mv %0, %2\n"                    // 将 b 的值移动到结果中
      "j end\n"                        // 无条件跳转到结束标签
      "greater_equal:\n"               // greater_equal 标签，如果跳转到此处，则说明 a >= b
      "mv %0, %1\n"                    // 将 a 的值移动到结果中
      "end:\n"                         // 结束标签
      : "=r"(result)                   // 告诉编译器我们将使用寄存器约束来输出 result
      : "r"(a), "r"(b));               // 告诉编译器我们将使用寄存器约束来输入 a 和 b

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
