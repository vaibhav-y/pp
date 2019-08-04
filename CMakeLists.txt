cmake_minimum_required(VERSION 3.10)

project(leetcode_cxx CXX)

include(CTest)
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set (TEST_TARGETS
     0001-two-sum
     0002-add-two-numbers
     0003-longest-substring-without-repeating-characters
     0004-median-of-two-sorted-arrays
     0005-longest-palindromic-substring
     0006-zigzag-conversion
     0007-reverse-integer
     0008-string-to-integer-atoi
     0009-palindrome-number
     0011-container-with-most-water
     0017-letter-combinations-of-a-phone-number
     0043-multiply-strings
     0049-group-anagrams
     0062-unique-paths
     0064-minimum-path-sum
     0071-simplify-path
     0093-restore-ip-addresses
     0096-unique-binary-search-trees
     0070-climbing-stairs
     0120-triangle
     0121-best-time-to-buy-and-sell-stock
     0198-house-robber
     0300-longest-increasing-subsequence
     0334-increasing-triplet-subsequence
     0338-counting-bits
     0322-coin-change
     0647-palindromic-substrings
     0678-valid-parenthesis-string
     0718-maximum-length-of-repeated-subarray
     0746-min-cost-climbing-stairs
     0848-shifting-letters
     0890-find-and-replace-pattern
)

foreach (TEST ${TEST_TARGETS})
    add_executable(${TEST}.t
                   test/${TEST}.t.cpp)

    add_library(${TEST} src/${TEST}.cpp)
    target_include_directories(${TEST} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

    target_compile_features(${TEST} PRIVATE cxx_std_17)
    target_compile_options(${TEST}
         PRIVATE
         -g
         -Wall -Werror
         -fsanitize=address
         -fsanitize=undefined
         $<$<CXX_COMPILER_ID:Clang>:-fcolor-diagnostics>)

    target_compile_features(${TEST}.t PRIVATE cxx_std_17)
    target_compile_options(${TEST}.t
         PRIVATE
         -g
         -Wall -Werror
         -fsanitize=address
         -fsanitize=undefined
         $<$<CXX_COMPILER_ID:Clang>:-fcolor-diagnostics>)

    target_link_libraries(${TEST}.t
                          PRIVATE
                          -fsanitize=address
                          -fsanitize=undefined
                          ${TEST}
                          ${GTEST_BOTH_LIBRARIES}
                          pthread)
    add_test(NAME ${TEST}
             COMMAND ${TEST}.t)
endforeach (TEST)
