#include <iostream>
using namespace std;

//general template function
template <typename T>
void display(T value){
    cout<<"Genertic display: "<<value<<endl;
}

//specialized template for char
template<>
void display<char>(char value){
    cout << "Specialized Display for char (ASCII): " << static_cast<int>(value) << endl;
}


// General template for Container class
template <typename T>
class Container {
    T data;

public:
    Container(T value) : data(value) {}
    void display() { cout << "Generic Container: " << data << endl; }
};

// Specialized template for strings
template <>
class Container<string> {
    string data;

public:
    Container(string value) : data(value) {}
    void display() { cout << "String Container: \"" << data << "\"" << endl; }
};


int main() {
    display(42);      // Calls generic template
    display(3.14);    // Calls generic template
    display('A');     // Calls specialized template

    Container<int> intContainer(42);      // Generic container
    Container<double> doubleContainer(3.14);  // Generic container
    Container<string> stringContainer("Hello!");  // Specialized container

    intContainer.display();
    doubleContainer.display();
    stringContainer.display();

    return 0;
}