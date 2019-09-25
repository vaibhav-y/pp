#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#define INCLUDED_SOLUTION_HEADER

#include <vector>

namespace p0064 {
class Solution {
public:
  int minPathSum(std::vector<std::vector<int>> &grid) {
    // Arbitrarily return 0 for an empty grid
    if (grid.empty()) {
      return 0;
    }
    std::vector<int> minRowCost(grid[0]);

    // Compute the costs for the first row, each cell in the first row can
    // ONLY be approached by the cell to its left
    for (size_t c = 1; c < minRowCost.size(); ++c) {
      minRowCost[c] += minRowCost[c - 1];
    }

    // Now iterate over the remaining rows
    for (size_t r = 1; r < grid.size(); ++r) {
      // The ONLY way to traverse the first column, is straight down
      minRowCost[0] += grid[r][0];
      for (size_t c = 1; c < minRowCost.size(); ++c) {
        minRowCost[c] = grid[r][c] + std::min(minRowCost[c], minRowCost[c - 1]);
      }
    }

    // This contains our minimum cost
    return minRowCost.back();
  }
};
} // namespace p0064
