#include "Queue.h"

// List contructor
Queue::Queue() {
	head = nullptr;
  tail = nullptr;
  num_items = 0;
}

void Queue::push_back(string name){
  // adds node to the back of the list
  Node* newNode = new Node;
  newNode->name = name;
  newNode->next = nullptr;
  // checks if empty, if so then tail = head
  if (empty()){
    head = newNode;
    tail = newNode;
  }
  // if not empty, add to the end of list and reassign tail
  else{
    tail->next = newNode;
    tail = newNode;
  }
  //increment num_items
  num_items++;
}


string Queue::pop_front(){ //pop head node
  //if empty do nothing
  if (empty()){
    return "Queue is empty.\n";
  }
  //create temp space to hold head data
  Node* temp = new Node;
  temp = head;
// reassign head and delete old head space and data
  head = head->next;
// decrement num_items
  num_items--;
  return temp->name;
}

string Queue::front(){ //return value of head node
  return head->name;
}


bool Queue::empty(){ //check if empty. Return true if empty, return false if not empty
  if (num_items == 0)
    return true;
  return false;
}

size_t Queue::size(){
  return num_items;
}

void Queue::printList() { //prints the list by creating a temp node and assigning it to the head and then continuing down the list
  Node *tempPtr = new Node;
  tempPtr = head;
  while(tempPtr != nullptr){
    cout << tempPtr->name << endl;
    tempPtr = tempPtr->next;
  }
}


