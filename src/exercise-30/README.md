# 30 - 编写一个内核模块打印 hello world

难度：入门

## 描述

编写一个内核模块，打印 `hello world!`。

### 输入：

无

### 输出：

打印 `hello world!`。

### 示例：

输出：hello world!

### 本地测试

``` shell
make
insmod hello.ko
rmmod hello.ko
```

## 如何通过测试

结果需以如下格式输出：

```c
printk (KERN_INFO "hello world!"");
```
