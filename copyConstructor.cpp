#include <iostream>
using namespace std;

class Number{
    int a;

    public:
        Number(){
            a=100;
        }//default constructor
        Number(int num){
            a = num;
        }
        Number(Number &obj){
            cout<<"Copy Constructor Called"<<endl;
            a = obj.a;
        }
        void display(){
            cout<<"The number for this object is "<<a<<endl;
        }
};

// When there is no copy constructor is found, compiler supplies its own copy constructor and there will be no error
// Copy Constructor is used to create a new object to resemble the passed object.
// ex:
// Number(Number &obj){
//      cout<<"Copy Constructor Called"<<endl;
//      a = obj.a;
//  }

int main(){
    Number x,y,z(45);
    x.display();
    y.display();
    z.display();
    Number z1(z),z2; //Copy Contructor Invoked
    z1.display();

    z2 = z; //Copy Constructor not Invoked but the object get coppied to a new object. Intialized first then defined.
    z2.display();

    Number z3 = z;//Copy Constructor Invoked because the new object is intialized and defined at a same time.
    z3.display();

    return 0;
}