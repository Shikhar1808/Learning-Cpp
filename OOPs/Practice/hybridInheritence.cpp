#include <iostream>
using namespace std;

class Publication{
    protected:
        string title;
        float price;
    
    public:
        void setPublication(string t, float p){
            title = t;
            price = p;
        }
};

class Book : virtual public Publication{
    protected:
        int pageCount;

    public:
        void setBookData(int pc){
            pageCount = pc;
        }
};

class Tape : virtual public Publication{
    protected:
        float playingTime;

    public:
        void setTapeData(float pt){
            playingTime = pt;
        }
};

class Disk : public Book, public Tape{
    public:
        void setData(string t, float p, int pc, float pt){
            setPublication(t,p);
            setBookData(pc);
            setTapeData(pt);
        }

        void display(){
            cout<<"Title: "<<title<<endl;
            cout<<"Price: "<<price<<endl;
            cout<<"Page Count: "<<pageCount<<endl;
            cout<<"Playing Time: "<<playingTime<<endl;
        }
};

int main(){
    Disk disk;
    disk.setData("hihi",12,20,15);
    disk.display();

    return 0;
}