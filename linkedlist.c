#include <stdio.h>
#include <stdlib.h>
struct List{
    struct List* next;
    int data;
};

typedef struct List List;
List* createNode()
{
   static curr = 1;
   List *l = (List*)malloc(sizeof(List));
   l->next = NULL;
   l->data = curr++;
   return l;
}
void createList(List** headRef, int num)
{
    int i =0;
    for ( i =0; i< num; i++){
        List* l = createNode();
        l->next = *headRef;
        *headRef = l;       
    }
}
void printList(List* head)
{
    List * L = head;
    while (L!=NULL)
    {   
        printf("%d ",L->data);
        L=L->next;
    }

}
int main()
{
    List* head= NULL;
    createList(&head, 5);   
    printList(head);    
}
