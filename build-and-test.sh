#!/usr/bin/env bash

! [[ -d ./build ]] \
    && echo "Creating build dir..." \
    && mkdir ./build \
    && echo "Done."

(
    CC=/usr/local/bin/clang \
    CXX=/usr/local/bin/clang++ \
    cmake -G Ninja \
        -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
        -Bbuild -H. && \
    VERBOSE=1 ninja -C build && \
    CTEST_OUTPUT_ON_FAILURE=1 GTEST_COLOR=1 ninja -v -C build test)
