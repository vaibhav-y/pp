#include <gtest/gtest.h>
#include <utility>
#include <tuple>
#include <1203/sortItems.h>

#include <vector>

typedef std::tuple<int, int, std::vector<int>, std::vector<std::vector<int>>> INPUT;
typedef std::vector<int> OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;


auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;

#define TEST_CONS t
#include "./include/1203.def"

class P1203_SortItems : public ::testing::TestWithParam<TESTCASE> {
protected:
  p1203::Solution sol;
};

INSTANTIATE_TEST_CASE_P(SortItemsTest, P1203_SortItems,
  ::testing::Values(
    t({8, 2, {-1,-1,1,0,0,1,0,-1}, {{},{6},{5},{6},{3,6},{},{},{}}},
      {0,6,3,4,1,7,5,2}),
    t({8, 2, {-1,-1,1,0,0,1,0,-1}, {{},{6},{5},{6},{3},{},{4},{}}},
      {}),
    t({5, 3, {0,0,2,1,0}, {{3},{},{},{},{1,3,2}}},
      {3,2,0,1,4}),
    t({3, 2, {0,1,0}, {{}, {0}, {1}}},
      {})
#ifdef TEST_CONS
    ,
    EXTRA_CASES
#endif
  ));



TEST_P(P1203_SortItems, Generic) {
  int n, m;
  std::vector<int> group;
  std::vector<std::vector<int>> beforeItems;

  std::tie(n, m, group, beforeItems) = GetParam().first;
  auto &expected = GetParam().second;

  EXPECT_EQ(expected, sol.sortItems(n, m, group, beforeItems));
}
