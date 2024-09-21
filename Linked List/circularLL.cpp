#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};

void InsertAtHead(Node* &head, int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        newNode->next = newNode;
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}

void InsertAtTail(Node* &head, int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        newNode->next = newNode;
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}

void DeleteAtHead(Node* &head){
    if(head == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    Node* toDelete = head;
    temp->next = head->next;
    head = head->next;
    delete toDelete;
}

void print(Node* head){
    if(head == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    Node* temp = head;
    do{
        cout << temp->data << " -> ";
        temp = temp->next;
    }while(temp != head);
    cout << "(back to head)" << endl;
}


int main(){
    Node* head = NULL;

    InsertAtHead(head, 50);
    InsertAtHead(head, 25);

    InsertAtTail(head, 200);
    InsertAtTail(head, 300);

    print(head);

    return 0;
}
