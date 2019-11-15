#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <algorithm>
#include <queue>
#include <vector>

namespace p0743 {
class Solution {
private:
  void propagate(const std::vector<std::vector<std::pair<int, int>>> &edges,
                 std::vector<int> &arrival, int src) {
    std::queue<int> processing;
    processing.push(src);
    while (!processing.empty()) {
      src = processing.front();
      processing.pop();
      for (auto &edge : edges[src]) {
        int dest = edge.first;
        int delay = edge.second;

        // Only travese an edge if we found a shorter path leading to it
        if (arrival[src] + delay < arrival[dest]) {
          arrival[dest] = arrival[src] + delay;
          processing.push(dest);
        }
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
    propagate(edgeList, arrival, K - 1);

    int delay = std::numeric_limits<int>::min();

    // If this is a DAG, then there are sources and sinks
    // we need to find the max time taken to arrive at all sinks
    for (int i = 0; i < arrival.size(); ++i) {
      if (arrival[i] == NEVER) {
        return -1;
      } else {
        delay = std::max(delay, arrival[i]);
      }
    }
    return delay;
  }
};
} // namespace p0743
