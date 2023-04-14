#include <stdio.h>

int main() {
    int n, i;
    scanf("%d", &n);
    for (i = -n; i <= n; i++) {
        if (i == 0) continue;
        if (n % i == 0) printf("%d ", i);
    }
    printf("\n");
    return 0;
}
