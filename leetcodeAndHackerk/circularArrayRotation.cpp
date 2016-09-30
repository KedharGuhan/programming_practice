#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int* rotate(int a[], int k, int n){
    int* b = new int[n];
    int j = 0;
    int div;
    if(n-k < 0){
        div = k/n;
        k = k - div*n;
    }
    
    for(int i =n-k;i<n;i++)
        b[j++] = a[i];
    for(int i =0 ; i < n-k ; i++)
        b[j++] = a[i];
    
    return b;
    
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int n,q,k,x;
    //n ints, k rotations, q queries
    
    cin>>n>>k>>q;
  
    int *a = new int[n];
    for( int i = 0; i < n;i++ ){
        cin >> a[i];
    }
    int* b;
    b = rotate(a,k,n);
    for(int i = 0 ; i < q; i++)
    {   
        //cout<<i+100;
        cin>>x;
        if(x<n && x>=0 )
            cout<<b[x]<<endl;
    }
    return 0;
}

