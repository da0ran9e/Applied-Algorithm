#include<bits/stdc++.h>
using namespace std;


int main(){
	int count=0;
	for (int a=1; a<=200; a++)
	{
		if (a%2==0) count +=1;
		else if (a%3==0) count +=1;
	}
	cout << count;
}