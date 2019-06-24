#include <gtest/gtest.h>

#include <vector>
#include <utility>

#include "countingBits.h"


typedef int Input;
typedef std::vector<int> Output;
typedef std::pair<Input, Output> TestCase;

auto& t = std::make_pair<Input, Output>;

class P0338_CountingBits : public ::testing::TestWithParam<TestCase> {
protected:
  p0338::Solution sol;
};


INSTANTIATE_TEST_CASE_P(SetBitCountTest, P0338_CountingBits,
                        testing::Values(
                            t(0, {0}),
                            t(1, {0, 1}),
                            t(2, {0, 1, 1}),
                            t(3, {0, 1, 1, 2}),
                            t(4, {0, 1, 1, 2, 1}),
                            t(5, {0, 1, 1, 2, 1, 2}),
                            t(6, {0, 1, 1, 2, 1, 2, 2}),
                            t(7, {0, 1, 1, 2, 1, 2, 2, 3}),
                            t(8, {0, 1, 1, 2, 1, 2, 2, 3, 1}),
                            t(9, {0, 1, 1, 2, 1, 2, 2, 3, 1, 2}),
                            t(10, {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2}),
                            t(11, {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3}),
                            t(12, {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2}),
                            t(13, {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3}),
                            t(14, {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3})
                        ));

TEST_P(P0338_CountingBits, Generic) {
  EXPECT_EQ(GetParam().second, sol.countBits(GetParam().first));
}
