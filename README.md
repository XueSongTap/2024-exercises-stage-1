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

## 使用教程

### step0

**请确保已在训练营网站个人信息中正确填写了 Gitee Username**

### step1

fork 本仓库并开通 Gitee go 服务。

首先 fork 本仓库到自己的 Gitee 下。

而后切换到 fork 后仓库的流水线页面：

![](resource/kaitong.jpg)

点击”开通 Gitee GO“来使用 CI。

![](resource/chuagjian.jpg)

是否创建默认流水线建议选择“不创建”。

*注：开通 Gitee go 后流水线页面显示无流水线为正常现象*

### step2

将远程仓库 clone 到本地或者使用 webIDE 进行实验

项目结构

```shell
.
├── build
├── CMakeLists.txt
├── COPYING
├── img
├── Makefile
├── README.en.md
├── README.md
├── src//习题在此
└── test
```

本地需要配置部分环境，Ubuntu/Debain 配置参考如下

```shell
sudo apt install git opensbi u-boot-qemu sshpass openssh-client jq curl qemu-system-misc
```

验证 qemu 是否配置成功

```shell
qemu-system-riscv64 --version
```

而后拉取交叉编译工具链镜像

```shell
git clone https://isrc.iscas.ac.cn/gitlab/learningeulixos/2024-exercises-virtual-machines.git
```

通过 qemu 启动工具链与测试环境

```shell
qemu-system-riscv64 \
    -machine 'virt' \
    -cpu 'rv64' \
    -m 1G \
    -device virtio-blk-device,drive=hd \
    -drive file=qcow2镜像路径,if=none,id=hd \
    -virtfs local,id=lee,path=实验工程路径,mount_tag=lee,security_model=passthrough \
    -bios /usr/lib/riscv64-linux-gnu/opensbi/generic/fw_jump.elf \
    -kernel /usr/lib/u-boot/qemu-riscv64_smode/uboot.elf \
    -object rng-random,filename=/dev/urandom,id=rng \
    -device virtio-rng-device,rng=rng \
    -nographic \
    -append "root=LABEL=rootfs console=ttyS0"

```

qemu 启动后进行测试

实验被挂载到 /lee 目录下，需要切换目录进行测试

```shell
cd /lee
```

使用 GNU Make 进行构建。

``` shell
# 构建所有（exercise-xx）。
make all
# 构建一个或多个 exercise，比如，exercise-01, exercise-02。
make exercise-xx # 
```

清除产物：

```shell
make clean
```

测试

```shell
# 运行所有测试
make test
# 运行一个或多个测试，比如，test-exercise-01, test-exercise-02。
make test-exercise-xx
```

测试完成后可退出按 ctrl+A 然后按 X 退出 qemu

### step3

完成实验后，请上传至远程仓库运行 CI。详细执行情况与输出可在流水线页面查看。

![](resource/jeiguo.jpg)

最终的结果可在训练营网站查看：

https://opencamp.cn/EulixOS/camp/202401/stage/1?tab=rank

关于 Gitee go 的介绍：

[Gitee Go 2.0 - Gitee.com](https://gitee.com/help/categories/69)



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
