//Inorder Traversing in BST

#include <iostream>
#include <stack>
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

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

//Iterative Inorder Traversal
void inorderIterative(Node* root){
    stack<Node*> st;
    Node* curr = root;
    while(curr != NULL || !st.empty()){
        while(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

//Inorder Successor
Node* inorderSucc(Node* root){
    Node* curr = root->right;
    while(curr && curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}

//Recursive inorder Successor
Node* inorderSuccRec(Node* root, Node* target){
    if(target->right != NULL){
        return inorderSucc(target);
    }
    Node* succ = NULL;
    while(root != NULL){
        if(target->data < root->data){
            succ = root;
            root = root->left;
        }
        else if(target->data > root->data){
            root = root->right;
        }
        else{
            break;
        }
    }
    return succ;
}

//Inorder Predecessor
Node* inorderPred(Node* root){
    Node* curr = root->left;
    while(curr && curr->right != NULL){
        curr = curr->right;
    }
    return curr;
}

//Recursive inorder Predecessor
Node* inorderPredRec(Node* root, Node* target){
    if(target->left != NULL){
        return inorderPred(target);
    }
    Node* pred = NULL;
    while(root != NULL){
        if(target->data < root->data){
            root = root->left;
        }
        else if(target->data > root->data){
            pred = root;
            root = root->right;
        }
        else{
            break;
        }
    }
    return pred;
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