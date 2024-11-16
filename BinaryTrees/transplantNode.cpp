#include<iostream>
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

int transplantNode(Node* root, int oldNode, int newNode){
    if(root == NULL){
        return -1;
    }
    else{
        if(root->data == oldNode){
            root->data = newNode;
            cout<<"OldNode "<<oldNode<<" is replaced by "<<newNode<<endl;
            return root->data;
        }
        else{
            int left = transplantNode(root->left, oldNode, newNode);
            int right = transplantNode(root->right, oldNode, newNode);
        }
    }
}

Node* createTree(int arr[], int size, int index){
    
    if(index >= size){
        return NULL;
    }

    Node* root = new Node(arr[index]);

    root->left = createTree(arr, size, index*2 +1);
    root->right = createTree(arr, size, index*2 +2);

    return root;
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


    int ans = transplantNode(root, 3, 11);
    printTree(root);
    cout << ans << endl;

    return 0;
}
