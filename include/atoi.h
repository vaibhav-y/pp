#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#define INCLUDED_SOLUTION_HEADER

#include <limits>
#include <string>

namespace p008 {
class Solution {
private:
  /* Checks if the expression 10 * quotient + rem can overflow
   * integer limits
   */
  inline bool checkOverflow(int quotient, int rem) const {
    if (quotient == 0) {
      return false;
    }

    const int &MAX = std::numeric_limits<int>::max();
    const int &MIN = std::numeric_limits<int>::min();

    if (quotient > 0) {
      return quotient > (MAX - rem) / 10;
    }
    return quotient < (MIN - rem) / 10;
  }

  inline std::string::const_iterator
  skipSpaces(std::string::const_iterator cit) const {
    while (*cit == ' ') {
      ++cit;
    }
    return cit;
  }

  inline int readNum(std::string::const_iterator cit, int sign) const {
    int result = 0;

    while (*cit >= '0' && *cit <= '9') {
      int rem = sign * (*cit - '0');
      if (checkOverflow(result, rem)) {
        return sign == 1 ? std::numeric_limits<int>::max()
                         : std::numeric_limits<int>::min();
      }
      result = 10 * result + rem;
      ++cit;
    }

    return result;
  }

public:
  /* This implements the state machine for /^\s*((-|+)?\d+)/ */
  int myAtoi(std::string str) {
    int sign = 1;
    auto cit = str.cbegin();
    cit = skipSpaces(cit);
    if (*cit == '-' || *cit == '+') {
      sign = (*cit == '-') ? -1 : 1;
      ++cit;
    }
    if (*cit >= '0' && *cit <= '9') {
      return readNum(cit, sign);
    }
    return 0;
  }
};
} // namespace p008
