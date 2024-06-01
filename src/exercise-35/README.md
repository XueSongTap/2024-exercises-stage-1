# 35 - 编写一个内核模块延时打印字符串

难度：基础

## 描述

编写一个内核模块，延时打印一串字符 `Delay 2s!`

### 输入：

无

### 输出：

延时 2s 后打印 `Delay 2s!`。

### 示例：

输出：hello world!

### 本地测试

``` shell
make
insmod delay.ko
rmmod dealy.ko
```

## 如何通过测试

结果需以如下格式输出：

```c
printk (KERN_INFO "Delay 2s!"");
```
