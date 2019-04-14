#!/usr/bin/env bash

find src include test -type f \( -name "*.cpp" -o -name "*.t.cpp" -o -name "*.h" \) | \
    xargs clang-format -verbose -i -style=file
