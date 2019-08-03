#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#define INCLUDED_SOLUTION_HEADER

#include <vector>

namespace p062 {
class Solution {
public:
  int uniquePaths(int m, int n) {
    if (n == 1 || m == 1) {
      return 1;
    }
    size_t inner = std::min(n, m);
    size_t outer = n + m - inner;
    std::vector<int> pathCount(inner, 1);

    for (size_t i = 1; i < outer; ++i) {
      for (size_t j = 1; j < inner; ++j) {
        pathCount[j] = pathCount[j] + pathCount[j - 1];
      }
    }

    return pathCount[inner - 1];
  }
};
} // namespace p062
