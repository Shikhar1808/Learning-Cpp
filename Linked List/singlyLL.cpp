#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;//next is a pointer to the next node

        Node(int data){
            this->data = data; //this line means the data of the object that is being created will be equal to the data that is passed in the constructor
            this->next = NULL; //this line means the next of the object that is being created will be equal to NULL
        }
};

void InsertAtHead(Node* &head, int data){
    //create a new node
    Node* newNode = new Node(data);
    //check if the linked list is empty
    if(head == NULL){//here we are checking NULL at head's address
        head = newNode;
        return;
    }
    newNode->next = head; //this line means that the next of the new node will be the head's address
    head = newNode;//this line means that the head will be equal to the new node. 
    //So, the new node will be the head of the linked list
    //How it works: the next of the new node will be the head and the head will be the new node. Basically,the address of the head will be the next of the new node and the new node will be the head
}

void InsertAtTail(Node* &head, int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node* temp = head; //temp is a pointer to the head
    while(temp->next != NULL){ //this line means that the loop will run until the next of the temp's node is not NULL
        temp = temp-> next; //this line means that the temp will be equal to the next of the temp's node
    }
    temp->next = newNode; //this line means that the next of the temp's node will be the new node
}

void InsertAtMiddle(Node* &head, int data, int index){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node* temp = head;
    for(int i=0; i<index-1; i++){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void DeletionAtIndex(Node* &head, int index){
    Node* temp = head;
    for(int i=0; i<index-1; i++){
        temp = temp->next;
    }
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

void DeletionAtHead(Node* &head){
    Node* toDelete = head;
    head = head->next;
    delete toDelete;
}

void DeleteAtTail(Node* &head){
    Node* temp = head;
    while(temp->next->next != NULL){ //we used temp->next->next because we want to access the second last node. With the second last node, we can delete the last node
        temp = temp->next;
    }
    Node* toDelete = temp->next;
    temp->next = NULL;
    delete toDelete;
}

void pirntLL(Node* head){
    Node* temp = head;
    while(temp != NULL){ //temp != NULL means that the loop will run until the temp's next is not NULL
        cout<<temp->data<<"->";
        temp = temp->next; //this line means that the temp will be equal to the next of the temp's node
    }
    cout<<"NULL"<<endl;
}

int main(){

    Node* node1 = new Node(100);
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;

    Node* head = node1; //head is a pointer to the first node
    InsertAtHead(head, 200);
    InsertAtHead(head, 300);
    InsertAtTail(head, 400);
    InsertAtTail(head, 500);
    InsertAtMiddle(head, 600, 2);
    pirntLL(head);
    return 0;
}