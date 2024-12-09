#include <iostream>
#include <stack>
#include <vector>

using namespace std;


void nearestSmallestNumeber(vector<int> arr, int index){
    stack<int> s;
    for(int i= 0; i<index; i++){
        if(arr[i] < arr[index]){
            s.push(arr[i]);
        }
    }
    if(s.empty()){
        cout<<"_";
    }
    else{
        cout<<" "<<s.top();
    }
}

void printNearestSmallestNumeber(vector<int> arr){
    for(int i = 0; i<arr.size(); i++){
        nearestSmallestNumeber(arr, i);
    }
}

//Time Complexity: O(n^2)
//Space Complexity: O(n) because of stack

int main(){
    vector<int> arr = {1,6,4,10,2,5};
    printNearestSmallestNumeber(arr);

    return 0;
}