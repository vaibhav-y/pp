#include <gtest/gtest.h>
#include <utility>
#include <0973/kClosest.h>

#include <vector>

typedef std::pair<std::vector<std::vector<int>>, int> INPUT;
typedef std::vector<std::vector<int>> OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;


auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;

class P0973_KClosest : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0973::Solution sol;
};

INSTANTIATE_TEST_CASE_P(KClosestTest, P0973_KClosest,
  ::testing::Values(
    t({{{1,3}, {-2,2}}, 1}, {{-2,2}}),
    t({{{3,3}, {5,-1}, {-2,4}}, 2}, {{3,3}, {-2,4}}),
    t({{{3,3}, {5,-1}, {-2,4}}, 3}, {{3,3}, {-2,4}, {5,-1}})
));

TEST_P(P0973_KClosest, Generic) {
  auto input = GetParam().first;
  EXPECT_EQ(GetParam().second, sol.kClosest(input.first, input.second));
}
