#include <iostream>
using namespace std;


class Point{
    private:
        int x, y;

    public:
        Point(int x=0, int y=0): x(x), y(y) {}

        friend ostream& operator<<(ostream& os, const Point& p){
            os<<"(" << p.x << ", " << p.y << ")";
            return os; //returning ostream object for chaining
        }

        // In C++, ostream& refers to a reference to an object of the ostream class, 
        // which is part of the Standard Input/Output Library in the <iostream> header. 
        // It represents an output stream that is used for sending data (output) to various destinations, 
        // such as the console, files, or other devices.
        //& is used to pass the original object to the function rather than a copy.
        //Function returning ostream& allow for operator chaining.
};

int main(){

    Point p1(1, 2);
    Point p2(3, 4);

    cout << p1 << endl;
    cout << p2 << endl;

    return 0;
}