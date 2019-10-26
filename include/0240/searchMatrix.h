#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <vector>

namespace p0240 {
class Solution {
  // Find the lower bound of 'target' in the array
  size_t bisect(const std::vector<int> &row, int target) {
    size_t lower = 0, upper = row.size() - 1;
    while (lower < upper) {
      size_t mid = lower + (upper - lower) / 2;
      if (row[mid] < target) {
        lower = mid + 1;
      } else {
        upper = mid;
      }
    }
    return lower;
  }
public:
  bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix.front().empty()) {
      return false;
    }
    for (auto &row : matrix) {
      size_t lower = bisect(row, target);
      if (lower < row.size() && row[lower] == target) {
        return true;
      }
    }
    return false;
  }
};
}
