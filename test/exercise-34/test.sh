#!/usr/bin/env bash

EXECUTABLE=$1

insmod $EXECUTABLE ls_array_input=3,6,9,12,15 ls_target=12

MODULE_MESSAGE=$(dmesg | grep "Index of 12 in the array: 3")

rmmod $EXECUTABLE || true # 卸载模块有概率会失败，不过我们只需要运行一次。由于 EXECUTABLE 脱离了产物构造路径造成。

if [ ! -z "$MODULE_MESSAGE" ]; then
  echo "Test passed."
  exit 0
else
  echo "Test failed. Expected have '$MODULE_MESSAGE' but got empty"
  exit 1
fi
