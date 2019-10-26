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
     0029-divide-two-integers
     0043-multiply-strings
     0049-group-anagrams
     0053-maximum-subarray
     0062-unique-paths
     0064-minimum-path-sum
     0070-climbing-stairs
     0071-simplify-path
     0074-search-a-2d-matrix
     0093-restore-ip-addresses
     0094-binary-tree-inorder-traversal
     0096-unique-binary-search-trees
     0098-validate-binary-search-tree
     0102-binary-tree-level-order-traversal
     0103-binary-tree-zigzag-level-order-traversal
     0105-construct-binary-tree-preorder-inorder
     0106-construct-binary-tree-postorder-inorder
     0113-path-sum-ii
     0114-flatten-binary-tree-to-linked-list
     0120-triangle
     0121-best-time-to-buy-and-sell-stock
     0129-sum-root-to-leaf-numbers
     0144-binary-tree-preorder-traversal
     0169-majority-element
     0198-house-robber
     0199-binary-tree-right-side-view
     0222-count-complete-tree-nodes
     0230-kth-smallest-element-in-a-bst
     ## Really hard to test to exact pointers too much work.
     # 0236-lowest-common-ancestor-of-a-binary-tree
     0240-search-a-2d-matrix-ii
     0241-different-ways-to-add-parentheses
     ## Identical to 449, but 'HARD'
     # 0297-serialize-and-deserialize-binary-tree
     0300-longest-increasing-subsequence
     0322-coin-change
     0334-increasing-triplet-subsequence
     0338-counting-bits
     0449-serialize-and-deserialize-bst
     0508-most-frequent-subtree-sum
     0513-find-bottom-left-tree-value
     0515-find-largest-value-in-each-tree-row
     0623-add-one-row-to-tree
     0647-palindromic-substrings
     0652-find-duplicate-subtrees
     0654-maximum-binary-tree
     0678-valid-parenthesis-string
     0701-insert-into-bst
     0718-maximum-length-of-repeated-subarray
     0746-min-cost-climbing-stairs
     ## Uses 'delete' that interferes with our destructor implementations
     # 0814-binary-tree-pruning
     0848-shifting-letters
     0890-find-and-replace-pattern
     0916-word-subsets
     0973-k-closest-points-to-origin
)

foreach (TEST ${TEST_TARGETS})
    # So far our test ids are any number between 0000-9999
    # Each of our tests begin with an id, followed by a name
    string(SUBSTRING "${TEST}" 0 4  TEST_ID)

    add_executable(${TEST_ID}.t
                   test/${TEST}.t.cpp)

    # Configure the source library to generate a named library for us
    add_library(${TEST} src/${TEST}.cpp)
    target_include_directories(${TEST}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include/${TEST_ID})

    target_compile_features(${TEST} PRIVATE cxx_std_17)
    target_compile_options(${TEST}
         PRIVATE
         -g
         -Wall -Werror
         -fsanitize=address
         -fsanitize=undefined
         $<$<CXX_COMPILER_ID:Clang>:-fcolor-diagnostics>)

    # Configure the test binary, here onwards
    target_compile_features(${TEST_ID}.t PRIVATE cxx_std_17)
    target_compile_options(${TEST_ID}.t
         PRIVATE
         -g
         -Wall -Werror
         $<$<CXX_COMPILER_ID:Clang>:-fcolor-diagnostics>)

    target_include_directories(${TEST_ID}.t
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include/${TEST_ID})

    target_link_libraries(${TEST_ID}.t
                          PRIVATE
                          ${TEST}
                          ${GTEST_BOTH_LIBRARIES}
                          pthread)
    add_test(NAME ${TEST}
             COMMAND ${TEST_ID}.t)
endforeach (TEST)
