#include <gtest/gtest.h>
#include <utility>

#include "palindromicNumber.h"

class P0009_ShittyPalindrome
    : public ::testing::TestWithParam<std::pair<int, bool>> {
protected:
  p0009::Solution sol;
};

INSTANTIATE_TEST_CASE_P(AtoiTest, P0009_ShittyPalindrome,
                        ::testing::Values(std::make_pair(42, false),
                                          std::make_pair(10, false),
                                          std::make_pair(0, true),
                                          std::make_pair(0, true),
                                          std::make_pair(121, true),
                                          std::make_pair(2147447412, true),
                                          std::make_pair(11, true)));

TEST_P(P0009_ShittyPalindrome, Generic) {
  EXPECT_EQ(sol.isPalindrome(GetParam().first), GetParam().second);
}
