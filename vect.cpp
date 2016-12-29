#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> a(4);
    a[0] = 2;
    a[1] = 4;
    a[2] = 6;

    vector <int> b(5);
    for ( int i = 0 ; i< 5; i++ )
        b[i] = 10*i;

    a.insert ( a.begin()+1, b.begin(), b.end()  );
    
    vector<int>::size_type sz = 0;
    for ( ;  sz < a.size(); sz++ )
        cout << a.at(sz) << " ";

}
