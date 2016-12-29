#include<iostream>
#include<map>
using namespace std;
int main()
{
    map<int,int> intmap;
    pair<map<int,int>::iterator,bool> ret;
    ret = intmap.insert(make_pair(1,2)); 
    cout << ret.second;
    //cout << ret.first;
    ret = intmap.insert(make_pair(1,3));
    cout << ret.second;
    //cout << ret.first;
 
    intmap[1] = 3;
    for(map<int,int>::iterator it = intmap.begin(); it!= intmap.end(); it++)
    {
        cout << it->first;
        cout << it ->second;
        cout << "\n moving on";
    }
    
}