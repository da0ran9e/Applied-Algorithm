// #include <bits/stdc++.h>
// #define MAX 200005
// using namespace std;
// int n,k,c[MAX][20],f[MAX][20];

// int solve(int x,int y){
//     if(f[x][y]!=-1) return f[x][y];
//     if(y==k){
//         f[x][y]=c[x][0];
//         return f[x][y];
//     }
//     f[x][y]=1e9;
//     for(int i=0;i<n;i++){
//         f[x][y]=min(f[x][y],c[x][i]+solve(i,y+1));
//     }
//     return f[x][y];
// }

// int main(){
//     cin>>n>>k;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cin>>c[i][j];
//         }
//     }
//     memset(f,-1,sizeof(f));
//     cout<<solve(0,0)<<endl;
//     return 0;
// }

#include <iostream>
#include <climits>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    
    int C[n+1][n+1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++)
            cin >> C[i][j];
    }

    int dp[n][1 << n];
    // Initially everything is marked as infinite
    for (int i = 0; i < n; i++)
        for (int j = 0; j < (1 << n); j++)
            dp[i][j] = INT_MAX;
        
    // Starting point (0) is marked as 0 
    dp[0][1] = 0;
    
    // Compute all intermediate distances 
    // considering combinations of trips
    for (int i = 1; i < (1 << n); ++i){
        for (int j = 1; j <= n; ++j){
            for (int k = 0; k <= n; ++k){
                if ((i & (1 << (k-1))) && C[j-1][k-1] && dp[j-1][i - (1<<(k-1))] != INT_MAX){
                    dp[j-1][i] = min(dp[j-1][i], dp[j-1][i - (1<<(k-1))] + C[j-1][k-1]);
                }
            }
        }
    }
    
    // Return the length of the shortest route 
    cout << dp[0][(1 << n) - 1] << endl;
    return 0;
}

