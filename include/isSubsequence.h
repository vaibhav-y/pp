#if defined(INCLUDED_SOLUTION_HEADER)
static_assert(false, "Won't include multiple solution headers");
#endif

#define INCLUDED_SOLUTION_HEADER

#include <string>

namespace p0392 {
class Solution {
public:
  bool isSubsequence(std::string s, std::string t) {
    if (t == s) {
      return true;
    }
    for (size_t si = 0, ti = 0; ti < t.size(); ++ti) {
      if (t[ti] == s[si]) {
        ++si;
      }
      if (si == s.size()) {
        return true;
      }
    }
    return false;
  }
};
} // namespace p0392
