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
};

int main(){

    return 0;
}