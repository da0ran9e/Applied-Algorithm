#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,c[N],ans[N];
bool f[N][N];
bool dfs(int u,int t){
if(t>m) return true;
for(int v=1;v<=n;v++){
if(!f[u][v]){
f[u][v]=f[v][u]=true;
ans[t]=max(ans[t],c[v]);
if(dfs(v,t+1)) return true;
f[u][v]=f[v][u]=false;
}
}
return false;
}
int main(){
cin>>n>>m;
for(int i=1;i<=n;i++) cin>>c[i];
int x;
for(int i=1;i<=n;i++)
for(int j=1;j<=n;j++){
cin>>x;
if(x==1) f[i][j]=true;
}
dfs(0,1);
int sum=0;
for(int i=1;i<=m;i++) sum=max(sum,ans[i]);
cout<<sum<<endl;
return 0;
}