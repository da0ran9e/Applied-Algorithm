#include <iostream>
#include <algorithm>
using namespace std;

void permute(int n, int* perm) {
    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
    }
    do {
        for (int i = 0; i < n; i++) {
            cout << perm[i] << ' ';
        }
        cout << endl;
    } while (next_permutation(perm, perm + n));
}

int main() {
    int n;
    cin >> n;
    int* perm = new int[n];
    permute(n, perm);
    delete[] perm;
    return 0;
}
