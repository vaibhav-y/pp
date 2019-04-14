#if defined(INCLUDED_SOLUTION_HEADER)
static_assert(false, "Won't include multiple solution headers together!")
#else
#define INCLUDED_SOLUTION_HEADER "002"

#include "Common.h"

namespace p002 {
class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    if (!l1 && !l2) {
      return nullptr;
    } else if (!l1 && l2) {
      return l2;
    } else if (l1 && !l2) {
      return l1;
    }

    int carry = 0;
    ListNode *head = new ListNode(0);
    ListNode *current = head;

    // The problem that may arise is what if the lists have unequal length?
    // We treat that by implicitly extending the list that ended early using a
    // sequence of 0s, this ends up in the code being a little cleaner.
    //
    // The alternative was to:
    //  1. Add till shorter lists ends, track carry
    //  2. If any of the list pointers is a ``nullptr``, replace it via an
    //     implied 0
    //
    // Visually:
    //   0->0->0->1->2->3
    // + 1->2->3->9->0->0
    while (l1 || l2) {
      int val1 = l1 ? l1->val : 0;
      int val2 = l2 ? l2->val : 0;

      current->val = val1 + val2 + carry;
      carry = current->val / 10;
      current->val = current->val % 10;

      l1 = l1 ? l1->next : nullptr;
      l2 = l2 ? l2->next : nullptr;

      if (l1 || l2) {
        current->next = new ListNode(0);
        current = current->next;
      }
    }

    // if carry != 0 at this point, it means that the result
    // has more digits than max (len(l1), len(l2))
    if (carry != 0) {
      current->next = new ListNode(0);
      current = current->next;
      current->val = carry;
    }

    return head;
  }
};
} // namespace p002
#endif // INCLUDED_SOLUTION_HEADER
