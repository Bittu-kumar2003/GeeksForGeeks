#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int firstElement(int n) {
        if(n==1 or n==2) return 1;
        long long a=1,b=1,ans=1,mod=1e9+7;
        for(int i=3;i<=n;i++)
        {
            ans=a+b;
            a=b;
            ans%=mod;
            a%=mod;
            b%=mod;
            b=ans;
        }
        return ans;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}
