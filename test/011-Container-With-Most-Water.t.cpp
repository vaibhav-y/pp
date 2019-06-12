#include <gtest/gtest.h>
#include <vector>
#include <utility>

#include "maxArea2D.h"

class P011_ContainerWithMostWater :
  public ::testing::TestWithParam<std::pair<std::vector<int>, int>> {
protected:
  p011::Solution sol;
};

INSTANTIATE_TEST_CASE_P(MaxAreaTest, P011_ContainerWithMostWater,
  ::testing::Values(
    std::make_pair<std::vector<int>, int>({}, 0),
    std::make_pair<std::vector<int>, int>({1, 1}, 1),
    std::make_pair<std::vector<int>, int>({1, 8, 6, 2, 5, 4, 8, 3, 7}, 49),
    std::make_pair<std::vector<int>, int>({1, 2, 3, 4, 5, 6}, 12),
    std::make_pair<std::vector<int>, int>({6, 1, 5, 2, 4, 3}, 16)
  ));


TEST_P(P011_ContainerWithMostWater, Parameterized) {
  // FIXME Not a good idea to do this, but I can't figure this out
  // I am screamed at for discarding a seemingly non-existent const qualifier
  // I know map<K,V> is has an implied <const K, V> pair internally
  // But why is a list of pairs showing this behaviour... ?!
  // Thus we cast away the qualifier we never added.
  int area = sol.maxArea(const_cast<std::vector<int>&>(GetParam().first));
  EXPECT_EQ(area,  GetParam().second);
}
