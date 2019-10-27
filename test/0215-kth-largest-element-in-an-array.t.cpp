#include <gtest/gtest.h>
#include <utility>
#include <0215/findKthLargest.h>

#include <vector>

typedef std::pair<std::vector<int>, int> INPUT;
typedef int OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;


auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;

class P0215_FindKthLargest : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0215::Solution sol;
};

INSTANTIATE_TEST_CASE_P(FindKthLargestTest, P0215_FindKthLargest,
  ::testing::Values(
    t({{0}, 1}, 0),
    t({{1,1},1}, 1),
    t({{1,1},2}, 1),
    t({{1,2},1}, 2),
    t({{1,2},2}, 1),
    t({{3,2,1,5,6,4}, 2}, 5),
    t({{7,-2,5,8,1,6}, 3}, 6),
    t({{3,2,3,1,2,4,5,5,6},4}, 4)
));

TEST_P(P0215_FindKthLargest, Generic) {
  auto input = GetParam().first;
  EXPECT_EQ(GetParam().second, sol.findKthLargest(input.first, input.second));
}
