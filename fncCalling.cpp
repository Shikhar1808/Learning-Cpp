#include <iostream>
using namespace std;

class Calculator{
    private:
        int value;

    public:
        Calculator(): value(0){}

        Calculator& add(int num){//& is used to return the reference of the object so that we can use the object in the same line.
            value += num;
            return *this; //returning the reference of the object so that we can use the object in the same line.
        }

        Calculator& sub(int num){
            value -= num;
            return *this; //returning the reference of the object so that we can use the object in the same line.
        }

        Calculator& mul(int num){
            value *= num;
            return *this; //returning the reference of the object so that we can use the object in the same line.
        }

        void display() const{
            cout<<"Value: "<<value<<endl;
        }
};

int main(){
    Calculator cal;
    cal.add(10).sub(5).mul(2).display();
    return 0;
}