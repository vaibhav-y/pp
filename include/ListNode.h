#if !defined(INCLUDED_LISTNODE_H)
#define INCLUDED_LISTNODE_H

#include <algorithm>
#include <iosfwd>
#include <list>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

bool operator==(const ListNode &lhs, const ListNode &rhs) {
  if (lhs.val != rhs.val) {
    return false;
  }
  if (lhs.next && rhs.next) {
    return *lhs.next == *rhs.next;
  }
  return lhs.next == nullptr && rhs.next == nullptr;
}


void trimLeftTrailingSpaces(std::string &input) {
  input.erase(input.begin(),
              std::find_if(input.begin(), input.end(),
                           [](int ch) { return !std::isspace(ch); }));
}

void trimRightTrailingSpaces(std::string &input) {
  input.erase(std::find_if(input.rbegin(), input.rend(),
                           [](int ch) { return !std::isspace(ch); })
                  .base(),
              input.end());
}

std::vector<int> stringToIntegerVector(std::string input) {
  std::vector<int> output;
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);
  input = input.substr(1, input.length() - 2);
  std::stringstream ss;
  ss.str(input);
  std::string item;
  char delim = ',';
  while (std::getline(ss, item, delim)) {
    output.push_back(stoi(item));
  }
  return output;
}

ListNode *stringToListNode(std::string input) {
  // Generate list from the input
  std::vector<int> list = stringToIntegerVector(input);

  // Now convert that list into linked list
  ListNode *dummyRoot = new ListNode(0);
  ListNode *ptr = dummyRoot;
  for (int item : list) {
    ptr->next = new ListNode(item);
    ptr = ptr->next;
  }
  ptr = dummyRoot->next;
  delete dummyRoot;
  return ptr;
}

void prettyPrintLinkedList(std::ostream &os, ListNode *node) {
  while (node && node->next) {
    os << node->val << "->";
    node = node->next;
  }

  if (node) {
    os << node->val;
  }
}

std::ostream &operator<<(std::ostream &os, ListNode *node) {
  os << "[";
  prettyPrintLinkedList(os, node);
  os << "]";
  return os;
}

#endif // INCLUDED_LISTNODE_H
