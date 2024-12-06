//Find max and min element in BT

#include <iostream>
#include <climits>
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

int findMax(Node* root){
    if(root == NULL){
        return INT_MIN;
    }
    int res = root->data;
    int lMax = findMax(root->left);
    int rMax = findMax(root->right);
    if(lMax > res){
        res = lMax;
    }
    if(rMax > res){
        res = rMax;
    }
    return res;
}




int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << findMax(root) << endl;
}