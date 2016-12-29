#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <list>
using namespace std;

class Graph{
    int v;
    list<int> *adj;
    public:
    Graph(int n){
        v = n;
        adj = new list<int>[n];
    }
    void addEdge(int from, int to){
        adj[from].push_back(to);
    }
    bool dfs(int start, int color[], int count){
      //  cout <<"\ncolor at every point";
      /*  for (int i = 0;i <count; i++)
            cout <<" "<<color[i]<<" ";
        */
        color[start] = 2;
        bool ret = true;
        list<int>::iterator it;
        for (it = adj[start].begin(); it!=adj[start].end();it++)
        {
            if (color[*it]== 1) 
                ret = dfs(*it, color,count);
            else if (color[*it]==2)
                 return false;
        }
        color[start] = 3;
        return ret;
    }
    bool doDFS(int count){
        int color[count];
        bool ret = true;
        for (int i = 0; i<count;i++)
            color[i] = 1;
        for (int i = 0; i<count; i++){
            ret = dfs(i, color, count);
            if (ret == false)
                break;
        }
        return ret;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
     
    int n,x;
    cin >> x;
    string str;
    Graph g(200);
    for( int i = 0; i< x; i++ ){
        cin >> n;
        cin.ignore();
       
        map<string,int> placesToEvents;
        map<string,int>::iterator it;

        int count  = 0;
        int prevDest = -1; 
        int pos;
        int numPlaces = 0;
        string prev;
        string currentStr;
        for (int j = 0; j<n ; j++ ){
               getline (cin,str ,'\n');
                
                while (!str.empty()){
                    pos = str.find(',');
                   
                    if (pos != string::npos ){
                        currentStr = str.substr(0,pos);
                        str = str.substr( pos+1, str.length());
                    }
                    else{
                        currentStr = str;
                        str.clear();
                    }
                    it = placesToEvents.find(currentStr);
                    if( it == placesToEvents.end() ){
                        placesToEvents.insert(pair<string,int>(currentStr,count));
                        numPlaces++;
                    }
                    else
                        count = it->second;
        
                    if ( prevDest != -1 ){
                        g.addEdge (prevDest,count);
                  
                    } 
                    
                    
                    prevDest = count;
                    count++;
                }
                
            
            prevDest = -1;
            
        }
       // cout <<"count : "<<count;
       // cout <<"numPlaxces: " <<numPlaces;
        bool isCycle = g.doDFS (numPlaces);
        
        if ( isCycle )
            cout <<"ORDER EXISTS\n";
        else
            cout <<"ORDER VIOLATION\n";
            
        
       
       count = 0;
    }
    return 0;
}

