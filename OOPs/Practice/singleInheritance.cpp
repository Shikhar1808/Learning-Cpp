#include <iostream>
using namespace std;

class Animal{
    public:
        virtual void speak(){ //creating a virtual function so that it can be overridden in the derived classes
            cout<<"Animal Speaking"<<endl;
        }
};

class Dog: public Animal{
    public:
        void speak(){
            cout<<"Dog Barking"<<endl;
        }
};

class Cat: public Animal{
    public:
        void speak(){
            cout<<"Cat Meowing"<<endl;
        }
};

int main(){
    Animal *A; //Declared A as a pointer of Animal class because we want to point to the objects of derived classes
    Dog d;
    Cat c;

    A = &d; //A is pointing to the object of Dog class
    A->speak();//It will call the speak function of Dog class. 
    //The function is virtual so it will call the function of the object to which A is pointing
    //If the function is not virtual, then it will call the function of the class of the pointer
    
    A = &c;
    A->speak();
    return 0;
}