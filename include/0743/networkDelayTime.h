#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <algorithm>
#include <vector>


namespace p0743 {
class Solution {
private:
  void propagate(const std::vector<std::vector<std::pair<int, int>>> &edges,
                 std::vector<int> &arrival, int src, int now) {
    for (auto &edge : edges[src]) {
      int dest = edge.first;
      int delay = edge.second;

      // Only travese an edge if we found a shorter path leading to it
      if (now + delay < arrival[dest]) {
        arrival[dest] = now + delay;
        propagate(edges, arrival, dest, arrival[dest]);
      }
    }
  }

public:
  int networkDelayTime(std::vector<std::vector<int>> &times, int N, int K) {
    int NEVER = std::numeric_limits<int>::max();
    std::vector<int> arrival(N, NEVER);
    std::vector<std::vector<std::pair<int, int>>> edgeList(N);
    for (auto &t : times) {
      edgeList[t[0] - 1].emplace_back(t[1] - 1, t[2]);
    }

    arrival[K - 1] = 0;
    propagate(edgeList, arrival, K - 1, 0);

    int delay = NEVER;

    // If this is a DAG, then there are sources and sinks
    // we need to find the max time taken to arrive at all sinks
    for (int i = 0; i < arrival.size(); ++i) {
      if (arrival[i] == NEVER) {
        return -1;
      }
      if (edgeList[i].empty()) {
        delay = std::max(delay, arrival[i]);
      }
    }

    if (delay != NEVER) {
      return delay;
    }

    // We were bamboozled, and this wasn't a DAG, return the max over all
    // elements
    return *std::max_element(arrival.begin(), arrival.end());
  }
};
} // namespace p0743
