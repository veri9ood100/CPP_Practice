#ifndef KV_ARRAY_H
#define KV_ARRAY_H

#include <string>
//#include <vector>

#define NR_TESTS (1 << 15)

using namespace std;

typedef pair<string, string> Node;

// Node Node;

class array_storage {
 public:
  array_storage();
  ~array_storage();

  int BS(string key, int begin, int end);

  void put(string key, string value, bool sortFlag);
  string get(string key);
  void remove(string key);
  void display();

 private:
  // Node *A = new Node[NR_TESTS];
  Node A[NR_TESTS];
  int tail = 0;
};

#endif
