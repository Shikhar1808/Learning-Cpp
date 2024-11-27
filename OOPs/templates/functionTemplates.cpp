#include <iostream>
using namespace std;

template <typename T>
void swapValue(T&a, T&b){
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T add(T& a, T& b){
    return a+b;
}


int main(){
    int x=10,y=5;
    double p=1.5,q=2.5;

    swapValue(x,y);
    cout<<"x: "<<x<<" y: "<<y<<endl;

    swapValue(p,q);
    cout<<"p: "<<p<<" q: "<<q<<endl;

    cout<<"Sum of x and y: "<<add(x,y)<<endl;
    cout<<"Sum of p and q: "<<add(p,q)<<endl;
}