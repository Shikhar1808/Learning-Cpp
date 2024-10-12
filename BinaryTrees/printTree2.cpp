#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void createTree(Node* root) {
    int data;
    cout << "Enter the data of the left child of " << root->data << ": ";
    cin >> data;
    if (data != -1) {
        root->left = new Node(data);
        createTree(root->left);
    }

    cout << "Enter the data of the right child of " << root->data << ": ";
    cin >> data;
    if (data != -1) {
        root->right = new Node(data);
        createTree(root->right);
    }
}

void printTree(Node* root, int space = 0, int height = 5) {
    if (root == NULL){
        return;
    } 
    
    space += height;
    printTree(root->right, space);
    cout << endl;

    for (int i = height; i < space; i++) cout << " "; 
    cout << root->data << "\n";

    printTree(root->left, space);
}

int main() {
    int rootData;
    cout << "Enter the root node data: ";
    cin >> rootData;

    Node* root = new Node(rootData);

    createTree(root);

    cout << "The binary tree in structured form:\n";
    printTree(root);

    return 0;
}
