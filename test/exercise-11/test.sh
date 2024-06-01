#!/usr/bin/env bash

EXECUTABLE=$1

ENTRY_STDOUT=$(readelf -l "$EXECUTABLE" | grep "Entry point" | head -n 1 | awk '{print $3}')

EXPECTED_STDOUT=$(printf "0x8000000")

if [ "$ENTRY_STDOUT" == "$EXPECTED_STDOUT" ]; then
  echo "Test passed."
  exit 0
else
  echo "Test failed. Expected '$EXPECTED_STDOUT' but got '$ENTRY_STDOUT'"
  exit 1
fi
