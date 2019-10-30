#include <gtest/gtest.h>
#include <utility>
#include <1042/gardenNoAdj.h>

#include <vector>

typedef std::pair<int, std::vector<std::vector<int>>> INPUT;
typedef std::vector<int> OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;


auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;

class P1042_GardenNoAdj : public ::testing::TestWithParam<TESTCASE> {
protected:
  p1042::Solution sol;
};

INSTANTIATE_TEST_CASE_P(GardenNoAdjTest, P1042_GardenNoAdj,
  ::testing::Values(
    t({0, {}}, {}),
    t({1, {}}, {1}),
    t({3, {{1,2},{2,3},{3,1}}}, {1,2,3}),
    t({4, {{1,2},{3,4}}}, {1,2,1,2}),
    t({4, {{1,2},{2,3},{3,4},{4,1},{1,3},{2,4}}}, {1,2,3,4}),
    t({5, {{4,1},{4,2},{4,3},{2,5},{1,2},{1,5}}}, {1,2,1,3,3}),
    t({5, {{4,1},{4,2},{4,3},{2,5},{1,2},{1,5},{4,5}}}, {1,2,1,3,4})
));


TEST_P(P1042_GardenNoAdj, Generic) {
  auto expected = GetParam().second;
  auto input = GetParam().first;
  EXPECT_EQ(expected, sol.gardenNoAdj(input.first, input.second));
}
