#!/usr/bin/env bash

! [[ -d ./build ]] \
    && echo "Creating build dir..." \
    && mkdir ./build \
    && echo "Done."

set -ex;

# Use clang and LLD if possible
if which llvm-config >/dev/null 2>&1; then
    export LLVM_BINDIR=$(llvm-config --bindir)
    export CC="${LLVM_BINDIR}/clang"
    export CXX="${LLVM_BINDIR}/clang++"
    export _CMAKE_EXTRA_ARGS="-DCMAKE_LINKER=${LLVM_BINDIR}/ld64.lld -DCMAKE_BUILD_TYPE=RelWithDebInfo"
fi;

cmake \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ${_CMAKE_EXTRA_ARGS} \
    -Bbuild -H. && \
cmake --build build/ -- -j4 && \
CTEST_OUTPUT_ON_FAILURE=1 GTEST_COLOR=1 make -j4 -C build test
