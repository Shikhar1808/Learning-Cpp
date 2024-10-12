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

Node* createTree(int arr[], int size, int index){
    
    if(index >= size){
        return NULL;
    }

    Node* root = new Node(arr[index]);

    root->left = createTree(arr, size, index*2 +1);
    root->right = createTree(arr, size, index*2 +2);

    return root;
}

void preOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main(){
    int noOfNodes;
    cout << "Enter the number of nodes: ";
    cin >> noOfNodes;

    int arrOfNodes[noOfNodes];

    for(int i = 0; i < noOfNodes; i++){
        cout << "Enter the data of the node " << i+1 << ": ";
        cin >> arrOfNodes[i];
    }

    Node* root = createTree(arrOfNodes, noOfNodes, 0);

    preOrderTraversal(root);
    cout << endl;

    return 0;
}