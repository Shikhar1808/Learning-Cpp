#include <iostream>
using namespace std;

class Rectangle{
    private:
        double length;
        double width;

    public: 
        Rectangle(double l=0, double w=0): length(l), width(w){}

        double area() const{
            return length*width;
        }
};

class Square{
    private:
        double side;

    public:

        Square(double s=0): side(s) {}
        Square(const Rectangle& rect){ //Conversion constructor
            side = rect.area();
            cout<<"Square side: "<<side<<endl;
        }

        void displayArea() const {
            cout << "Area of Square: " << side * side << endl;
        }
};


int main(){
    
        Rectangle rect(5, 10);
        Square sq(rect);
        sq.displayArea();
    
        return 0;
}

    
