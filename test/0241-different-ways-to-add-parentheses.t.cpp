#include <gtest/gtest.h>
#include <utility>
#include <0241/diffWaysToCompute.h>

#include <string>
#include <vector>
#include <algorithm>


typedef std::string INPUT;
typedef std::vector<int> OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;


auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;

class P0241_DiffWaysToCompute : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0241::Solution sol;
};

INSTANTIATE_TEST_CASE_P(DiffWaysToComputeTest, P0241_DiffWaysToCompute,
  ::testing::Values(
    t("1247141", {1247141}),
    t("2-1-1", {0, 2}),
    t("2*3-4*5", {-34, -14, -10, -10, 10}),
    t("20*13-148*500", {-1479740,-1350000,-1350000,-73740,56000}),
    t("20*13*148*500", {19240000,19240000,19240000,19240000,19240000})
));

TEST_P(P0241_DiffWaysToCompute, Generic) {
  auto expected = GetParam().second;
  auto output = sol.diffWaysToCompute(GetParam().first);

  std::sort(expected.begin(), expected.end());
  std::sort(output.begin(), output.end());

  EXPECT_EQ(expected, output);
}
