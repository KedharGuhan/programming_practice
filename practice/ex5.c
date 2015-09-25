#include<stdio.h>
#include<stdlib.h>
/*
	1. strcpy(s,t) copies s to t
  	2. strcmp(s,t) compares s with t
*/

size_t strlen_(char *p){
	char *old_p = p;
	while(*p!='\0')
		p++;
	size_t len = p-old_p;
	return len;

}
void strcpy_(char *p, char *q){
	while(*q!='\0'){
		*p = *q;
		p++; q++;
	}	
}

void strncpy_(char*p, char*q, int n){
	int i =0;
	if(strlen_(p)<n) n = strlen_(p);
	for(;i<n-1;i++)
		p[i]=q[i];
	p[i]='\0';
}
/*copies string t to the end of s*/
// if memory isnt allocated for ptr,; seg fault

char* strcat_(char*s, char*t){
int k = strlen_(s)+strlen_(t)+1;
char* ptr=(char*)malloc(sizeof(char)*(k));
int i =0, j =0;
for(; i<strlen_(s);i++) ptr[i] = s[i];

for(; j<strlen_(t);j++) ptr[i+j]= t[j];
ptr[i+j]='\0';
return ptr;

}
int strcmp_(char *s, char*t){
	size_t slen = strlen_(s);
	size_t tlen = strlen_(t);
	if(tlen > slen ) return -1;
	else if (tlen < slen ) return 1;
	int i =0;
	for (; s[i]!='\0';i++){
		if(s[i]==t[i]) continue;
		if(s[i]^32 == t[i]) continue;
		else break;
	}
	return s[i]-t[i]; 
}

// returns 1 if t is at the end of s, zero otherwise
int strend_(char*s, char*t ){

	int tlen = strlen_(t);
	int slen = strlen_(s);
	if(tlen > slen) return -1;
	int i =0,j=tlen-1;
	for(i=slen-1;i>(slen-tlen);i--,j--) if(s[i]!=t[j]) return -1;
	return 1;
}
main(){
	
	char p[] = "geeksforgeeks";
	char q[] = "GeeksForGeeks9";
	printf("%s%zu", "\nstrlen of q :",strlen_(q));
	printf("%s", "\ncalling strcpy");
	strcpy_(p,q);
	int j= strcmp_(p,q);
	printf("%s %s %s %s %s %d","\nComparing",p, "and" ,q,"is:",j);
	int k = strlen_(p)+strlen_(q);
	// is it possible to put char[] here instead of char*
	char* ptr= strcat_(p,q);
	printf("\nPrinting after strcat%s",ptr);
	free(ptr);
	int x = strend_("hello","low");
	printf("\nstreend%d",x);
	strncpy_(p,q,strlen_(q));
	printf("\nstrncpy%s",p);
}

