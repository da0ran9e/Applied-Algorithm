// a sequence of integers a1, a2, ..., an. A k-subsequence is define to be a sequence of k consecutive elements ai, ai+1,... ai+k-1. the weight of a k-subsequence is the sum of all elements. give integers, k, A, B. compute number Q of k-subsequences such that the weight >= A and <=B
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k, A, B;
    cin >> n >> k >> A >> B;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int count = 0;
    for (int i = 0; i <= n - k; i++) {
        int sum = 0;
        for (int j = 0; j < k; j++) sum += a[i + j];
        if (sum >= A && sum <= B) count++;
    }
    cout << count << endl;
    return 0;
}
