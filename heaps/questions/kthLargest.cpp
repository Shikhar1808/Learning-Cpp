//output kth largest hap nodes in an array

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

int countNodes(Node* root){
    if(root == NULL){
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

void createHeapArr(vector<int>& heapArr, Node* root, int index, int size){
    if(root == NULL || index >= size){
        return;
    }

    heapArr[index] = root->data;
    createHeapArr(heapArr, root->left, 2*index+1, size);
    createHeapArr(heapArr, root->right, 2*index+2, size);
}

void printHeapArr(vector<int>& heapArr, int size){
    for(int i = 0; i < size; i++){
        cout << heapArr[i] << " ";
    }
    cout << endl;
}
void maxHeapify(vector<int>& vectorArr, int index, int size){
    int largest = index;
    int left = index*2+1;
    int right = index*2+2;

    if(left<size && vectorArr[left] > vectorArr[largest]){
        largest = left;
    }
    if(right<size && vectorArr[right] > vectorArr[largest]){
        largest = right;
    }

    if(largest != index){
        swap(vectorArr[largest], vectorArr[index]);
        maxHeapify(vectorArr, largest, size);
    }
    
}

void printKthMaxNodes(vector<int>& vectorArr, int k, int size){
    for(int i = size/2 - 1; i >= 0; i--){
        maxHeapify(vectorArr, i, size); //Build the max-heap
    }

    for(int i =0; i<k; i++){
        cout<<vectorArr[i]<<" ";
    }
    cout<<endl;
}


int main(){
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);

    int size = countNodes(root);
    cout << "Size: " << size << endl;
    vector<int> heapArr(size-1);

    createHeapArr(heapArr, root, 0, size);
    printHeapArr(heapArr, size);

    printKthMaxNodes(heapArr, 3, size);
}