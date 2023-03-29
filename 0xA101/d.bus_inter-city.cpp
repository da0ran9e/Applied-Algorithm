#include <bits/stdc++.h>
using namespace std;

int n, m, x, y;
int c[101], d[101];
vector<vector<int>> adj(101);
int vis[101];
long long dp[101][101];

long long solve(int at, int tickets){
    int dest = n;
    if (at == dest) return 0;
    if (tickets == 0) return 99999999;
    
    long long &ans = dp[at][tickets];
    if (ans != -1) return ans;
    ans = 99999999;
    
    for (int i = 0; i<adj[at].size(); i++){
        int to = adj[at][i];
        ans = min(ans, c[at]*tickets + solve(to, min(tickets-1, d[to])));
    }
    return ans;
}

int main(){
    
  cin >> n >> m;
  for (int i = 1; i<=n; i++)
    cin >> c[i] >> d[i];
  for (int i = 0; i<m; i++){
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  memset(dp, -1, sizeof(dp));
  long long result = solve(1, d[1]);
  
  cout << result << endl;
  return 0;
}
