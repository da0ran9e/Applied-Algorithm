#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

// viết hàm giải bài toán cái túi dùng thuật toán Dynamic programming
#define MAX_N 101
#define EPSILON 0.0001

int cnt[MAX_N][MAX_N]={0};
int dp[MAX_N][10001];
int opindex=0;
int opsol=INT_MAX;
int sol[MAX_N][MAX_N];
int x[MAX_N];
int index=0;
int unboundedKnapsack(int W, int wt[], int val[], int idx, int n) {
  // nếu idx=0 (chỉ có 1 item để chọn).
    int cases = 0;
  if (idx == 0) {
    return (W / wt[0]) * val[0];
  }
// nếu giá trị đã được tính toán 
  if (dp[idx][W] != -1)
    return dp[idx][W];
// Chia bài toán roa thành 2 trường hợp
  int notTake = 0 + unboundedKnapsack(W, wt, val, idx - 1, n);
// nếu lấy thì weight = W-wt[idx] và index không đổi
  int take = INT_MIN;
  if (wt[idx] <= W) {
    take = val[idx] + unboundedKnapsack(W - wt[idx], wt, val, idx, n);
  }
  return dp[idx][W] = (take > notTake) ? take : notTake;
}
//từ giá trị lớn nhất tìm được, tìm ra tất cả cách chọn đồ vật bằng thuật toán bruce force
void find_solutions(int i, int n, int M, int a[]) {
  int j;

  if (i == n) {
    int sum = 0;
    for (j = 0; j < n; j++) {
      sum += a[j] * x[j];
    }
    if (fabs(sum - M) < EPSILON) {
      for (j = 0; j < n; j++) {
        sol[index][0] += x[j];
        sol[index][j+1]= x[j];
      }
//chọn ra phương pháp chọn tối ưu nhất sao cho không phải chọn quá nhiều đồ vật mà vẫn có thể có giá trị lớn nhất 
      if(opsol>sol[index][0])
      {
        opsol = sol[index][0];
        opindex = index;
      }
      index++;
    }
  } else {
    for (j = 0; j <= M / a[i]; j++) {
      x[i] = j;
      find_solutions(i + 1, n, M, a);
    }
  }
}

int main() {
    int N, W;
//mở file BAG.INP để đọc 
    FILE *inp;
    inp = fopen("BAG.INP", "r");
    if (inp == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    fscanf(inp, "%d %d", &N, &W);
    int g[N], v[N];
    char n[N];
    for (int i=0; i<N; i++){
        fscanf(inp, "%d %d %c", &g[i], &v[i], &n[i]);
    }

//khỏi tạo ma trận quy hoạch động với mỗi cell bằng -1 tức là chưa được tính toán 
    for (int i = 0; i < N + 1; i++) {
        for (int j = 0; j < W + 1; j++) {
          dp[i][j] = -1;
        }
      }
    int res = unboundedKnapsack(W, g, v, N-1, N);
    printf("%d", res);
    find_solutions(0, N, res, v);
    for(int k=1; k<=N; k++){
        if(sol[opindex][k]!=0){
            printf("\n%c  ", n[k-1]);
            printf("%d ", sol[opindex][k]);
        }
        }
    fclose(inp);
    return 0;
}
