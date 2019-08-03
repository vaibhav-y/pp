#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#define INCLUDED_SOLUTION_HEADER

#include <bitset>
#include <vector>

namespace p0718 {
class Solution {
  static constexpr size_t MAX_ARRAY_SIZE = 1000;

public:
  int findLength(std::vector<int> &A, std::vector<int> &B) {
    if (A.empty() || B.empty()) {
      return 0;
    }
    std::bitset<MAX_ARRAY_SIZE * MAX_ARRAY_SIZE> matrix;

    size_t maximum = 0;

    // 1. Set up the bitset to record common elements
    for (size_t i = 0; i < A.size(); ++i) {
      for (size_t j = 0; j < B.size(); ++j) {
        if (A[i] == B[j]) {
          matrix.set(i * A.size() + j);
        }
      }
    }

    // traverse left-right by row till we hit a common element
    // at which point we attempt to move down-right to find the sequence length
    // Each such sequence of set bits is traversed ONLY ONCE.
    for (size_t i = 0; i < A.size(); ++i) {
      for (size_t j = 0; j < B.size(); ++j) {
        // Upon finding a match, traverse diagonally to count
        // the match length
        if (matrix.test(i * A.size() + j)) {
          size_t length = 1;
          size_t r = i + 1, c = j + 1;
          while (r < A.size() && c < B.size() &&
                 matrix.test(r * A.size() + c)) {
            ++length;
            // Clear what is already seen so that
            // we never bump into this again
            matrix.set(r * A.size() + c, false);
            ++r, ++c;
          }
          maximum = std::max(maximum, length);
        }
      }
    }

    return maximum;
  }
};
} // namespace p0718
