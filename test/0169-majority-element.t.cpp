#include <gtest/gtest.h>
#include <utility>
#include <0169/majorityElement.h>

#include <vector>

typedef std::vector<int> INPUT;
typedef int OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;


auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;

class P0169_MajorityElement : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0169::Solution sol;
};

INSTANTIATE_TEST_CASE_P(MajorityElementTest, P0169_MajorityElement,
  ::testing::Values(
    t({3,2,3}, 3),
    t({2,2,1,1,1,2,2}, 2),
    t({1,2,0,3,0,0,4,0,5,0,5,0,5,0,5,0,5,0}, 0)
));

TEST_P(P0169_MajorityElement, Generic) {
  auto input = GetParam().first;
  EXPECT_EQ(GetParam().second, sol.majorityElement(input));
}
