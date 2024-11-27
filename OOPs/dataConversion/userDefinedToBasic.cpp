#include <iostream>
using namespace std;

class Distance {
private:
    int meters;

public:
    Distance(int m) : meters(m) {}

    // Overloaded type-cast operator to convert user-defined to basic type
    operator int() const {
        return meters;
    }
};

int main() {
    Distance d(15);

    // Converting Distance object to int
    int basicValue = d; // Implicit conversion
    cout << "Basic value: " << basicValue << " meters" << endl;

    return 0;
}
