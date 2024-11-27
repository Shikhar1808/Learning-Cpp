#include <iostream>
using namespace std;

class Fraction{
    private:
        int num, den;
    

    public: 
        Fraction(int n=0, int d=1): num(n), den(d) {}

        Fraction operator+(const Fraction& other){ //Overloading the + operator as a member function
            int newNum = (num*other.den) + (den*other.num);
            int newDen = den*other.den;

            return Fraction(newNum, newDen);
        }

        void display(){
            cout << num << "/" << den << endl;
        }
};


int main(){

    Fraction f1(2, 5);
    Fraction f2(3, 4);

    Fraction f3 = f1 + f2;

    f3.display();

    return 0;
}