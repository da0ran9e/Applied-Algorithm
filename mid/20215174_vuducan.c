#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 101

char bks[MAX_N][3];
int year[MAX_N];
char brand[MAX_N][20];
char line[30];
int index = 0;

typedef struct
{
	char bks[3];
	int year;
	char brand[20];
}car;



void Enter(int n){
	char name[20];
	for (int i=0; i<n; i++)
	{
		printf("%d. ", i+1);
		scanf("%s %d %s", line, &year[index], name);
		int len = strlen(name);
		for(int l=0; l<3; l++) bks[index][l]=line[l];

		for (int j=0; j<len; j++)
		{
			brand[index][j]=name[j];
		};
		index++;
	}
	printf("\n");
}
void Print()
{
	for(int i=0; i<index; i++)
	{
		for (int j=0; j<3; j++) printf("%c", bks[i][j]);
		printf("		%d	", year[i]);
		for (int k=0; brand[i][k]!='\0'; k++) printf("%c", brand[i][k]);
		printf("\n");
	}
}
void Count()
{
	int months[25]={0};
	int y=2023;
	int kd;
	for(int t=0; t<index; t++)
	{
		kd = y - year[t];
		if (kd<1&&kd>=0)months[24]++;
	}
}

void Options()
{
	int n;
	char option;
	scanf("%c", &option);
	if (option=='1')
	{
		printf("Số lượng: \n");
		scanf("%d", &n);
		Enter(n);
	}
	else if (option==2)
	{
		Print();
	}
	else if (option==3)
	{
		Count();
	}
	else if (option==4)
	{
		return;
	}
	else 
	{printf("cú pháp không hợp lệ!\n");}
	Options();
}

int main(){
	
	
	int bar = 20;
	printf("Menu: \n1. Enter\n2. Print\n3. Count\n4. Exit\n");
	while(bar--) printf("-");
	printf("\n");
	Options();
}