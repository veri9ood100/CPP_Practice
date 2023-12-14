#ifndef KV_HASH_H
#define KV_HASH_H

#include <string>

#include "../linked_list/kv_list.h"
using namespace std;

/*
   HashTable should be looks like below:
   |0|: SingleLinkedList[KV_NODE -> KV_NODE -> KV_NODE]
   |1|: SingleLinkedList[KV_NODE -> KV_NODE]
   |2|: SingleLinkedList[]
   ......
   |1023|: SingleLinkedList[KV_NODE -> KV_NODE -> KV_NODE -> KV_NODE]

   Hash table is an array that having 1024 single linked list.
   Each indexes has single linked list that includes KV_NODE.
   Index is calculated by 'hashIndex(string key)` function.
   Implement `hashIndex()` whatever you want.
*/



class HashTableStorage {
 public:
  void put(string key, string value);
  string get(string key);
  void remove(string key);
  void display();

 private:
  int hashIndex(string key);
  SinglyLinkedList SLL[1<<10];

};

#endif
