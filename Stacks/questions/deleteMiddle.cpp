#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

void insertAtBottom(stack<int>& st, int element) {
    if (st.empty()) {
        st.push(element);
        return;
    }

    int topElement = st.top();
    st.pop();
    insertAtBottom(st, element);

    st.push(topElement);
}

void reverseStack(stack<int>& st) {
    if (st.empty()) {
        return;
    }

    int topElement = st.top();
    st.pop();
    reverseStack(st);

    insertAtBottom(st, topElement);
}

void deleteMiddleStack(stack<int>& st, int current, int middle, int size){
    if(st.empty() || current == size){
        return;
    }
    if(current == middle){
        st.pop();
        // return;
    }

    int topElement = st.top();
    st.pop();

    deleteMiddleStack(st, current+1, middle, size);

    st.push(topElement);
}

void deleteMiddle(stack<int>& st){
    int size = st.size();
    int middle = (size+1)/2;

    deleteMiddleStack(st,1,middle,size);
    
    reverseStack(st);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

//Time Complexity: O(N) because we are traversing through the stack twice 
//Space Complexity: O(N) because we are using a stack to store the elements


int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    deleteMiddle(st);
}