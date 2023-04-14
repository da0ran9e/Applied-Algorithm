#include<stdio.h>

int main(){
    int n, k;
    scanf("%d", &n);
    int a[21], s[21];

    k=1;
    s[k]=0;
    while (k>0)
    {
        while (s[k]<=1)
        {
            a[k]=s[k];
            s[k]=s[k]+1;
            if (k==n)
            {
                for(int i=1; i<=n; i++)
                {
                    printf("%d", a[i]);
                }
                printf("\n");
            }
            else
            {
                k++, s[k]=0;
            }
        }
        k--;
    }
    return 0;
}
