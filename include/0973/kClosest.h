#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <vector>

namespace p0973 {
class Solution {
private:
  typedef std::vector<int> Point;
  struct MinHeap {
    std::vector<Point> m_points;
    size_t m_size;

    MinHeap(const std::vector<Point> &points)
        : m_points(points), m_size(points.size()) {
      for (int root = m_size / 2; root >= 0; --root) {
        make_heap(root);
      }
    }

    const Point &min() const {
      return m_points.front();
    }

    void consume() {
      if (!empty()) {
        std::swap(m_points[0], m_points[m_size - 1]);
        --m_size;
        make_heap(0);
      }
    }

    bool empty() const {
      return m_size == 0;
    }

  private:
    void make_heap(size_t root) {
      size_t left = 2 * root + 1;
      size_t right = 2 * root + 2;
      size_t least = root;

      if (left < m_size && measure(m_points[left]) < measure(m_points[least])) {
        least = left;
      }
      if (right < m_size &&
          measure(m_points[right]) < measure(m_points[least])) {
        least = right;
      }

      if (root != least) {
        std::swap(m_points[root], m_points[least]);
        make_heap(least);
      }
    }
  };
  static unsigned long measure(const Point &p) {
    return p[0] * p[0] + p[1] * p[1];
  }

public:
  std::vector<Point> kClosest(std::vector<Point> &points, int K) {
    std::vector<Point> closest(K);
    MinHeap heap(points);
    int idx = 0;
    while (idx < K) {
      closest[idx++] = heap.min();
      heap.consume();
    }
    return closest;
  }
};
} // namespace p0973
