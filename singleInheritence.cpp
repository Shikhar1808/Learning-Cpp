#include <iostream>
using namespace std;

class Animal{
    public:
    void sound(){
        cout<<"Animal Sound"<<endl;
    }
};

class Dog: public Animal{
    public:
    void sound(){
        cout<<"Dog Barks"<<endl;
    }
};
int main(){
    Animal a;
    Dog d;
    a.sound();
    d.sound();

    return 0;
}