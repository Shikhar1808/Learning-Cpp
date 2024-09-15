#include<iostream>
using namespace std;

class Base {
    protected:
    //protected members are accessible in derived class
    //protected members are not accessible in main function
    //protected members are accessible in derived class objects
        int protected_var;
    public:
        int public_var;

        void setVars(int a, int b) {
            protected_var = a;
            public_var = b;
        }

        void showVars() {
            cout << "Protected var: " << protected_var << endl;
            cout << "Public var: " << public_var << endl;
        }
};

// Derived class with public inheritance
class DerivedPublic : public Base {
    public:
        void display() {
            cout << "Accessing protected var: " << protected_var << endl;  // Can access protected var
            cout << "Accessing public var: " << public_var << endl;        // Can access public var
        }
};

int main() {
    DerivedPublic obj;
    obj.setVars(10, 20);
    obj.display();

    return 0;
}
