#include <iostream>
using namespace std;

class A{
    static int count;
    public:
        A(){
            cout<<++count<<endl;
        }
};
int A:: count = 0;

int main(){
    A a[5];
}