#!/usr/bin/env bash

EXECUTABLE=$1

EXPECTED_STDOUT=$(printf "Merged Queue: 1 1 2 3 4 4 5 5 7 8 9 ")

STDOUT=$($EXECUTABLE 1,2,4,5,9 1,3,4,5,7,8 | grep "Merged Queue: 1 1 2 3 4 4 5 5 7 8 9")

if [ "$STDOUT" == "$EXPECTED_STDOUT" ]; then
  echo "Test passed."
  exit 0
else
  echo "Test failed. Expected '$EXPECTED_OUTPUT' but got '$STDOUT'"
  exit 1
fi
