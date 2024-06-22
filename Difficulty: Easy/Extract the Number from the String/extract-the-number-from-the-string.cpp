//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    public:
    long long ExtractNumber(string str) {

        // code here
        string _maxi;
        long long maxi = -1, temp;
        
        int i = 0, j = 0;
        
        while(i < str.size()){
            
            bool t = 0;
            
            if(str[i] >= '0' && str[i] <= '9'){
                
                while(i < str.size() && (str[i] >= '0' && str[i] <= '9')){
                    
                    if(str[i] == '9')   t = 1;
                    
                    i++;
                }
                
                if(!t){
                    
                    _maxi = str.substr(j, i-j);
                    
                    temp = stoll(_maxi);
                    
                    maxi = max(maxi, temp);
                }
            }
            i++;
            j = i;
        }
        
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends