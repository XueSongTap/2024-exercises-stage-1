#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

#define MAX_ARRAY_SIZE 10

static int average_input[MAX_ARRAY_SIZE];
static int average_input_size = 0;

/* 理解 module_param_array 是如何工作的 */
module_param_array (average_input, int, &average_input_size, 0444);
MODULE_PARM_DESC (average_input, "An array of integers");

static int
average (int arr[], int size)
{
  /* >>> 求并返回平均数 */
 int sum = 0;
 for (int i = 0; i < size; ++ i) {
  sum += arr[i];
 }
 return sum /size;
  /* <<< */
}

static int __init
average_init (void)
{
  /*
    初始化 average.ko，注意：你需要检查 average_input_size < MAX_ARRAY_SIZE。
    >>>
   */
  if (average_input_size > MAX_ARRAY_SIZE)
    {
      printk (KERN_WARNING "Array size exceeds maximum limit of %d\n",
              MAX_ARRAY_SIZE);
      return -EINVAL;
    }

  int avg = average (average_input, average_input_size);
  printk (KERN_INFO "Average of the array: %d\n", avg);

  /*
    <<<
   */

  return 0;
}

static void __exit
average_exit (void)
{
  printk (KERN_INFO "Module unloaded\n");
}

module_init (average_init);
module_exit (average_exit);

MODULE_LICENSE ("GPL");
MODULE_AUTHOR ("Your Name");
MODULE_DESCRIPTION (
    "Array Average Calculation Module using Kernel Parameters");
