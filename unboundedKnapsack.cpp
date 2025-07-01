int unboundedknapsack(int n, int W, vector<int> &wt, vector<int> &val) {
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (wt[i-1] <= j) {
                int pick = val[i-1] + dp[i][j - wt[i-1]]; 
                int notPick = dp[i-1][j];
                dp[i][j] = max(pick, notPick);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][W];
}
