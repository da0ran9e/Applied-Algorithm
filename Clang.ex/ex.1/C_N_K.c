#include <stdio.h>

// function tính tổ hợp chập k của n 
double combination(int n, int k) {
    double result = 1;
    int i;
    for (i = 1; i <= k; i++) {
        result = result * (n - k + i) / i;
    }
    return result;
}

int main() {
    int t;
    int n, k;
//mở file TOHOP.INP để đọc 
    FILE *inp;
    inp = fopen("TOHOP.INP", "r");
    if (inp == NULL) {
        printf("Error opening file\n");
        return 1;
    }
// nhập số lượn test case trong file TOHOP.INP
    printf("Enter number of test cases: \n");
    scanf("%d", &t);
    int a[t]; // mảng kết quả
    for (int i=0; i<t; i++){
        fscanf(inp, "%d %d", &n, &k);
        printf("Number of %d conminations of %d is: ", k,n);
        a[i] = combination(n, k);
        printf("%d \n", a[i]);

    }
    fclose(inp);
// mở file TOHOP.OUT để viết 
    FILE *out;
// clear file
    out = fopen("TOHOP.OUT", "w");
            fclose(out);
// mở lại file sau khi đã trống
            out = fopen("TOHOP.OUT", "w");
//viết kết quả tính được vào file
        for(int j=0; j<t; j++)
        {
            fprintf(out, "%d \n", a[j]);
        }
// lưu và đóng file
        fclose(out);

    return 0;
}
