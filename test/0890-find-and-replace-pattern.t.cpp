#include <gtest/gtest.h>
#include <utility>
#include <string>
#include <vector>

#include "findAndReplacePattern.h"

typedef std::pair<std::vector<std::string>, std::string> INPUT;
typedef std::vector<std::string> OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<INPUT, OUTPUT>;

class P0890_FindAndReplacePattern : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0890::Solution sol;
};

INSTANTIATE_TEST_CASE_P(FindAndReplacePatternTest, P0890_FindAndReplacePattern,
  ::testing::Values(
    t({{}, ""}, {}),
    t({{"abc","deq","mee","aqq","dkd","ccc"}, "abb"}, {"mee", "aqq"}),
    t({{"abc","deq","mee","aqq","dkd","ccc"}, "xyz"}, {"abc", "deq"}),
    t({{"abc","deq","mee","aqq","dkd","ccc"}, "ggg"}, {"ccc"})
  )
);

TEST_P(P0890_FindAndReplacePattern, Generic) {
  // Yes. Bad practice. But leetcode.
  auto &input = const_cast<INPUT&>(GetParam().first);
  auto &expected = GetParam().second;

  EXPECT_EQ(expected, sol.findAndReplacePattern(input.first, input.second));
}
