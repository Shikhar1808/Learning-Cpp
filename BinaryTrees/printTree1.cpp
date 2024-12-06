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

int calcualteHeight(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftHeight = calcualteHeight(root->left);
    int rightHeight = calcualteHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}


// For basic tree
void printLevel(Node* root, int level){
    if(root == NULL){
        return;
    }
    if(level == 1){
        cout << root->data << " ";
        return;
    }
    printLevel(root->left, level-1);
    printLevel(root->right, level-1);
}

void printTree(Node* root){
    int height = calcualteHeight(root);
    for(int i = 1; i <= height; i++){
        printLevel(root, i);
        cout << endl;
    }
}

//node search
Node* seachNode(Node* root, int key){
    if(root == NULL){
        return NULL;
    }
    if(root->data == key){
        return root;
    }
    if(key < root->data){
        return seachNode(root->left, key);
    }
    return seachNode(root->right, key);
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

    printTree(root);

    return 0;
}