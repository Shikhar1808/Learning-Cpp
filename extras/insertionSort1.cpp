#include <iostream>
using namespace std;

void insertionSort(int arr[], int n){
    //here n is the size of the array
    for(int i=1; i<n; i++){
        int current = arr[i];
        int j = i-1;
        while(arr[j] > current && j >= 0){
            //this loop will run until the element at jth index is greater than the current element and j is greater than or equal to 0
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
}

//time complexity of insertion sort is O(n^2) in worst case and O(n) in best case
//space complexity of insertion sort is O(1) because it uses a constant amount of extra space

void insertionSortRecursive(int arr[], int n) {
    if (n <= 1) {
        return;
    }

    insertionSortRecursive(arr, n - 1);

    int last = arr[n - 1];
    int j = n - 2;

    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}
//time complexity of recursive insertion sort is O(n^2) and space complexity is O(n)

int main(){

    int arr[] = {5, 4, 3, 2, 1,8,7,5,1,10};
    int n = sizeof(arr)/sizeof(arr[0]);

    insertionSort(arr, n);
    //insertionSortRecursive(arr, n);

    cout<<"Sorted array: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}