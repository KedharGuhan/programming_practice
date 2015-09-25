#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
	char* b;
	int offset;
	int size;
}CharBuffer;

typedef struct{
	CharBuffer *map;
	int index;
}BuffAggr;


CharBuffer* createBuffer(const char *b_, int offset_, int size_){
	
	CharBuffer* cb = (CharBuffer*)malloc(sizeof(CharBuffer));
	cb->b = (char*)malloc(sizeof(char)*size_);
	strcpy(cb->b, b_);
	cb->offset= offset_;
	cb->size = size_;
	return cb;
}

void printOffset(CharBuffer* c){
	printf("offset:%d",c->offset);
	printf("size:%d", c->size);
	printf("buffer:%s",c->b);
}

BuffAggr* initBufMap(int k){
	BuffAggr*  aggr = (BuffAggr*)malloc(sizeof(BuffAggr));
	aggr->index=0;
	aggr->map = (CharBuffer*) malloc(sizeof(CharBuffer)*k);
	return aggr;
}
void addToBuffAggr(BuffAggr* b,CharBuffer* c){
	b->map[b->index++]= *c;
}
void removeFromBuffAggr(BuffAggr* b, offset c){
	int i =0;
	for(;i<b->index;i++)
		if(b->map[i]->offset == c)
			
}
void freeCharBuffer(CharBuffer* c){
	free(c->b);
}
void freeBuffAggr(BuffAggr* b)
{	free(b->map);
}
void main(){
	BuffAggr* buf= initBufMap(5);
	const char* s = "hello";
	CharBuffer *ptr = createBuffer(s,0,strlen(s));
	addToBuffAggr(buf,ptr);

	printOffset(ptr);
	/* free-ing code*/
	freeCharBuffer(ptr);
	free(ptr);
	freeBuffAggr(buf);
	free(buf);
}
