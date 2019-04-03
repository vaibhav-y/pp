#!/usr/bin/env bash

find src include test -type f \( -name "*.cpp" -o -name "*.t.cpp" -o -name "*.h" \) | \
    xargs -P 4 clang-format -i -style=file
