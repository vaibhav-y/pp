#if defined(INCLUDED_SOLUTION_HEADER)
#error Won't include multiple solution headers
#endif

#define INCLUDED_SOLUTION_HEADER

#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

namespace p0093 {
class Solution {
private:
  // This function assumes that the input prefix is a numeric literal
  // represented as a string
  inline bool valid(const std::string &chunk) {
    switch (chunk.size()) {
    case 3: {
      // Check if this three byte string represents a number in [100, 255]
      auto value = strtoul(chunk.c_str(), nullptr, 10);
      return value > 99 && value < 256;
    }
    case 2:
      // Check if this two byte string is a number in [10, 99]
      return chunk[0] != '0';
    case 1:
      // All 1 byte strings are valid
      return true;
    default:
      return false;
    }
  }

  std::vector<std::pair<std::string, std::string>>
  feasibleSplits(const std::string &str) {
    if (str.empty()) {
      return {};
    }
    // These store prefix-suffix pairs
    std::vector<std::pair<std::string, std::string>> splits;

    // What if the suffix is shorter than 3 bytes?
    size_t max_length = std::min<size_t>(3, str.size());

    //  Great, now generate all them suffixes
    for (size_t length = 1; length <= max_length; ++length) {
      std::string prefix = str.substr(0, length);
      if (valid(prefix)) {
        splits.push_back({prefix, str.substr(length)});
      }
    }

    return splits;
  }

  std::vector<std::string> decode(const std::string &prefix,
                                  const std::string &suffix,
                                  size_t splitCount) {
    if (splitCount < 3) {
      std::string previous(prefix.empty() ? "" : prefix + ".");
      std::vector<std::string> decodings;
      for (auto &part : feasibleSplits(suffix)) {
        for (auto &decoding :
             decode(previous + part.first, part.second, splitCount + 1)) {
          decodings.push_back(decoding);
        }
      }
      return decodings;
    } else if (splitCount == 3) {
      if (valid(suffix)) {
        return {prefix + "." + suffix};
      }
    }
    return {};
  }

public:
  std::vector<std::string> restoreIpAddresses(std::string ip) {
    // Impossible to decode strings with:
    // - More than 12 chars, or
    // - Fewer than 4 characters
    if (ip.size() < 4 || ip.size() > 12) {
      return {};
    }

    std::vector<std::string> decodings;
    for (auto &decoding : decode("", ip, 0)) {
      decodings.push_back(decoding);
    }
    return decodings;
  }
};
} // namespace p0093
