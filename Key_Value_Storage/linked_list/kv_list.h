#ifndef KV_LIST_H
#define KV_LIST_H

#include <string>

using namespace std;

class Node {
public:
    // Change the codes that node stores key-value pair
    string key;
    string value;
    Node* next;

    Node(); // Default constructor
    Node(string key, string value); // Constructor with string argument
    ~Node(); // Destructor
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList(); // Constructor
    ~SinglyLinkedList(); // Destructor

    void put(string key, string value, bool sortFlag);
    string get(string key); // New function!
    void remove(string key);
    void display();
};

#endif // KV_LIST_H

