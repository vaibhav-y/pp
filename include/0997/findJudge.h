#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <algorithm>
#include <vector>

namespace p0997 {
// In a town, there are N people labelled from 1 to N.
// There is a rumor that one of these people is secretly the town judge.
//
// If the town judge exists, then:
//
//  1. The town judge trusts nobody.
//  2. Everybody (except for the town judge) trusts the town judge.
//  3. There is exactly one person that satisfies properties 1 and 2.
//
// You are given trust, an array of pairs trust[i] = [a, b] representing
// that the person labelled a trusts the person labelled b.
//
// If the town judge exists and can be identified,
//  Return the label of the town judge.
//  Otherwise, return -1.

class Solution {
public:
  int findJudge(int N, std::vector<std::vector<int>> &trust) {
    if (trust.empty()) {
      return N;
    }
    // This boils down to finding the node with outdegree 0, and indegree N - 1
    std::vector<int> lhsCount(N, 0), rhsCount(N, 0);

    for (auto &p : trust) {
      int trustor = p[0] - 1;
      int trustee = p[1] - 1;
      lhsCount[trustor] += 1;
      rhsCount[trustee] += 1;
    }

    // #1: Trusts nobody
    int candidate = -1;
    for (int i = 0; i < N; ++i) {
      if (lhsCount[i] == 0) {
        // #3: There is only one such candidate!
        if (candidate == -1) {
          candidate = i;
        } else {
          return -1;
        }
      }
    }

    if (candidate == -1) {
      return -1;
    }

    // #2: Does everyone else trust this candidate?
    if (rhsCount[candidate] == N - 1) {
      return candidate + 1;
    }

    return -1;
  }
};
} // namespace p0997
