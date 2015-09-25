#include<stdio.h>
#include<stdlib.h>
void swap_(int i, int j, int a[]){
int t=a[i];
a[i] = a[j];
a[j]=t;
}
int findPivot(int a[],int start, int end){
	printf("entring findPivot");
	int i,j,pivot;
	pivot = a[start];
	for(i = start+1, j = end;i<=end,j>=start; ){
		if(a[i]>a[pivot] && a[j]<a[pivot])
		{	
			swap_(i,j,a);
			i++;j--;
		}
		if(a[i]<a[pivot])i++;
		if(a[j]>a[pivot])j--;
		if(i>j) break;
	}
	swap_(j,pivot,a);
	return j;
}
void print(int a[], int len){
	int i =0;
	for(; i<=len;i++)
		printf("%d\t", a[i]);
}
void qsort_(int a[], int start, int end)
{
	if(start<end){
    int p = findPivot(a, start, end);
    qsort_(a,0,p-1);
    qsort_(a,p+1,end);
	}
}

void main(){
	int a[5]={4,5,6,1,2};	
	int i;
	for(i =0; i<5;i++)
		printf("%d",a[i]); 
	qsort_(a,0,4);
	print(a,4);
}
