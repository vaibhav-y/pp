#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <vector>

namespace p0210 {
class Solution {
private:
  struct Vertex {
    enum e_Color { e_Unexplored = 0, e_Pending, e_Done } color;
    int id;
    int indegree;
    std::vector<int> adj;

    Vertex() = default;
  };

  bool toposort(std::vector<Vertex> &vertices, int sid,
                std::vector<int> &sorted) {
    vertices[sid].color = Vertex::e_Pending;
    for (auto &destId : vertices[sid].adj) {
      auto &dest = vertices[destId];
      if (dest.color == Vertex::e_Unexplored) {
        if (!toposort(vertices, destId, sorted)) {
          return false;
        }
      } else if (dest.color == Vertex::e_Pending) {
        return false;
      }
    }

    vertices[sid].color = Vertex::e_Done;
    sorted.push_back(sid);

    return true;
  }

public:
  std::vector<int> findOrder(int numCourses,
                             std::vector<std::vector<int>> &prerequisites) {
    std::vector<Vertex> vertices(numCourses);

    std::vector<int> sorted;
    sorted.reserve(numCourses);

    for (auto &p : prerequisites) {
      auto &to = vertices[p[1]];
      auto &from = vertices[p[0]];
      to.indegree++;
      from.adj.push_back(p[1]);
    }

    for (int i = 0; i < numCourses; ++i) {
      vertices[i].id = i;
    }

    for (int i = 0; i < numCourses; ++i) {
      if (vertices[i].indegree == 0 &&
          vertices[i].color == Vertex::e_Unexplored) {
        if (!toposort(vertices, i, sorted)) {
          return {};
        }
      }
    }

    // For when there is a disconnected cyclic subgraph
    if (sorted.size() < numCourses) {
      return {};
    }
    return sorted;
  }
};
} // namespace p0210
