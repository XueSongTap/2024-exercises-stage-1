#!/usr/bin/env bash

EXECUTABLE=$1

insmod $EXECUTABLE factorial_input=5

MODULE_MESSAGE=$(dmesg | grep "Factorial of 5 is 120")

rmmod $EXECUTABLE || true # 卸载模块有概率会失败，不过我们只需要运行一次。由于 EXECUTABLE 脱离了产物构造路径造成。

if [ ! -z "$MODULE_MESSAGE" ]; then
  echo "Test passed."
  exit 0
else
  echo "Test failed. Expected have '$MODULE_MESSAGE' but got emoty"
  exit 1
fi
