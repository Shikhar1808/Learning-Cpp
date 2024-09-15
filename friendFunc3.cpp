#include <iostream>
using namespace std;

class c1;
class c2;
void exchange(c1 &o1, c2 &o2);

class c1{
    int val1;
    friend void exchange(c1 &, c2 &);
    public:
        void inData(int a){
            val1 = a;
        }

        void display(void){
            cout<<val1<<endl;
        }
};

class c2{
    int val2;
    friend void exchange(c1 &, c2 &);
    public:
        void inData(int a){
            val2 = a;
        }

        void display(void){
            cout<<val2<<endl;
        }
};


void exchange(c1 &x, c2 &y){
    int temp = x.val1;
    x.val1 = y.val2;
    y.val2 = temp;

    cout<<"The values afte exchanging-> o1: "<<x.val1<<" o2: "<<y.val2<<endl;
}

int main(){
    c1 o1;
    c2 o2;

    o1.inData(3);
    o2.inData(5);

    exchange(o1,o2);
    return 0;
}