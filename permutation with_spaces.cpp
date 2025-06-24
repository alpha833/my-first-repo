#include <bits/stdc++.h>
using namespace std;

void solve(string ip, string op) {
    // Base case
    if (ip.length() == 0) {
        cout << op << endl;
        return;
    }

    // Option 1: Add space before next character
    string op1 = op + ' ' + ip[0];

    // Option 2: Add character without space
    string op2 = op + ip[0];

    // Remove the processed character from input
    ip.erase(ip.begin() + 0);

    // Recursive calls
    solve(ip, op1);
    solve(ip, op2);
}

int main() {
    string ip;
    cin >> ip;

    string op = "";
    op.push_back(ip[0]); // Start with the first character
    ip.erase(ip.begin() + 0);

    solve(ip, op);
    return 0;
}
