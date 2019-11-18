#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <vector>
#include <unordered_map>

namespace p0133 {

// Definition for a Node.
class Node {
public:
    int val;
    std::vector<Node*> neighbors;

    Node() = default;

    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

//
// https://leetcode.com/submissions/detail/279723161
//

class Solution {
private:
  Node *cloneGraph(Node *node,
                   std::unordered_map<Node *, Node *> &visited) {
    if (visited.find(node) == visited.end()) {
      visited[node] = new Node(node->val, {});
      for (auto &n : node->neighbors) {
        visited[node]->neighbors.push_back(cloneGraph(n, visited));
      }
    }
    return visited[node];
  }
public:
  Node *cloneGraph(Node *node) {
    // Need to depth first clone so that the resolution occurs in toplogical
    // order
    std::unordered_map<Node *, Node *> visited;
    return cloneGraph(node, visited);
  }
};
} // namespace p0133
