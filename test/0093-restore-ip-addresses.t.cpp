#include <gtest/gtest.h>
#include <utility>
#include <vector>
#include <string>

#include "restoreIpAddresses.h"

typedef std::string INPUT;
typedef std::vector<std::string> OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<INPUT, OUTPUT>;

class P0093_RestoreIPAddresses : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0093::Solution sol;
};

INSTANTIATE_TEST_CASE_P(IpAddrRestorationTest, P0093_RestoreIPAddresses,
                        ::testing::Values());

TEST_P(P0093_RestoreIPAddresses, Generic) {
  EXPECT_EQ(GetParam().second, sol.restoreIpAddresses(GetParam().first));
}
