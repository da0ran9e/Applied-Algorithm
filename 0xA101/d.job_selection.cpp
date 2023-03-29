#include <iostream>
#include <algorithm>

using namespace std;

struct Job {
    int deadline;
    int profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    int n;
    cin >> n;
    Job *jobs = new Job[n];
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].deadline >> jobs[i].profit;
    }
    sort(jobs, jobs + n, compare);
    int maxProfit = 0;
    bool *slot = new bool[n];
    for (int i = 0; i < n; i++) {
        slot[i] = false;
    }
    for (int i = 0; i < n; i++) {
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if (slot[j] == false) {
                maxProfit += jobs[i].profit;
                slot[j] = true;
                break;
            }
        }
    }
    cout << maxProfit << endl;
    return 0;
}
