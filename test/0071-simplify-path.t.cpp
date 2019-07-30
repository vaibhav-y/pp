#include <gtest/gtest.h>
#include <utility>
#include <string>

#include "simplifyPath.h"

typedef std::string INPUT;
typedef std::string OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<INPUT, OUTPUT>;

class P0071_SimplifyPath : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0071::Solution sol;
};

INSTANTIATE_TEST_CASE_P(SimplifyPathTest, P0071_SimplifyPath,
                        ::testing::Values(t("/", "/"),
                                          t("//////", "/"),
                                          t("/root/", "/root"),
                                          t("/root/relative/../relative/path/", "/root/relative/path"),
                                          t("/a/../../b/../c//.//", "/c"),
                                          t("/a/./b/../../c/", "/c"),
                                          t("//root///lol", "/root/lol"),
                                          t("/a//b////c/d//././/..", "/a/b/c"),
                                          // Yes, this is a valid UNIX directory tree
                                          t("/.../.../.././.../", "/.../...")));

TEST_P(P0071_SimplifyPath, Generic) {
  EXPECT_EQ(GetParam().second, sol.simplifyPath(GetParam().first));
}
