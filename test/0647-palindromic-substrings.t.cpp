#include <gtest/gtest.h>
#include <string>
#include <utility>

#include "countPalindromicSubstrings.h"

typedef std::string INPUT;
typedef int OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<INPUT, OUTPUT>;

class P0647_CountPalindromicSubstrings
    : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0647::Solution sol;
};

INSTANTIATE_TEST_CASE_P(
    CountPalindromicSubstrings,
    P0647_CountPalindromicSubstrings,
    ::testing::Values(t("", 0),
                      t("abc", 3),
                      t("aaa", 6),
                      t("abba", 6),
                      t("xabbavbxaxdxaxc", 22),
                      t("itsbeenalongtime", 17),
                      t("itsbeenalongtimee", 19),
                      t("bbccaacacdbdbcbcbbbcbadcbdddbabaddbcadb", 64))
);

TEST_P(P0647_CountPalindromicSubstrings, Generic) {
  EXPECT_EQ(GetParam().second, sol.countSubstrings(GetParam().first));
}
