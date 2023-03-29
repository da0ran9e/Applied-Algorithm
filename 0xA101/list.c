#include<stdio.h>
#include <string.h>
#define N_MAX 101

int index=0;
typedef struct
{
	char id[8];
	int year;
} Student;

int main(){
	int list;
	int true=1;
	Student student[N_MAX];
	int n;
	char input[13];
	printf("so luong sinh vien can nhap: ");
	scanf("%d", &n);
	while(n--)
	{
		printf("%d: ", index+1);
		scanf("%s %d", student[index].id, &student[index].year);
		index++;
	}
	for (int i = 0; i < index - 1; i++) {
	    for (int j = 0; j < index - i - 1; j++) {
	      	if (strcmp(student[j].id, student[j+1].id) > 0) {
		        Student cmp = student[j];
		        student[j] = student[j+1];
		        student[j+1] = cmp;
      }
    }
  }
	list = index;
	printf("\n\n Danh sach sinh vien\n");
  	for (int i = 0; i < index; i++) {
    	printf("\n%d: ", i + 1);
    	printf("%s\b %d", student[i].id, student[i].year);
    }
    scanf("%s");
}