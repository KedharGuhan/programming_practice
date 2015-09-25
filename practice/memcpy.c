#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main(){
	char* p = (char*)malloc(sizeof(char)*10);
	char* q = (char*)malloc(sizeof(char)*10);
	strcpy(p,"hello");
	char* r = p;
	r++;
	int len = strlen(r);
	printf("\n size of r:%d",len);
	memcpy(q,r,sizeof(char)*strlen(r));
	printf("\n printing q:%s",q);	
}
