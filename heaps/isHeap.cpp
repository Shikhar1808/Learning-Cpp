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

int countNodes(Node* root){
    if(root == NULL){
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool isComplete(Node* root, int index, int size){
    if(root == nullptr){
        return true;
    }
    if(index>size){
        return false;
    }

    return isComplete(root->left, 2*index+1, size) && isComplete(root->right, 2*index+2, size);
}

bool isHeapUtil(Node* root){
    if(root->left == nullptr && root->right == nullptr){
        return true;
    }
    if(root->right == nullptr){
        return root->data >= root->left->data;
    }

    if(root->data >= root->left->data && root->data >= root->right->data){
        return isHeapUtil(root->left) && isHeapUtil(root->right);
    }
    return false;
}

bool isHeap(Node* root){
    int size = countNodes(root);

    if(isComplete(root,0,size) && isHeapUtil(root)){
        return true;
    }
    return false;
}

bool isHeapArr(int arr[], int index, int size){
    if(index >= (size-1)/2){ //leaf node condition
        return true;
    }

    return (arr[index]>= arr[index*2+1]) && (arr[index] >= arr[index*2+2]) && isHeapArr(arr,2*index+1,size) && isHeapArr(arr,2*index+2,size);
}

int main(){
    int arr[] = {10,9,8,7,6,5,4};
    int size = sizeof(arr)/sizeof(arr[0]);

    Node* root = new Node(arr[0]);

    root->left = new Node(arr[1]);
    root->right = new Node(arr[2]);

    root->left->left = new Node(arr[3]);
    root->left->right = new Node(arr[4]);

    root->right->left = new Node(arr[5]);
    root->right->right = new Node(arr[6]);

    // if(isHeap(root)){
    //     cout<<"Is Heap"<<endl;
    // }
    // else{
    //     cout<<"Not Heap"<<endl;
    // }

    if(isHeapArr(arr, 0, size)){
        cout<<"Is Heap"<<endl;
    }
    else{
        cout<<"Not Heap"<<endl;
    }

    return 0;
}