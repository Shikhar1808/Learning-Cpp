#include <iostream>
#include <stack>


using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }
};

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

void inorder(Node* root, stack<int> &st){
    if(root == NULL){
        return;
    }
    inorder(root->left, st);
    st.push(root->data);
    inorder(root->right, st);
}

void inorderIterative(Node* root){
    stack<Node*> st;
    Node* curr = root;

    while(curr != NULL || !st.empty()){
        while(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();

        cout<<curr->data<<" ";

        curr = curr->right;
    }
}


int main(){
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);

    stack<int> st;

    inorder(root1, st);

    reverseStack(st);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}