#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#define INCLUDED_SOLUTION_HEADER

#include <string>
#include <vector>

namespace p0678 {
class Solution {
public:
  bool checkValidString(std::string str) {
    // Store the least, and most number of open left-parens as a result of
    // traversing this string
    int balanceLowerBound = 0;
    int balanceUpperBound = 0;
    for (auto &c : str) {
      switch(c) {
      // If a '(' is encountered, then both the least and most number of
      // open parens possible increases by 1
        case '(':
          ++balanceLowerBound;
          ++balanceUpperBound;
          break;
      // If a ')' is encountered, then both the least and most number of
      // open parens possible increases by 1
        case ')':
          // ')' can only balance a '(' if it exists. This condition prunes
          // away branches where we have more ')' than '('
          if (balanceLowerBound > 0) {
            --balanceLowerBound;
          }
          --balanceUpperBound;
          break;
        // If a '*' is encountered, it can either be treated as a '(' or a ')'
        // Update our counts to reflect that respectively.
        case '*':
          if (balanceLowerBound > 0) {
            --balanceLowerBound;
          }
          ++balanceUpperBound;
          break;
        default:
          return false;
      }
      if (balanceUpperBound < balanceLowerBound) {
          return false;
      }
    }
    return balanceLowerBound == 0;
  }
};
}
