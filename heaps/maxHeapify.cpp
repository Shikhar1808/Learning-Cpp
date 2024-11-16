#include <iostream>
using namespace std;

//Parent of A[i] == A[(floor(i-1)/2)]
//Number of elements in the heap which are stored within an array A = A.heap-size
//The elements in the subarray A[(n/2)+1....n] are all leaves of the tree

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

Node* createtree1(int arr[], int size, int index){
    if(index >= size){
        return NULL;
    }

    Node* root = new Node(arr[index]);

    root->left = createtree1(arr, size, index*2 + 1);
    root->right = createtree1(arr, size, index*2 + 2);

    return root;
}

void createtree2(Node* root) {
    int data;
    cout << "Enter the data of the left child of " << root->data << ": ";
    cin >> data;
    if (data != -1) {
        root->left = new Node(data);
        createtree2(root->left);
    }

    cout << "Enter the data of the right child of " << root->data << ": ";
    cin >> data;
    if (data != -1) {
        root->right = new Node(data);
        createtree2(root->right);
    }
}

Node* maxHeapify(int arr[], int size, int index){
    if(index >= size){
        return NULL;
    }

    if(index >= size){
        return NULL;
    }

    Node* root = new Node(arr[index]);

    root->left = createtree1(arr, size, index*2 + 1);
    root->right = createtree1(arr, size, index*2 + 2);

    if(root->left != NULL && root->left->data > root->data){
        swap(root->left->data, root->data);
    }

    if(root->right != NULL && root->right->data > root->data){
        swap(root->right->data, root->data);
    }

    return root;

    //This function traces path from root to a leaf.
    //In worst case length of path is h(height of tree).
    //Time complexity of this function is O(h) or O(logh).
}

int main(){

    int noOfNodes;
    cout<<"Enter the number of nodes: ";
    cin>>noOfNodes;

    int arrOfNodes[noOfNodes];

    for(int i = 0; i < noOfNodes; i++){
        cout<<"Enter the data of the node "<<i+1<<": ";
        cin>>arrOfNodes[i];
    }

    //arr = [16,4,10,14,7,9,3,2,8,1]

    // Node* root = createHeap1(arrOfNodes, noOfNodes, 0);

    Node* root = maxHeapify(arrOfNodes, noOfNodes, 0);
    //arr = [16,14,10,8,7,9,3,2,4,1]


    return 0;
}