#include <iostream>
using namespace std;

const int INT_MIN = -10000;
const int INT_MAX = 10000;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

bool isBSTUtil(Node* root, int min, int max){
    if(root == nullptr){
        return true;
    }
    if(root->data < min || root->data > max){
        return false;
    }

    return isBSTUtil(root->left, min , root->data) && isBSTUtil(root->right, root->data, max);
}

bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    if (isBST(root)) {
        cout << "The tree is a BST." << endl;
    } else {
        cout << "The tree is not a BST." << endl;
    }

    return 0;
}
