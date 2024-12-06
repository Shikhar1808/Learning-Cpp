//XOR Linked List Operaions

#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* npx; // XOR of next and previous node
};

Node* XOR(Node* a, Node* b){ // XOR of two pointers is a pointer to the XOR of the values

    return (Node*)((uintptr_t)(a) ^ (uintptr_t)(b));

    // uintptr_t is an unsigned integer type that is capable of storing a data pointer.
    //this XOR operation is possible because of the property of XOR operation that if A XOR B = C then C XOR B = A and C XOR A = B
    //So, if we XOR the address of the next node with the address of the previous node, we get the address of the next node.
    //Explanation: Suppose we have two nodes A and B. A is the current node and B is the next node.
    //We have the address of A and B. We XOR the address of A and B and store it in C. Now, we have the address of A and C.
    //If we XOR the address of A and C, we get the address of B.
    //This is how we can traverse the XOR linked list.
}

//Insertion at beginning
Node* insertBeg(Node* head, int data){
    Node* newNode = new Node();
    newNode->data = data;

    newNode->npx = head;

    if(head != NULL){
        head->npx = XOR(newNode, head->npx);
    }

    head = newNode;

    return head;
}

//Insertion at end
Node* insertEnd(Node* head, int data){
    Node* newNode = new Node();
    newNode->data = data;

    if(head == NULL){
        return newNode;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* next;

    while(curr != NULL){
        next = XOR(prev, curr->npx);

        prev = curr;
        curr = next;
    }

    newNode->npx = XOR(prev, NULL); // XOR of previous node and NULL is the next node i.e. newNode->npx = prev XOR NULL = prev
    prev->npx = XOR(newNode, XOR(prev->npx, NULL)); // XOR of prev->npx and newNode is the next node i.e. prev->npx = prev->npx XOR newNode XOR NULL = prev->npx XOR newNode

    return head;
}

//Insertion before a node
Node* insertBefore(Node* head, int data, Node* x){
    if(x == head){
        return insertBeg(head, data);
    }

    Node* newNode = new Node();
    newNode->data = data;

    Node* prev = NULL;
    Node* curr = head;
    Node* next;

    while(curr != x){
        next = XOR(prev, curr->npx);

        prev = curr;
        curr = next;
    }

    newNode->npx = XOR(prev, curr); // XOR of previous node and current node is the next node i.e. newNode->npx = prev XOR curr
    curr->npx = XOR(newNode, XOR(prev, curr->npx)); // XOR of newNode and XOR of prev and curr is the next node i.e. curr->npx = newNode XOR prev XOR curr

    prev->npx = XOR(prev->npx, curr); // XOR of prev->npx and curr is the next node i.e. prev->npx = prev->npx XOR curr

    return head;
}

//Deletion at beginning
Node* deleteBeg(Node* head){
    if(head == NULL){
        return head;
    }

    Node* next = XOR(NULL, head->npx); // XOR of NULL and next node is the previous node i.e. next = NULL XOR head->npx = head->npx

    next->npx = XOR(NULL, XOR(head, next->npx)); // XOR of NULL and XOR of head and next is the next node i.e. next->npx = NULL XOR head XOR next->npx = head XOR next->npx

    head = NULL;

    return next;
}

//Deletion at end
Node* deleteEnd(Node* head){
    if(head == NULL){
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* next;

    while(curr->npx != prev){
        next = XOR(prev, curr->npx);

        prev = curr;
        curr = next;
    }

    prev->npx = XOR(prev->npx, curr); // XOR of prev->npx and curr is the next node i.e. prev->npx = prev->npx XOR curr

    curr = NULL;

    return head;
}

//Deletion before a node
Node* deleteBefore(Node* head, Node* x){
    if(x == head || x->npx == NULL){
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* next;

    while(curr != x){
        next = XOR(prev, curr->npx);

        prev = curr;
        curr = next;
    }

    Node* prevPrev = NULL;
    Node* currPrev = head;
    Node* nextPrev;

    while(currPrev != prev){
        nextPrev = XOR(prevPrev, currPrev->npx);

        prevPrev = currPrev;
        currPrev = nextPrev;
    }

    currPrev->npx = XOR(currPrev->npx, XOR(prev, currPrev)); // XOR of currPrev->npx and XOR of prev and currPrev is the next node i.e. currPrev->npx = currPrev->npx XOR prev XOR currPrev

    prev->npx = XOR(prev->npx, curr); // XOR of prev->npx and curr is the next node i.e. prev->npx = prev->npx XOR curr

    curr = NULL;

    return head;
}

//Traversal
void traverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next;

    while(curr != NULL){
        cout<<curr->data<<" ";

        next = XOR(prev, curr->npx);

        prev = curr;
        curr = next;
    }
}