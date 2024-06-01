# 33 - 编写一个内核模块实现平均数计算

难度：基础

## 描述

编写一个内核模块，

给定的数据应通过一个名为 `average_input` 的 kernel parameter 传入，使用 `,` 分割。

### 输入：

一组数字，使用 `,` 分割。

### 输出：

一个平均数。

### 示例：

输入：1,2,3,4,5
输出：3

### 本地测试

``` shell
make
insmod average_input.ko average_input=1,2,3,4,5
rmmod average_input.ko
```

## 如何通过测试

结果需以如下格式输出：

```c
printk (KERN_INFO "Average of the array: %d\n", avg);
```
