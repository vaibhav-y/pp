#if defined INCLUDED_SOLUTION_HEADER
static_assert(false, "Won't include multiple solution headers together");
#else

#include <vector>
#include <string>

namespace p006 {
class Solution {
public:
  std::string convert(std::string s, int numRows) {
    // Fast path out for numRows = 0 or 1 (0 isn't valid tho)
    // strings of size 2 and below also are invariant under this
    // transformation
    if (numRows < 2 || s.size() < 3) {
      return s;
    }

    size_t numBlocks = s.size() / (2 * numRows - 2) + 1;

    // Simply adding to the string is 4x faster than using an
    // ostringstream. Lmao counter intuitive
    // Original source: https://stackoverflow.com/a/49267798/2857070
    // Live: http://coliru.stacked-crooked.com/a/c04552b29c1542ff
    // 1. -O0 : (string 28ms vs oss: 26ms)
    // 2. -O3 : (string: 1.6ms vs oss: 7.x ms)
    std::vector<std::string> outputRows{static_cast<size_t>(numRows)};

    // reserve memory because we have an upper bound on the number of
    // chars per row
    for (auto row : outputRows) {
      row.reserve(numBlocks);
    }

    for (size_t blkIdx = 0, offset = 0; blkIdx < numBlocks; ++blkIdx) {
      // First traverse the column, ever iteration is guaranteed
      // to start at a column index
      for (size_t idx = 0; idx != numRows - 1; ++idx) {
        if (offset < s.size()) {
          outputRows[idx] += s[offset++];
        }
      }

      if (numRows > 2) {
        // Now traverse the diagnol, all the way up
        for (size_t idx = numRows - 2; idx !=  1; --idx) {
          if (offset < s.size()) {
            outputRows[idx] += s[offset++];
          }
        }
      }
    }

    // Now concatenate all of the streams to return
    for (size_t rowIdx = 1; rowIdx < outputRows.size(); ++rowIdx) {
      outputRows[0] += outputRows[rowIdx];
    }

    return outputRows[0];
  }
};
} // namespace p006

#endif
