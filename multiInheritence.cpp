#include<iostream>
using namespace std;

// Base class (Level 1)
class Device {
    protected:
        string brand;
    public:
        // Constructor
        Device(string b) : brand(b) {
            cout << "Device constructor called for " << brand << endl;
        }

        // Virtual Destructor
        virtual ~Device() {
            cout << "Device destructor called for " << brand << endl;
        }

        // A virtual method to be overridden
        virtual void start() {
            cout << brand << " Device is starting." << endl;
        }
        //virtual keyword is used to make the function to be overridden in derived class.
        //If want to overide the function in derived class because the function is used in base class and we want to change the functionality of the function in derived class then we use virtual keyword.
};

// Derived class (Level 2)
class Computer : public Device {
    protected:
        string processor;
    public:
        // Constructor
        Computer(string b, string p) : Device(b), processor(p) {
            cout << "Computer constructor called for " << brand << " with processor " << processor << endl;
        }

        // Destructor
        ~Computer() {
            cout << "Computer destructor called for " << brand << endl;
        }

        // Overriding start method
        void start() override {
            cout << brand << " Computer with " << processor << " processor is booting up." << endl;
        }
};

// Further derived class (Level 3)
class Laptop : public Computer {
    private:
        int batteryLife;
    public:
        // Constructor
        Laptop(string b, string p, int battery) : Computer(b, p), batteryLife(battery) {
            cout << "Laptop constructor called for " << brand << " with battery life " << batteryLife << " hours" << endl;
        }

        // Destructor
        ~Laptop() {
            cout << "Laptop destructor called for " << brand << endl;
        }

        // Overriding start method
        void start() override {
            cout << brand << " Laptop with " << processor << " processor and " 
                 << batteryLife << " hours of battery life is starting." << endl;
        }

        // Additional method for Laptop
        void showSpecs() {
            cout << "Brand: " << brand << ", Processor: " << processor 
                 << ", Battery Life: " << batteryLife << " hours." << endl;
        }
};

int main() {
    // Creating an object of the most derived class
    Laptop myLaptop("Dell", "Intel i7", 10);

    // Accessing overridden and additional methods
    myLaptop.start();     // Calls the overridden start method from Laptop
    myLaptop.showSpecs(); // Calls the additional method from Laptop

    // Object gets destroyed here, and destructors are called
    return 0;
}
