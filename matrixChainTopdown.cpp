#include <bits/stdc++.h>

using namespace std;

const int MAX = 100;      // Maximum size of matrix chain
int dp[MAX][MAX];         // Global memoization table

int matrixChainMemo(int arr[], int i, int j) {
    if (i >= j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int minCost = INT_MAX;

    for (int k = i; k < j; k++) {
        int cost = matrixChainMemo(arr, i, k) +
                   matrixChainMemo(arr, k + 1, j) +
                   arr[i - 1] * arr[k] * arr[j];

        minCost = min(minCost, cost);
    }

    return dp[i][j] = minCost;
}

int main() {
    int arr[] = {10, 20, 30, 40, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Initialize dp to -1
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            dp[i][j] = -1;

    cout << "Minimum number of multiplications: "
         << matrixChainMemo(arr, 1, n - 1) << endl;

    return 0;
}
