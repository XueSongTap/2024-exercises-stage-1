# 42 - 使用内联  RISCV 汇编实现数组元素查找

## 描述

设计一个C语言函数 `find_value`，接受一个整数数组 `arr`、数组的长度 `n`、一个目标值 `target`，以及一个起始索引 `start_index`，返回目标值在数组中从指定起始索引开始的第一次出现的索引。如果目标值不在数组中或起始索引超出数组范围，则返回 `-1`。然后编写一个程序调用该函数，并输出结果。

## 输入

1. 一个整数数组 `arr`，以逗号分割，比如 `1,2,3,4,5`；
2. 一个整数 `n`；
3. 一个目标 `target`；
4. 一个索引 `start_index`；

输入保证在`int`类型范围内。

## 输出

返回字符串格式 `Index of target from start index: INDEX`，`INDEX` 表示`target`在指定数组范围内的索引，若没有该元素，返回字符串 `Target not found or start index out of range.`。`

## 如何通过测试

保持输出格式为 `Index of target from start index: INDEX`。



