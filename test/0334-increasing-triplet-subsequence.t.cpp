#include <gtest/gtest.h>
#include <vector>
#include <utility>

#include "increasingTriplet.h"

typedef std::vector<int> INPUT;
typedef bool OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<INPUT, OUTPUT>;

class P0334_IncreasingTriplet : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0334::Solution sol;
};


INSTANTIATE_TEST_CASE_P(IncreasingTripletTest, P0334_IncreasingTriplet,
  ::testing::Values(
    t({}, false),
    t({1}, false),
    t({1, 2}, false),
    t({1, 2, 3}, true),
    t({5, 4, 3, 2, 1}, false),
    t({6, 1, 4, 3, 5, 0}, true),
    t({6, 1, 50000, 2, 1, 1, 3}, true)
  )
);


TEST_P(P0334_IncreasingTriplet, Generic) {
  EXPECT_EQ(
    GetParam().second,
    sol.increasingTriplet(const_cast<INPUT&>(GetParam().first))
  );
}
