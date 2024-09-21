#include <iostream>

#define MAX 100

class Stack {
private:
    int top; 
    int arr[MAX]; 
public:
Stack() {
        top = -1;
    }

    void push(int value) {
        if (top >= MAX - 1) {
            std::cout << "Stack Overflow" << std::endl;
            return;
        }
        arr[++top] = value; 
    }
    int pop() {
        if (top < 0) {
            std::cout << "Stack Underflow" << std::endl;
            return -1; 
        }
        return arr[top--]; 
    }

    int peek() {
        if (top < 0) {
            std::cout << "Stack is empty" << std::endl;
            return -1;
        }
        return arr[top];
    }
    bool isEmpty() {
        return (top < 0);
    }
};

class Queue {
private:
    Stack stack1, stack2;

public:
    void enqueue(int value) {
        stack1.push(value);
    }

    int dequeue() {
        if (stack2.isEmpty()) {
            while (!stack1.isEmpty()) {
                stack2.push(stack1.pop());
            }
        }

        if (stack2.isEmpty()) {
            std::cout << "Queue is empty!" << std::endl;
            return -1;
        }

        return stack2.pop(); 
    }

    int peek() {
        if (stack2.isEmpty()) {
            while (!stack1.isEmpty()) {
                stack2.push(stack1.pop());
            }
        }

        if (stack2.isEmpty()) {
            std::cout << "Queue is empty!" << std::endl;
            return -1;
        }

        return stack2.peek();
    }

    bool isEmpty() {
        return stack1.isEmpty() && stack2.isEmpty();
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << "Dequeued: " << q.dequeue() << std::endl;  
    std::cout << "Front: " << q.peek() << std::endl;         

    q.enqueue(40);
    std::cout << "Dequeued: " << q.dequeue() << std::endl;  
    std::cout << "Dequeued: " << q.dequeue() << std::endl;  
    std::cout << "Dequeued: " << q.dequeue() << std::endl;  
    std::cout << "Dequeued: " << q.dequeue() << std::endl;  

    return 0;
}
