#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, int W, vector<int> &wt, vector<int> &val) {
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (wt[i-1] <= j) {
                int pick = val[i-1] + dp[i-1][j - wt[i-1]];
                int notPick = dp[i-1][j];
                dp[i][j] = max(pick, notPick);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n = 3;
    int W = 50;
    vector<int> wt = {10, 20, 30};
    vector<int> val = {60, 100, 120};

    cout << "Max value: " << knapsack(n, W, wt, val) << endl;
    return 0;
}
