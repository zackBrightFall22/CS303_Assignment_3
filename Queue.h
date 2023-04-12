#pragma once
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

// Node struct to serve as list structure
// I chose to make the list a list of names, based on the example seen in class.
struct Node {
	string name;
	Node* next;

};

class Queue {
private:
// Required member variables
	Node* head;
  Node* tail;
  size_t num_items;

public:
// Required member functions
	Queue();
  void push_back(string name);  
  string pop_front(); 
  string front(); 
  bool empty();
  size_t size();
// Extra member function I added
  void printList();
};