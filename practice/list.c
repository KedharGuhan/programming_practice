#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// implementing link list
typedef struct{
	char* buf;
	int offset;
	int size;
}CharBuffer;

struct List{
	struct List* next;
	CharBuffer* data;
};


typedef struct List Node;
// my buffer aggr ADT is a linked list of buffers
// ordered list can be done later

Node* head = NULL;
CharBuffer* createBuffer(char* str,int size,int offset){
	printf("\n in create buffer");
	CharBuffer* charbuf = (CharBuffer*)malloc(sizeof(CharBuffer));
	(charbuf)->buf = (char*)malloc(sizeof(char)*size);
	strcpy(str,(charbuf)->buf);
	(charbuf)->offset = offset;
	(charbuf)->size = size;
	return charbuf;
}

Node* createNode(){
	printf("\n creating node");
	Node* n = (Node*)malloc(sizeof(Node));
	n->next = NULL;
	return n;
}

void freeCharData(CharBuffer* x){
	printf("\n In Free Char data");
	if(x!=NULL){
		free(x->buf);
		free(x);
	}
}
void freeNode(Node* x){
	printf("\n Freeing Node");
	if(x!=NULL)
	{
		if(x->data!=NULL)
			freeCharData(x->data);
		free(x);
	}
}
/* create the head node*/
Node* createHead(){
	
	printf("\n create Node head");
	Node *head = (Node*)malloc(sizeof(Node));
	(head)->next = NULL;
	printf("\n returning from create Node head");
	return head;
}
/* inserts new buffer to end of list */
Node* insertToList( char* str, int size,int offset){
	printf("\ninserting to list%s",str);
	if(head==NULL){
		printf("\nallocation");
		head = (Node*)malloc(sizeof(Node));
		printf("\nallocation done");
	//	head->next= NULL;
		printf("\ncallin createBuffer");
		(head)->data =(CharBuffer*)malloc(sizeof(CharBuffer));
		(head)->data->offset = offset;
		(head)->data->size = size;
		(head)->data->buf = (char*)malloc(sizeof(char)*size);
		strcpy(str,(head)->data->buf); 
		printf("value in the buffer is%s",(head)->data->buf);
		printf("returning from insert to list");
		return head;
	}
	Node* x= head;
	/* go to the last node*/
	while(x!=NULL)
		x=x->next;
	/* create a new Node*/
	Node* newNode = createNode();
	 newNode->data=createBuffer(str, size,offset);
	/* make the last node point to the newly created node*/
	x->next = newNode;
	return head;
}

/* returns the position if the offset already exists */
/*int findOffset(Node* head,int offset){
	
	Node* p = head;
	int i =0;
	while(p!=NULL){
		if(p->data->offset == offset)
			break;
		i++;
		p=p->next;
	}
	return i;
}
*/
/*
void removeFromList(Node* head, int offset){
	//int location = findOffset(head, offset);
	Node* p = head;
	int i =0;
	while(p->next->offset!=offset) {
		p= p->next;
	}
	Node* q = p;
	p->next = p->next->next;
	freeNode(q);
}
*/
void printCharBuffer(CharBuffer *ptr){
	printf("%s,%d,%d",ptr->buf,ptr->offset, ptr->size);
}
void printAggr(Node* aggr){
	
	Node* ptr = aggr;
	while(ptr!=NULL){
		printCharBuffer(ptr->data);
		ptr = ptr->next;	
	}
}

void freeList(Node* head){
	printf("\nIn freeing List");
	Node* p = head;
	while(p!=NULL){
		head = p;
		freeNode(head);
		p = p->next;
	}
}

main(){
	char *p = "harsh";
	head = insertToList(p, 5, 0);
	//printAggr(aggr1);
	freeList(head);
}
