// A DFS based approach to find if there is a cycle
// in a directed graph. This approach strictly follows
// the algorithm given in CLRS book.
#include <bits/stdc++.h>
using namespace std;

enum Color {WHITE, GRAY, BLACK};

// Graph class represents a directed graph using
// adjacency list representation
class Graph
{
	int V; // No. of vertices
	list<int>* adj; // adjacency lists

	// DFS traversal of the vertices reachable from v
	bool DFSUtil(int v, int color[]);
public:
	Graph(int V); // Constructor

	// function to add an edge to graph
	void addEdge(int v, int w);

	bool isCyclic();
};

// Constructor
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

// Utility function to add an edge
void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v's list.
}

// Recursive function to find if there is back edge
// in DFS subtree tree rooted with 'u'
bool Graph::DFSUtil(int u, int color[])
{
	// GRAY : This vertex is being processed (DFS
	//		 for this vertex has started, but not
	//		 ended (or this vertex is in function
	//		 call stack)
	color[u] = GRAY;

	// Iterate through all adjacent vertices
	list<int>::iterator i;
	for (i = adj[u].begin(); i != adj[u].end(); ++i)
	{
		int v = *i; // An adjacent of u

		// If there is
		if (color[v] == GRAY)
		return true;

		// If v is not processed and there is a back
		// edge in subtree rooted with v
		if (color[v] == WHITE && DFSUtil(v, color))
		return true;
	}

	// Mark this vertex as processed
	color[u] = BLACK;

	return false;
}

// Returns true if there is a cycle in graph
bool Graph::isCyclic()
{
	// Initialize color of all vertices as WHITE
	int *color = new int[V];
	for (int i = 0; i < V; i++)
		color[i] = WHITE;

	// Do a DFS traversal beginning with all
	// vertices
	for (int i = 0; i < V; i++)
		if (color[i] == WHITE)
		if (DFSUtil(i, color) == true)
			return true;

	return false;
}

// Driver code to test above
int main()
{
	// Create a graph given in the above diagram
	Graph g(4);
	int count ;
	int from, to;
	cin >>count;
	while (count>0){
	cin >> from;
	cin >> to;
	cout <<from<< " "<<to;
	g.addEdge(from, to);
	count --;	
	}
	if (g.isCyclic())
		cout << "Graph contains cycle";
	else
		cout << "Graph doesn't contain cycle";

	return 0;
}
