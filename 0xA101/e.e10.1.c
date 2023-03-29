//write a function that reverse the array content. Use this function in a program that asks user to enter a list of floatting numbers
// Then reverse all these numbers whitout creating another array.
#include<stdio.h>

float Reverse(float arr[], int size)
{
	int a;
	for(int i=0; i<size/2; i++)
	{
		a=arr[i];
		arr[i]=arr[size-i-1];
		arr[size-i-1]=a;
	}
	return arr[size];
}
int main()
{
	int a;
	printf("Size of the list? \n");
	scanf("%d", &a);
	float arr[a];
	printf("Input the list: \n");
	for (int i=0; i<a; i++)
	{
		printf("%d: ", i+1);
		scanf("%f", &arr[i]);
	}
	printf("Reversed into: \n");
	arr[a] = Reverse(arr, a);
	for (int i=0; i<a; i++)
	{
		printf("%f   ", arr[i]);
	}
	scanf("%d");

	return 0;
}