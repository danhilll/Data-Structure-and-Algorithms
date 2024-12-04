#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return -1;
}

int evaluatePostfix(string expression) {
    stack<int> s;
    for (int i = 0; i < expression.length(); i++) {
        if (isdigit(expression[i])) {
            s.push(expression[i] - '0');
        } else {
            int op1 = s.top();
            s.pop();
            int op2 = s.top();
            s.pop();
            switch (expression[i]) {
                case '+':
                    s.push(op2 + op1);
                    break;
                case '-':
                    s.push(op2 - op1);
                    break;
                case '*':
                    s.push(op2 * op1);
                    break;
                case '/':
                    s.push(op2 / op1);
                    break;
            }
        }
    }
    return s.top();
}

string infixToPostfix(string expression) {
    stack<char> s;
    string postfix;
    for (int i = 0; i < expression.length(); i++) {
        if (isdigit(expression[i])) {
            postfix += expression[i];
        } else if (expression[i] == '(') {
            s.push('(');
        } else if (expression[i] == ')') {
            while (s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        } else {
            while (!s.empty() && precedence(expression[i]) <= precedence(s.top())) {
                postfix += s.top();
                s.pop();
            }
            s.push(expression[i]);
        }
    }
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

int main() {
    string infixExpression;
    cout << "Enter an infix expression: ";
    getline(cin, infixExpression);

    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExpression << endl;

    int result = evaluatePostfix(postfixExpression);
    cout << "Result: " << result << endl;

    return 0;

}