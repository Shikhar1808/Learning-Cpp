#include<iostream>
using namespace std;


//Defining the class so the complier should know that this class exists
class Complex;


//friend class that uses a friend function
class Calculator{
    public:
        int add(int a, int b){
            return a+b;
        }

        //Defining the function for later use
        int sumRealComplex(Complex o1, Complex o2);
        int subRealComplex(Complex o1, Complex o2);
};

class Complex{
    int a;
    int b;

    //Individually declaring fncs as friends
    friend int Calculator :: sumRealComplex(Complex o1, Complex o2);
    friend int Calculator :: subRealComplex(Complex o1, Complex o2);

    //Declaring enrire class as friend
    friend class Calculator;

    public:
        void setData(int n1, int n2){
            a = n1;
            b = n2;
        }

        void printData(void){
            cout<<"Your complex number: "<<a<<" + "<<b<<"i"<<endl;
        }
};

int Calculator :: sumRealComplex(Complex o1, Complex o2){
    return (o1.a + o2.a);
}
int Calculator :: subRealComplex(Complex o1, Complex o2){
    return (o1.a - o2.a);
}


int main(){
    Complex o1,o2;
    o1.setData(1,2);
    o1.printData();
    o2.setData(3,6);
    o2.printData();

    Calculator calc;
    int resAdd = calc.sumRealComplex(o1,o2);
    cout<<"The sum of real part of o1 and o2 is: "<<resAdd<<endl;
    
    int resSub = calc.subRealComplex(o1,o2);
    cout<<"The minus of real part of o1 and o2 is: "<<resSub<<endl;

    return 0;
}