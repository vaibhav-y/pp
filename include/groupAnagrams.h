#if defined(INCLUDED_SOLUTION_HEADER)
#error Won't include multiple solution headers
#endif

#define INCLUDED_SOLUTION_HEADER

#include <string>
#include <unordered_map>
#include <vector>

namespace p0049 {
class Solution {
public:
  std::vector<std::vector<std::string>>
  groupAnagrams(std::vector<std::string> &strs) {
    if (strs.empty()) {
      return {};
    }
    std::unordered_map<std::string, std::vector<std::string>> groupings;

    for (auto &str : strs) {
      auto key(str);
      std::sort(key.begin(), key.end());
      auto it = groupings.find(key);
      if (it != groupings.end()) {
        it->second.push_back(str);
      } else {
        groupings[key] = {str};
      }
    }
    std::vector<std::vector<std::string>> results;
    for (auto &group : groupings) {
      results.push_back(group.second);
    }

    return results;
  }
};
} // namespace p0049
