#include <iostream>
using namespace std;

class Queue{
    int *arr;
    int front, rear, size;
    public:
    Queue(int s){
        size = s;
        arr = new int[s];
        front = rear = -1;
    }
    void enQueue(int value);
    int deQueue();
    void displayQueue();
};

void Queue::enQueue(int value){
    if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))){
        cout << "Queue is full" << endl;
        return;
    }
    else if(front == -1){
        front = rear = 0;
        arr[rear] = value;
    }
    else if(rear == size-1 && front != 0){
        rear = 0;
        arr[rear] = value;
    }
    else{
        rear++;
        arr[rear] = value;
    }
}

int Queue:: deQueue(){
    if(front == -1){
        cout << "Queue is empty" << endl;
        return;
    }
    int data = arr[front];
    arr[front] = -1;
    if(front == rear){
        front = rear = -1;
    }
    else if(front == size-1){
        front = 0;
    }
    else{
        front++;
    }
    return data;
}

void Queue::displayQueue(){
    if(front == -1){
        cout << "Queue is empty" << endl;
        return;
    }
    if(rear >= front){
        for(int i = front; i <= rear; i++){
            cout << arr[i] << " ";
        }
    }
    else{
        for(int i = front; i < size; i++){
            cout << arr[i] << " ";
        }
        for(int i = 0; i <= rear; i++){
            cout << arr[i] << " ";
        }
    }
}

int main(){

    return 0;
}