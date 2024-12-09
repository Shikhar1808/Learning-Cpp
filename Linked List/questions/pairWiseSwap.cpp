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

void pirntLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void pairWiseSwapData(Node*& head){
    //Time Complexity: O(n) because we are traversing the linked list
    //Space Complexity: O(1) because we are not using any extra space

    Node* curr = head;

    while(curr->next != NULL && curr != NULL){
        int currData = curr->data;

        if(curr->next == NULL){
            break;
        }
        curr->data = curr->next->data;
        curr->next->data = currData;
        curr = curr->next->next;
    }
} 

void pairWiseSwapNode(Node*& head){
    //Time Complexity: O(n) because we are traversing the linked list
    //Space Complexity: O(1) because we are not using any extra space

    if(head == NULL || head->next == NULL){
        return;
    }

    Node* prevNode = NULL;
    Node* currNode = head;
    Node* nextNode = NULL;

    while(currNode != NULL && currNode->next != NULL){
        nextNode = currNode->next;
        currNode->next = nextNode->next;
        nextNode->next = currNode;

        if(prevNode == NULL){
            head = nextNode;
        }
        else{
            prevNode->next = nextNode;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
}


int main(){

    Node* node1 = new Node(100);
    Node* head = node1; //head is a pointer to the first node
    InsertAtTail(head, 200);
    InsertAtTail(head, 300);
    InsertAtTail(head, 400);
    InsertAtTail(head, 500);
    
    pirntLL(head);

    // pairWiseSwapData(head);
    pairWiseSwapNode(head);

    pirntLL(head);

    return 0;
}