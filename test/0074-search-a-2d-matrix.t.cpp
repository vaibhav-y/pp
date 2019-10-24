#include <gtest/gtest.h>
#include <utility>
#include <0074/searchMatrix.h>

#include <vector>

typedef std::pair<std::vector<std::vector<int>>, int> INPUT;
typedef bool OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;


auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;

class P0074_SearchMatrix : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0074::Solution sol;
};

INSTANTIATE_TEST_CASE_P(SearchMatrixTest, P0074_SearchMatrix,
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
       {23,30,34,50}}, 13}, false)
));

TEST_P(P0074_SearchMatrix, Generic) {
  auto input = GetParam().first;
  EXPECT_EQ(GetParam().second, sol.searchMatrix(input.first, input.second));
}
