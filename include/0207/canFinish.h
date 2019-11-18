#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <iostream>
#include <unordered_map>
#include <vector>

namespace p0207 {
class Solution {
private:
  bool findCycle(const std::vector<std::vector<int>> &edges,
                 std::vector<int> &color, int src) {
    if (color[src] == -1) {
      color[src] = 0;
    } else if (color[src] == 0) {
      return true;
    }
    for (auto it = edges[src].begin(); it != edges[src].end(); ++it) {
      int v = *it;
      if (color[v] == -1) {
        if (findCycle(edges, color, v)) {
          return true;
        }
      } else if (color[v] == 0) {
        return true;
      }
    }
    color[src] = 1;
    return false;
  }

public:
  bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites) {
    if (prerequisites.empty()) {
      return true;
    }
    std::vector<std::vector<int>> edges(numCourses);
    std::vector<int> indegree(numCourses, 0);

    for (auto &p : prerequisites) {
      edges[p[0]].push_back(p[1]);
      indegree[p[1]]++;
    }

    // Find a vertex with 0 indegree:
    std::vector<int> color(numCourses, -1);

    // Only explore subgraphs that are reachable via a SOURCE vertex
    for (int i = 0; i < color.size(); ++i) {
      if (indegree[i] == 0 && color[i] == -1 && findCycle(edges, color, i)) {
        return false;
      }
    }
    // If after exploring all valid starting points, there are still unexplored
    // regions, those must be cycles
    for (auto &c : color) {
      if (c == -1) {
        return false;
      }
    }

    // No cycles
    return true;
  }
};
} // namespace p0207
