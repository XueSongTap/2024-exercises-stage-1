#!/usr/bin/env bash

EXECUTABLE=$1

SECTION_STDOUT=$(readelf -s "$EXECUTABLE" | grep ' my_custom_data$' | awk '{print $2}')

EXPECTED_STDOUT=$(printf "0000000000001234")

if [ "$SECTION_STDOUT" == "$EXPECTED_STDOUT" ]; then
  echo "Test passed."
  exit 0
else
  echo "Test failed. Expected '$EXPECTED_STDOUT' but got '$SECTION_STDOUT'"
  exit 1
fi
