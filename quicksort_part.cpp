#include <iostream>
using namespace std;

void swap (int arr[] , int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp; 
}
void print (int [], int start, int end );
int quick(int arr[],int start, int end){
    //given a pivot, rearrange the elements such that 
    //numbers<pivot || pivot || numbers > pivot
    int element = arr[start];
    int i = start-1,j = end+1;
    while(true)
    {
        do {
            i++;
        }while(arr[i]<= element);
        do{
            j--;
        }while (arr[j]> element);
        if ( i < j)
            return j;
        swap (arr, i, j);
    }
    // returns end when the array is already sorted; thats when end will already be in place
    return j;
}

void print(int arr[],int start, int end){
    for (int i = start; i<= end; i++ ){
        cout <<arr[i]<<" ";
    }
    cout <<endl;
}
int qsort ( int arr[], int start, int end ){

    cout <<"\nstart: "<<start <<" end :"<<end; 
    if ( start <  end )
    {
        int pivot = quick (arr, start, end );
        qsort( arr, start, pivot);
        qsort( arr, pivot+1, end);
        
    } 
    
}

bool checker (int arr[], int len )
{
    for (int i =1; i< len; i++ )
        if (arr[i-1 ] > arr[i])
            return false;
    return true;
}
int main(){
    int arr[]={10,20,30,40,34,60,70,80,5};
    qsort(arr, 0, 8);
    print (arr, 0 , 8);
    checker (arr, 9);
}
