#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T, N;
    cin >> T;
    bool flag =false;
    for(int i = 0 ; i < T ; i++ ){
        cin >> N;
        int* num = new int[N];
        int * sum = new int[N];
        cin >> num[0];
        sum[0] = num[0];
        for( int j = 1; j < N ; j++ ){
            cin >> num[j];
            sum[j] = sum[j-1] + num[j];
        }
        for( int j = 1; j < N; j++ ){
            if( sum[j-1] == sum[N-1] - sum[j] ){
                flag = true;
                break;
            }
        }
        if( N == 1)
            flag = true;
        if( sum[N-1] - num[0] == 0 )
            flag = true;
        if( sum[N-2] == 0 )
            flag = true;
        if( flag )
            cout << "YES\n";
        else
            cout << "NO\n";
        flag = false;
        delete []num;
        delete []sum;
    }
        
    
    return 0;
}

