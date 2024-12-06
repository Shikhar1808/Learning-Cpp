//write a program to calculate the size of a binary tree(gfg easy)

#include <iostream>
#include <vector>
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

int getSize(Node* root){
    if(root == NULL){
        return 0;
    }
    return 1 + getSize(root->left) + getSize(root->right);
}

    

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << getSize(root) << endl;
}