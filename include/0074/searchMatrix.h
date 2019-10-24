#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <vector>

namespace p0074 {
class Solution {
public:
  bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
    if (matrix.empty() || matrix.front().empty()) {
      return false;
    }

    size_t nrows = matrix.size();
    size_t ncols = matrix[0].size();
    size_t nelems = nrows * ncols;

    size_t lower = 0, upper = nelems;

    while (lower < upper) {
      size_t t = lower + (upper - lower) / 2;
      size_t r = t / ncols;
      size_t c = t % ncols;
      if (target <= matrix[r][c]) {
        upper = t;
      } else {
        lower = t + 1;
      }
    }
    if (lower >= nelems) {
      return false;
    }
    return matrix[lower / ncols][lower % ncols] == target;
  }
};
} // namespace p0074
