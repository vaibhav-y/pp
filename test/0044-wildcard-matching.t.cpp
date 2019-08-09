#include <gtest/gtest.h>
#include <utility>
#include <string>

#include "isMatch.h"

typedef std::pair<std::string, std::string> INPUT;
typedef bool OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<INPUT, OUTPUT>;

class P0044_WildCardMatching : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0044::Solution sol;
};

INSTANTIATE_TEST_CASE_P(WildCardMatching, P0044_WildCardMatching,
  ::testing::Values(
    t({"something", ""}, false),
    t({"aa", "a"}, false),
    t({"", ""}, true),
    t({"aa", "*"}, false),
    t({"cb", "?a"}, false),
    t({"acdcb", "a*c?b"}, false),
    t({"adceb", "a*b"}, true),
    t({"acdceb", "a*c?b"}, true)
));

TEST_P(P0044_WildCardMatching, Generic) {
  auto input = GetParam().first;
  EXPECT_EQ(GetParam().second, sol.isMatch(input.first, input.second));
}
