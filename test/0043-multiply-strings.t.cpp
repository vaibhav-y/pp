#include <gtest/gtest.h>
#include <utility>
#include <string>

#include "multiply.h"

typedef std::pair<std::string, std::string> INPUT;
typedef std::string OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<INPUT, OUTPUT>;

class P0043_MultiplyStrings : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0043::Solution sol;
};

INSTANTIATE_TEST_CASE_P(MultiplyStringsTest, P0043_MultiplyStrings,
  ::testing::Values(
    t({"0", "125771156556565"}, "0"),
    t({"1255819719518516", "0"}, "0"),
    t({"2", "3"}, "6"),
    t({"123", "456"}, "56088"),
    // Begin randomly generated cases
    t({"66762256", "62565709"}, "4177027881079504"),
    t({"1104768804", "2022542144"},  "2234441465466475776"),
    t({"1287931282", "2025140454"},  "2608241741150282028"),
    t({"639310351", "212958744"},  "136146729375159144"),
    t({"1598879372", "532178431"},  "850889115549225332"),
    t({"254330385", "793815383"},  "201891371977312455"),
    t({"325729535", "634431447"},  "206653060220687145"),
    t({"160986231", "522046918"},  "84042365733986058"),
    t({"1804711339", "1663969468"},  "3002984566649397652"),
    t({"601698370", "302134645"},  "181793923417028650"),
    t({"1243479812", "128961480"},  "160360996905641760"),
    // End randomly generated cases
    t({"9999", "999000"}, "9989001000"),
    t({"999999999999", "999999999999"}, "999999999998000000000001")
));

TEST_P(P0043_MultiplyStrings, Generic) {
  EXPECT_EQ(
    GetParam().second,
    sol.multiply(GetParam().first.first, GetParam().first.second)
  );
}
