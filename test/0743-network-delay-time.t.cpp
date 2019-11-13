#include <gtest/gtest.h>
#include <utility>
#include <0743/networkDelayTime.h>

#include <vector>

typedef std::tuple<std::vector<std::vector<int>>, int, int> INPUT;
typedef int OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;


auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;

class P0743_NetworkDelayTime : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0743::Solution sol;
};

INSTANTIATE_TEST_CASE_P(NetworkDelayTimeTest, P0743_NetworkDelayTime,
  ::testing::Values(
    t({{{1,2,1}}, 2, 2}, -1),
    t({{{1,2,1},{2,1,3}}, 2, 2}, 3),
    t({{{2,1,1},{2,3,1},{3,4,1}}, 4, 2}, 2),
    t({{{1,3,1},{2,1,1},{2,3,1},{3,4,1}}, 4, 2}, 2)
));

TEST_P(P0743_NetworkDelayTime, Generic) {
  auto input = GetParam().first;
  auto expected = GetParam().second;
  std::vector<std::vector<int>> times;
  int N, K;
  std::tie(times, N, K) = input;

  EXPECT_EQ(expected, sol.networkDelayTime(times, N, K));
}
