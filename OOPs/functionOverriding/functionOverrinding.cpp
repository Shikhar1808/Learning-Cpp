#include <iostream>
using namespace std;

class Base{
    public: 
        virtual void show(){
            cout << "Base class" << endl;
        }
};

class Derived: public Base{
    public:
        void show(){
            cout << "Derived class" << endl;
        }
};

int main(){
    Base *b = new Derived();
    b->show();
    return 0;
}