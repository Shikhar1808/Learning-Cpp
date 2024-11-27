#include <iostream>
#include <string>
using namespace std;

class MyException {
public:
    string message;
    MyException(string msg) : message(msg) {}
};

int main() {
    try {
        throw MyException("Custom exception occurred!");
    }
    catch (MyException& e) {
        cout << "Caught custom exception: " << e.message << endl;
    }

    return 0;
}
