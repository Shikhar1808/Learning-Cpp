#include <iostream>
using namespace std;

void arrayException(){
    int arr[5];
    int a = 10;
    
    if(a>5)
        throw arr;
    else
        cout<<"No exception thrown"<<endl;
}

int main(){
    try{
        int option;
        cout<<"Enter 1 to interger exception, 2 to access an array out of bounds, 3 to throw a string, 4 to throw a double: ";
        cin>>option;

        if(option==1){
            throw 404;
        }
        else if(option==2){
            arrayException();
        }
        else if(option==3){
            throw "Exception thrown";
        }
        else if(option==4){
            throw 10.5;
        }
    }
    catch(int e){
        cout<<"Exception caught: "<<e<<endl;
    }
    catch(const char* e){
        cout<<"Exception caught: "<<e<<endl;
    }
    catch(double e){
        cout<<"Exception caught: "<<e<<endl;
    }
    catch(...){
        cout<<"Default exception caught"<<endl;
    }
}