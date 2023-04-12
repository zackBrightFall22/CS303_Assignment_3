#include <iostream>
#include <stack>
#include <cstring>
#include "Functions.h"

using namespace std;

bool isBalanced(string expression) {
    stack<char> stack1;
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[') {
            stack1.push(expression[i]);
        } else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']') {
            if (stack1.empty()) {
                return false;
            } else if ((expression[i] == ')' && stack1.top() == '(') ||
                       (expression[i] == '}' && stack1.top() == '{') ||
                       (expression[i] == ']' && stack1.top() == '[')) {
                stack1.pop();
            } else {
                return false;
            }
        }
    }
    return stack1.empty();
}

bool isOperand(char c) {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

int getOrder(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/' || c == '%')
        return 2;
    else
        return 0;
}

string infixToPostfix(string infix) {
    stack<char> stack1;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == ' ' || infix[i] == ',') {
            continue;
        } else if (isOperand(infix[i])) {
            while (isOperand(infix[i])) {
                postfix += infix[i];
                i++;
            }
            i--;
            postfix += " ";
        } else if (isOperator(infix[i])) {
            while (!stack1.empty() && stack1.top() != '(' && getOrder(stack1.top()) >= getOrder(infix[i])) {
                postfix += stack1.top();
                stack1.pop();
                postfix += " ";
            }
            stack1.push(infix[i]);
        } else if (infix[i] == '(') {
            stack1.push(infix[i]);
        } else if (infix[i] == ')') {
            while (!stack1.empty() && stack1.top() != '(') {
                postfix += stack1.top();
                stack1.pop();
                postfix += " ";
            }
            stack1.pop();
        }
    }

    while (!stack1.empty()) {
        postfix += stack1.top();
        stack1.pop();
        postfix += " ";
    }

    return postfix;
}
