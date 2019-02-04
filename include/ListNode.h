#if !defined(INCLUDED_LISTNODE_H)
#define INCLUDED_LISTNODE_H

#include <list>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}

  std::list<int> as_list() {
    std::list<int> result;
    ListNode *current = this;
    while (current) {
      result.push_back(current->val);
      current = current->next;
    }

    return result;
  }
};

#endif // INCLUDED_LISTNODE_H