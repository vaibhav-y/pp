#!/usr/bin/env bash

! [[ -d ./build ]] \
    && echo "Creating build dir..." \
    && mkdir ./build \
    && echo "Done."

cmake \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
    -Bbuild -H. && \
cmake --build build/ -- -j4 && \
CTEST_OUTPUT_ON_FAILURE=1 GTEST_COLOR=1 make -C build test
