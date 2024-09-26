#include <iostream>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

//time complexity of selection sort is O(n^2) in all cases
//space complexity of selection sort is O(1) because it uses a constant amount of extra space

int main(){

    int arr[] = {5, 4, 3, 2, 1,8,7,5,1,10};

    return 0;
}