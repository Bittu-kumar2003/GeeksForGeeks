//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    string removeDups(string str) {
        // Your code goes here
        string ans = "";
         vector<int>f(26,0);
        //  How do you access the alpha bets according to the letter given !!
        for(auto &x : str ){
            
            if(f[x-'a']<1){
                ans+=x;
                f[x-'a']++;
            }
            
        }
        
        return ans ;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.removeDups(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends