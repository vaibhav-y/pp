#include <gtest/gtest.h>
#include <utility>
#include <vector>
#include <string>

#include "wordSubsets.h"

typedef std::pair<std::vector<std::string>, std::vector<std::string>> INPUT;
typedef std::vector<std::string> OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<INPUT, OUTPUT>;

#define TEST_CONS t
#include "./include/0916.def"

class P0916_WordSubsets : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0916::Solution sol;
};

INSTANTIATE_TEST_CASE_P(WordSubsetsTest, P0916_WordSubsets, ::testing::Values(
  t({{}, {}}, {}),
  t({{"amazon","apple","facebook","google","leetcode"}, {"e","o"}}, {"facebook","google","leetcode"}),
  t({{"amazon","apple","facebook","google","leetcode"}, {"l","e"}}, {"apple","google","leetcode"}),
  t({{"amazon","apple","facebook","google","leetcode"}, {"e","oo"}}, {"facebook","google"}),
  t({{"amazon","apple","facebook","google","leetcode"}, {"lo","eo"}}, {"google","leetcode"}),
  t({{"amazon","apple","facebook","google","leetcode"}, {"ec","oc","ceo"}}, {"facebook","leetcode"}),
  t({ {"warrior", "warlord", "worker"}, {"rawr", "ior"}}, {"warrior"})
  #ifdef EXTRA_CASES
  , EXTRA_CASES
  #endif
));

TEST_P(P0916_WordSubsets, Generic) {
  auto &input = const_cast<INPUT&>(GetParam().first);
  auto &expected = GetParam().second;
  
  EXPECT_EQ(expected, sol.wordSubsets(input.first, input.second));
}
