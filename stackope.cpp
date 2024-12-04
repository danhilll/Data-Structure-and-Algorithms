#include <iostream>

using namespace std;

class Stack {
private:
    int top;
    int maxSize;
    int* stackArray;

public:
    Stack(int size) {
        maxSize = size;
        stackArray = new int[maxSize];
        top = -1;
    }

    ~Stack() {
        delete[] stackArray;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == maxSize - 1);
    }

    bool push(int value) {
        if (isFull()) {
            cout << "Stack is full. Cannot push " << value << " onto the stack." << endl;
            return false;
        } else {
            stackArray[++top] = value;
            cout << "Pushed " << value << " onto the stack." << endl;
            return true;
        }
    }

    bool pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop from the stack." << endl;
            return false;
        } else {
            cout << "Popped " << stackArray[top--] << " from the stack." << endl;
            return true;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. No top element to peek." << endl;
            return -1;
        } else {
            cout << "Top element: " << stackArray[top] << endl;
            return stackArray[top];
        }
    }
};

int main() {
    Stack myStack(5);
    
    cout << "Is Empty?: " << myStack.isEmpty() << endl;
    
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    
    cout << "Is Full?: " << myStack.isFull() << endl;
    
    myStack.push(40);
    myStack.push(50);
    
    myStack.peek();
    
    cout << "Is Full?: " << myStack.isFull() << endl;
    
    myStack.pop();
    myStack.pop();
    
    myStack.peek();
    
    myStack.push(60);

    return 0;
}