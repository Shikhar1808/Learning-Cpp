#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Rectangle;
class Triangle;
void addArea(Rectangle r, Triangle t);

class Rectangle{
    int length;
    int breadth;
    string color;

    public:
        Rectangle(){
            length = 0;
            breadth = 0;
            color = "Green";
        }
        void setData(int len, int brd, string clr = "Green"){
            length = len;
            breadth = brd;
            color = clr;
        }

        friend void addArea(Rectangle r, Triangle t);
};

class Triangle{
    string color;
    int s1, s2, s3;

    public:
        Triangle(){
            s1 = 0;
            s2 = 0;
            s3 = 0;
            color = "Green";
        }

        void setData(int side1, int side2, int side3){
            s1 = side1;
            s2 = side2;
            s3 = side3;
        }

        friend void addArea(Rectangle r, Triangle t);
};

void addArea(Rectangle r, Triangle t){
    float rArea = r.length * r.breadth;
    cout<<"Area of rectangle is: "<<rArea<<endl;
    float s = (t.s1 + t.s2 + t.s3)/2;
    float tArea = sqrt(s*(s-t.s1)*(s-t.s2)*(s-t.s3));
    cout<<"Area of triangle is: "<<tArea<<endl;
    cout<<"Total Area is: "<<rArea + tArea<<endl;
}

int main(){
    Rectangle r;
    Triangle t;

    r.setData(3,4,"Red");
    t.setData(3,4,5);

    addArea(r,t);
    
    return 0;
}