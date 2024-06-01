# 34 - 编写一个内核模块实现线性查找

难度：基础

## 描述

编写一个内核模块，

给定的数据应通过一个名为 `ls_array_input` 的 kernel parameter 传入，使用 `,` 分割。

查找的目标应通过一个名为 `ls_target` 的 kernel parameter 传入。

### 输入：

1. 一组数字，使用 `,` 分割。
2. 一个数字，必须包含在上述组中。

### 输出：

目标在给定数组中的下标。

### 示例：

输入：
    1. 3,6,9,12,15
    2. 12
输出：3

### 本地测试

``` shell
make
insmod linear_search.ko ls_array_input=3,6,9,12,15 ls_target=12
rmmod linear_search.ko
```

## 如何通过测试

结果需以如下格式输出：

```c
printk (KERN_INFO "Index of %d in the array: %d\n", target, result);
```
