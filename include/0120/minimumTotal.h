#if defined(INCLUDED_SOLUTION_HEADER)
Wont include multiple solution headers);
#endif

#define INCLUDED_SOLUTION_HEADER

#include <algorithm>
#include <limits>
#include <vector>

namespace p0120 {
class Solution {
public:
  int minimumTotal(std::vector<std::vector<int>> &triangle) {
    if (triangle.empty()) {
      return 0;
    }
    if (triangle.size() == 1) {
      return triangle[0][0];
    }
    // This is the most amount of space we'll end up needing,
    // which should be the same as triangle.size() but lets be explicit about
    // what this number means
    std::vector<int> row(triangle.back().size(),
                         std::numeric_limits<int>::max());
    row[0] = triangle[0][0];
    // This needs a staging array, since each element is used in
    // two comparisons, so the single array approach doesn't work because both
    // the children are in the next iteration (unlike previous scenarios) where
    // we had one child path in the same iteration (horizontal)
    std::vector<int> updated(row);
    // The traversal looks like so:
    // [1]-+
    //  |  |
    // [2, 3]-+
    //  | \|  |
    // [4, 5, 6]
    // ...
    for (size_t i = 1; i < triangle.size(); ++i) {
      for (size_t j = 1; j <= i; ++j) {
        updated[j] = triangle[i][j] + std::min(row[j - 1], row[j]);
      }
      updated[0] += triangle[i][0];
      row = updated;
    }

    // This is to stay outside to avoid the extra comparisons inside the loop
    return *std::min_element(row.begin(), row.end());
  }
};
} // namespace p0120
