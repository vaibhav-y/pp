#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <queue>
#include <vector>

namespace p0310 {
class Solution {
public:
  std::vector<int> findMinHeightTrees(int n,
                                      std::vector<std::vector<int>> &edges) {
    if (n == 1) {
      return {0};
    }
    std::vector<int> degree(n, 0);
    std::vector<std::vector<int>> edgeList(n);
    std::queue<int> leaves;

    for (auto &edge : edges) {
      edgeList[edge[0]].push_back(edge[1]);
      edgeList[edge[1]].push_back(edge[0]);

      ++degree[edge[0]];
      ++degree[edge[1]];
    }

    for (int i = 0; i < n; ++i) {
      if (degree[i] == 1) {
        leaves.push(i);
      }
    }

    std::queue<int> scratch;
    // No vertex occurs more than once, keep processing till we have
    // at least 2
    while (n > 2) {
      while (!leaves.empty()) {
        int leaf = leaves.front();
        leaves.pop();
        --n;
        // Now that we're done processing $leaf, reduce the degree
        for (auto &v : edgeList[leaf]) {
          --degree[v];
          if (degree[v] == 1) {
            scratch.push(v);
          }
        }
        // Now that counts to neighbours are updated, declare this leaf dead
        --degree[leaf];
      }
      leaves.swap(scratch);
    }

    std::vector<int> roots;
    while (!leaves.empty()) {
      roots.emplace_back(leaves.front());
      leaves.pop();
    }
    return roots;
  }
};
} // namespace p0310
