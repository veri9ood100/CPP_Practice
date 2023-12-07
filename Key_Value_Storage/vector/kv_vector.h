#ifndef KV_VECTOR_H
#define KV_VECTOR_H

#include <string>
#include <vector>

using namespace std;

typedef pair<string, string> Node;

// Node Node;

typedef vector<Node> VECTOR;

class VectorContainer {
 public:
  VectorContainer();
  ~VectorContainer();

  int BS(string key, int begin, int end);

  void put(string key, string value, bool sortFlag);
  string get(string key);
  void remove(string key);
  void display();

 private:
  // Node Node;
  VECTOR V;
};

#endif
