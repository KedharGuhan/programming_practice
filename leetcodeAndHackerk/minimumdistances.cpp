#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 0;i < n;i++){
       cin >> A[i];
    }
    int dist_prev=0, mindist=10000, dist=0;
    map<int, int> curdist;
    for(int i =0;i<n; i++){
        if(curdist.find(A[i])!= curdist.end()){
            dist_prev=curdist[A[i]];
            curdist[A[i]] = i;
            dist = i - dist_prev;
          //  cout<<"\n"<<dist<<" "<<i;
            if(dist<mindist){
             //   cout<<endl<<"dist:"<<dist;
             //   cout<<endl<<"mindist:"<<mindist;
                mindist = dist;
            }
        
    } else{
        curdist[A[i]] = i;
    }
    }
    if( mindist == 10000 )
        cout <<-1<<"\n";
    else
        cout<<mindist<<"\n";
    return 0;
}

