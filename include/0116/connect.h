#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <vector>
#include <queue>

class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() = default;

  Node(int val_, Node *left_, Node *right_, Node *next_)
      : val(val_), left(left_), right(right_), next(next_) {}
};


namespace p0116 {
class Solution {
public:
  Node *connect(Node *root) {
    if (!root) {
      return nullptr;
    }
    std::queue<Node *> parentQ;
    std::queue<Node *> childQ;
    Node *previous = nullptr;

    root->next = nullptr;
    parentQ.push(root);

    while (true) {
      while (!parentQ.empty()) {
        // Get the current node to process
        Node *current = parentQ.front();
        parentQ.pop();

        // Link previous node (if valid) in this level to the current node
        if (previous) {
          previous->next = current;
        }

        // Queue an non-null children, this is still necessary because the final
        // set of children will all be nullptrs
        if (current->left) {
          childQ.push(current->left);
        }
        if (current->right) {
          childQ.push(current->right);
        }
        previous = current;
      }

      // This is the last node in the parent (current) layer
      previous->next = nullptr;

      if (childQ.empty()) {
        return root;
      }

      // New layer, start with null
      previous = nullptr;
      parentQ.swap(childQ);
    }
  }
};
}
