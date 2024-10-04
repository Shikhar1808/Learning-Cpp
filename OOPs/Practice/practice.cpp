#include <iostream>
using namespace std;
class Test{
    static int i;
    int num;

public:
    void static getvalue(int);
    Test(int x){ 
        num = x; 
    }
    void show(){
        cout << "i=" << i << endl;
        cout << "num=" << num << endl;
    }
};

void Test :: getvalue(int x){
    i = x;
    i++;
    cout << "i=" << i << endl;
}

int Test :: i;

int main(){
    Test :: getvalue(10);
    Test t1(10);
    t1.show();
}