#include <gtest/gtest.h>
#include <utility>
#include <string>

#include "checkValidString.h"

typedef std::string INPUT;
typedef bool OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<INPUT, OUTPUT>;

class P0678_ValidParenthesisString : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0678::Solution sol;
};

INSTANTIATE_TEST_CASE_P(ValidParenTest, P0678_ValidParenthesisString,
  ::testing::Values(
    t("", true),
    t("(", false),
    t("()", true),
    t("()()()()", true),
    t("()(()())()", true),
    t("()(()()()", false),
    t(")()()())", false),
    t(")(", false),
    t("**", true),
    t("(***)", true),
    t("(*)", true),
    t("(*))", true),
    t("(()(()))(()()()))))((((()*()*(())())(()))((*()(*((*(*()))()(())*()()))*)*()))()()(())()(()))())))", false),
    t("(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())", false)
  )
);

TEST_P(P0678_ValidParenthesisString, Generic) {
  EXPECT_EQ(GetParam().second, sol.checkValidString(GetParam().first));
}
