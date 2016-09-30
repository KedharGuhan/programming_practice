#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int compareFunc(const void* a , const void* b){
    return *(int*)a-*(int*)b;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    int a[100000];
    cin >> N;
    
    for( int i = 0; i< N; i++){
        cin >> a[i];
    }
    qsort(a, N, sizeof(int), compareFunc);
    int units = 1;
    int weight = a[0];
        
    for(int i =1; i < N; i++ ){
        if((a[i] >= weight) && (a[i] <= (weight+4)))
            continue;
        units++;
        weight = a[i];
    }
    cout<< units;
    return 0;
}

