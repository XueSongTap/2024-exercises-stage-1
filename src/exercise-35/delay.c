#include <linux/delay.h>
#include <linux/kernel.h>
#include <linux/module.h>

static int __init
delay_init (void)
{
  // >>> 在这里编写延时功能，并打印 Delay 2s!
  msleep(2000);  // 延时2秒
  printk (KERN_INFO "Delay 2s!\n");
  // <<<
  return 0;
}

static void __exit
delay_exit (void)
{
  printk (KERN_ALERT "exit kernel.\n");
}

module_init (delay_init);
module_exit (delay_exit);
MODULE_LICENSE ("GPL");
