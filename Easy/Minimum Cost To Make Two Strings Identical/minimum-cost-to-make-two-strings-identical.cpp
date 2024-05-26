//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findMinCost(string x, string y, int costX, int costY) {
        int n = x.size(), m = y.size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(i == 0 && j == 0) {
                    dp[i][j] = (x[i] == y[i] ? 0 : costX + costY);
                } else if(i == 0) {
                    dp[i][j] = (x[i] == y[j] ? costY * j : min(costX + (j+1)*costY, costY + dp[i][j-1]));
                } else if(j == 0) {
                    dp[i][j] = (x[i] == y[j] ? costX * i : min(costY + (i+1)*costX, costX + dp[i-1][j]));
                } else {
                    dp[i][j] = (x[i] == y[j] ? dp[i-1][j-1] : min(costX + dp[i-1][j], costY + dp[i][j-1]));
                }
            }
        }
        return dp[n-1][m-1];
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;

        int costX, costY;
        cin >> costX >> costY;

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends