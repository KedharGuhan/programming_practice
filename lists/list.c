#include<stdio.h>
#include<stdlib.h>
struct Node{
	struct Node* next;
	int data;
};
typedef struct Node List;

List* createNode(){
	int num;
	List* newList;
	newList = (List*)malloc(sizeof(List));
	newList->next = NULL;
	printf("enter the num");
	scanf("%d",&num);
	newList->data = num;
}

List* createList(List* head, int num){
	int i =0;
	List* ptr = head;
	for(;i<num;i++)
	{	if(head == NULL ){
			head = createNode();
			ptr = head;
		}
		else{
			ptr->next = createNode();
			ptr= ptr->next;
		}
	}
	return head;
}		

void freeList(List* head){
	List* p = head;
	while(p!=NULL){
		head = head->next;
		free(p);
		p = head;
	}
}

void printList(List* head){
	List* ptr = head;
	printf("\n");
	while(ptr!=NULL){
		printf("%d\t",ptr->data);
		ptr= ptr->next;
	}
}
List*  mergeList(List* L, List* F){
	List* M;
	List*ptr;
	if(L->data<F->data){	M = L; L = L->next; }
	else {	M = F; F= F->next;}
	ptr = M;
	while(L && F ){
		printf(" in while loop");
		if(L->data< F->data){
			M->next = L;
			L = L->next;
		}
		else{
			M->next = F;
			F = F->next;
		}
		printf("\n%d",M->data);
		M = M->next;
	}
	if(L){
		M->next = L;
	}
	if(F)	
		M->next = F;
	return ptr;
}
void main(){
	List* L = createList(NULL, 3);
	List* F = createList(NULL,3);
	printList(L);
	printList(F);
	List* M = mergeList(L,F);
	printList(M);
	freeList(M);
 
}
