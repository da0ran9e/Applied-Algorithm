#include <stdio.h>
#include<algorithm>

#define MOD 1000000007

int combination(int n, int k) {
    k = (k < n-k) ? k : n-k;
    int a[k], b[k], g;
    long long result = 1;
    for (int i = 0; i < k; i++) {
        a[i] = n-k+1+i;
        b[i] = i+1;
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (b[i] == 1) break;
            g = std::__gcd(b[i], a[j]);
            a[j] = a[j]/g;
            b[i] = b[i]/g;
        }
    }
    for (int i = 0; i < k; i++) {
        result = (result*a[i])%MOD;
    }
    return result;
}

int main() {
    int k, n;
    scanf("%d %d", &k, &n);
    printf("%d\n", combination(n, k));
    return 0;
}
