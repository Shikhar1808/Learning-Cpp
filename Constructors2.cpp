#include <iostream>
using namespace std;

class Complex{
    int a,b;

    public:
        Complex(int,int);

        void printData(void){
            cout<<"Your complex number is: "<<a<<"+i"<<b<<endl;
        }
};

Complex :: Complex(int x, int y){ //This is a parameterzied constructor
    a =x;
    b= y;
}

int main(){
    //implicit Call
    Complex C(4,6);
    C.printData();

    //explicit call
    Complex D = Complex(5,7);
    D.printData();
    return 0;
}