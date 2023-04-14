#include <stdio.h>

void generate(int n, int m, int* collection, int index) {
    int sum=0;
    if (m == 0) {
        // Print the current collection
        for (int i = 0; i < n; i++) {
            printf("%d", collection[i]);
            if (i != n - 1) {
                printf(" ");
            }
        }
        printf("\n");
        return;
    }


    if (index == n) {
        return;
    }

    for (int i = 1; i <= m+1; i++) {
        collection[index] = i;
        generate(n, m - i, collection, index + 1);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int collection[n];
    generate(n, m, collection, 0);

    return 0;
}
