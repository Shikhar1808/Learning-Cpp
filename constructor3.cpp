#include <iostream>
using namespace std;

class Simple{
    int data1;
    int data2;
    public:
        Simple(int a, int b=9){//Default Argument
            data1 = a;
            data2 = b;
        }

        void printData(void){
            cout<<"Your complex number is: "<<data1<<"+i"<<data2<<endl;
        }

};
int main(){
    Simple C1(4);
    C1.printData();

    return 0;
}