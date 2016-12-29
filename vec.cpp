#include <iostream>
#include <vector>
using namespace std;
class Vertex{
    public:
    int data;
    Vertex( int d ){
        data = d;
    }
};
int main(){
    // array of int vectors
    vector<int> *adjList = new vector<int>[3];
    vector<Vertex*> *adj = new vector<Vertex*>[3];

    for (int i = 0;i < 3; i++)
    {   
        adjList[i].push_back(1);
        adjList[i].push_back(4);
        Vertex* v = new Vertex (33);
        adj[i].push_back(v);
        adj[i].push_back(v);
    }

    for (int i = 0 ; i< 3;i++){
        vector<int>::iterator it = adjList[i].begin();
        vector<Vertex*>::iterator itt = adj[i].begin();
        
        for (; itt!=adj[i].end();itt++)
        {
            Vertex* v = *itt;
            cout << v->data << " ";
        }
        cout <<endl;
    }

    return 0;
}

