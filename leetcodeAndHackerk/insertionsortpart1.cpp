#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void out(int a[], int N){
    for(int i =0; i < N; i++){
        cout<< a[i] << " ";
    }
    cout<<"\n";
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin>>N;
    int a[1000];
    for(int i =0;i<N;i++){
        cin >> a[i];
    }
    int e = a[N-1];
    //cout << "e: "<< e;
    for(int i =N-2; i>=0 ;i--){
       // cout<< "\na[i] "<<a[i];
        if(a[i] > e){
            a[i+1]=a[i];
        }
        else {
            a[i+1]  = e;
            break;
        }
        out(a,N);
    }
    // you did not come across an element which is smaller than e
    if(a[0] > e)
        a[0] = e;
    out(a,N);
    return 0;
}

