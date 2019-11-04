#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <vector>

namespace p0841 {
class Solution {
private:
  void colorRooms(int source,
                  const std::vector<std::vector<int>> &rooms,
                  std::vector<int> &colors) {
    auto &keys = rooms[source];
    for (int i = 0; i < keys.size(); ++i) {
      if (colors[keys[i]] == -1) {
        colors[keys[i]] = source;
        colorRooms(keys[i], rooms, colors);
      }
    }
  }
public:
  bool canVisitAllRooms(std::vector<std::vector<int>> &rooms) {
    if (rooms.empty()) {
      return false;
    }
    // Legend:
    // -1 -> unreachable
    // i -> reachable via room 'i' (i >= 0 && i < rooms.size())
    // All rooms must be reachable via room '0'
    std::vector<int> colors(rooms.size(), -1);
    colors[0] = 0;
    colorRooms(0, rooms, colors);

    // All rooms are reachable via '0'
    for (auto &c : colors) {
      if (c == -1) {
        return false;
      }
    }
    return true;
  }
};
} // namespace p0841
