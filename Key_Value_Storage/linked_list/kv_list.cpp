#include "kv_list.h"

#include <iostream>

using namespace std;

Node::Node() : key(""), value(""), next(nullptr) {}

Node::Node(string _key, string _value)
    : key(_key), value(_value), next(nullptr) {}

Node::~Node() {}

SinglyLinkedList::SinglyLinkedList() : head(nullptr) {}

SinglyLinkedList::~SinglyLinkedList() {
  while (head != nullptr) {
    Node* toDelete = head;
    head = head->next;
    delete toDelete;
  }
}

void SinglyLinkedList::put(string _key, string _value, bool sortFlag) {
  Node* newNode = new Node(_key, _value);

  if (head == nullptr) {
    head = newNode;
  }

  else if (sortFlag) {
    Node* prevNode = nullptr;
    Node* currentNode = head;

    if (currentNode->key > _key) {
      newNode->next = currentNode;
      head = newNode;
    }

    else {
      while (currentNode != nullptr && currentNode->key < _key) {
        prevNode = currentNode;
        currentNode = currentNode->next;
      }

      if (currentNode == nullptr) {
        prevNode->next = newNode;
      }

      else {
        prevNode->next = newNode;
        newNode->next = currentNode;
      }
    }
  }

  else {
    newNode->next = head;
    head = newNode;
  }
}

string SinglyLinkedList::get(string _key) {
  if (head == nullptr) return "";

  if (head->key == _key) {
    return head->value;
  }

  Node* currentNode = head;

  while (currentNode != nullptr && currentNode->key != _key) {
    currentNode = currentNode->next;
  }

  if (currentNode->key == _key) {
    return currentNode->value;
  }

  return "";
}

void SinglyLinkedList::remove(string _key) {
  if (head == nullptr) return;

  if (head->key == _key) {
    Node* toDelete = head;
    head = head->next;
    delete toDelete;
    return;
  }

  Node* previousNode = nullptr;
  Node* currentNode = head;

  while (currentNode != nullptr && currentNode->key != _key) {
    previousNode = currentNode;
    currentNode = currentNode->next;
  }

  if (currentNode != nullptr) {
    previousNode->next = currentNode->next;
    delete currentNode;
  }
}

void SinglyLinkedList::display() {
  Node* currentNode = head;
  while (currentNode != nullptr) {
    cout << currentNode->value << "\n";
    currentNode = currentNode->next;
  }
}
