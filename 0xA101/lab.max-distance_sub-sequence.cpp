#include<bits/stdc++.h>
using namespace std;
#define maxn 1000007

int N, C;
int t;
int x[maxn];

bool Check(int d)
{
	int sl = 1; 
	int i=1, j=2;
	while(i<N)
	{
		while(i<=N && x[j]-x[i] < d) ++j;
		if (j<N) sl++;
		if (sl>=C) return true;
		i=j;
		j++;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> t;
	while(t--)
	{
		cin >> N >> C;
		for (int i=1; i<=N; i++) cin >> x[i];
		sort(x+1, x+N+1);
		int low=0;
		int high=x[N]-x[1];
		while (low <=high)
		{
			int mid = (low+high)/2;
			if(Check(mid)) low = mid+1;
			else high = mid-1;
		}
		cout << high << endl;
	}
}
