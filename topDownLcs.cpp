#include<bits/stdc++.h>
using namespace std;

int lcs(string x , string y){
    int m = x.size();
    int n = y.size();

    vector<vector<int>>dp(n+1 , vector<int>(m+1 , 0));

    for(int i=1; i<m+1; i++){
        for(int j=1; j<n+1; j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max((dp[i-1][j]),dp[i][j-1]);
            }
        }

        
    }
    return dp[n][m];

    
}