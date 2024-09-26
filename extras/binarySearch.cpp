#include <iostream>
using namespace std;

int binarySearch(int A[], int low, int high, int key) {
    if (low > high) {
        return -1;  
    }

    int mid = low + (high - low) / 2;

    if (A[mid] == key) {
        return mid; 
    } 
    else if (A[mid] > key) {
        return binarySearch(A, low, mid - 1, key);
    } 
    else {
        return binarySearch(A, mid + 1, high, key);
    }
}

//time complexity of binary search is O(logn)
//space complexity of binary search is O(logn) because of recursion stack

int main() {
    int A[] = {2, 5, 6, 7, 8, 9, 10, 15, 16, 18, 19, 20};
    int n = sizeof(A) / sizeof(A[0]);

    int key = 8;

    int result = binarySearch(A, 0, n - 1, key);

    if (result != -1) {
        cout << "Key " << key << " found at index " << result << endl;
    } 
    else {
        cout << "Key " << key << " not found in the array." << endl;
    }

    return 0;
}
