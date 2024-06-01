#!/usr/bin/env bash

EXECUTABLE=$1

MODULE_MESSAGE_1=$(dmesg | grep "Delay 2s!")

insmod $EXECUTABLE

sleep 3

MODULE_MESSAGE_2=$(dmesg | grep "Delay 2s!")

rmmod $EXECUTABLE || true # 卸载模块有概率会失败，不过我们只需要运行一次。由于 EXECUTABLE 脱离了产物构造路径造成。

if [ -n "$MODULE_MESSAGE_2" ] && [ -z "$MODULE_MESSAGE_1" ]; then
  echo "Test passed."
  exit 0
else
  echo "Test failed. Expected have '$MODULE_MESSAGE_2' but got empty"
  exit 1
fi
