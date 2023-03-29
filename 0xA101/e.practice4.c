#include <stdio.h>

int sortmax(int n){
	if (n < 10) return n;

	int r = n % 10;
	int l = (n - r) / 10 % 10;

	int trysort = sortmax(n / 10 - l + r);
	int last = trysort % 10;

	if (l > last)
		return 10 * sortmax(trysort - last + l) + last;
	else
		return 10 * trysort + l;
}

int sortmin(int n){
	if (n < 10) return n;

	int r = n % 10;
	int l = (n - r) / 10 % 10;

	int trysort = sortmin(n / 10 - l + r);
	int last = trysort % 10;

	if (l < last)
		return 10 * sortmin(trysort - last + l) + last;
	else
		return 10 * trysort + l;
}

int main(){
	int n;
	int res;

	scanf("%d", &n);
	if (n < 0)
		res = -sortmin(-n);
	else
		res = sortmax(n);

	printf("%d\n", res);

	return 0;
}