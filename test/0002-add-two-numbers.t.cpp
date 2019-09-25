#include "Common.h"
#include "addTwoNumbers.h"
#include <gtest/gtest.h>

using p0002::Solution;

void freeList(ListNode *node) {
  if (!node) {
    return;
  }
  // Free all children first
  freeList(node->next);
  delete node;
}

TEST(P0002_AddTwoNumbers, BothAreNull) {
  Solution sol;
  ListNode *l1 = nullptr;
  ListNode *l2 = nullptr;

  EXPECT_EQ(sol.addTwoNumbers(l1, l2), nullptr);
  freeList(l1);
  freeList(l2);
}

TEST(P0002_AddTwoNumbers, OneListIsNull) {
  p0002::Solution sol;

  ListNode *l1 = new ListNode(2);
  l1->next = new ListNode(4);

  EXPECT_EQ(sol.addTwoNumbers(l1, nullptr), l1);
  EXPECT_EQ(sol.addTwoNumbers(nullptr, l1), l1);
  freeList(l1);
}

TEST(P0002_AddTwoNumbers, NonNullSameSize) {
  Solution sol;
  // Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
  // Output: 7 -> 0 -> 8
  // Explanation: 342 + 465 = 807

  ListNode *l1 = new ListNode(2);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(3);

  ListNode *l2 = new ListNode(5);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(4);

  ListNode *result = new ListNode(7);
  result->next = new ListNode(0);
  result->next->next = new ListNode(8);

  ListNode* sum = sol.addTwoNumbers(l1, l2);
  EXPECT_EQ(sum->as_list(), result->as_list());
  freeList(l1);
  freeList(l2);
  freeList(result);
  freeList(sum);
}

TEST(P0002_AddTwoNumbers, NonNullDisparateSize) {
  Solution sol;
  // Input: (1) + (9 -> 9 -> 9)
  // Output: 0 -> 0 -> 0-> 1
  // Explanation: 1 + 999 = 1000

  ListNode *l1 = new ListNode(1);

  ListNode *l2 = new ListNode(9);
  l2->next = new ListNode(9);
  l2->next->next = new ListNode(9);

  ListNode *result = new ListNode(0);
  result->next = new ListNode(0);
  result->next->next = new ListNode(0);
  result->next->next->next = new ListNode(1);

  ListNode* sum = sol.addTwoNumbers(l1, l2);
  EXPECT_EQ(sum->as_list(), result->as_list());
  freeList(l1);
  freeList(l2);
  freeList(sum);
  freeList(result);
}
