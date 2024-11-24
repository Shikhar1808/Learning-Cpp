#include <iostream>
#include <vector>
using namespace std;


void printArray(vector<int> arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void heapify(vector<int>& arr, int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }

    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }

}

void heapSort(vector<int>& arr, int n){
    for(int i = n/2 - 1; i >= 0; i--){
        heapify(arr,n,i); //Build the max-heap
    }

    for(int i = n-1; i > 0; i--){ //Reversing the max-heap
        swap(arr[0],arr[i]); //Move the current root to the end
        heapify(arr,i,0);
    }
}

int main(){

    vector<int> arr = {4,10,3,5,1};
    int n = arr.size();
    printArray(arr);

    heapSort(arr,n);

    cout<<"Sorted array is: ";
    printArray(arr);


    return 0;
}