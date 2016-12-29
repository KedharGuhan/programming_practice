#include <iostream>
#include <map>
using namespace std;

map<char,int> buildMap(const string& a)
{
    map<char,int> strmap;
    for (int i = 0; i<a.length(); i++)
        strmap[a.at(i)]++;
    return strmap;
}

int main(){
    string a, b;
    cin >>a>>b;

    if (a.length() != b.length())
        cout << "FALSE";
    
    else
    {   int i = 0;
        map<char,int> a_map, b_map;
        a_map = buildMap(a);
        b_map = buildMap(b);
    
        for (i = 0; i<a.length();i++){
            if ( a_map[a.at(i)] != b_map[a.at(i)] )
                break;
        }
        if ( i < a.length())
            cout <<"FALSE";
        
        for ( i = 0; i<b.length();i++){
            if ( a_map[b.at(i)] != b_map[b.at(i)] )
                break;
        }
        if ( i < b.length())
            cout <<"FALSE";

    }
    return 0;
}
