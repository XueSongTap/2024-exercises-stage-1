# 14 - 编写一个简单的 ld 文件并指定自定义 section

难度：基础。

## 描述

编写一个 ld 文件（命名为 `custom_section_.ld`），设置内存区域起始地址为 `0x8000000`，长度为 `0x2000`，指定 setions 包含一个自定义的 section 名为 `my_custom_section`，并在 `my_custom_section` 内放置 `my_custom_data`，其地址为 `0x1234`。

## 构建

``` shell
make all
```

## 如何通过测试

预期能够编译出二进制程序并可执行。

**注意**

该二进制程序并非一定可以执行，除非使用的地址是合法的。
