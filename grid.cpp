#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


bool myfunc(pair<long long, long long > p1, pair<long long,long long> p2){
    if ( p1.first <= p2.first )
        return true;
    return false;
}
// Cases
// --------
//   ----
//               -------
//   ---------
long long computeDistance( vector<pair<long long, long long> > dist){
    long long curc1 = -1, curc2 = -1, p = 0, c1, c2;

    vector<pair<long long, long long > >::iterator it = dist.begin();

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
    return p;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long  long n, m ,k;
    long  long row, c1, c2;
    
    cin >> n >> m >> k;
    // array of vector of pairs
    vector<pair<long long ,long long > > lines [1001];
    bool ks[1001];
    for (long i = 1;i <= k; i++){
        cin >> row >>c1 >> c2;
        ks[row] = true;
        lines[row].push_back(pair<int,int>(c1,c2));
    }
    vector<pair<long long , long long> >::iterator it;
    for ( long long i = 1; i<= k; i++ ){
        it = lines[i].begin();
        while (it != lines[i].end()){
            it++;
        }
        
    }
    // sort the vector pairs based on c1
    long long p = 0; 
    for ( long long  i = 1; i<= 1000; i++ ){
        if ( ks[i] == true ) {
            sort( lines[i].begin(), lines[i].end(), myfunc);
            p+= computeDistance(lines[i] );
            ks[i] = false;
        }
    }    
    cout << n*m - p; 
    return 0;
}

