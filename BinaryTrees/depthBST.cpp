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

int maxDepth(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return max(leftDepth, rightDepth) + 1;
}

int minDepth(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);

    return min(leftDepth, rightDepth) + 1;
}

Node* insert(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val < root->data){
        root->left = insert(root->left, val);
    }
    else if(val> root->data){
        root->right = insert(root->right, val);
    }

    return root;
}

int main(){

    Node* root = nullptr;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 1);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);
    insert(root, 9);

    cout<<"Max Depth: "<<maxDepth(root)<<endl;
    cout<<"Min Depth: "<<minDepth(root)<<endl;


    return 0;
}