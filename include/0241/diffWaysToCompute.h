#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <string>
#include <utility>
#include <vector>

#include <iostream>
namespace p0241 {
class Solution {
  typedef std::string::const_iterator sit;
private:
  void diffWaysToCompute(sit first, sit last, std::vector<int> &output) {
    bool sawOp = false;
    for (auto i = first; i < last; ++i) {
      switch(*i) {
        case '+':
        case '-':
        case '*': {
          sawOp = true;
          std::vector<int> lhs;
          diffWaysToCompute(first, i, lhs);
          std::vector<int> rhs;
          diffWaysToCompute(i + 1, last, rhs);

          for (auto &l: lhs) {
            for (auto &r: rhs) {
              switch(*i) {
                case '+':
                  output.push_back(l + r);
                  break;
                case '-':
                  output.push_back(l - r);
                  break;
                case '*':
                  output.push_back(l * r);
                  break;
              }
            }
          }
        }
      }
    }
    // If the input contains only a number, return just that
    if (!sawOp) {
      output.push_back(std::atoi(std::string(first, last).c_str()));
    }
  }

public:
  std::vector<int> diffWaysToCompute(std::string input) {
    if (input.empty()) {
      return {};
    }
    std::vector<int> output;
    diffWaysToCompute(input.begin(), input.end(), output);
    return output;
  }
};
} // namespace p0241
