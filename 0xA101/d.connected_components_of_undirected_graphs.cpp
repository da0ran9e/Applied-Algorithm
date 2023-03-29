#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

const int N = 10001;

vector<int> adj[N]; // Adjacency list to store the graph
bitset<N> visited; // To keep track of visited nodes

void dfs(int node, int n) {
    visited[node] = true;
    for (auto& next : adj[node]) {
        if (!visited[next]) {
            dfs(next, n);
        }
    }
}

int main() {
    int n, m; // n = number of nodes, m = number of edges
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b); // Adding an edge from a to b
        adj[b].push_back(a); // Adding an edge from b to a (for undirected graph)
    }
    int count = 0; // To keep track of number of connected components
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            count++;
            dfs(i, n);
        }
    }
    cout << count << endl;
    return 0;
}
