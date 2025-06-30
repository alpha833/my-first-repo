#include <bits/stdc++.h>
using namespace std;

int minimumsetDifference(int n, vector<int> &arr)
{
    int n = arr.size();
    int totalsum = accumulate(arr.begin(), arr.end(), 0);

    vector<vector<bool>> dp;
    dp.resize(n + 1);

    for (int i = 0; i < n; i++)
    {
        dp[i].resize(totalsum + 1, false);
    }

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < totalsum; j++)
        {
            if (arr[i] - j <= j)
            {
                int pick = dp[i][j] = dp[i - 1][j - arr[i - 1]];
                int notpick = dp[i - 1][j];
                dp[i][j] = pick || notpick;
            }

            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    vector<int> candidates;
    for(int s1=0; s1<totalsum/2; s1++){
        if(dp[n][s1]) candidates.push_back(s1);
    }
    int minDiff = INT_MAX;
    for (int s1 : candidates) {
        int s2 = totalsum - s1;
        minDiff = min(minDiff, abs(s2 - s1));
    }

    return minDiff;

}
int main() {
    vector<int> arr = {1, 6, 11, 5};
    
    return 0;
}