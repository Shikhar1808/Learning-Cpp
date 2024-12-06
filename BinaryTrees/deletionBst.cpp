//Deletion in BST

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

Node* insert(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val < root->data){
        root->left = insert(root->left, val);
    }
    else if(val> root->data){
        root->right = insert(root->right, val);
    }

    return root;
}

//Inorder Successor
Node* inorderSucc(Node* root){
    Node* curr = root->right;
    while(curr && curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}

//Inorder Predecessor
Node* inorderPred(Node* root){
    Node* curr = root->left;
    while(curr && curr->right != NULL){
        curr = curr->right;
    }
    return curr;
}

//Deletion in BST
Node* deletion(Node* root, int key){
    if(root == NULL){
        return root;
    }
    if(key < root->data){
        root->left = deletion(root->left, key);
    }
    else if(key > root->data){
        root->right = deletion(root->right, key);
    }
    else{
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else{
            Node* temp = inorderSucc(root);//Inorder Successor
            // Node* temp = inorderPred(root);//Inorder Predecessor
            root->data = temp->data;
            root->right = deletion(root->right, temp->data);
        }
    }
    return root;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){

    Node* root = nullptr;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 1);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);

    inorder(root);
    cout<<endl;

    root = deletion(root, 5);
    inorder(root);

    return 0;
}