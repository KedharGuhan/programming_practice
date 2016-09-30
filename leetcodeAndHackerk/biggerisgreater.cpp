#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void sortstr(string w, int pos){
    //int len = w.length();
    cout <<"\n before sort "<<w;
    sort(w.begin()+pos, w.end());
    cout<<"\n sorted "<< w;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int len,t, i,j, minpos;
    string w;
    char min, temp;
    string tempstr;
    cin>>t;
    int nextmax, maxpos;
    bool done = false;
    while( t > 0){
        cin>> w;
       // cout << endl << w;
        len = w.length();
        minpos = len-1;
        maxpos = len -1;
        nextmax = w.at(maxpos);
        
        min = w.at(minpos);
        // i-1 is the position whihc will be replaced
        // search  from last to i to find the first number greater than w.at(i-1)
        // break out of two for loops when done
        for( i = len-1; i > 0; i-- ){
           if( w.at(i) > w.at(i-1)){
                for( j = len - 1; j>=i; j--)
                {   
                    if( w.at( j ) > w.at( i-1 ))
                    {
                        temp = w.at(j);
                        w.at(j) = w.at(i-1);
                        w.at(i-1) = temp;
                        sort( w.begin()+i, w.end());
                        cout <<w<<endl;
                        done = true;
                        break;
                    }
                }
                if(done == true )
                    break;
            }//endif
        } 
        if( done == false )
            cout <<"no answer\n"; 
        done = false;
        t--;
    }
    return 0;
}

