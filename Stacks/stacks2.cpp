#include <iostream>
using namespace std;

//2 stacks implementaion in 1 array

class TwoStack{
    int *arr;
    int size;
    int top1, top2;

    public:
        TwoStack(int n){
            size = n;
            arr = new int[n];
            top1 = -1;
            top2 = size;
        }

        void push1(int x){
            if(top1 < top2 - 1){
                top1++;
                arr[top1] = x;
            }else{
                cout << "Stack Overflow" << endl;
            }
        }

        void push2(int x){
            if(top1 < top2 - 1){
                top2--;
                arr[top2] = x;
            }else{
                cout << "Stack Overflow" << endl;
            }
        }

        int pop1(){
            if(top1 >= 0){
                int x = arr[top1];
                top1--;
                return x;
            }else{
                cout << "Stack Underflow" << endl;
                return -1;
            }
        }

        int pop2(){
            if(top2 < size){
                int x = arr[top2];
                top2++;
                return x;
            }else{
                cout << "Stack Underflow" << endl;
                return -1;
            }
        }

        void printStack1(){
            cout<<"Stack 1: ";
            for(int i = 0; i <= top1; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        void printStack2(){
            cout<<"Stack 2: ";
            for(int i = size - 1; i >= top2; i--){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main(){

    TwoStack t(5);

    t.push1(5);
    t.push2(10);
    t.push2(15);

    cout << t.pop1() << endl;
    t.push2(40);

    cout << t.pop2() << endl;

    t.printStack1();
    t.printStack2();

    return 0;
}