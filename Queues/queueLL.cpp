#include <iostream>

struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top; 

public:
    Stack() : top(nullptr) {}

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top; 
        top = newNode; 
    }

    int pop() {
        if (top == nullptr) {
            std::cout << "Stack Underflow" << std::endl;
            return -1;
        }
        Node* temp = top;
        int poppedValue = temp->data;
        top = top->next; 
        delete temp; 
        return poppedValue;
    }

    // Peek the top element
    int peek() {
        if (top == nullptr) {
            std::cout << "Stack is empty" << std::endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
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
