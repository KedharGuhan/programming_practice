#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int T, N, K, x, count;
    cin >> T;
    while(T > 0 ){
        cin>> N >> K;
        for( int i = 0; i < N ; i++ ){
            cin >> x;
            if( x <= 0)
                count++;
        }
        if( count < K )
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
        T--;
        count = 0;
    }
    return 0;
}
