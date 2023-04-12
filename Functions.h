
#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

bool isBalanced(string expression);
//PRE : User inputs infix expression
//POST: Checks that each open (, {, [, has a closing ], }, )

bool isOperand(char c);
//PRE : input is character from infix expression
//POST: Checks if character in infix expression is an operand


bool isOperator(char c);
//PRE : input is character from infix expression
//POST: Checks if character in infix expression is an operator

int getOrder(char c);
//PRE : input is operator from infix expression
//POST: assigns priority based on order of operations


string infixToPostfix(string infix);
//PRE : input is balance-checked infix expression
//POST: converts the infix expression to postfix using a stack
