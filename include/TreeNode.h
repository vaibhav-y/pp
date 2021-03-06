#ifndef INCLUDED_TREENODE_H
#define INCLUDED_TREENODE_H

#include <algorithm>
#include <ostream>
#include <queue>
#include <sstream>
#include <string>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  bool compare(const TreeNode &other) const {
    if (val != other.val) {
      return false;
    }
    if (left && !left->compare(*other.left)) {
      return false;
    }
    if (right && !right->compare(*other.right)) {
      return false;
    }
    return true;
  }
  ~TreeNode() {
    delete right;
    delete left;
  }
};


inline bool operator==(TreeNode lhs, TreeNode rhs) { return lhs.compare(rhs); }

inline bool TreeEq(TreeNode *lhs, TreeNode *rhs) {
  if (lhs && rhs) {
    return *lhs == *rhs;
  } else {
    return lhs == rhs;
  }
}

inline std::string treeNodeToString(TreeNode *root) {
  if (root == nullptr) {
    return "[]";
  }

  std::string output = "";
  std::queue<TreeNode *> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode *node = q.front();
    q.pop();

    if (node == nullptr) {
      output += "null, ";
      continue;
    }

    output += std::to_string(node->val) + ", ";
    q.push(node->left);
    q.push(node->right);
  }
  return "[" + output.substr(0, output.length() - 2) + "]";
}

inline void trimLeftTrailingSpaces(std::string &input) {
  input.erase(input.begin(),
              std::find_if(input.begin(), input.end(),
                           [](int ch) { return !std::isspace(ch); }));
}

inline void trimRightTrailingSpaces(std::string &input) {
  input.erase(std::find_if(input.rbegin(), input.rend(),
                           [](int ch) { return !std::isspace(ch); })
                  .base(),
              input.end());
}

inline TreeNode *stringToTreeNode(std::string input) {
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);
  input = input.substr(1, input.length() - 2);
  if (!input.size()) {
    return nullptr;
  }

  std::string item;
  std::stringstream ss;
  ss.str(input);

  getline(ss, item, ',');
  TreeNode *root = new TreeNode(std::stoi(item));
  std::queue<TreeNode *> nodeQueue;
  nodeQueue.push(root);

  while (true) {
    TreeNode *node = nodeQueue.front();
    nodeQueue.pop();

    if (!std::getline(ss, item, ',')) {
      break;
    }

    trimLeftTrailingSpaces(item);
    if (item != "null") {
      int leftNumber = std::stoi(item);
      node->left = new TreeNode(leftNumber);
      nodeQueue.push(node->left);
    }

    if (!getline(ss, item, ',')) {
      break;
    }

    trimLeftTrailingSpaces(item);
    if (item != "null") {
      int rightNumber = std::stoi(item);
      node->right = new TreeNode(rightNumber);
      nodeQueue.push(node->right);
    }
  }
  return root;
}

inline std::ostringstream &operator<<(std::ostringstream &os, TreeNode *node) {
  std::string prefix = "";
  bool isLeft = true;

  if (node == nullptr) {
    os << "ø";
    return os;
  }

  if (node->right) {
    os << prefix + (isLeft ? "│   " : "    ") << node->right;
  }

  os << prefix + (isLeft ? "└── " : "┌── ") + std::to_string(node->val) + "\n";

  if (node->left) {
    os << prefix + (isLeft ? "    " : "│   ") << node->left;
  }

  return os;
}

inline std::ostream &operator<<(std::ostream &os, TreeNode *node) {
  return os << treeNodeToString(node);
}

#endif
