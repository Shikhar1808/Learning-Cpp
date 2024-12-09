#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
};

void InsertAtHead(Node* &head, int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void InsertAtTail(Node* &head, int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = NULL;
}

void printLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" <-> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void reverseDLL(Node*& head){
    if(head == NULL || head->next == NULL){
        cout<<"No DLL"<<endl;
        return;
    }

    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL){
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;

        curr = curr->prev;
    }

    if(prev != NULL){
        head = prev->prev;
    }
}

Node* reverseRecursive(Node* curr){
    if(curr == NULL ){
        return NULL;
    }

    Node* temp = curr->prev;
    curr->prev = curr->next;
    curr->next = temp;

    if(curr->prev == NULL){
        return curr;
    }

    return reverseRecursive(curr->prev);
}

void reverseDLLRecursve(Node*& head){
    head = reverseRecursive(head);
} 


int main(){

    Node* node1 = new Node(100);
    Node* head = node1;

    InsertAtTail(head, 200);
    InsertAtTail(head, 300);
    InsertAtTail(head, 400);
    InsertAtTail(head, 500);
    printLL(head);

    // reverseDLL(head);
    reverseDLLRecursve(head);

    printLL(head);


    return 0;
}