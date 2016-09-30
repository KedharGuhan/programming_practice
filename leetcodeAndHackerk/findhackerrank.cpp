#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int N;
    cin >> N;
    string str;
    cin.ignore();
    bool start=false,end=false;
    while(N > 0){
        getline(cin,str);
      //  cout<<str;
        int len = str.length();
      //  cout<<"\nlen of str "<<str<<" "<<len;
        if(str.substr(0,10)=="hackerrank")
            start = true;
        if(str.substr(len-10, 10)=="hackerrank")
            end = true;
        
        if(start && end )
            cout<<"0";
        else if( start )
            cout<<"1";
        else if( end )
            cout<<"2";
        else
            cout <<"-1";
        start = false;
        end = false;
        cout<<endl;
        N--;
    }
    return 0;
}

