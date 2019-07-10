#if defined(INCLUDED_SOLUTION_HEADER)
static_assert("Won't include multiple solution headers");
#endif

#define INCLUDED_SOLUTION_HEADER

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
    const size_t MAX_COLS = triangle.back().size();
    std::vector<int> row(MAX_COLS);
    return MAX_COLS;
  }
};
}
