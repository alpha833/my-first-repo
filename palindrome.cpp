#include <iostream>
#include <climits>
using namespace std;

bool isPalindrome(string &s, int i, int j) {
    while (i < j)
        if (s[i++] != s[j--]) return false;
    return true;
}

// MCM-style recursion
int f(int i, int j, string &s) {
    if (i >= j || isPalindrome(s, i, j)) return 0;

    int minCuts = INT_MAX;
    for (int k = i; k < j; ++k) {
        if (isPalindrome(s, i, k)) {
            int cuts = 1 + f(k + 1, j, s);  // cut after k
            minCuts = min(minCuts, cuts);
        }
    }
    return minCuts;
}

int minCut(string s) {
    return f(0, s.size() - 1, s);
}

int main() {
    string s = "aab";
    cout << "Minimum cuts: " << minCut(s) << endl;
}
