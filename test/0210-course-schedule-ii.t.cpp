#include <gtest/gtest.h>
#include <utility>
#include <0210/findOrder.h>

#include <vector>

typedef std::pair<int, std::vector<std::vector<int>>> INPUT;
typedef std::vector<int> OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;


auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;

class P0210_FindOrder : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0210::Solution sol;
};

INSTANTIATE_TEST_CASE_P(FindOrderTest, P0210_FindOrder,
  ::testing::Values(
    t({2, {{1,0}}}, {0,1}),
    t({2, {{1,0}, {0, 1}}}, {}),
    t({4, {{1,0}, {2,0},{3,1},{3,2}}}, {0,1,2,3}),
    t({8, {{1,0},{2,6},{1,7},{5,1},{6,4},{7,0},{0,5}}}, {})
));

TEST_P(P0210_FindOrder, Generic) {
  auto input = GetParam().first;
  auto &expected = GetParam().second;

  EXPECT_EQ(expected, sol.findOrder(input.first, input.second));
}
