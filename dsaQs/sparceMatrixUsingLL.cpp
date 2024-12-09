#include <iostream>
using namespace std;

class Node{
    public:
        int row,column,data;
        Node* next;

        Node(int d, int r, int c){
            this->row = r;
            this->column = c;
            this->data = d;
            this->next = NULL;
        }
};

void insertNode(int r, int c, int d, Node*& head){
    Node* newNode = new Node(d,r,c);

    if(head == NULL){
        head = newNode;
        return;
    }
    
    Node* temp = head;
    
    while(temp->next != NULL){
        temp = temp->next;
    }
    
    temp->next = newNode;
}

void displaySparseMatrix(Node* head){
    cout << "Row\tCol\tValue\n";

    Node* temp = head;
    while(temp != NULL){
        cout << temp->row << "\t" << temp->column << "\t" << temp->data << "\n";
        temp = temp->next;
    }
}

Node* addSparseMatrix(Node* head1, Node* head2){
    Node* head3 = NULL;
    Node* temp1 = head1;
    Node* temp2 = head2;

    while(temp1 != NULL && temp2 != NULL){
        if(temp1->row == temp2->row){
            if(temp1->column == temp2->column){
                insertNode(temp1->row, temp1->column, temp1->data + temp2->data, head3);
                temp1 = temp1->next;
                temp2 = temp2->next;
            }else if(temp1->column < temp2->column){
                insertNode(temp1->row, temp1->column, temp1->data, head3);
                temp1 = temp1->next;
            }else{
                insertNode(temp2->row, temp2->column, temp2->data, head3);
                temp2 = temp2->next;
            }
        }else if(temp1->row < temp2->row){
            insertNode(temp1->row, temp1->column, temp1->data, head3);
            temp1 = temp1->next;
        }else{
            insertNode(temp2->row, temp2->column, temp2->data, head3);
            temp2 = temp2->next;
        }
    }

    while(temp1 != NULL){
        insertNode(temp1->row, temp1->column, temp1->data, head3);
        temp1 = temp1->next;
    }

    while(temp2 != NULL){
        insertNode(temp2->row, temp2->column, temp2->data, head3);
        temp2 = temp2->next;
    }

    return head3;
}

int main(){
    
    int matrix1[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    Node* head1 = NULL;

    for(int i =0; i<4; i++){
        for(int j =0; j<5; j++){
            if(matrix1[i][j] != 0){
                insertNode(i,j,matrix1[i][j],head1);
            }
        }
    }

    displaySparseMatrix(head1);

    int matrix2[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    Node* head2 = NULL;

    for(int i =0; i<4; i++){
        for(int j =0; j<5; j++){
            if(matrix2[i][j] != 0){
                insertNode(i,j,matrix2[i][j],head2);
            }
        }
    }

    displaySparseMatrix(head2);

    Node* head3 = NULL;
    head3 = addSparseMatrix(head1, head2);

    displaySparseMatrix(head3);
}