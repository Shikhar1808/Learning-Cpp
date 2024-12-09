//Given the array arr[] of heights of certain buildings that lie adjacent to each other, 
//Sunlight starts falling from the left side of the buildings. 
//If there is a building of a certain height, all the buildings to the right side of it having lesser heights cannot see the sun. 
//The task is to find the total number of buildings that receive sunlight.

// Input: arr[] = [6, 2, 8, 4, 11, 13]
// Output: 4
// Explanation: Only buildings of height 6, 8, 11 and 13 can see the sun, hence output is 4.

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void buildingFacingSun(vector<int> arr){
    stack<int> s;
    
    int tallBuilding = arr[0];
    s.push(tallBuilding);

    for(auto it: arr){
        if(it > tallBuilding){
            s.push(it);
            tallBuilding = it;
        }
    }

    //reversing the stack
    stack<int> s1;
    while(!s.empty()){
        s1.push(s.top());
        s.pop();
    }


    while(!s1.empty()){
        cout<<s1.top()<<" ";
        s1.pop();
    }
}


int main(){
    vector<int> arr = {6,2,8,4,11,13};
    buildingFacingSun(arr);
}