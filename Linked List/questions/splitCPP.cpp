#include <iostream>
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

void InsertAtTail(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}

void printCLL(Node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(head)" << endl;
}

void splitCLL(Node* head, Node** head1, Node** head2) {
    if (head == NULL || head->next == head) { // Empty or single-node list
        *head1 = head;
        *head2 = NULL;
        return;
    }

    Node* slow = head;
    Node* fast = head;

    // Find the midpoint of the circular linked list
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Set the two heads
    *head1 = head;
    *head2 = slow->next;

    // Split the list into two circular lists
    slow->next = *head1;

    Node* temp = *head2;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = *head2;
}

int main() {
    Node* head = NULL;

    // Create a circular linked list
    InsertAtTail(head, 100);
    InsertAtTail(head, 400);
    InsertAtTail(head, 500);
    InsertAtTail(head, 200);
    InsertAtTail(head, 300);

    cout << "Original Circular Linked List: ";
    printCLL(head);

    Node* head1 = NULL;
    Node* head2 = NULL;

    // Split the circular linked list
    splitCLL(head, &head1, &head2);

    cout << "First Circular Linked List: ";
    printCLL(head1);

    cout << "Second Circular Linked List: ";
    printCLL(head2);

    return 0;
}
