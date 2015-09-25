#include<stdio.h>
#include<stdlib.h>
void swap_(int i, int j, int a[]){
int t=a[i];
a[i] = a[j];
a[j]=t;
}
int findPivot(int a[],int start, int end){
	printf("\nentring findPivot\t%d\t%d:",start,end);
	int i,j,pivot;
	pivot = a[start];
	i = start+1;
	j = end;
	while(1){
		if(a[i]>pivot && a[j]<pivot)
		{	
			swap_(i,j,a);
			i++;j--;
		}
		while(a[i]<=pivot)i++;
		while(a[j]>pivot)j--;
		if(i>j) break;
	}
	swap_(j,start,a);
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
	int a[5]={7,7,7,7,7};	
	int i;
	for(i =0; i<5;i++)
		printf("%d",a[i]); 
	qsort_(a,0,4);
	print(a,4);
}
