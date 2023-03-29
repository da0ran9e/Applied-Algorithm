#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int maxSum = 0, currentSum = 0;
    for (int i = 0; i < n; i++) {
        currentSum = max(a[i], currentSum + a[i]);
        maxSum = max(maxSum, currentSum);
    }
    cout << maxSum << endl;
    return 0;
}
