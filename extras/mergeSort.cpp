//merge sort

#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right){
    int leftSize = mid-left+1;
    int rightSize = right-mid;

    int leftArr[leftSize], rightArr[rightSize];

    for(int i=0; i<leftSize; i++){
        leftArr[i] = arr[left+i];
    }
    for(int i=0; i<rightSize; i++){
        rightArr[i] = arr[mid+1+i];
    }

    int i =0, j =0, k=left;

    while(i<leftSize && i<rightSize){
        if(leftArr[i] <= rightArr[j]){
            arr[k] = leftArr[i];
            i++;
        }
        else{
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while(i<leftSize){
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while(j<rightSize){
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right){
    if(left<right){
        int mid = left+(right-left)/2;

        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);

        merge(arr,left,mid,right);
    }
}

//Time Complexity: O(nlogn)
//Space Complexity: O(n)

int main(){
    int arr[] = {5,7,6,1,3,2,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    mergeSort(arr, 0, n-1);
    
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}