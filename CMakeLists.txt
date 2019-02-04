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
     004-Median-Of-Two-Sorted-Arrays)

foreach (TEST ${TEST_TARGETS})
     add_executable(${TEST}.t
                    test/${TEST}.t.cpp)
     target_compile_features(${TEST}.t PRIVATE cxx_std_17)
     target_link_libraries(${TEST}.t
                           ${GTEST_BOTH_LIBRARIES}
                           pthread)
     add_test(NAME ${TEST}
              COMMAND ${TEST}.t)
endforeach (TEST)