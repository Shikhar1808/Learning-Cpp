#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

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

void printLL(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void listUnion(Node* head1, Node* head2){
    //Time complexity: O(n)
    //Space complexity: O(n)
    Node* temp1 = head1;
    Node* temp2 = head2;

    Node* resultHead = new Node(0);

    vector<int> v = {0};

    while(temp1 != NULL){
        v[temp1->data] = 1;
        // cout<<temp1->data<<endl;
        InsertAtTail(resultHead, temp1->data);
        temp1 = temp1->next;
    }
    while(temp2 != NULL){
        if(v[temp2->data] == 1){
            temp2 = temp2->next;
        }
        else{
            v[temp2->data] = 1;
            // cout<<temp2->data<<endl;
            InsertAtTail(resultHead, temp2->data);
            temp2 = temp2->next;
        }
    }

    cout<<"Union of the two lists is: "<<endl;
    printLL(resultHead);
}

void listIntersection(Node* head1, Node* head2){
    //Time complexity: O(n)
    //Space complexity: O(n)
    Node* temp1 = head1;
    Node* temp2 = head2;

    Node* resultHead = NULL;

    vector<int> visited = {0};

    while(temp1 != NULL){
        visited[temp1->data] = 1;
        // cout<<temp1->data<<endl;
        // InsertAtTail(resultHead, temp1->data);
        temp1 = temp1->next;
    }
    while(temp2 != NULL){
        if(visited[temp2->data] == 1){
            // cout<<temp2->data<<endl;
            InsertAtTail(resultHead, temp2->data);
            temp2 = temp2->next;
        }
        else{
            visited[temp2->data] = 1;
            temp2 = temp2->next;
        }
    }

    cout<<"Intersection of the two lists is: "<<endl;
    printLL(resultHead);
}

int main(){
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);

    Node* head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);
    head2->next->next->next = new Node(8);

    printLL(head1);
    printLL(head2);

    // listUnion(head1, head2);
    listIntersection(head1, head2);
}