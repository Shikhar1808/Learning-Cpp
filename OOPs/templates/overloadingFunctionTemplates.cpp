#include <iostream>
using namespace std;

template <typename T>
void display(T value) {
    cout << "Generic value: " << value << endl;
}

void display(int value) {
    cout << "Specialized for int: " << value << endl;
}

int main() {
    display(10);       // Calls overloaded function for int
    display(10.5);     // Calls generic template
    display("Hello");  // Calls generic template

    return 0;
}
