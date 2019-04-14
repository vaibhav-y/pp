#include <gtest/gtest.h>
#include <vector>

#include "Common.h"
#include "medianOfTwoSortedArrays.h"

class P004_MedianOfTwoSortedArrays : public ::testing::Test {
protected:
  p004::Solution sol;
};

TEST_F(P004_MedianOfTwoSortedArrays, LeftEmpty1) {
  std::vector<int> left{};
  std::vector<int> right{1};
  EXPECT_EQ(sol.findMedianSortedArrays(left, right), 1);
}

TEST_F(P004_MedianOfTwoSortedArrays, LeftEmpty2) {
  std::vector<int> left{};
  std::vector<int> right{1, 2};
  EXPECT_EQ(sol.findMedianSortedArrays(left, right), 1.5);
}

TEST_F(P004_MedianOfTwoSortedArrays, LeftEmpty3) {
  std::vector<int> left{};
  std::vector<int> right{1, 2, 3};
  EXPECT_EQ(sol.findMedianSortedArrays(left, right), 2);
}

TEST_F(P004_MedianOfTwoSortedArrays, RightEmpty1) {
  std::vector<int> left{1};
  std::vector<int> right{};
  EXPECT_EQ(sol.findMedianSortedArrays(left, right), 1);
}

TEST_F(P004_MedianOfTwoSortedArrays, RightEmpty2) {
  std::vector<int> left{1, 2};
  std::vector<int> right{};
  EXPECT_EQ(sol.findMedianSortedArrays(left, right), 1.5);
}

TEST_F(P004_MedianOfTwoSortedArrays, RightEmpty3) {
  std::vector<int> left{1, 2, 3};
  std::vector<int> right{};
  EXPECT_EQ(sol.findMedianSortedArrays(left, right), 2);
}

TEST_F(P004_MedianOfTwoSortedArrays, GenericNonOverlappingEvenSizeSeq) {
  std::vector<int> left{1, 2, 3};
  std::vector<int> right{4, 5, 6};

  EXPECT_EQ(sol.findMedianSortedArrays(left, right), 3.5);
}

TEST_F(P004_MedianOfTwoSortedArrays, GenericNonOverlappingOddSizeSeq) {
  std::vector<int> left{1, 2, 3, 4};
  std::vector<int> right{5, 6, 7};

  EXPECT_EQ(sol.findMedianSortedArrays(left, right), 4);
}

TEST_F(P004_MedianOfTwoSortedArrays, GenericOverlappingEvenSizeSeq) {
  std::vector<int> left{1, 2, 4};
  std::vector<int> right{3, 5, 6};

  EXPECT_EQ(sol.findMedianSortedArrays(left, right), 3.5);
}

TEST_F(P004_MedianOfTwoSortedArrays, GenericOverlappingOddSizeSeq) {
  std::vector<int> left{1, 2, 3, 5};
  std::vector<int> right{4, 6, 7};

  EXPECT_EQ(sol.findMedianSortedArrays(left, right), 4);
}
