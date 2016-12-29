#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
#include <unordered_map>
#include "my_pq.h"
using namespace std;


void find_top(vector<int> &num, int k){
    // find frequency of each number :
    // map uses rb tree, o(log n) for each operation
    // inserting n entries would be n log n complexity
    // use heap to find top k
    unordered_map<int, int> entries;
    for (int i = 0; i < num.size(); i++ ){
        entries[num[i]]++; 
    }
    for (unordered_map<int,int>::iterator it = entries.begin(); it!= entries.end(); it++ )
    {
        cout << it->first << " "  << it->second << endl;
    }
}
int main(){
    vector<int> num;
    int n = 13;
    while (n  > 0) {
        num.push_back(rand()%10);
        n--;
    }
    for (int i = 0; i < num.size(); i++){
        cout << num[i] << " ";
    }
    find_top(num,2);
    int arr[] ={1,2,3,7,-1};
    PQ *q = new PQ(arr, 5);
    q->print();
}