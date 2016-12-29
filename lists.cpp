#include <iostream>
class Node
{
    int data;
    Node* next;

    public : 
    Node(int d)
    {   
        data = d;
    }

    void appendToTail(int d)
    {
        Node*end = new Node(d);
        Node* x = this;
        while (x->next !=NULL)
        {
            x = x->next;   
        }
        x->next = end;
    }
    void printList()
    {
        Node* x = this;
        while (x!=NULL)
        {
            std::cout << x->data << " ";
            x=x->next;
        }
    }
};

int main()
{
    Node*n = new Node(2);
    n->appendToTail(2);
    n->appendToTail(4);
    n->appendToTail(6);
    n->appendToTail(8);
    n->printList();
}
