#if defined(INCLUDED_SOLUTION_HEADER)
#error Won't include multiple solution headers
#endif

#define INCLUDED_SOLUTION_HEADER

#include <string>
#include <iostream>
#include <sstream>
#include <vector>

namespace p0071 {
class Solution {
public:
  std::string simplifyPath(std::string path) {
    size_t pos = 0;
    std::vector<std::string> fragments;
    while (pos < path.size()) {
      if (path[pos] == '/') {
        ++pos;
      } else {
        size_t next_fragment_start = path.find_first_of('/', pos);
        std::string fragment = (next_fragment_start == std::string::npos) ?
          path.substr(pos) :
          path.substr(pos, next_fragment_start - pos);
        if (fragment == ".") {
          pos = next_fragment_start;
          continue;
        } else if (fragment == "..") {
          if (!fragments.empty()) {
            fragments.pop_back();
          }
        } else {
          fragments.push_back(fragment);
        }
        pos = next_fragment_start;
      }
    }
    if (fragments.empty()) {
      return "/";
    }
    std::stringstream ss;
    for (auto &fragment : fragments) {
      ss << "/" << fragment;
    }
    return ss.str();
  }
};
}
