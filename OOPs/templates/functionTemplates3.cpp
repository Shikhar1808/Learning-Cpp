//more on non-type parameters

#include <iostream>
using namespace std;

//compile-time constant
//The value of the non-type parameter must be known at compile time
template <int N>
int add(int a){
    return a+N;
}

template <int N>
int factorial() {
    static_assert(N >= 0, "Factorial is not defined for negative numbers.");
    //static_assert is used to check the condition at compile time and if the condition is false, it throws an error message
    return N * factorial<N - 1>();
}
//specialization of the template for handling the base case
template <>
int factorial<0>() {
    return 1;
}

//pointers and references as non-type parameters
//Non-type template parameters of type pointer (int*) must point to global, static, or external variables. 
//Local variables like x in main cannot be used.
template <int *ptr>
void print1(){
    cout<<*ptr<<endl;
}

template <int *ptr>
void increment(){
    (*ptr)++;
}

template <int &ref>
void print2(){
    cout<<ref<<endl;
}

int globalX = 10;

int main(){
    cout<<add<5>(10)<<endl; //15
    cout<<add<10>(20)<<endl; //30
    cout<<add<15>(30)<<endl; //45

    cout<<factorial<5>()<<endl; //120
    cout<<factorial<3>()<<endl; //6

    print1<&globalX>(); //10
    increment<&globalX>();
    print2<globalX>(); //11 (globalX is passed by reference)
}