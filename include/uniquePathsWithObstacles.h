#if defined(INCLUDED_SOLUTION_HEADER
static_assert(false, "Won't include multiple solution headers");
#endif

#define INCLUDED_SOLUTION_HEADER

#include <vector>

namespace p063 {
class Solution {
public:
  int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
    size_t m = obstacleGrid.size();
    size_t n = obstacleGrid[0].size();
    std::vector<unsigned int> counts(n, 0);
    if (obstacleGrid[0][0] == 0) {
      counts[0] = 1;
    }
    for (size_t i = 0; i < m; ++i) {
      for (size_t j = 0; j < n; ++j) {
        if (obstacleGrid[i][j] == 0) {
          if (i == 0 && j > 0) {
            counts[j] = counts[j - 1];
          }
          else if (i > 0 && j > 0) {
            counts[j] += counts[j - 1];
          }
        }
        else {
          counts[j] = 0;
        }
      }
    }

    return counts.back();
  }
};
} // namespace p063
