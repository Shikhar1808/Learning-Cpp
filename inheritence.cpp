#include <iostream>
using namespace std;

class Employee{ //Base class
    float salary;

    public:
    int id;
    Employee(int id){
        this->id = id;
        salary = 34.0;
    }
    Employee(){ //Default constructor
        salary = 120.0;
    }

};

class Programmer : public Employee{  //Derived class
    public:
        Programmer(int id){
            this->id = id;
        }
};

//public keyword is used to inherit the base class public members (public members of base class will be public in derived class)
//private keyword is used to inherit the base class private members (public members of base class will be private in derived class)
//private members of base class are not accessible in derived class

//If we dont specify the visibility mode, then private is default

//Why we use Default Constructor in Base Class?
//We use default constructor in base class because when we create object of derived class, it will call the default constructor of base class first and then the constructor of derived class will be called automatically
int main(){

    Employee harry(1), rohan(2);
    Programmer skillf(10);

    return 0;
}