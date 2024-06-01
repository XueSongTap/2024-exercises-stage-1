#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

static int factorial_input = 0;
module_param (factorial_input, int, S_IRUGO);
MODULE_PARM_DESC (factorial_input, "An integer input parameter");

static int
factorial (int n)
{
  /* >>> 实现 factorial 算法。*/


  /* <<<  */
}

static int __init
factorial_init (void)
{
  int n = factorial_input;
  int result = factorial (n);
  printk (KERN_INFO "Factorial of %d is %d\n", n, result);
  return 0;
}

static void __exit
factorial_exit (void)
{
  printk (KERN_INFO "Module unloaded\n");
}

/* >>> 加载和卸载内核模块。*/
module_init (factorial_init);
module_exit (factorial_exit);
/* <<<  */

MODULE_LICENSE ("GPL");
MODULE_AUTHOR ("Your Name");
MODULE_DESCRIPTION ("Factorial Calculation Module");
