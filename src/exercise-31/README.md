# 31 - 编写一个内核模块实现阶乘计算

难度：基础

## 描述

写一个内核模块，实现计算给定整数的阶乘。

给定整数应通过一个名为 `factorial_input` 的 kernel parameter 传入。

### 输入：

一个整数n（n >= 0）

### 输出：

整数n的阶乘值

### 示例：

输入：5
输出：120

### 本地测试

``` shell
make
insmod factorial.ko
rmmod factorial.ko factorial_input=N # 1,2,3,4,5,6,7, etc
```


## 如何通过测试

结果需以如下格式输出：

```c
printk(KERN_INFO "Factorial of %d is %d\n", n, result);
```
