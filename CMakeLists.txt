cmake_minimum_required(VERSION 3.10)

project(leetcode_cxx CXX)

include(CTest)
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set (TEST_TARGETS
     001-Two-Sum
     002-Add-Two-Numbers
     003-Longest-Substring-Without-Repeating-Characters
     004-Median-Of-Two-Sorted-Arrays
     005-Longest-Palindromic-Substring
     006-ZigZag-Conversion
     007-Reverse-Integer
     008-String-To-Integer-Atoi
     009-Palindrome-Number
     011-Container-With-Most-Water
     0338-Counting-Bits)

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
         -fsanitize=address
         -fcolor-diagnostics)

    target_compile_features(${TEST}.t PRIVATE cxx_std_17)
    target_compile_options(${TEST}.t
         PRIVATE
         -g -O0
         -Wall -Werror
         -fcolor-diagnostics)

    target_link_libraries(${TEST}.t
                          PRIVATE
                          ${TEST}
                          ${GTEST_BOTH_LIBRARIES}
                          pthread)
    add_test(NAME ${TEST}
             COMMAND ${TEST}.t)
endforeach (TEST)
