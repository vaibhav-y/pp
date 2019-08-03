#include <gtest/gtest.h>
#include <utility>
#include <string>
#include <algorithm>

#include "groupAnagrams.h"

typedef std::vector<std::string> INPUT;
typedef std::vector<std::vector<std::string>> OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<INPUT, OUTPUT>;

class P0049_GroupAnagrams : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0049::Solution sol;
};

INSTANTIATE_TEST_CASE_P(AnagramGroupTest, P0049_GroupAnagrams,
  ::testing::Values(
    t({}, {}),
    t({"eat", "tea", "tan", "ate", "nat", "bat"},
      {{"bat"}, {"tan", "nat"}, {"eat", "tea", "ate"}})
  )
);

TEST_P(P0049_GroupAnagrams, Generic) {
  auto input = GetParam().first;
  auto expected = GetParam().second;
  auto output = sol.groupAnagrams(input);
  std::set<std::vector<std::string>> expectedSet(expected.begin(), expected.end());
  std::set<std::vector<std::string>> outputSet(output.begin(), output.end());

  EXPECT_EQ(expectedSet, outputSet);
}
