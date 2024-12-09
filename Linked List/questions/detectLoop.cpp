#include <iostream>
#include <vector>
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

void pirntLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void detectLoop(Node* head){
    vector<int> visitedData = {0};

    Node* temp = head;
    bool isLoop = false;
    int count = 0;
    while(temp!=NULL){
        int data = temp->data;
        if(visitedData[data] == 1){
            cout<<"Loop detected"<<endl;
            count++;
            isLoop = true;
            Node* temp2 = temp->next;
            while(temp2->data != data){
                cout<<temp2->data<<"->";
                temp2 = temp2->next;
                count++;
            }
            cout<<"Loop starts at "<<temp->data<<endl;
            cout<<"Loop length is "<<count<<endl;
            break;
            // return;
        }
        visitedData[temp->data] = 1;
        temp = temp->next;
    }
    if(!isLoop){
        cout<<"No loop detected"<<endl;
        cout<<"Loop length is "<<count<<endl;
    }
}

int main(){

    Node* node1 = new Node(100);
    Node* head = node1; //head is a pointer to the first node
    head->next = new Node(200);
    head->next->next = new Node(300);
    head->next->next->next = new Node(400);
    head->next->next->next->next = new Node(500);
    head->next->next->next->next->next = head->next;
    
    // pirntLL(head);

    // pairWiseSwapData(head);
    // pairWiseSwapNode(head);

    detectLoop(head);

    return 0;
}