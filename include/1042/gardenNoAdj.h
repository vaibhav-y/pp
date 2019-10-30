#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <set>
#include <vector>

namespace p1042 {
class Solution {
private:
  inline int missingColor(const std::vector<int> &color,
                   const std::vector<int> &neighbours,
                   int maxColors) {
    std::vector<bool> colorUsed(maxColors + 1, false);

    for (auto &n : neighbours) {
      if (color[n] != 0) {
        colorUsed[color[n]] = true;
      }
    }

    for (int i = 1; i <= maxColors; ++i) {
      if (!colorUsed[i]) {
        return i;
      }
    }
    return 0;
  }
public:
  std::vector<int> gardenNoAdj(int N, std::vector<std::vector<int>> &paths) {
    // Store colors allocated to each vertex
    std::vector<int> color(N, 0);

    // We are guaranteed that the maximum degree of ANY vertex is 3
    // so it suffices to iterate and arbitrarily assign the lowest color
    // available by the neighbours
    // We don't need to pre-process too.
    std::vector<std::vector<int>> neighbours(N);

    for (auto &path : paths) {
      auto lhs = path[0] - 1;
      auto rhs = path[1] - 1;
      neighbours[lhs].push_back(rhs);
      neighbours[rhs].push_back(lhs);
    }

    for (int v = 0; v < N; ++v) {
      color[v] = missingColor(color, neighbours[v], 4);
    }

    return color;
  }
};
} // namespace p1042
