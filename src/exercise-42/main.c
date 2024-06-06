#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// RISC-V 汇编内联汇编函数，用于在指定起始索引开始查找目标值的索引
int
find_value (int *arr, int n, int target, int start_index)
{
  int index = -1; // 默认为目标值未找到或起始索引超出数组范围

  // >>> 替换 PLACEHOLDER 为合适的指令完成注释的功能
  __asm__ volatile (
      // 检查起始索引是否超出数组范围 
      "bge %4, %2, out_of_range\n\t" // 如果 start_index >= n，则跳转到 out_of_range 标签
      "blt %4, x0, out_of_range\n\t" // 如果起始索引 start_index < 0，则跳转到
                                     // out_of_range 标签
      // 用于循环计数的寄存器
      "li t0, 0\n\t"
      "sub t3,%2,%4\n\t"
      // 将 start_index 乘以 4（整数大小）保存到t2寄存器
      "slli t2, %4, 2\n\t"
      "add %1, %1, t2\n\t" // 将计算的偏移量添加到数组指针中
      "loop:\n\t"
      // 使用 load 指令将 arr[i] 加载到 t1 寄存器
      "lw t1, 0(%1)\n\t"
      // 比较 arr[i] 和目标值
      "beq t1, %3, found\n\t" // 如果 arr[i] == target，则跳转到 found 标签
      "bne t0, t3, next\n\t" // 如果循环计数 t0 != n，则跳转到 next 标签
      "jal x0, out_of_range\n\t" // 否则跳转到 out_of_range 标签
      "found:\n\t"
      // 如果找到目标值，保存索引并跳转到 end 标签
      "mv %0, t0\n\t"
      "jal x0, end\n\t"
      "next:\n\t"
      // 指针增加 4，指向下一个元素
      "addi %1, %1, 4\n\t"
      // 循环计数加 1
      "addi t0, t0, 1\n\t"
      // 判断是否达到循环结束条件
      "blt t0, t3, loop\n\t"
      "jal x0, out_of_range\n\t"
      "out_of_range:\n\t"
      // 如果起始索引超出数组范围，返回 -1
      "li %0, -1\n\t"
      "end:\n\t"
      : "=r"(index)
      : "r"(arr), "r"(n), "r"(target), "r"(start_index)
      : "t0", "t1", "t2", "t3");

//<<<
  return index;
}

int
main (int argc, char *argv[])
{
  if (argc != 5)
    {
      fprintf (stderr, "Usage: %s <n> <arr> <target> <start_index>\n",
               argv[0]);
      return 1;
    }

  int n = atoi (argv[1]);
  int arr[n];

  // 解析逗号分隔的数组字符串
  char *arr_str = argv[2];
  char *token = strtok (arr_str, ",");
  int i = 0;
  while (token != NULL)
    {
      if (i >= n)
        {
          fprintf (stderr, "Error: Expected %d array elements but got more.\n",
                   n);
          return 1;
        }
      arr[i++] = atoi (token);
      token = strtok (NULL, ",");
    }
  if (i != n)
    {
      fprintf (stderr, "Error: Expected %d array elements but got %d.\n", n,
               i);
      return 1;
    }

  int target = atoi (argv[3]);
  int start_index = atoi (argv[4]);

  int index = find_value (arr, n, target, start_index);
  if (index != -1)
    printf ("Index of target from start index: %d\n", index + start_index);
  else
    printf ("Target not found or start index out of range.\n");

  return 0;
}
