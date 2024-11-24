#include <iostream>
using namespace std;

class Stack{
    private:

    // Queue implementation using array
        int *arr;
        int front, rear, size, capacity;

        void queueEnqueue(int x){
            if(isFull()){
                cout << "Stack is full" << endl;
                return;
            }
            rear = (rear + 1) % capacity;
            arr[rear] = x;
            size++;
        }

        int queueDequeue(){
            if(isEmpty()){
                cout << "Stack is empty" << endl;
                return -1;
            }
            int temp = arr[front];
            front = (front + 1) % capacity;
            size--;
            return temp;
        }

    public:

        Stack(int capacity){ // Constructor (like for queue)
            this->capacity = capacity;
            arr = new int[capacity];
            front =0;
            rear = -1;
            size = 0;
        }

        ~Stack(){
            delete[] arr;
        }

        bool isEmpty(){
            return size == 0;
        }

        bool isFull(){
            return size == capacity;
        }

        void push(int x){
            if(isFull()){
                cout << "Stack is full" << endl;
                return;
            }
            queueEnqueue(x);

            for(int i = 0; i < size - 1; i++){
                queueEnqueue(queueDequeue());
            }
        }

        int pop(){
            if(isEmpty()){
                cout << "Stack is empty" << endl;
                return -1;
            }
            return queueDequeue();
        }

        int top(){
            if(isEmpty()){
                cout << "Stack is empty" << endl;
                return -1;
            }
            return arr[front];
        }

        void display(){
            if(isEmpty()){
                cout << "Stack is empty" << endl;
                return;
            }
            int count = size;
            int i = front;
            while(count--){
                cout << arr[i] << " ";
                i = (i + 1) % capacity;
            }
            cout << endl;
        }
};

int main(){
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30); 
    s.push(40);

    s.display();

    cout << s.pop() << endl;
    cout << s.top() << endl;


    return 0;
}