#include <iostream>
using namespace std;

void bubbleSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                swap(A[j], A[j + 1]);
                swapped = true;
            }
        }
        
        if (!swapped) break;
        
            cout << "Pass " << i + 1 << ": ";
            for (int k = 0; k < n; k++) {
            cout << A[k] << " ";
        }
        cout << endl;
    }
}
//time complexity of bubble sort is O(n^2) and space complexity is O(1)

void bubbleSortRecursive(int A[], int n) {
    if (n == 1) {
        return;
    }

    bool swapped = false;
    for (int i = 0; i < n - 1; i++) {
        if (A[i] > A[i + 1]) {
            swap(A[i], A[i + 1]);
            swapped = true;
        }
    }

    cout << "Pass for n=" << n << ": ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    if (!swapped) {
        return;
    }
    bubbleSortRecursive(A, n - 1);
}
//time complexity of recursive bubble sort is O(n^2) and space complexity is O(n)

int main() {
    int A[] = {77, 33, 44, 11, 88, 22, 66, 55};
    int n = sizeof(A) / sizeof(A[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl << endl;

    bubbleSort(A, n);
    //bubbleSortRecursive(A, n);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
