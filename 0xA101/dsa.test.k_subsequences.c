#include <stdio.h>

#define MAX_N 100000
#define INF (-1u/2)

int n, k, a, b, x[MAX_N], sum[MAX_N], count;

void subarrays() {
    int f[MAX_N] = {0};

    for (int i = 1; i < n; i++) {
        f[i] = f[i-1] + x[i];
    }

    for (int i = k-1; i < n; i++) {
        int sum = f[i] - (i >= k ? f[i-k] : 0);
        if (sum >= a && sum <= b) {
            count++;
        }
    }

    printf("%d\n", count);
}

int main() {
    scanf("%d %d %d %d", &n, &k, &a, &b);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }

    count = 0;

    subarrays(); 

    return 0;
}
