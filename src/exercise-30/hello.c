
#include <linux/module.h>

/*
 * hello_init ---初始化函数，当模块装载时被调用，如果成功返回 0，否则返回非0值
 *
 */
static int __init
hello_init (void)
{

  // >>> 在这里编写如何使用打印函数 输出 hello world!

  // <<<

  return 0;
}

/*
 * hello_exit ---退出函数，当模块卸载时被调用
 *
 */

static void __exit
hello_exit (void)
{

  // >>> 在这里编写如何使用打印函数输出 exit world!

  // <<<
}

// >>> 在这里编写模块的入口和出口
module_init (hello_init);
module_exit (hello_exit);
// <<<

MODULE_LICENSE ("GPL");
