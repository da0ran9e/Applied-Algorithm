#include <stdio.h>


int main()
{
	int n;
	float c, m;
	scanf("%d %f", &n, &m);
	m=m/1000;
	if (n==0)
	{
		c = 0.95;
	}
	else if (n==1)
	{
		if (m<=3.2) c = 0.95;
		else if (m<=6.2) c = 0.95 + 0.1*(m-3.2);
		else if (m>6.2 && m<=20.2) c = 0.95 + 0.1*3 + 0.05*(m-6.2);
		else if (m>20.2) c = 0.95 + 0.1*3 + 0.05*14 + 0.01*(m-20.2);
	}
	else if (n==2)
	{
		if (m<=3.2) c = 1.55;
		else if (m<=6.2) c = 1.55 + 0.1*(m-3.2);
		else if (m>6.2 && m<=20.2) c = 1.55 + 0.1*3 + 0.05*(m-6.2);
		else if (m>20.2) c = 1.55 + 0.1*3 + 0.05*14 + 0.01*(m-20.2);
	}
	printf("%.4f", c);
	return 0;
}