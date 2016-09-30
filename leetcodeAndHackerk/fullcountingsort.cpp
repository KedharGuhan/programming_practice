#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int size = 0;
    cin >> size;
    map<int, vector<string>> sortedOrder;
    vector<int> numbers;
    for(int i = 0; i < size; i++) {
        int n = 0;
        string str;
        cin >> n;
        cin >> str;
        
        if ( i < size/2 ) {
            str = "-";
        }
        if ( sortedOrder.find(n) == sortedOrder.end() ) {
            vector<string> strings;
            strings.push_back(str);
            sortedOrder[n] = strings;
        } else {
            sortedOrder[n].push_back(str);
        }    
    }
    
    for ( auto& entry : sortedOrder ) {
        for ( auto& vectorEntry : entry.second ) {
            cout << vectorEntry << " ";
        }
    }
    return 0; 
   
}

