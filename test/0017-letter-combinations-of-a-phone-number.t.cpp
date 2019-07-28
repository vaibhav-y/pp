#include <gtest/gtest.h>
#include <utility>
#include <string>

#include "letterCombinations.h"

typedef std::string INPUT;
typedef std::vector<std::string> OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<INPUT, OUTPUT>;

class P0017_LetterCombinations : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0017::Solution sol;
};

INSTANTIATE_TEST_CASE_P(LetterCombinationsTest, P0017_LetterCombinations,
  ::testing::Values(
    t("0", {}),
    t("2", {"a", "b", "c"}),
    t("3", {"d", "e", "f"}),
    t("4", {"g", "h", "i"}),
    t("5", {"j", "k", "l"}),
    t("6", {"m", "n", "o"}),
    t("7", {"p", "q", "r", "s"}),
    t("8", {"t", "u", "v"}),
    t("9", {"w", "x", "y", "z"}),
    t("23", {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}),
    t("222", {"aaa","aab","aac","aba","abb","abc","aca","acb","acc",
              "baa","bab","bac","bba","bbb","bbc","bca","bcb","bcc",
              "caa","cab","cac","cba","cbb","cbc","cca","ccb","ccc"})
  )
);

TEST_P(P0017_LetterCombinations, Generic) {
  auto result = sol.letterCombinations(GetParam().first);
  std::sort(result.begin(), result.end());
  EXPECT_EQ(
    GetParam().second,
    result
  );
}
