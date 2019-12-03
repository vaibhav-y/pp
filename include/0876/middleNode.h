#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <ListNode.h>

namespace p0876 {
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *middleNode(ListNode *head) {
    ListNode *middle = head;
    ListNode *it = head;

    while (it != nullptr) {
      // End of odd length list
      if (nullptr == it->next) {
        return middle;
      }
      // End of even length list
      if (nullptr == it->next->next) {
        return middle->next;
      }

      middle = middle->next;
      it = it->next->next;
    }

    return nullptr;
  }
};
} // namespace p0876
