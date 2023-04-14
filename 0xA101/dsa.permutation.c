#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void permute(int arr[], int start, int end) {
    if (start == end) {
        for (int i = 0; i <= end; i++) {
            printf("%d", arr[i]);
            if (i != end) {
                printf(" ");
            }
        }
        printf("\n");
    } else {
        for (int i = start; i <= end; i++) {
            swap(&arr[start], &arr[i]);
            permute(arr, start+1, end);
            swap(&arr[start], &arr[i]);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i+1;
    }

    permute(arr, 0, n-1);

    return 0;
}
