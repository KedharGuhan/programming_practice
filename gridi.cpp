#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <map>
#include <set>
using namespace std;
bool myfunc(pair<int64_t, int64_t > p1, pair<int64_t,int64_t> p2){
    if ( p1.first <= p2.first )
        return true;
    return false;

}
int64_t computeDistance( vector<pair<int64_t, int64_t> > dist){
    int64_t curc1 = -1, curc2 = -1;
    int64_t p = 0 , c1, c2;

    vector<pair<int64_t, int64_t > >::iterator it = dist.begin();

    
    for (; it!= dist.end(); it++){
        if (curc1 == -1 && curc2 == -1 ){
            curc1 = it->first;
            curc2 = it->second;
            p = curc2- curc1+1;
        }
        else {
            c1 = it->first;
            c2 = it -> second;
            if ( c1 > curc2  ){
                p += c2-c1+1; 
                curc1 = c1;
                curc2 = c2;
            }
            if (c1 == curc2 ){
                p += c2-c1;
                curc2 = c2;
            }
            else if ( c1 < curc2 ){ // c1< cur2
                if ( c2 > curc2 ){
                    p += c2-curc2;
                    curc2 = c2;
                }
            }
       }
    }
    cout << "p : " << p <<"  ";
    return p;
}
int main() {
    int64_t n, m ,k;
    int64_t row, c1, c2;
    
    cin >> n >> m >> k; 
    cout << " n: " << n <<" m: "<<m<<"k: " << k;
    vector<pair<int64_t ,int64_t > > lines [1001];
    map <int64_t , int64_t> mapToIndex;
    map <int64_t, int64_t>::iterator it;
    int count= 0;
    int indexToInsert;
    for (int64_t i = 1;i <= k; i++){
        cin >> row >> c1 >> c2;
        it = mapToIndex.find (row);
        if (it!= mapToIndex.end ()){
            indexToInsert = it->second;
            mapToIndex.insert(make_pair(row,indexToInsert ));
            lines[indexToInsert].push_back(pair<int64_t, int64_t>(c1,c2));
        }
        else 
            lines[count++].push_back(pair<int64_t, int64_t>(c1,c2));
    }
    
    int64_t p = 0;  int64_t num = 0;
    for ( it = mapToIndex.begin(); it!= mapToIndex.end() ; it++) { 
            sort( lines[it->second].begin(), lines[it->second].end(), myfunc);
            p+= computeDistance(lines[it->second] );
    }
    int64_t mult = n*m;
    cout << mult - p; 
    
    return 0;
}

