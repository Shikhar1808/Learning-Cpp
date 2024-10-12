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

void createTree(Node* root){
    int data;
    cout << "Enter the data of the left child of " << root->data << ": ";
    cin >> data;
    if(data != -1){
        root->left = new Node(data);
        createTree(root->left);
    }

    cout << "Enter the data of the right child of " << root->data << ": ";
    cin >> data;
    if(data != -1){
        root->right = new Node(data);
        createTree(root->right);
    }
}

void preOrderTraversal(Node* root){
    if(root == NULL){ //this means that this is a leaf node. It checks the NULL in the left or right of the leaf node
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main(){
    Node* root = new Node(1);
    createTree(root);
    preOrderTraversal(root);
    cout << endl;
    return 0;

}