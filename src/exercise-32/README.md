# 32 - 编写一个内核模块实现字符串反转

难度：基础

## 描述

编写一个内核模块，接收一个字符串作为输入，将其反转后输出。

给定字符串应通过一个名为 `reverse_string_input` 的 kernel parameter 传入。

### 输入：

一个字符串（长度 >0）。

### 输出：

反转后的字符串。

### 示例：

输入：hello
输出：olleh

### 本地测试

``` shell
make
insmod reverse_string.ko
rmmod reverse_string.ko reverse_string_input="hello"
```

## 如何通过测试

结果需以如下格式输出：

```c
printk (KERN_INFO "Reversed string: %s\n", str);
```
