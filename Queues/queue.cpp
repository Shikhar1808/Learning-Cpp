#include <iostream>
using namespace std;

class Queue{
    int *arr;
    int front, rear, size, capacity;
    public:
    Queue(int s){
        capacity = s;
        arr = new int[s];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~Queue(){
        delete[] arr;
    }

    void enQueue(int value);
    int deQueue();
    void displayQueue();

    bool isFull(){
        return size == capacity;
    }

    bool isEmpty(){
        return size == 0;
    }
};

void Queue::enQueue(int value){
    if(isFull()){
        cout << "Queue is full" << endl;
        return;
    }
    rear++;
    arr[rear] = value;
    size++;
}

int Queue:: deQueue(){
    if(isEmpty()){
        cout << "Queue is empty" << endl;
        return -1;
    }
    int temp = arr[front];
    front++;
    size--;
    return temp;
}

void Queue::displayQueue(){
    if(isEmpty()){
        cout << "Queue is empty" << endl;
        return;
    }
    for(int i = front; i <= rear; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){

    Queue q(5);

    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);

    q.displayQueue();

    cout << q.deQueue() << endl;

    q.displayQueue();

    return 0;
}