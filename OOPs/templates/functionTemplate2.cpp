//function template with a non-type parameter
//Non-type parameters allow you to pass compile-time constants, such as integers, pointers, or references.

#include <iostream>
using namespace std;

template <typename T, size_t size>
//size_t is an unsigned integral type meaning that it can only store positive values. 
//It is used to store the size of objects. 
//Typically an allias for unsigned long int

void printArray1(T (&arr)[size]){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

template <typename T, int size>
//size is a non-type parameter. 
//It is a constant value that is passed to the function at compile time

//Here we are using int as the non-type parameter because the size of the array is always an integer value 
void printArray2(T (&arr)[size]){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//we can use any of the function because the size of the array is always an integer value

int main(){
    int arr1[] = {1,2,3,4,5}; //size is deduced as 5
    double arr2[] = {1.1,2.2,3.3,4.4,5.5}; //size is deduced as 5

    printArray1(arr1);
    printArray1(arr2);

    printArray2(arr1);
    printArray2(arr2);
}