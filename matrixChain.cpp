#include <bits/stdc++.h>

using namespace std;

int matrixChainRec(int arr[], int i, int j) {
    if (i >= j)
        return 0;

    int minCost = INT_MAX;

    for (int k = i; k < j; k++) {
        int cost = matrixChainRec(arr, i, k) +
                   matrixChainRec(arr, k + 1, j) +
                   arr[i - 1] * arr[k] * arr[j];

        minCost = min(minCost, cost);
    }

    return minCost;
}

int main() {
    int arr[] = {40, 20, 30, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum number of multiplications: "
         << matrixChainRec(arr, 1, n - 1) << endl;

    return 0;
}
