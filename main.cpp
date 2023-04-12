// Zack Bright
// zmbrfq@umsystem.edu
// CS303 Assignment 3
// Due Apr 11 2023

#include <iostream>
#include "Queue.h"
#include "Functions.h"

int main() {

  // PROBLEM 1 //

  cout << "QUESITON 1 SOLUTION\n-------------------\n\n";

  string infix;
  cout << "Enter infix expression (No Spaces, use * for multiplication): ";
  cin >> infix;

  if (!isBalanced(infix)) {
    cout << "Expression has unbalanced parentheses, try again." << endl;
  }
  
  string postfix = infixToPostfix(infix);
  cout << "Postfix expression: " << postfix << endl;


  // PROBLEM 2 //\
  

  Queue students;
  
  cout << "\n\n";
  cout << "QUESITON 2 SOLUTION\n-------------------\n\n";
  students.push_back("Zack");
  students.push_back("Rye");
  students.push_back("Monica");
  cout << "Empty? : ";
  cout << students.empty();
  cout << "\n\n";
  students.printList();
  cout << "\n\n";
  cout << "Front : ";
  cout << students.front();
  cout << "\n\n";
  cout << "Size before pop: ";
  cout << students.size();
  students.pop_front();
  cout << "\n\n";
  students.printList();
}