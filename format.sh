#!/usr/bin/env bash

set -e;

find src include -type f \( -name "*.cpp" -o -name "*.h" \) | \
    xargs clang-format -verbose -i -style=file
