#include <gtest/gtest.h>

#include "zigzagConversion.h"

class P0006_ZigZagConversion : public ::testing::Test {
protected:
  p0006::Solution sol;
};

TEST_F(P0006_ZigZagConversion, EmptyStr) {
  EXPECT_EQ(sol.convert("", 1), "");
  EXPECT_EQ(sol.convert("", 2), "");
  EXPECT_EQ(sol.convert("", 3), "");
  EXPECT_EQ(sol.convert("", 4), "");
}

TEST_F(P0006_ZigZagConversion, StrSize1) {
  EXPECT_EQ(sol.convert("A", 1), "A");
  EXPECT_EQ(sol.convert("B", 2), "B");
  EXPECT_EQ(sol.convert("C", 3), "C");
  EXPECT_EQ(sol.convert("D", 4), "D");
}
TEST_F(P0006_ZigZagConversion, StrSize2) {
  EXPECT_EQ(sol.convert("AB", 1), "AB");
  EXPECT_EQ(sol.convert("AB", 2), "AB");
  EXPECT_EQ(sol.convert("AB", 3), "AB");
  EXPECT_EQ(sol.convert("AB", 4), "AB");
}

TEST_F(P0006_ZigZagConversion, Generic0) {
  EXPECT_EQ(sol.convert("SOMESTRINGDUNNO", 1), "SOMESTRINGDUNNO");
}

TEST_F(P0006_ZigZagConversion, Generic1) {
  EXPECT_EQ(sol.convert("ABABABABABABABA", 2), "AAAAAAAABBBBBBB");
}

TEST_F(P0006_ZigZagConversion, Generic2) {
  EXPECT_EQ(sol.convert("INVARIANT", 9), "INVARIANT");
}

TEST_F(P0006_ZigZagConversion, LeetCode1) {
  EXPECT_EQ(sol.convert("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR");
}

TEST_F(P0006_ZigZagConversion, LeetCode2) {
  EXPECT_EQ(sol.convert("PAYPALISHIRING", 4), "PINALSIGYAHRPI");
}
