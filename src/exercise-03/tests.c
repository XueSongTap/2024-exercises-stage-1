#include <stdio.h>

// 声明外部函数
extern void hello ();

// 测试函数
void
test_hello ()
{
  printf ("Running test_hello...\n");
  hello ();
}

int
main ()
{
  test_hello ();
  printf ("All tests passed.\n");
  return 0;
}
