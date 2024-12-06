//Check if the binary tree is a sum tree or not

#include <iostream>
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

int sum(Node* root){
    if(root == NULL){
        return 0;
    }
    return sum(root->left) + root->data + sum(root->right);
}

bool isSumTree(Node* root){
    if(root == NULL){
        return true;
    }
    if(root->left == NULL && root->right == NULL){
        return true;
    }

    int lSum = sum(root->left);
    int rSum = sum(root->right);

    if(root->data == lSum + rSum && isSumTree(root->left) && isSumTree(root->right)){
        return true;
    }

    
}



int main(){
    Node* root = new Node(26);
    root->left = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(3);

    if(isSumTree(root)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }

    return 0;
}