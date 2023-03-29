#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 1005;

vector<int> graph[MAXN];
int inDegree[MAXN];
int d[MAXN];

void topoSort(int n) {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            inDegree[v]--;
            d[v] = max(d[v], d[u] + 1);
            if (inDegree[v] == 0) q.push(v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        inDegree[v]++;
    }
    topoSort(n);
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, d[i]);
    cout << ans << endl;
    return 0;
}
