#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#define INCLUDED_SOLUTION_HEADER

#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

namespace p0043 {
class Solution {
private:
  typedef std::vector<unsigned int> Number;

  Number parse(const std::string &number, size_t chunkSize) {
    Number parsed;
    size_t firstChunkSize = number.size() % chunkSize;
    size_t start = 0;
    std::string chunk;
    // The number cannot be split into chunks evenly
    // The first chunk will be the smallest therefore
    if (firstChunkSize != 0) {
      chunk = number.substr(0, firstChunkSize);
      parsed.push_back(
          static_cast<Number::value_type>(strtol(chunk.c_str(), nullptr, 10)));
      start = firstChunkSize;
    }
    // The rest of the number is parsed into chunks now
    while (start < number.size()) {
      chunk = number.substr(start, chunkSize);
      parsed.push_back(
          static_cast<Number::value_type>(strtol(chunk.c_str(), nullptr, 10)));
      start += chunkSize;
    }

    return parsed;
  }

  // Multiplies the 'Big' Number by a single digit, returning another Big
  // Number
  Number singleDigitMultiply(const Number &number, Number::value_type digit,
                             size_t base) {
    Number result;
    Number::value_type carry = 0;
    for (auto rit = number.crbegin(); rit != number.crend(); ++rit) {
      result.push_back(digit * (*rit) + carry);
      carry = result.back() / base;
      result.back() %= base;
    }
    if (carry) {
      result.push_back(carry);
    }
    std::reverse(result.begin(), result.end());
    return result;
  }
  // Adds two 'Big' Numbers represented as vectors (right to left)
  // Equivalent to the following operation:
  // first + second * (10 ** secondPadding)
  Number add(const Number &first, const Number &second, size_t base) {
    if (first.empty()) {
      return second;
    }
    if (second.empty()) {
      return first;
    }

    auto shorter = first.size() < second.size() ? first : second;
    auto longer = first.size() < second.size() ? second : first;

    auto rlit = longer.crbegin();
    auto rsit = shorter.crbegin();

    Number::value_type carry = 0;
    Number result;
    // First add up the common segment of the two numbers
    // starting at the lowest place (highest index)
    while (rsit != shorter.rend()) {
      result.push_back(*rsit + *rlit + carry);
      carry = result.back() / base;
      result.back() %= base;
      ++rsit, ++rlit;
    }
    // Now process the longer number's remainder in the same manner
    while (rlit != longer.rend()) {
      result.push_back(*rlit + carry);
      carry = result.back() / base;
      result.back() %= base;
      ++rlit;
    }
    if (carry > 0) {
      result.push_back(carry);
    }

    // The above produces our numbers in the reverse order
    // reverse th result to return the correctly ordered number
    std::reverse(result.begin(), result.end());
    return result;
  }

public:
  std::string multiply(std::string num1, std::string num2) {
    if (num1.empty() || num2.empty()) {
      return "";
    }
    if (num1[0] == '0' || num2[0] == '0') {
      return "0";
    }

    constexpr auto CHUNK_SIZE = 4;
    constexpr auto BASE = 10000;

    // These are the numbers as represented in base 10000
    // Imagine multiplying them as:
    //   I N N E R
    // x O U T E R
    Number inner(parse(num1, CHUNK_SIZE));
    Number outer(parse(num2, CHUNK_SIZE));
    Number result;

    size_t place = 0;
    for (auto rit = outer.crbegin(); rit != outer.crend(); ++rit, ++place) {
      auto currentResult = singleDigitMultiply(inner, *rit, BASE);
      size_t x = 0;
      // Pad it with zeros for the appropriate power of the base
      while (x < place) {
        currentResult.push_back(0);
        ++x;
      }
      result = add(result, currentResult, BASE);
    }

    std::stringstream ss;
    ss << result.front();
    for (auto cit = result.cbegin() + 1; cit != result.cend(); ++cit) {
      // Pad the string being insert with 0s so that it is 4 characters long
      // This is a bit of a hack but better than stringstream::tellg() which
      // I only know about because I got to google stuff
      if (*cit < 10) {
        ss << "000";
      } else if (*cit < 100) {
        ss << "00";
      } else if (*cit < 1000) {
        ss << "0";
      }
      ss << *cit;
    }
    return ss.str();
  }
};
} // namespace p0043
