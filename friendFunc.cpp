#include <iostream>
using namespace std;

class Complex{
    int a;
    int b;

    public:
        void setData(int v1, int v2){
            a = v1;
            b = v2;
        }

        friend Complex sumComplete(Complex o1, Complex o2); //it give access to private variables and functions to functions not defined in the class

        void printData(void){
            cout<<"Your complex number is: "<<a<<"+i"<<b<<endl;
        }

};

Complex sumComplete(Complex o1, Complex o2){  //friend function- it will not become the part of public/private member func of the class
    Complex o3;
    o3.setData((o1.a + o2.a), (o1.b + o2.b));
    return o3;
}

// Properties of Friend Function
// 1. Not it the scope of the class
// 2. Since it is not in the scope of the class it cant be called from of the object of the class 
// 3. Can be envoked without the help of any object 
// 4. Usually contains the objects as arguments
// 5. Cab be declared inside public and privte sections of the class 
// 6. It cant access the members directly by calling their name


int main(){
    Complex c1,c2,sum;
    c1.setData(2,2);
    c1.printData();
    c2.setData(3,6);
    c2.printData();
    // c3.setDataBySum(c1,c2);
    // c3.printData();

    sum = sumComplete(c1,c2);
    sum.printData();
    return 0;
}