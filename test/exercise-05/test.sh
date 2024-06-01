#!/usr/bin/env bash

EXECUTABLE=$1

if ldd "$EXECUTABLE" | grep "libfunctions.so"; then
  echo "$EXECUTABLE is dynamically linked."
  exit 0
else
  echo "$EXECUTABLE is statically linked."
  exit 1
fi
