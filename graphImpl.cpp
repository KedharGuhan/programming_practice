#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Vertex{
    public: int from, to, edge;
    public :
    Vertex(int f, int t, int e){
        cout << "vertex constructor call";
        from = f;
        to = t;
        edge = e;
    }
};
class Graph{
    vector<vector<Vertex> > adjList;
    int N,M;
    public :
    Graph(int n, int m){
       
        N = n;
        M = m;
        int from, to, edge;
        
        vector<Vertex> temp;
        for (int i = 0; i< N+1; i++){
            adjList.push_back(temp);
        }
        
        
        for (int i = 0 ;i < M; i++ ){
            cin >> from >> to >> edge;
            cout << from << to << edge;
            Vertex f(from , to , edge);
            Vertex t (to, from , edge);
      
            adjList[from].push_back(t);   
            adjList[to].push_back(f);
        }
    }
    void printGraph(){
        for (int i = 1; i<=N; i++){
            vector<Vertex>::iterator it = adjList[i].begin();
            for (; it!= adjList[i].end();it++){
                cout << (*it).from <<"->" <<(*it).to << " " <<(*it).edge <<endl;
             }
            cout <<endl;
        }
    }
    
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m;
    int T;
    cin >> T;
    while (T > 0){
        cin >>n >> m;
        Graph G(n,m);
        G.printGraph();
        T--;
    }
    return 0;
  
}

