# 05 - 使用 Makefile 构建第一个动态链接库

难度：入门。

## 描述

> 此题希望你能掌握基础的 Makefile 编写规则。

修改 Makefile，能够将 `functions.c` 编译为动态链接库 `libfunctions.so`，最终使用该库编译出可执行程序并运行它。此处的“它”指能够成功生成 Makefile 中的 `TARGET` 和 `TEST_TARGET`。

## 构建

``` shell
make all
```

## 如何通过测试

预期能够编译出二进制程序并可执行。

**注意**

请不要修改 C 源代码文件。
