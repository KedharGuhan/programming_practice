#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <map>
using namespace std;
bool myfunc(pair<int64_t, int64_t > p1, pair<int64_t,int64_t> p2){
    if ( p1.first <= p2.first )
        return true;
    return false;
}
// Cases
// --------
//   ----
//               -------
//   ---------
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
   // cout << p;
    return p;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int64_t n, m ,k;
    int64_t row, c1, c2;
    
    cin >> n >> m >> k;
    // array of vector of pairs of 1001 since its only 1000 rows max
    vector<pair<int64_t ,int64_t > > lines [1001];
    // boolean to find which rows have tracks
    map <int, bool > ks1;
    
    vector <bool> ks;
    // store the lines
    for (int64_t i = 1;i <= k; i++){
        cin >> row >>c1 >> c2;
        ks1[row] = true;
        lines[row].push_back(pair<int64_t, int64_t>(c1,c2));
    }
    
    // sort the vector pairs based on c1
    int64_t p = 0; 
    for ( int64_t  i = 1; i<= row; i++ ){
        if ( ks1[i] == true ) {
            sort( lines[i].begin(), lines[i].end(), myfunc);
            p+= computeDistance(lines[i] );
            ks1[i] = false;
        }
    }    
    int64_t mult = n*m;
    cout << mult - p; 
    return 0;
}
