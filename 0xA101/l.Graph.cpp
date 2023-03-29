#include <iostream>
#include <list>
#include <queue>
#include <stack>
using namespace std;


struct DisjointSets
		{
			int *parent, *num;
			int n;
			DisjointSets(int n)
			{
				this -> n=n;
				parent = new int[n+1];
				num = new int[n+1];

				for (int i=0; i<=n; i++)
				{
					num[i] = 1;
					parent[i]=i;
				}
			}
		}
class Graph
{
	public:
		int V, E;	// No of vertices
		list<int> *adj;
		bool *visited;

		int *pred;

		Graph(int V);	// Constructor
		void addEdge(int u, int v);	// Add edge from u to v
		void BFS(int s);			// print BFS traversal
		void DFS(int s);			// print DFS traversal
		void reversePrint(int v);	// print the path from start to v

		void DFS_Topo(int s, stack <int> &Stack);
		void TopoSort();
		void TopoSort_BFS();
		bool CheckBipartite_BFS(int s);

		Graph getTranspose();
		bool checkSC();


		int Find(int x);
		void Union(int x; int y);

		int KruskalMST_Disjointsets();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);		// Undirected graph
}

void Graph::BFS(int s){
	queue<int> Q;
	visited[s] = true;
	Q.push(s);

	int u, v;
	while (!Q.empty()){
		u = Q.front(); 
		Q.pop();
		cout << u << " ";

		list<int>::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); i++){
			v = *i;
			if (visited[v] == 0) {
				visited[v] = 1;
				Q.push(v);

				pred[v] = u;
			}
		}
	}
}

void Graph::DFS(int s){
	visited[s] = true;
	cout << s << " ";

	list<int>::iterator i;
	for (i = adj[s].begin(); i != adj[s].end(); i++){
		int v = *i;
		if (visited[v] == 0){
			DFS(v);

			pred[v] = s;
		}
	}
}


void Graph::DFS_Topo(int s, stack <int> &Stack){
	visited[s] = true;

	list<int>::iterator i;
	for (i = adj[s].begin(); i != adj[s].end(); i++){
		int v = *i;
		if (visited[v] == 0){
			DFS_Topo(v, Stack);

			pred[v] = s;
		}
	}

	Stack.push(s);
}

void Graph::TopoSort(){
	for (int s = 0; s < V; s++)
		visited[s] = false;
	
	stack <int> Stack;
	int u;
	for (int s = 0; s < V; s++)
		if (!visited[s])
			DFS_Topo(s, Stack);

	while (!Stack.empty()){
		u = Stack.top(); 
		Stack.pop();
		cout << u << "->";
	}
}

void Graph::TopoSort_BFS(){
	vector <int> in_degree(V, 0);

	list<int>::iterator i;
	for (int u = 0; u < V; u++){
		for (i = adj[u].begin(); i != adj[u].end(); i++){
			in_degree[*i]++;
		}
	}

	queue<int> Q;
	for (int u = 0; u < V; u++){
		if (in_degree[u] == 0){
			Q.push(u);
		}
	}

	int num = 0;
	int u, v;
	vector <int> topo_order;
	while (!Q.empty()){
		u = Q.front(); 
		Q.pop();

		num = num+1;
		topo_order.push_back(u);

		for (i = adj[u].begin(); i != adj[u].end(); i++){
			v = *i;
			in_degree[v] = in_degree[v]-1;
			if (in_degree[v] == 0)
				Q.push(v);
		}
	}

	for (auto i = topo_order.begin(); i != topo_order.end(); i++){
		cout << *i << "->";
	}
}

bool Graph::CheckBipartite_BFS(int s){
	int color[V];
	for (int u = 0; u < V; u++)
		color[u] = 0;

	queue<int> Q;
	color[s] = 1;
	Q.push(s);


	int u, v;
	while (!Q.empty()){
		u = Q.front(); 
		Q.pop();

		list<int>::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); i++){
			v = *i;
			if (u == v) return false;

			if (color[v] == 0) {
				color[v] = (color[u] == 1) ? 2 : 1;
				Q.push(v);
			} else {
				if (color[v] == color[u])
					return false;
			}
		}
	}

	cout << "\nRed: ";
	for (int u = 0; u < V; u++)
		if (color[u] == 1)
			cout << u << " ";

	cout << "\nBlue: ";
	for (int u = 0; u < V; u++)
		if (color[u] == 2)
			cout << u << " ";

	return true;
}


void Graph::reversePrint(int v){
	if (pred[v] != -1)
		reversePrint(pred[v]);
	
	cout << v << "->";

	return;
}
Graph Graph::getTranspose()
{
	Graph gTS(V);
	for(int u=0; u<V; u++){
		list<int>>::iterator i;
		for(i=adj[u].begin(); i!=adj[u].end(); i++){
			int v = *i;
			gTS.adj[v].push_back(u);
		}
	}
	return gTS;
}
bool Graph::checkSC()
{
	for(int v=0; v<V; v++){
		visited[v]=0;
	}
	DFS(0);
	for(int v=1; v<V; v++){
		if(visited[v]==0) return false;
	}
	for(int v=0; v<V; v++){
		visited[v]=0;
	}
	Graph gTS=getTranspose();
	gTS.DFS(0);
	for(int v=1; v<V; v++){
		if(visited[v]==0) return false;
	}

}
int Graph::Find(int x){
	while(parent[x]!=x){
		x=parent[x];
	}
	return x;
}
int Graph::KruskalMST_Disjointsets(){
	DisjointSets ds(V);
	sort(edges.begin(), edges.end());
	vector<pair<int, iPair>>::iterator i;
	for(i=edges.begin(); i!=edges.end(); i++){
		int u = i->second.first();
		int v = i->second.second();
		int rootU = ds.Find(u);
		int rootV = ds.Find(v);
		if (ds.Find(u) != ds.Find(v)){
			res += i->first;
			ds.Union(rootU, rootV);
		}
	}
	return res;
}