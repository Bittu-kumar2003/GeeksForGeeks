//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
         size_t firstNonZeroIndex = s.find_first_not_of("0");
        if (firstNonZeroIndex == string::npos) {
            return "1";
        }
        s = s.substr(firstNonZeroIndex);
        
        
        bool foundZero = 0;
        for (int i = s.length() - 1; i >= 0; i--){
            if(s[i] == '0'){
                s[i] = '1';
                foundZero = 1;
                for (int j = i + 1; j < s.length(); j++){
                    s[j] = '0';
                }
                break;
            }
        }
        if(!foundZero){
            string temp = "1";
            for (int i = 0; i < s.length(); i++){
                temp += '0';
            }
            s = temp;
        }
        return s;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends