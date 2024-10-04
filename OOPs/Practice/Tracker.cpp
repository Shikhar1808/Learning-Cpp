#include <iostream>
using namespace std;

class Tracker{
    private:
        int PersonId;
        int step_count;
        int stair_count;

        static int object_count;

    public:
        Tracker(int id=0, int steps=0, int stairs=0){
            PersonId = id;
            step_count = steps;
            stair_count = stairs;
            object_count++;
        }

        ~Tracker(){
            object_count--;
        }

        void incrementSteps(int n);

        friend void conversionStep(Tracker &o);

        void display_count(){
            cout<<"PersonID: "<<PersonId<<endl;
            cout<<"Step Count: "<<step_count<<endl;
            cout<<"Stair Count: "<<stair_count<<endl;
            cout<<endl<<endl;
        }

        static int get_object_count(){
            return object_count;    
        }
};

int Tracker :: object_count = 0;

void Tracker :: incrementSteps(int n){
    step_count += n;
}

void conversionStep(Tracker &o){
    o.step_count += o.stair_count * 2;
    o.stair_count = 0;
}

int main(){
    
    int trackerNo;
    cout<<"Enter the number of trackers: ";
    cin>>trackerNo;

    Tracker* objArr = new Tracker[trackerNo];

    for (int i = 0; i < trackerNo; i++) {
        int id, steps, stairs;
        cout << "Enter PersonID, Step Count, and Stair Count for tracker " << i + 1 << ": ";
        cin >> id >> steps >> stairs;
        objArr[i] = Tracker(id, steps, stairs);
    }


    for(int i =0; i<trackerNo; i++){
        objArr[i].incrementSteps(5);
    }

    for(int i =0; i<trackerNo; i++){
        conversionStep(objArr[i]);
    }

    for(int i =0; i<trackerNo; i++){
        objArr[i].display_count();
    }

    cout<<"Total number of objects: "<<Tracker :: get_object_count()<<endl;

    delete [] objArr;

    return 0;
}