#include <gtest/gtest.h>
#include <utility>
#include <0785/isBipartite.h>

#include <vector>

typedef std::vector<std::vector<int>> INPUT;
typedef bool OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;


auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;

class P0785_IsBipartite : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0785::Solution sol;
};

INSTANTIATE_TEST_CASE_P(IsBipartiteTest, P0785_IsBipartite,
  ::testing::Values(
    t({}, false),
    t({{1,3},{0,2},{1,3},{0,2}}, true),
    t({{1,2,3},{0,2},{0,1,3},{0,2}},false)
));

TEST_P(P0785_IsBipartite, Generic) {
  auto input = GetParam().first;
  EXPECT_EQ(GetParam().second, sol.isBipartite(input));
}
