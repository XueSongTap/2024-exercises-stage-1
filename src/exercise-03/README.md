# 03 - 使用 Makefile 进行静态链接

难度：入门。

## 描述

> 此题希望你能掌握基础的 Makefile 编写规则。

在这个练习中，你将编译和链接两个源文件 functions.c 和 main.c 以生成一个可执行程序。修改 Makefile，能够将 `functions.c` 编译为中间产物 `functions.a`，最终使用该产物静态链接出可执行程序并运行它。此处的“它”指能够成功生成 Makefile 中的 `TARGET` 和 `TEST_TARGET`。

## 描述

> 修改Makefile文件，使用static进行编译，生成可执行程序myprogram

## 输入与输出

运行可执行程序，能够打印出"Hello, world!"

## 构建


``` shell
make
make test
```
