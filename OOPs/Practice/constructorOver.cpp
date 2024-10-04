#include <iostream>
using namespace std;

class test_start;
void display_id();

class test_start{
    static int t_id;
    int hour, minutes, secconds;

    public:
        test_start(){
            t_id++;
            hour = 0;
            minutes = 0;
            secconds = 0;
        }

        test_start(int h, int m, int s){
            t_id++;
            hour = h;
            minutes = m;
            secconds = s;
        }

        test_start(test_start &t){
            t_id++;
            hour = t.hour;
            minutes = t.minutes;
            secconds = t.secconds;
        }

        friend void display_id();

};

int test_start :: t_id = 0;

void display_id(){
    cout<<"Final ID: "<<test_start::t_id<<endl;
}

int main(){
    test_start t1;
    test_start t2(1,2,3);
    test_start t3(t2);

    display_id();

    return 0;
}