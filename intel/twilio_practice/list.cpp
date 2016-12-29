#include <iostream>
using namespace std;
struct Node{
    int data;
    struct Node* next;
};

void add(Node**head, int n){

    Node* newNode = new Node();
    newNode->data = n;
    if ( head == NULL )
    {
        *head = newNode;         
    }
    else
    {
        newNode->next = *head;
        *head = newNode;
    }
}
void print(Node *head){
    Node* curr = head;
    while(curr!=NULL){
        cout << curr->data;
        curr = curr->next;
    }
}
//prev->curr->next

//curr->prev

void reverse(Node** head)
{
    Node* curr = *head;
    Node* prev = NULL;
    Node* next = NULL;

    while(curr!= NULL){
        next = curr->next;
        curr ->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}
int main(){

    Node* head = NULL;
    add(&head, 1);
    add(&head, 2);
    print(head);
    reverse(&head);
    print(head);
}