#!/usr/bin/env bash

EXECUTABLE=$1

SYMBOL_STDOUT=$(nm "$EXECUTABLE" | grep ' my_custom_symbol$' | awk '{print $1}')

EXPECTED_STDOUT=$(printf "0000000008001111")

if [ "$SYMBOL_STDOUT" == "$EXPECTED_STDOUT" ]; then
  echo "Test passed."
  exit 0
else
  echo "Test failed. Expected '$EXPECTED_STDOUT' but got '$SYMBOL_STDOUT'"
  exit 1
fi
