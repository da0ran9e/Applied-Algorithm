#include <iostream>
#include <vector>

using namespace std;



int merge(vector<int>& arr, int left, int mid, int right) {
    int i, j, k;
    int inv_count = 0;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
            inv_count += (mid - i + 1);
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    return inv_count;
}

int mergeSort(vector<int>& arr, int left, int right) {
    int mid, inv_count = 0;
    if (right > left) {
        mid = (right + left) / 2;
        inv_count = mergeSort(arr, left, mid);
        inv_count += mergeSort(arr, mid + 1, right);
        inv_count += merge(arr, left, mid + 1, right);
    }
    return inv_count;
}

int main() {
    int N;
    vector<int> arr;
    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    int n = arr.size();
    cout << mergeSort(arr, 0, n - 1) << endl;
    return 0;
}
