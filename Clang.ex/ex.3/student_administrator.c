#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include"student.h"

int c;
int index=0;
int foot=0;
char line[MAX_N];
char table[MAX_N][MAX_N];
int namelen;

void options(int option)
{
	int maxlen=-1;
	char name[MAX_N];
	float grade;
		if(option==49||option==50)
		{
			FILE *list;
    		list = fopen("SV2023.dat", "r");
    		    if (list == NULL) {
        		printf("Dữ liệu trống\n");
    		}
    		while(fscanf(list, "%s", line)&&line[0]!='#'){
    		fscanf(list, "%s", line);
    		namelen = strlen(line);
    		if(namelen>maxlen) maxlen=namelen+4;
    		for(int i=0; i<namelen; i++)
    		{
    			if(line[i]<=57&&line[i]>=48) table[index][MAX_N-1]=line[i];
    			else{
    				table[index][i]=line[i];
    			}
    		}
    		if(option==49)
    		{
    			printf("%c", 201);
    			while(maxlen--) printf("%c", 205);
    			printf("%c", 203);
    			printf("%5.c", 205);
    			printf("%c\n", 187);
    			printf("%c", 186);
    			int tagloc = maxlen/2-1;
    			while(tagloc--) printf("%c",032);
    			printf("Name");
    			while(tagloc--) printf("%c",032);
    			printf("%c", 186);
    			printf("grade");
    			printf("%c", 186);

    		}
    		if(option==50)
    		{
    			printf("Nhập thêm sinh viên bằng cấu trúc ` tên, điểm `");
    		}
    	}

    		fclose(list);
		}
}

int main()
{
	int option;
// giao diện
	printf("Chương trình quản lý sinh viên\n");
	int bar=30;
	while(bar--) printf("-");
	printf("\n1.Xem danh sách sinh viên\n2.Nhập thêm sinh viên\n3.Tìm sinh viên\n4.Thoát\n");
// người dùng chọn
	scanf("%c", &option);
	while(option!=52)
	{
		printf("1");
		
		options(option);
		scanf("%c", &option);
	}
	return 0;
}

