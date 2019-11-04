#include <gtest/gtest.h>
#include <utility>
#include <0841/canVisitAllRooms.h>

#include <vector>

typedef std::vector<std::vector<int>> INPUT;
typedef bool OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;


auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;

class P0841_CanVisitAllRooms : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0841::Solution sol;
};

INSTANTIATE_TEST_CASE_P(CanVisitAllRoomsTest, P0841_CanVisitAllRooms,
  ::testing::Values(
    t({}, false),
    t({{}}, true),
    t({{0}, {}}, false),
    t({{1},{2},{3},{}}, true),
    t({{1,3},{3,0,1},{2},{0}}, false),
    t({{}, {1},{2}}, false),
    t({{}, {1,1},{2,2}}, false)
));

TEST_P(P0841_CanVisitAllRooms, Generic) {
  auto input = GetParam().first;
  EXPECT_EQ(GetParam().second, sol.canVisitAllRooms(input));
}
