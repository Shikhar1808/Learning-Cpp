#include <iostream>
using namespace std;

const int MAX_SIZE = 100; 
class Stack {
private:
    int size;
    int top;
    int s[MAX_SIZE]; 

public:
    Stack(int size) {
        if (size > MAX_SIZE) {
            size = MAX_SIZE;
        }
        this->size = size;
        top = 0;
    }

    void push(int x) {
        if (top == size) {
            cout << "Stack Overflow" << endl;
            return;
        }
        s[top++] = x;
    }

    int pop() {
        if (top == 0) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return s[--top];
    }

    bool isEmpty() {
        return top == 0;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1; // Return a sentinel value
        }
        return s[top - 1];
    }

    void sort() {
        Stack temp(size); 
        while (!isEmpty()) {
            int x = pop();
            while (!temp.isEmpty() && temp.peek() > x) {
                push(temp.pop());
            }
            temp.push(x);
        }

        while (!temp.isEmpty()) {
            push(temp.pop());
        }

        cout << "Sorted" << endl;
    }

    void display() {
        cout << "Stack: ";
        for (int i = top - 1; i >= 0; i--) {
            cout << s[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s(5);

    s.push(5);
    s.push(3);
    s.push(8);
    s.push(1);
    s.push(5);

    int x = s.pop();;
    cout << "Popped element: " << x << endl;

    cout << "Original stack: ";
    s.display();

    s.sort();

    cout << "Sorted stack: ";
    s.display();

    return 0;
}
