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
void InsertAtIndex(Node* &head, int data, int index){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node* temp = head;
    for(int i=0; i<index-1; i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

void DeletionAtHead(Node* &head){
    Node* toDelete = head;
    head = head->next;
    head->prev = NULL;
    delete toDelete;
}
void DeletionAtTail(Node* &head){
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    Node* toDelete = temp->next;
    temp->next = NULL;
    delete toDelete;
}

void DeletionAtIndex(Node* &head, int index){
    Node* temp = head;
    for(int i=0; i<index-1; i++){
        temp = temp->next;
    }
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    temp->next->prev = temp;
    delete toDelete;
}

void printLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" <-> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){

    Node* node1 = new Node(100);
    Node* head = node1;

    InsertAtHead(head, 200);
    InsertAtHead(head, 300);
    InsertAtTail(head, 400);
    InsertAtTail(head, 500);
    InsertAtIndex(head, 600, 2);
    printLL(head);


    return 0;
}