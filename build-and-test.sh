#!/usr/bin/env bash

! [[ -d ./build ]] \
    && echo "Creating build dir..." \
    && mkdir ./build \
    && echo "Done."

cmake -Bbuild -H.
make -C build
CTEST_OUTPUT_ON_FAILURE=1 GTEST_COLOR=1 make -C build test