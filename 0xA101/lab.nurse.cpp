#include<bits/stdc++.h>
using namespace std;
 
#define max 2000

int N, K1, K2;
void solve()
{
	int S0[max], S1[max];
	for (int i=1; i<=N; i++)
	{
		S0[i]=0;
		S1[i]=0;
	}
	// S0[i]=1;
	// S1[K1]=1;
	// S0[0]=1;
	for(int i=K1+1; i<=N; i++) 
	{
		S0[i]=S1[i-1];
		S1[i]=0;
		for(int j=K1; j<=K2; j++)
		{
			if (i-j>=0) S1[i]=S1[i] + S0[i-j];
		}
	}
	int rs = S0[N]+S1[N];
	cout << rs;
}
int main () 
{
	cin >> N >> K1 >> K2;
	solve();
}