#include<bits/stdc++.h>
using namespace std;


int n, X;
int d[10];
int i, S;
int mem[10][1000];

int opt(int i, int S)
{
	if (i<0) return 9999999;
	if (S==0) return 0;
	if (S<0) return 9999999;

	if (mem[i][S]!=-1) return mem[i][S];
	int res = min(opt(i-1,S),1+opt(i,S-d[i]));
	mem[i][S]=res;
	return res;
}

void trace(int i, int S)
{
	if (i<0) return;
	if (S==0) return;
	if (S<0) return;

	if (mem[i][S] == mem[i-1][S]) trace(i-1,S);
	else
	{
		cout << d[i] << " ";
		trace(i, S-d[i]);
	}
}
 
int main()
{
	memset(mem, -1, sizeof(mem));
	cin >> n;
	for (int i=0; i<n; i++) cin >> d[i];
	cin >> X;
	int res = opt(n-1, X);
	cout << res << endl;
	trace(n-1, X);
	for (int i=n-1, k=1; k<=res; k++)
	{
		if (mem[i][X] == 1 + mem[i][X-d[i]])
		{
			cout<<d[i]<<" ";
			X=X-d[i];
		}
		else i--;
	}
}