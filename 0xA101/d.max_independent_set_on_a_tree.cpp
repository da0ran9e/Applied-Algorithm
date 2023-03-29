#include<bits/stdc++.h>

using namespace std;
const int N=1e5+10;


vector<int> edge[N];
int w[N];
int dp[N][2];

void dfs(int u,int fa){
	dp[u][1]=w[u];
	for(int i=0;i<edge[u].size();i++){
		int v=edge[u][i];
		if(v==fa) continue;
		dfs(v,u);
		dp[u][0]+=max(dp[v][0],dp[v][1]);
		dp[u][1]+=dp[v][0];
	}
}

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>w[i];
	int x,y;
	for(int i=1;i<n;i++){
		cin>>x>>y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	dfs(1,0);
	cout<<max(dp[1][0],dp[1][1])<<endl;
	return 0;
}