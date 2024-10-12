#include <iostream>
using namespace std;

//Fastest sorting algorithm
//Time complexity: O(nlogn) in average case
//Space complexity: O(logn) in average case
//Worst case time complexity: O(n^2)
//In place sorting algorithm
//Not stable sorting algorithm

int partition(int arr[], int low, int high){
    int x = arr[high];
    int i = low -1;
    for(int j = low; j<=high-1; j++){
        if(arr[j] < x){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}


int main(){
    int arr[] = {5,7,6,1,3,2,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    quickSort(arr, 0, n-1);
    
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}