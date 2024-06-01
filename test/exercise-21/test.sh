#!/usr/bin/env bash

EXECUTABLE=$1

EXPECTED_STDOUT=$(printf "Reversed queue: 2 1 5 4 1 9 4 3 7 5 8 ")

STDOUT=$($EXECUTABLE 1,2,4,5,9,1,3,4,5,7,8 2 | grep "Reversed queue: 2 1 5 4 1 9 4 3 7 5 8")

if [ "$STDOUT" == "$EXPECTED_STDOUT" ]; then
  echo "Test passed."
  exit 0
else
  echo "Test failed. Expected '$EXPECTED_OUTPUT' but got '$STDOUT'"
  exit 1
fi
