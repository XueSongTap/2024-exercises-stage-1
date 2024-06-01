#!/usr/bin/env bash

EXECUTABLE=$1

EXPECTED_STDOUT=$(printf "GCD of 48 and 18 is 6")

STDOUT=$(timeout 10s $EXECUTABLE 48 18 || true)

if [ "$STDOUT" == "$EXPECTED_STDOUT" ]; then
  echo "Test passed."
  exit 0
else
  echo "Test failed. Expected '$EXPECTED_OUTPUT' but got '$STDOUT'"
  exit 1
fi
