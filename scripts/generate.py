#!/usr/bin/env python3
"""
Automatically generate source, include and test file skeletons for a new
question given its title slug
"""
import os
import sys
import json
import string
import requests
import click

# pylint: disable=invalid-name,too-few-public-methods

HEADER = string.Template(
    """\
#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

$includeBlock

namespace p$number {
$skeleton
}
"""
)

SRC = string.Template(
    """\
#include <$number/$headerName.h>
"""
)

TEST = string.Template(
    """\
#include <gtest/gtest.h>
#include <utility>
#include <$number/$headerName.h>


typedef $paramType INPUT;
typedef $returnType OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;


auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;

class P$number$_$testName : public ::testing::TestWithParam<TESTCASE> {
protected:
  p$number::Solution sol;
};

INSTANTIATE_TEST_CASE_P($testIdentifier, P$number$_$testName,
  ::testing::Values());

TEST_P(P$number$_$testName, Generic) {
  FAIL();
}
"""
)


class QuestionData:
    """Encapsulate the information necessary to fill out our template"""

    # pylint: disable=too-many-arguments
    def __init__(self, number, title, code, lang, metadata):
        self._number = int(number)
        self.titleSlug = title
        self.skeletonSrc = code
        self.lang = lang
        self.metadata = metadata

    @staticmethod
    def inferCppIncludesFromType(typename):
        """Given a leetcode typestring, return the header(s) that we may need
        to include"""
        includes = []
        if "string" in typename:
            includes.append("string")
        if "TreeNode" in typename:
            includes.append("TreeNode.h")
        if "ListNode" in typename:
            includes.append("ListNode.h")
        if typename.endswith("[]"):
            includes.append("vector")
        return includes

    def inferredCppIncludes(self):
        """Return a set of includes inferred from the question metadata"""
        returnType = self.metadata["return"]["type"]
        paramTypes = set(p["type"] for p in self.metadata["params"])
        includes = set()
        includes.update(self.inferCppIncludesFromType(returnType))
        for pType in paramTypes:
            includes.update(self.inferCppIncludesFromType(pType))
        return includes

    @property
    def number(self):
        """Zero padded question number"""
        return f"{self._number:04d}"

    @property
    def srcFileName(self):
        """Source file path relative to src directory root"""
        return f"{self.number}-{self.titleSlug}.{self.lang}"

    @property
    def testFileName(self):
        """Test file path relative to test directory root"""
        return f"{self.number}-{self.titleSlug}.t.{self.lang}"

    @property
    def headerName(self):
        """Base name of the header file"""
        return self.metadata["name"]

    @property
    def cppIncludeBlock(self):
        """The cpp include block for this question"""
        includes = self.inferredCppIncludes()
        return "\n".join(f"#include <{inc}>" for inc in includes)

    @property
    def testPrefix(self):
        """Returns the name to use for this test case"""
        # This is in camel case, convert to pascal case
        name =  self.metadata["name"]
        return name[0].capitalize() + name[1:]

    @property
    def testIdentifier(self):
        """Returns the test case name to use for this test case"""
        # How very original
        return f"{self.testPrefix}Test"

class LeetCodeClient:
    """
    Wrapper for leetcode's API. Most of this is undocumented stuff,
    hopefully remains stable enough to use as a third party.
    """

    BASE_URL = "http://leetcode.com"
    ENDPOINT = f"{BASE_URL}/graphql"
    HEADERS = {
        "Referer": BASE_URL,
        "Content-Type": "application/json",
        # This will be filled in at the time of our request
        "X-CSRF-Token": None,
    }

    def __init__(self, lang):
        self.lang = lang
        self.client = requests.session()
        self.client.get(self.BASE_URL)
        if "csrftoken" not in self.client.cookies:
            raise RuntimeError("Couldn't acquire CSRF token for client!")
        self.HEADERS["X-CSRF-Token"] = self.client.cookies["csrftoken"]

    def createQuestionData(self, questionData):
        """Given a dictionary returned by the leetcode API, create a
        ``Question`` object to represent the useful parts of this data"""
        # This can be used to genrate types for the test later
        metadata = json.loads(questionData["metaData"])
        skeletonCode = next(
            snippet
            for snippet in questionData["codeSnippets"]
            if snippet["langSlug"] == self.lang
        ).get("code")
        number = questionData["questionFrontendId"]
        titleSlug = questionData["titleSlug"]
        return QuestionData(number, titleSlug, skeletonCode, self.lang, metadata)

    def fetchByTitleSlug(self, title):
        """Fetch a question given its title-slug as it appears in the url
        i.e.
        ```
            http://leetcode.com/problems/title-slug-goes-here
                                         ~~~~~~~~~~~~~~~~~~~~
                                         ^
                                         |
        This is what we care about ------+
        ```
        """
        query = """
        query questionData($titleSlug: String!) {
          question(titleSlug: $titleSlug) {
            questionId
            questionFrontendId
            title
            titleSlug
            content
            isPaidOnly
            codeSnippets {
              langSlug
              code
              __typename
            }
            sampleTestCase
            metaData
            __typename
          }
        }"""
        body = json.dumps(
            {
                "operationName": "questionData",
                "query": query,
                "variables": {"titleSlug": title},
            }
        )

        response = self.client.post(self.ENDPOINT, headers=self.HEADERS, data=body)

        if response:
            questionData = response.json().get("data").get("question")
            if not questionData:
                raise RuntimeError("Malformed response:\n{response.json()}")

            return self.createQuestionData(questionData)
        raise RuntimeError("Query to /graphql failed with:\n{response.text}")


@click.command()
@click.option("--lang", default="cpp", help="Which language to target")
@click.option("--title", required=True, help="Title slug from question URL")
@click.option(
    "-s",
    "srcDir",
    required=True,
    type=click.Path(file_okay=False),
    help="Source directory",
)
@click.option(
    "-t",
    "testDir",
    required=True,
    type=click.Path(file_okay=False),
    help="Tests directory",
)
@click.option(
    "-i",
    "includeDir",
    type=click.Path(file_okay=False),
    help="Include or imports directory ",
)
def main(lang, title, srcDir, testDir, includeDir):
    """Where all the magic happens"""
    client = LeetCodeClient(lang)
    questionData = client.fetchByTitleSlug(title)
    headerContents = HEADER.substitute(
        # Should be able to infer this from the C++ signature
        includeBlock=questionData.cppIncludeBlock,
        number=questionData.number,
        skeleton=questionData.skeletonSrc,
    )
    srcContents = SRC.substitute(
        number=questionData.number,
        headerName=questionData.headerName
    )
    testContents = TEST.substitute(
        number=questionData.number,
        headerName=questionData.headerName,
        # These two need more machinary (i.e. a tiny parser)
        paramType="XXX",
        returnType="XXX",
        testName=questionData.testPrefix,
        testIdentifier=questionData.testIdentifier,
        # This is sort of a hack because I can't figure out how to escape
        # the `_` character in templates so that its no a part of the
        # identifier. So we have hack, the best way to solve problems
        _="_"
    )
    incPath = os.path.join(includeDir, questionData.number)
    os.mkdir(incPath)

    with open(os.path.join(incPath, f"{questionData.headerName}.h"), "w") as i:
        i.write(headerContents)
    with open(os.path.join(srcDir, questionData.srcFileName), "w") as s:
        s.write(srcContents)
    with open(os.path.join(testDir, questionData.testFileName), "w") as t:
        t.write(testContents)
    return 0

if __name__ == "__main__":
    # pylint: disable=no-value-for-parameter
    sys.exit(main())
