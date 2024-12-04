// class templates with non-type parameters

#include <iostream>
using namespace std;

template <typename T, int size>
class Array{
    private:
        T arr[size];
    public:
        void set(int index, T value){
            arr[index] = value;
        }

        T get(int index){
            return arr[index];
        }

        void print(){
            for(int i = 0; i < size; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

int main(){
    Array<int, 5> arr1;
    arr1.set(0, 10);
    arr1.set(1, 20);
    arr1.set(2, 30);
    arr1.set(3, 40);
    arr1.set(4, 50);

    arr1.print();

    Array<double, 3> arr2;
    arr2.set(0, 1.1);
    arr2.set(1, 2.2);
    arr2.set(2, 3.3);

    arr2.print();
}