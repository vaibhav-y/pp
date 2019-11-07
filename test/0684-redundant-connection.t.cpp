#include <gtest/gtest.h>
#include <utility>
#include <0684/findRedundantConnection.h>

#include <vector>

typedef std::vector<std::vector<int>> INPUT;
typedef std::vector<int> OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;


auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;

class P0684_FindRedundantConnection : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0684::Solution sol;
};

INSTANTIATE_TEST_CASE_P(FindRedundantConnectionTest, P0684_FindRedundantConnection,
  ::testing::Values(
    t({{1,2},{1,3},{2,3}}, {2,3}),
    t({{1,2},{2,3},{1,3}}, {1,3}),
    t({{1,3},{2,3},{1,2}}, {1,2}),
    t({{1,2},{2,3},{3,4},{1,4},{1,5}}, {1,4}),
    t({{1,2},{2,3},{1,4},{3,4},{1,5}}, {3,4}),
    t({{1,4},{2,3},{3,4},{1,2},{1,5}}, {1,2}),
    t({{1,2},{1,5},{2,3},{3,4},{4,5}}, {4,5}),
    t({{1,2},{1,3},{1,4},{1,5},{4,5}}, {4,5}),
    t({{9,10},{5,8},{2,6},{1,5},{3,8},{4,9},{8,10},{4,10},{6,8},{7,9}}, {4,10})

));

TEST_P(P0684_FindRedundantConnection, Generic) {
  auto input = GetParam().first;
  EXPECT_EQ(GetParam().second, sol.findRedundantConnection(input));
}
