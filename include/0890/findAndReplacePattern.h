#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#define INCLUDED_SOLUTION_HEADER

#include <vector>
#include <bitset>
#include <string>
#include <iostream>

namespace p0890 {
class Solution {
public:
  std::vector<std::string> findAndReplacePattern(std::vector<std::string>& words,
                                                 std::string pattern) {
    constexpr size_t NUM_VALID_CHARS(256);

    // Pre-allocate enough memory for the maximum possible requirement
    std::vector<std::string> matches;
    matches.reserve(words.size());

    for (auto &word : words) {
      // Scan the pattern and collect symbols to replace
      // We don't really care for unicode / multibyte support so just use a
      // better lookup-table
      std::vector<char> replacement(NUM_VALID_CHARS, 0);
      std::bitset<NUM_VALID_CHARS> available;
      available.set();

      bool failed = false;
      for (size_t i = 0; i < word.size() && i < pattern.size(); ++i) {
        if (available.test(word[i]) && replacement[pattern[i]] == 0) {
          replacement[pattern[i]] = word[i];
          available.set(word[i], false);
        } else if (replacement[pattern[i]] != word[i]) {
          failed = true;
          break;
        }
      }

      if (!failed) {
        matches.push_back(word);
      }
    }
    return matches;
  }
};
}
