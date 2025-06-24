#include <bits/stdc++.h>
using namespace std;

void solve(string ip, string op) {
    // Base case
    if (ip.length() == 0) {
        cout << op << endl;
        return;
    }

    // Initilize with same output above
    string op1 = op;
    string op2 = op;

    // First add with small then capital
    op1.push_back(ip[0]);
    op2.push_back(toupper(ip[0]));
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
    solve(ip, op);
    return 0;
}
