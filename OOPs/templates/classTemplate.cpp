#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    T arr[10];
    int top;

public:
    Stack() : top(-1) {}

    void push(T value) {
        if (top == 9) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = value;
    }

    T pop() {
        if (top == -1) {
            throw "Stack Underflow";
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

template <typename T>
class Test{
    private:
        T obj;
    public:
        Test(T obj){
            this->obj = obj;
        }

        T divideBy2();
};

template <typename T>
T Test<T>::divideBy2(){
    return obj / 2;
}

int main() {
    Stack<int> intStack;
    Stack<string> stringStack;

    intStack.push(10);
    intStack.push(20);
    cout << "Popped from int stack: " << intStack.pop() << endl;

    stringStack.push("Hello");
    stringStack.push("World");
    cout << "Popped from string stack: " << stringStack.pop() << endl;

    Test<int> intObj(10);
    cout << intObj.divideBy2() << endl;

    return 0;
}
