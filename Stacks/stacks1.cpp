#include <iostream>
using namespace std;

class Stack{
    private:
        int top;
        int arr[5];
    public:
        Stack(){
            top = -1;
            for(int i = 0; i < 5; i++){
                arr[i] = 0;
            }
        }

        bool isEmpty(){
            if(top == -1){
                return true;
            }else{
                return false;
            }
        }

        bool isFull(){
            if(top == 4){
                return true;
            }else{
                return false;
            }
        }

        void push(int val){
            if(isFull()){
                cout << "Stack Overflow" << endl;
            }else{
                top++;
                arr[top] = val;
            }
        }

        int pop(){
            if(isEmpty()){
                cout << "Stack Underflow" << endl;
                return 0;
            }else{
                int popValue = arr[top];
                arr[top] = 0;
                top--;
                return popValue;
            }
        }

        int count(){
            return (top + 1);
        }

        int peek(int pos){
            if(isEmpty()){
                cout << "Stack Underflow" << endl;
                return 0;
            }else{
                return arr[pos];
            }
        }

        void change(int pos, int val){
            arr[pos] = val;
            cout << "Value changed at location " << pos << endl;
        }

        void display(){
            cout << "All values in the Stack are " << endl;
            for(int i = top; i >= 0; i--){
                cout << arr[i] << endl;
            }
        }
};
int main(){
    Stack s1;
    int option, position, value;

    s1.push(1);
    s1.push(10);
    s1.push(100);
    s1.push(1000);
    s1.push(10000);

    s1.display();

    s1.pop();
    s1.display();

    cout << "Enter the position you want to peek: ";
    cin >> position;
    cout << "Peek function called - Value at position " << position << " is " << s1.peek(position) << endl;

    cout << "Enter the position and value you want to change: ";
    cin >> position >> value;
    s1.change(position, value);

    s1.display();


    return 0;
}