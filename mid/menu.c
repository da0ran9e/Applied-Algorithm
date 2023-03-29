#include<stdio.h>

void chosen()
{
	char c;
		while(scanf("%c", &c), c!='4' ){scanf("%c", &c);
                if(c=='1') {printf("Bạn đã thực hiện chức năng Nhập.\n"); chosen();}
                else if(c=='2') {printf("Bạn đã thực hiện chức năng In\n"); chosen();}
                else if(c=='3') {printf("Bạn đã thực hiện chức năng Sắp xếp\n"); chosen();}
                else {printf("Vui lòng chọn từ 1 tới 4\n"); chosen();}}
}

int main(){
	printf("1. Nhập\n2. In ra\n3. Sắp xếp\n4. Thoát\n");
	chosen();
	return 0;
}