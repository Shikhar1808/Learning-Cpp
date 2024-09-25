#include <iostream>
using namespace std;

class stackUsingOneQueue{
    int *arr;
    int front, rear, capacity, size;

    public:

        stackUsingOneQueue(int c){
            arr = new int[c];
            capacity = c;
            front = 0;
            rear = 0;
            size = 0;
        }

        void push(int x){
            if(size == capacity){
                cout<<"Stack is full"<<endl;
                return;
            }
            arr[rear] = x;
            rear = (rear+1)%capacity;
            size++;
        }

        int pop(){
            if(size == 0){
                cout<<"Stack is empty"<<endl;
                return -1;
            }

            int res = arr[(rear-1+capacity)%capacity];
            rear = (rear-1+capacity)%capacity;
            size--;
            
        }

        int top(){
            if(size == 0){
                cout<<"Stack is empty"<<endl;
                return -1;
            }
            return arr[(rear-1+capacity)%capacity];
        }

        bool isEmpty(){
            return size == 0;
        }

        void display(){
            for(int i=0; i<size; i++){
                cout<<arr[(front+i)%capacity]<<" ";
            }
            cout<<endl;
        }
};

int main(){

    stackUsingOneQueue stack(5);

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    cout<<stack.top()<<endl;

    stack.display();

    stack.pop();

    cout<<stack.top()<<endl;

    stack.display();

    return 0;
}