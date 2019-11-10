#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <vector>

namespace p0785 {
class Solution {
private:
  bool dfsColor(const std::vector<std::vector<int>> &graph,
                std::vector<int> &color, std::vector<bool> &visited, int src,
                int srcColor) {
    for (auto &v : graph[src]) {
      if (color[v] == -1) {
        color[v] = srcColor == 0 ? 1 : 0;
      } else if (color[v] == srcColor) {
        return false;
      }
      if (!visited[v]) {
        visited[v] = true;
        dfsColor(graph, color, visited, v, color[v]);
      }
    }
    return true;
  }

public:
  bool isBipartite(std::vector<std::vector<int>> &graph) {
    if (graph.empty()) {
      return false;
    }
    std::vector<int> color(graph.size(), -1);
    std::vector<bool> visited(graph.size(), false);
    for (int i = 0; i < graph.size(); ++i) {
      if (color[i] == -1) {
        color[i] = 0;
      }
      if (!dfsColor(graph, color, visited, i, color[i])) {
        return false;
      }
    }
    return true;
  }
};
} // namespace p0785
