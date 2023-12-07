#include "kv_vector.h"

#include <cmath>
#include <iostream>

using namespace std;

VectorContainer::VectorContainer() : V() {}

VectorContainer::~VectorContainer() {
  while (V.size() != 0) {
    V.pop_back();
  }
}

int VectorContainer::BS(string _key, int _begin, int _end) {  // binary search
  if (_end == _begin) {                                       // find index
    return _begin;
  }

  else {  // searching continue
    int d = (_begin + _end + 1) / 2;

    if (V[d].first <= _key) {
      return BS(_key, d, _end);
    }

    else {
      return BS(_key, _begin, d - 1);
    }
  }
}

void VectorContainer::put(string _key, string _value, bool sortFlag) {
  Node newNode = make_pair(_key, _value);

  if (!sortFlag || V.size() == 0) {  // non-sorting
    V.push_back(newNode);
  }

  else {  // sorting
    V.insert(V.begin() + BS(_key, 0, V.size() - 1), newNode);
  }
}

string VectorContainer::get(string _key) {
  if (V.size() != 0) {
    int idx = BS(_key, 0, V.size() - 1);
    if (_key == V[idx].first) {
      return V[idx].second;
    }
  }

  // searching failed
  else {
    return "";
  }

  return "";
}

void VectorContainer::remove(string _key) {
  int idx = BS(_key, 0, V.size() - 1);
  V.erase(V.begin() + idx);
}

void VectorContainer::display() {
  for (auto v : V) {
    cout << v.second << "\n";
  }
}
