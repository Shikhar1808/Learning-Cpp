#include <iostream>
using namespace std;

class Complex{
    int a,b;

    public:
        Complex(int x, int y){
            a = x;
            b = y;
        }

        Complex(int x){ //same as fnc overloading
            a =x;
            b = 0;
        }

        void printData(void){
            cout<<"Your complex number is: "<<a<<"+i"<<b<<endl;
        }
};

//A class may have more than one constructors

int main(){
    Complex C(4);
    C.printData();
    return 0;
}