#include<stdio.h>
#include<string.h>

int main(){
//char line[51];
char from[20];
char to[20];
int amount;
int sum=0;
char time[20];
char atm[10];
	do{
		scanf("%s", from);
		if(strcmp(from, "#")==0) continue;
		scanf("%s %d %s %s", to, &amount, time, atm);
		sum+=amount;
		

	}while(from[0]!='#');
	printf("%d", sum);
}