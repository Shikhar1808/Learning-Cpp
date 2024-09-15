#include <iostream>
using namespace std;

class Machine{
    protected:
        string type;

    public:
        Machine(string t) : type(t){
            cout<<"Machine constructor called for "<<type<<endl;
        }

        virtual ~Machine(){
            cout<<"Machine destructor called for "<<type<<endl;
        }

        virtual void start(){
            cout<<type<<" Machine is starting."<<endl;
        }
};

class Fuel{
    protected:
        string fuelType;

    public:
        Fuel(string f) : fuelType(f){
            cout<<"Fuel constructor called for "<<fuelType<<endl;
        }

        virtual ~Fuel(){
            cout<<"Fuel destructor called for "<<fuelType<<endl;
        }

        virtual void fillFuel(){
            cout<<"Filling "<<fuelType<<" fuel."<<endl;
        }
};

class Car: public Machine, public Fuel{
    public:
        Car(string t, string f) : Machine(t), Fuel(f){
            cout<<"Car constructor called for "<<type<<" with "<<fuelType<<" fuel."<<endl;
        }

        ~Car(){
            cout<<"Car destructor called for "<<type<<endl;
        }

        void start() override{
            cout<<type<<" Car with "<<fuelType<<" fuel is starting."<<endl;
        }

        void fillFuel() override{
            cout<<"Filling "<<fuelType<<" fuel in "<<type<<" Car."<<endl;
        }
};

class Electric: public Fuel{
    public:
        Electric(string f) : Fuel(f){
            cout<<"Electric constructor called for "<<fuelType<<" fuel."<<endl;
        }

        ~Electric(){
            cout<<"Electric destructor called for "<<fuelType<<endl;
        }

        void fillFuel() override{
            cout<<"Charging "<<fuelType<<" fuel."<<endl;
        }
};

class ElectricCar: public Machine, public Electric{
    public:
        ElectricCar(string t, string f) : Machine(t), Electric(f){
            cout<<"ElectricCar constructor called for "<<type<<" with "<<fuelType<<" fuel."<<endl;
        }

        ~ElectricCar(){
            cout<<"ElectricCar destructor called for "<<type<<endl;
        }

        void start() override{
            cout<<type<<" ElectricCar with "<<fuelType<<" fuel is starting."<<endl;
        }

        void fillFuel() override{
            cout<<"Charging "<<fuelType<<" fuel in "<<type<<" ElectricCar."<<endl;
        }
};

int main(){
    Car c("Petrol", "Petrol");
    c.start();
    c.fillFuel();
    {

        ElectricCar ec("Tesla", "Electric");
        ec.start();
        ec.fillFuel();
    }
    return 0;
}