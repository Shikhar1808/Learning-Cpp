#include <iostream>
using namespace std;

class Distance {
private:
    int meters;

public:
    // Constructor to convert basic type to user-defined type
    Distance(int m) {
        meters = m;
    }

    void display() {
        cout << "Distance: " << meters << " meters" << endl;
    }
};

int main() {
    int basicValue = 10;

    // Converting int to Distance object
    Distance d = basicValue; // Implicit conversion
    d.display();

    return 0;
}
