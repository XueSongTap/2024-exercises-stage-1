#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

#define MAX_ARRAY_SIZE 10

static int ls_array_input[MAX_ARRAY_SIZE];
static int ls_array_input_size = 0;

module_param_array (ls_array_input, int, &ls_array_input_size, 0444);
MODULE_PARM_DESC (ls_array_input, "An array of integers");

static int ls_target = 0;

module_param (ls_target, int, S_IRUGO);
MODULE_PARM_DESC (ls_target, "An integer input parameter");

static int
linear_search (int arr[], int size, int target)
{
  int i;

  // >>> 在这里编写功能，返回匹配的索引

  // <<<

  return -1;
}

static int __init
search_init (void)
{
  /*
    初始化 linear_search.ko，注意：你需要检查 ls_array_input_size 小于
    MAX_ARRAY_SIZE。
    >>>
   */
  if (ls_array_input_size > MAX_ARRAY_SIZE)
    {
      printk (KERN_WARNING "Array size exceeds maximum limit of %d\n",
              MAX_ARRAY_SIZE);
      return -EINVAL;
    }

  int result = linear_search (ls_array_input, ls_array_input_size, ls_target);
  printk (KERN_INFO "Index of %d in the array: %d\n", ls_target, result);

  /*
   <<<
  */

  return 0;
}

static void __exit
search_exit (void)
{
  printk (KERN_INFO "Module unloaded\n");
}

module_init (search_init);
module_exit (search_exit);

MODULE_LICENSE ("GPL");
MODULE_AUTHOR ("Your Name");
MODULE_DESCRIPTION ("Linear Search Module");
