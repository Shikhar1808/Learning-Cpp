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

bool isSibling(Node* root, int a, int b){
    if(root == NULL){
        return false;
    }
    if(root->left == NULL || root->right == NULL){
        return false;
    }
    if((root->left->data == a && root->right->data == b) || (root->left->data == b && root->right->data == a)){
        return true;
    }
    return isSibling(root->left, a, b) || isSibling(root->right, a, b);
}

int level(Node* root, int a, int l){
    if(root == NULL){
        return 0;
    }
    if(root->data == a){
        return l;
    }

    int left = level(root->left, a, l+1);
    if(left != 0){
        return left;
    }
    
    return level(root->right, a, l+1);
}

bool isCousins(Node*root , int a, int b){
    if(a == b){
        return false;
    }

    int levelA = level(root, a, 1);
    int levelB = level(root, b, 1);

    if(levelA == 0 || levelB == 0){
        return false;
    }
    if(levelA == levelB && !isSibling(root, a, b)){
        return true;
    }
    return false;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int a = 4;
    int b = 3;

    if(isCousins(root, a, b)){
        cout << "Cousins" << endl;
    }
    else{
        cout << "Not Cousins" << endl;
    }
}