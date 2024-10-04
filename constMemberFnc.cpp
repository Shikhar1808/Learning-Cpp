#include <iostream>
using namespace std;

class MyClass{
    int x;

    public:
        MyClass(int i): x(i){}

        int getX() const{
            return x;
        }

        int setX(int i){
            x = i;
        }
};

int main(){

    const MyClass obj1(10);
    MyClass obj2(20);

    cout<<"obj1 value: "<<obj1.getX()<<endl;
    // obj1.setX(30); //This will give an error because we are trying to modify a const object.
    
    cout<<"obj2 value: "<<obj2.getX()<<endl;
    obj2.setX(30);
    cout<<"obj2 value: "<<obj2.getX()<<endl;

    return 0;
}