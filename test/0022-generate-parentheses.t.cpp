#include <gtest/gtest.h>
#include <utility>
#include <vector>
#include <string>

typedef int INPUT;
typedef std::vector<std::string> OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

class P0022_GenerateParens : public ::testing::TestWithParam<TESTCASE> {

};
