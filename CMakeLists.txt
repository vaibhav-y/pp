cmake_minimum_required(VERSION 3.10)

project(leetcode_cxx CXX)

include(CTest)
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set (TEST_TARGETS
     0001-Two-Sum
     0002-Add-Two-Numbers
     0003-Longest-Substring-Without-Repeating-Characters
     0004-Median-Of-Two-Sorted-Arrays
     0005-Longest-Palindromic-Substring
     0006-ZigZag-Conversion
     0007-Reverse-Integer
     0008-String-To-Integer-Atoi
     0009-Palindrome-Number
     0011-Container-With-Most-Water
     0062-Unique-Paths
     0070-Climbing-Stairs
     0121-Best-Time-To-Buy-And-Sell-Stock
     0198-House-Robber
     0338-Counting-Bits
     0746-Min-Cost-Climbing-Stairs
)

foreach (TEST ${TEST_TARGETS})
    add_executable(${TEST}.t
                   test/${TEST}.t.cpp)

    add_library(${TEST} src/${TEST}.cpp)
    target_include_directories(${TEST} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

    target_compile_features(${TEST} PRIVATE cxx_std_17)
    target_compile_options(${TEST}
         PRIVATE
         -g -O0
         -Wall -Werror
         $<$<CXX_COMPILER_ID:Clang>:-fcolor-diagnostics>)

    target_compile_features(${TEST}.t PRIVATE cxx_std_17)
    target_compile_options(${TEST}.t
         PRIVATE
         -g -O0
         -Wall -Werror
         $<$<CXX_COMPILER_ID:Clang>:-fcolor-diagnostics>)

    target_link_libraries(${TEST}.t
                          PRIVATE
                          ${TEST}
                          ${GTEST_BOTH_LIBRARIES}
                          pthread)
    add_test(NAME ${TEST}
             COMMAND ${TEST}.t)
endforeach (TEST)
