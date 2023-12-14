#include "kv_hash.h"

#include <iostream>
using namespace std;
void HashTableStorage::put(string _key, string _value) {

  int idx = hashIndex(_key);
  SLL[idx].put(_key, _value, false);
  /*
     Use 'hashIndex' to figure out the index for hash table
     */
}

string HashTableStorage::get(string _key) {
  int idx = hashIndex(_key);
  return SLL[idx].get(_key);
}

void HashTableStorage::remove(string _key) {
  int idx = hashIndex(_key);
  SLL[idx].remove(_key);
}

int HashTableStorage::hashIndex(string _key) {
  
  int result = 0;;
  while(!_key.empty()){
    int tmp = _key.back();
    _key.pop_back();
    result = (result + tmp) % (1<<10);
  }

  return result;
  /*
     Implement function that returns integer value between 0-1024
     */
}
