#include <bits/stdc++.h>
using namespace std;

void Print()
{
	for (int i=0; i<=7; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

void Try(int k)
{
	for (int i=1; i<=9; i++)
	{
		if (used[i]==0)
		{
			arr[k]=i;
			used[i]=1;
			if (k==7){
				
			}
		}
	}
}
