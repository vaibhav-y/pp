// Never visit this again#ifndef INCLUDED_COMMON_H
#ifndef INCLUDED_COMMON_H
#define INCLUDED_COMMON_H

#include "ListNode.h"
#include <ostream>

template <typename First, typename Second>
std::ostream &operator<<(std::ostream &os, std::pair<First, Second> &p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}

#endif // INCLUDED_COMMON_H
