#include <iostream>
using namespace std;

class Box{
    private:
        double length;

    public:
        Box(double l): length(l) {}

        bool operator== (const Box& b) const{
            return length == b.length;
        }

        //The const at the end of the function declares that the member function will not modify
        //the current object.
        //This guarantees that calling operator== on a const object is safe
        //and does not alter its state
};

int main(){
    Box box1(10.5);
    Box box2(10.5);

    if (box1 == box2) { //this requires operator== to be const
        cout << "Boxes are equal." << endl;
    } else {
        cout << "Boxes are not equal." << endl;
    }

    return 0;

}