#include <stdio.h>

#include "functions.h"

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
