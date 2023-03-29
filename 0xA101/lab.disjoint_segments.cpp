#include<bits/stdc++.h>
using namespace std;

#define maxn 1000005

int n;
pair<int, int> a[maxn];

bool cmp(pair<int, int> t1, pair<int, int> t2)
{
	return t1.second < t2.second;
}

int greedy(const vector<pair<int, int>> &c, int n)
{
	int s=0;
	int last = -1;

	for (int i=0; i<n; i++)
	{
		if (last < c[i].first)
			{
				cout << c[i].first << " " << c[i].second << endl;
				s += 1;
				last = c[i].second;
			}
	}
	return s;
}

int main ()
{
	cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a+n, cmp);
	int last = -1;
	int res = 0;
	for (int k=0; k<n; k++)
	{
		if (last <= a[k].first)
		{
			res ++;
			last = a[k].second;
		}
	}
	greedy(a, res);
}