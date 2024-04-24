#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    const int MOD =1e9 +7;
    int ways(int x, int y)
    {
        x++; y++;
        vector<vector<int>> dp(x, vector<int> (y, 0));
        for(int i = 0 ; i < x ; i++) {
            dp[i][0] = 1;
        }
        for(int j = 0 ; j < y ; j++) {
            dp[0][j] = 1;
        }
        for(int i = 1 ; i < x ; i++) {
            for(int j = 1 ; j < y ; j++) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
        }
        return dp[x - 1][y - 1];
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}
