//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        // code here
         unordered_map<char,int>mp;
        for(auto it:s){
            mp[it]++;
        }
        int count=0;
        for(auto it:mp){
            int a=(it.first-'a')+1;
            if(a%2==0 && it.second%2==0){
                count++;
            }
            else if(a%2==1 && it.second%2==1){
                count++;
            }
        }
        return count%2==0?"EVEN":"ODD";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends