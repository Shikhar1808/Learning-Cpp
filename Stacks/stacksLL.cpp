#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};


class Stack{
    private:
        Node* top;
    public:
        Stack(){
            top = NULL;
        }

        bool isEmpty(){
            return top == NULL;
        }

        void push(int x){
            Node* newNode = new Node(x);
            if(top == NULL){
                top = newNode;
                return;
            }
            newNode->next = top;
            top = newNode;
        }

        int pop(){
            if(isEmpty()){
                cout << "Stack Underflow" << endl;
                return -1;
            }
            int x = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            return x;
        }

        int peek(){
            if(isEmpty()){
                cout << "Stack is empty" << endl;
                return -1;
            }
            return top->data;
        }

        void display(){
            Node* temp = top;
            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};


int main(){
    return 0;
} 