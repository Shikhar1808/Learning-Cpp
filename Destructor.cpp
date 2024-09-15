#include <iostream>
using namespace std;

int count = 0;
class Num{
    public:
        Num(){
            count++;
            cout<<"No.of time constructor is called for object "<<count<<endl;
        }
        ~Num(){
            cout<<"This is the time when my distructor is called for object number "<<count<<endl;
            count--;
        }
};

//Destructor never takes an argument nor does it return any value

int main(){
    cout<<"We are inside in out main fnc"<<endl;
    cout<<"Creting first object n1"<<endl;
    Num n1;
    {
        cout<<"Entering this block"<<endl;
        cout<<"Creating two more objects"<<endl;
        Num n2,n3;
        cout<<"Exiting this block"<<endl;
    }
    cout<<"Back to main"<<endl;
    return 0;
}
