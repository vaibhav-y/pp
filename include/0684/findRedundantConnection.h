#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <stack>
#include <vector>

namespace p0684 {
class Solution {
private:
  int find_group(std::vector<int> &parent, int a) {
    if (parent[a] == a) {
      return a;
    }
    parent[a] = find_group(parent, parent[a]);
    return parent[a];
  }

  // Returns false if the two vertices are already part of the same group
  bool unify(std::vector<int> &parent, std::vector<int> &size, int a, int b) {
    a = find_group(parent, a);
    b = find_group(parent, b);

    // Only unify two items from different groups
    if (a != b) {
      // Place the one with fewer children under the one with more children
      if (size[a] < size[b]) {
        std::swap(a, b);
      }
      parent[b] = a;
      size[a] += size[b];
      return true;
    }
    return false;
  }
public:
  std::vector<int>
  findRedundantConnection(std::vector<std::vector<int>> &edges) {
    std::vector<int> parent(edges.size());
    std::vector<int> size(edges.size(), 1);

    for (int i = 0; i < parent.size(); ++i) {
      parent[i] = i;
    }

    // Fill up the information
    for (auto &e : edges) {
      if (!unify(parent, size, e[0] - 1, e[1] - 1)) {
        return e;
      }
    }

    return {};
  }
};
} // namespace p0684
