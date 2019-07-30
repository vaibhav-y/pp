#if defined(INCLUDED_SOLUTION_HEADER)
static_assert(false, "Won't include multiple solution headers");
#endif

#include <string>
#include <vector>

namespace p0017 {
class Solution {
public:
  std::vector<std::string> letterCombinations(std::string digits) {
    const std::vector<std::string> letters{"abc", "def",  "ghi", "jkl",
                                           "mno", "pqrs", "tuv", "wxyz"};

    std::vector<std::string> combinations;

    for (auto &c : digits) {
      int digit = c - '2';
      if (digit < 0) {
        return {};
      }
      std::vector<std::string> temp;
      if (combinations.empty()) {
        for (auto &l : letters[digit]) {
          temp.push_back(std::string{l});
        }
      } else {
        // Computes the cartesian product of the current array
        // with all the letters from the 'letters' vector
        for (auto &l : letters[digit]) {
          for (auto &str : combinations) {
            temp.push_back(str + l);
          }
        }
      }
      std::swap(combinations, temp);
    }
    return combinations;
  }
};
} // namespace p0017
