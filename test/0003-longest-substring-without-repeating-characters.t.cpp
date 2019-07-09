#include "Common.h"
#include "longestSubstringWithoutRepeatingCharacters.h"
#include <gtest/gtest.h>

class P003_LongestSubstringWithoutRepeatingCharacters : public ::testing::Test {
protected:
  p003::Solution sol;
};

TEST_F(P003_LongestSubstringWithoutRepeatingCharacters, EmptyStr) {
  EXPECT_EQ(sol.lengthOfLongestSubstring(""), 0);
}

TEST_F(P003_LongestSubstringWithoutRepeatingCharacters, UnitLengthStr) {
  EXPECT_EQ(sol.lengthOfLongestSubstring("a"), 1);
}

TEST_F(P003_LongestSubstringWithoutRepeatingCharacters, Length2) {
  EXPECT_EQ(sol.lengthOfLongestSubstring("ab"), 2);
}

TEST_F(P003_LongestSubstringWithoutRepeatingCharacters, Length3) {
  EXPECT_EQ(sol.lengthOfLongestSubstring("abc"), 3);
}

TEST_F(P003_LongestSubstringWithoutRepeatingCharacters, Length4) {
  EXPECT_EQ(sol.lengthOfLongestSubstring("abcd"), 4);
}

TEST_F(P003_LongestSubstringWithoutRepeatingCharacters, StrRepeats1) {
  EXPECT_EQ(sol.lengthOfLongestSubstring("aaaaaa"), 1);
}

TEST_F(P003_LongestSubstringWithoutRepeatingCharacters, StrRepeats2) {
  EXPECT_EQ(sol.lengthOfLongestSubstring("aaabbb"), 2);
}

TEST_F(P003_LongestSubstringWithoutRepeatingCharacters, StrRepeatsCyclic) {
  EXPECT_EQ(sol.lengthOfLongestSubstring("abcdabcdefabcd"), 6);
}

TEST_F(P003_LongestSubstringWithoutRepeatingCharacters, Generic1) {
  EXPECT_EQ(sol.lengthOfLongestSubstring("pwwkew"), 3);
}

TEST_F(P003_LongestSubstringWithoutRepeatingCharacters, Generic2) {
  EXPECT_EQ(sol.lengthOfLongestSubstring("abcabcbb"), 3);
}

TEST_F(P003_LongestSubstringWithoutRepeatingCharacters, Generic3) {
  EXPECT_EQ(sol.lengthOfLongestSubstring("dvdf"), 3);
}

TEST_F(P003_LongestSubstringWithoutRepeatingCharacters, Generic4) {
  EXPECT_EQ(sol.lengthOfLongestSubstring("abba"), 2);
}
