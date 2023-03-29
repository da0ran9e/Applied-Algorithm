#include <stdio.h>


long recurse(long n){
	if (n < 10) return n;

	n = 10 * recurse(n / 10) + n % 10;

	int r = n % 10;
	int l = n / 10 % 10;
	if (l == r)
		n = n / 10;

	printf("%ld\n", n);
	return n;
}

int main(){
	long n;
	long res;

	scanf(" %ld", &n);
	if (n < 0)
		res = -recurse(-n);
	else
		res = recurse(n);
	printf("%ld\n", res);

	return 0;
}