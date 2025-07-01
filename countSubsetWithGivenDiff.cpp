#include <bits/stdc++.h>
using namespace std;

int countSubsetWithGivenDiff(int n, vector<int> arr, int diff) {
    int totalSum = accumulate(arr.begin(), arr.end(), 0);

    if ((totalSum + diff) % 2 != 0 || totalSum < diff)
        return 0;

    int target = (totalSum + diff) / 2;

    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    // Base Case: There is 1 way to make sum 0 — by choosing nothing
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= target; j++) {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][target];
}
