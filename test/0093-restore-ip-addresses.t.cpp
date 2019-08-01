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
  ::testing::Values(
    t("1234", {"1.2.3.4"}),
    t("8888", {"8.8.8.8"}),
    t("10101010", {"10.10.10.10",
                   "10.10.101.0",
                   "10.101.0.10",
                   "101.0.10.10",
                   "101.0.101.0"}),
    t("1111111111111", {}),
    t("255255511135", {}),
    t("25525511135", {"255.255.11.135", "255.255.111.35"}),
    t("146573", {"1.4.65.73",
                 "1.46.5.73",
                 "1.46.57.3",
                 "14.6.5.73",
                 "14.6.57.3",
                 "14.65.7.3",
                 "146.5.7.3"}),
    t("172162541", {"17.216.25.41",
                    "17.216.254.1",
                    "172.16.25.41",
                    "172.16.254.1",
                    "172.162.5.41",
                    "172.162.54.1"}
)
));




TEST_P(P0093_RestoreIPAddresses, Generic) {
  EXPECT_EQ(GetParam().second, sol.restoreIpAddresses(GetParam().first));
}
