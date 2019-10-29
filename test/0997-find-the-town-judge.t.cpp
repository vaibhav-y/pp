#include <gtest/gtest.h>
#include <utility>
#include <0997/findJudge.h>

#include <vector>

typedef std::pair<int, std::vector<std::vector<int>>> INPUT;
typedef int OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;


auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;

class P0997_FindJudge : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0997::Solution sol;
};

INSTANTIATE_TEST_CASE_P(FindJudgeTest, P0997_FindJudge,
  ::testing::Values(
    t({1, {}}, 1),
    t({2,{{1,2},{2,1}}}, -1),
    t({2, {{1,2}}}, 2),
    t({3, {{1,3},{2,3}}}, 3),
    t({3, {{1,3},{2,3},{3,1}}}, -1),
    t({3, {{1,2},{2,3}}}, -1),
    t({4, {{1,3},{1,4},{2,3},{2,4},{4,3}}}, 3)
));

TEST_P(P0997_FindJudge, Generic) {
  auto expected = GetParam().second;
  auto input = GetParam().first;

  EXPECT_EQ(expected, sol.findJudge(input.first, input.second));
}
