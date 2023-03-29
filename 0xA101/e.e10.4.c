#include<stdio.h>

int Sort(int arr[], int size)
{
	for(int i=1; i<=a; i++)
	{
		for(int j=1; j<=a; j++)
		{
			if(arr[j]<arr[j+1])
			{
				int a = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = a;
			}
		}
	}
}