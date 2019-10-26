#include <gtest/gtest.h>
#include <utility>
#include <0240/searchMatrix.h>

#include <vector>

typedef std::pair<std::vector<std::vector<int>>, int> INPUT;
typedef bool OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;


auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;

class P0240_SearchMatrix : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0240::Solution sol;
};

INSTANTIATE_TEST_CASE_P(SearchMatrixTest, P0240_SearchMatrix,
  ::testing::Values(
    t({{}, 0}, false),
    t({{{}}, 1}, false),
    t({{{1}}, 0}, false),
    t({{{1}}, 1}, true),
    t({{{1}}, 2}, false),
    t({{{1,1}}, 0}, false),
    t({{{1,3}}, 2}, false),
    t({{{1,3}}, 4}, false),
    t({{{1,3,5,7},
       {10,11,16,20},
       {23,30,34,50}}, 3}, true),
    t({{{1,3,5,7},
       {10,11,16,20},
       {23,30,34,50}}, 13}, false),
    t({{{1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}}, 5}, true),
    t({{{1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}}, 20}, false)

));

TEST_P(P0240_SearchMatrix, Generic) {
  auto input = GetParam().first;
  EXPECT_EQ(GetParam().second, sol.searchMatrix(input.first, input.second));
}
