//given a sequence of integers a1, a2, ..., an. given positive integers k and m. compute the number Q ways to select k elements from the sequence such that the sum of selected elements is equal to m.
#include <iostream>
#include <vector>

using namespace std;

int waysToSelect(vector<int>& a, int n, int k, int m) {
  vector<vector<int>> dp(k + 1, vector<int>(m + 1));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = min(i, k); j >= 1; j--) {
      for (int t = a[i - 1]; t <= m; t++) {
        dp[j][t] += dp[j - 1][t - a[i - 1]];
      }
    }
  }
  return dp[k][m];
}

int main() {
  int n, k, m;
  cin >> n >> k >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  cout << waysToSelect(a, n, k, m) << endl;
  return 0;
}


