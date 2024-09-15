#include <iostream>
using namespace std;

class Complex{
    int a,b;

    public:
        //Creating a constructor
        //Constructor is a special member fnc that with same name as of the class. It is already invoked(called) whenever an object is created.
        //It is used to initialize the objects of its class
        Complex(void); //Constructor declaration

        void printData(void){
            cout<<"Your complex number is: "<<a<<"+i"<<b<<endl;
        }
};

Complex :: Complex(void){ //Defalut constructor as it taks no params
    a =10;
    b= 20;
}

//Characteristics of Constructors
//1. It should be declared in the public section of the class
//2. They are automaically invoked whenever the object is created
//3. Don't have return values(not in void) and do not have return values
//4. it can have default arguments
//5. We can not refer to the address

int main(){
    Complex C;
    C.printData();
    return 0;
}