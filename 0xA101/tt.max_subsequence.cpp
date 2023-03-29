#include <iostream>
#include <vector>
using namespace std;

int maxSum(const vector<int> &arr) {
  int n = arr.size();
  int max_sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      int sum = 0;
      int k = i;
      while (k <= j) {
        sum += arr[k];
        k += 2;
      }
      max_sum = max(max_sum, sum);
    }
  }
  return max_sum;
}
int main() {
    int n;
    cin >> n;
int d;
  vector<int> arr;
  for (int i=0; i<n; i++)
  {
    cin >> d;
    arr.push_back(d);
  }
  cout << maxSum(arr) << endl;
  return 0;
}
