#include<bits/stdc++.h>
using namespace std;

class Graph
{
    public:
        int V;    // No. of vertices
        list<int> *adj;    // Pointer to an array containing adjacency lists  (double linked list)
        bool *visited;
        Graph(int V);  // Constructor
        void addEdge(int v, int w);   // function to add an edge to graph
        void BFS(int s);        // prints BFS traversal from a given source s
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v) //directed graph
{
    adj[u].push_back(v); // Add v to u’s list.
   // adj[v].push_back(u);
}

d[u]=low[u]=++time;
numChild =0;
for(int v=1; v<=adj; v++)
{
	numChild++;
	parent[v] 
}

void main()
{
	cin >> n >> m;
	while(m--)
	{
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int u=1; u<=n; u++) parent[u] = u;
	for (int u=1; u<=n; u++) if (!d[u]) DPS(u);
	for (int u=1; u<=n; u++) numCV += cutVertex[u];
	cout << numCV << " " << numB;

}