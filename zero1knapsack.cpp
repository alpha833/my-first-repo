int knapsack(int wt[], int val[], int W, int n) {
    if (n == 0 || W == 0)
        return 0;

    if (wt[n-1] <= W) {
        // Option 1: Pick the item
        int pick = val[n-1] + knapsack(wt, val, W - wt[n-1], n - 1);
        // Option 2: Don't pick the item
        int notPick = knapsack(wt, val, W, n - 1);
        return max(pick, notPick);
    } else {
        // Can't pick the item
        return knapsack(wt, val, W, n - 1);
    }
}
