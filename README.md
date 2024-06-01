# 2024 傲来操作系统（EulixOS）训练营在线作业（导学与基础阶段）

## 概览

### 题目列表

| 编号 | 位置              | 简介                                       | 考察点          | 难度 |
|------|-------------------|--------------------------------------------|-----------------|------|
| 01   | `src/exercise-01` | 编写第一个 Makefile                        | 程序构建        | 入门 |
| 02   | `src/exercise-02` | 编写第一个测试                             | 程序构建        | 入门 |
| 03   | `src/exercise-03` | 使用 Makefile 静态链接程序                     | 程序构建        | 入门     |
| 04   | `src/exercise-04` | 使用 Makefile 构建第一个静态链接库         | 程序构建        | 入门 |
| 05   | `src/exercise-05` | 使用 Makefile 构建第一个动态链接库         | 程序构建        | 入门 |
| 11   | `src/exercise-11` | 编写一个简单的 ld 文件并指定内存区域       | 程序构建        | 基础 |
| 12   | `src/exercise-12` | 编写一个简单的 ld 文件并指定 text 起始地址 | 程序构建        | 基础 |
| 13   | `src/exercise-13` | 编写一个简单的 ld 文件并指定自定义 symbol  | 程序构建        | 基础 |
| 14   | `src/exercise-14` | 编写一个简单的 ld 文件并指定自定义 section | 程序构建        | 基础 |
| 20   | `src/exercise-20` | 合并两个任务队列                           | 数据结构        | 基础 |
| 21   | `src/exercise-21` | 按组反转一个任务队列                           | 数据结构        | 基础 |
| 30   | `src/exercise-30` | 编写一个内核模块打印 hello world           | 内核模块        | 入门 |
| 31   | `src/exercise-31` | 编写一个内核模块实现阶乘计算               | 内核模块        | 基础 |
| 32   | `src/exercise-32` | 编写一个内核模块实现字符串反转             | 内核模块        | 基础 |
| 33   | `src/exercise-33` | 编写一个内核模块实现平均数计算             | 内核模块        | 基础 |
| 34   | `src/exercise-34` | 编写一个内核模块实现线性查找               | 内核模块        | 基础 |
| 35   | `src/exercise-35` | 编写一个内核模块延时打印字符串             | 内核模块        | 入门 |
| 40   | `src/exercise-40` | 使用 RISC-V 内联汇编实现条件返回           | RISC-V 基础指令 | 基础 |
| 41   | `src/exercise-41` | 使用 RISC-V 内联汇编实现最大公因数求解     | RISC-V 基础指令 | 基础 |
| 42   | `src/exercise-42` | 使用 RISC-V 内联汇编实现数组元素查找       | RISC-V 基础指令 | 中等 |

## 构建

使用 GNU Make 进行构建。

``` shell
# 构建所有（exercise-xx）。
make all
# 构建一个或多个 exercise，比如，exercise-01, exercise-02。
make exercise-xx # 
```

清除产物：

``` shell
make clean
```

## 测试

``` shell
# 运行所有测试
make test
# 运行一个或多个测试，比如，test-exercise-01, test-exercise-02。
make test-exercise-xx
```

## 协议

除非另有说明，所有作品均为免费且无担保的作品，在 _Unlicense_ 的条款下已释放到公共领域。您应当已收到了一份 Unlicense 协议的副本，详情请查看 _COPYING_ 文件，如果没有收到，请参阅 <https://unlicense.org> 。
