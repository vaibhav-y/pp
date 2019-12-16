#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <vector>

namespace p1203 {
class Solution {
private:
  struct Vertex {
    enum Color {
      e_Unexplored,
      e_Pending,
      e_Done,
    } color;
    int id;
    int indegree;
    std::vector<int> adj;
  };

private:
  // I'm lying, this will also tell us if it found a cycle
  // and returns the largest acyclic subgraph, if any
  // Does a lot, tbh. Might make me brekky some day
  bool toposort(int sid,
                std::vector<Vertex> &vertices,
                std::vector<int> &ordered) {
    if (vertices[sid].color == Vertex::e_Pending) {
      return false;
    }

    if (vertices[sid].color == Vertex::e_Done) {
      return true;
    }

    // Move the state forward
    vertices[sid].color = Vertex::e_Pending;

    // Explore neighbours
    for (auto &destId : vertices[sid].adj) {
      if (!toposort(destId, vertices, ordered)) {
        return false;
      }
    }

    // We've explored all neighbours
    vertices[sid].color = Vertex::e_Done;
    ordered.push_back(sid);

    return true;
  }

public:
  std::vector<int> sortItems(int n, int m,
                             std::vector<int>& group,
                             std::vector<std::vector<int>>& beforeItems) {

    std::vector<Vertex> vertices(n + 2 * m);
    for (int i = 0; i < vertices.size(); ++i) {
      vertices[i].id = i;
    }

    for (int i = 0; i < n; ++i) {
      auto &vtx = vertices[i];
      int gid = group[i];

      if (gid != -1) {
        vertices[gid + n].adj.push_back(i);
        vtx.adj.push_back(gid + n + m);
      }

      // Set up fake dependencies to force group items
      // to stick together
      for (auto &dep : beforeItems[i]) {
        int depGroup = group[dep];
        if (depGroup == gid) {
          // Don't break intra group connections
          vertices[i].adj.push_back(dep);
        } else {
          // Inter group connections must go through
          // the vertices we introduced
          int src = gid == -1 ? i : n + m + gid;
          int dest = depGroup == -1 ? dep : n + depGroup;
          vertices[src].adj.push_back(dest);
        }
      }
    }

    for (auto &vtx : vertices) {
      for (auto &v : vtx.adj) {
        vertices[v].indegree++;
      }
    }

    std::vector<int> ordered;

    for (auto &vtx : vertices) {
      if (vtx.indegree == 0) {
        if (!toposort(vtx.id, vertices, ordered)) {
          return {};
        }
      }
    }

    // Delete extra nodes
    ordered.erase(
      std::remove_if(
        ordered.begin(),
        ordered.end(),
        [&n](int i){
          return i >= n;
        }),
      ordered.end()
    );

    if (ordered.size() < n) {
      return {};
    }

    return ordered;
  }
};
}
