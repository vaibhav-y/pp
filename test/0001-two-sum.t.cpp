#include <gtest/gtest.h>

#include <vector>

#include "Common.h"
#include "twoSum.h"

class P0001_TwoSutm : public ::testing::Test {
protected:
  p0001::Solution sol;
};

TEST_F(P0001_TwoSutm, TC0) {
  std::vector<int> result{};
  std::vector<int> nums{};
  int target{1};

  EXPECT_EQ(result, sol.twoSum(nums, target));
}

TEST_F(P0001_TwoSutm, TC1) {
  std::vector<int> result{0, 1};
  std::vector<int> nums{2, 7, 11, 15};
  int target{9};

  EXPECT_EQ(result, sol.twoSum(nums, target));
}

TEST_F(P0001_TwoSutm, TC2) {
  std::vector<int> result{2, 3};
  std::vector<int> nums{11, 15, 7, 2};
  int target{9};

  EXPECT_EQ(result, sol.twoSum(nums, target));
}

TEST_F(P0001_TwoSutm, TC3) {
  std::vector<int> result{0, 2};
  std::vector<int> nums{2, 11, 7, 15};
  int target{9};

  EXPECT_EQ(result, sol.twoSum(nums, target));
}

TEST_F(P0001_TwoSutm, TC4) {
  std::vector<int> result{0, 3};
  std::vector<int> nums{2, 11, 15, 7};
  int target{9};

  EXPECT_EQ(result, sol.twoSum(nums, target));
}

TEST_F(P0001_TwoSutm, TC5) {
  std::vector<int> result{1, 3};
  std::vector<int> nums{2, 11, 15, -2, 7};
  int target{9};

  EXPECT_EQ(result, sol.twoSum(nums, target));
}

TEST_F(P0001_TwoSutm, TC6) {
  std::vector<int> result{1, 2};
  std::vector<int> nums{3, 2, 4};
  int target{6};

  EXPECT_EQ(result, sol.twoSum(nums, target));
}

TEST_F(P0001_TwoSutm, TC7) {
  std::vector<int> result{0, 2};
  std::vector<int> nums{3, 2, 3, 4};
  int target{6};

  EXPECT_EQ(result, sol.twoSum(nums, target));
}
