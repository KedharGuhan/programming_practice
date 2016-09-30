#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int N;
    cin >> N;
    int a[26];
    bool found[26];
    for (int i = 0; i< 26; i++)
            found[i] = false;
    string s;
    for ( int i = 0; i< 26; i++)
          a[i] = 0;
    int numcases = N;
   // cout << "tc :"<< N<<endl;
    while ( N > 0 ){
        cin >> s;
        for (int i =0 ; i< s.length(); i++ ){  
            
            if( found[s[i] - 'a'] == false ){    
                a[s[i]- 'a']++;
                found[s[i] - 'a'] = true;
                
            }
           // cout << " what: " << s[i] -'a' << "count: " << a[s[i-'a']] << endl;
        }
        for (int i = 0; i< 26; i++)
            found[i] = false;
        N--; 
    }
    
    long count = 0;
    for ( int i = 0; i< 26; i++){
     //  cout << a[i] << endl;
        if( a[i] == numcases)
            count++;
        
    }
    cout << count << endl;
    return 0;
}

