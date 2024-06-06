#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/string.h>

#define MAX_LEN 100

static char reverse_string_input[MAX_LEN] = "\0";
module_param_string (reverse_string_input, reverse_string_input, MAX_LEN,
                     S_IRUGO);
MODULE_PARM_DESC (reverse_string_input, "A character string input parameter");

static void /* -> 我们原地对 reverse_string_input 进行处理。 */
reverse_string (char *str)
{
  int len = strlen (str);
  int i;
  char temp;
  for (i = 0; i < len / 2; i++)
    {
      temp = str[i];
      // >>> 在这里编写调换的功能
      str[i] = str[len - 1 -i];
      str[len - 1 -i] = temp;
      // <<<
    }
}

static int __init
reverse_init (void)
{
  printk (KERN_INFO "Original string: %s\n", reverse_string_input);
  reverse_string (reverse_string_input);
  printk (KERN_INFO "Reversed string: %s\n", reverse_string_input);
  return 0;
}

static void __exit
reverse_exit (void)
{
  printk (KERN_INFO "Module unloaded\n");
}

module_init (reverse_init);
module_exit (reverse_exit);

MODULE_LICENSE ("GPL");
MODULE_AUTHOR ("Your Name");
MODULE_DESCRIPTION ("String Reversal Module");
