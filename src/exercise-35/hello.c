
#include <linux/module.h>

/*
 * hello_init ---初始化函数，当模块装载时被调用，如果成功返回 0，否则返回非0值
 *
 */
static int __init
hello_init (void)
{

  printk (KERN_ALERT "hello world!\n");
  return 0;
}

/*
 * hello_exit ---退出函数，当模块卸载时被调用
 *
 */

static void __exit
hello_exit (void)
{

  printk (KERN_ALERT "exit kernel.\n");
}

module_init (hello_init);
module_exit (hello_exit);
MODULE_LICENSE ("GPL");
