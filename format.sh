#!/usr/bin/env bash

find src include -type f \( -name "*.cpp" -o -name "*.h" \) | \
    xargs clang-format -verbose -i -style=file
