//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n) {
        // code here
        int digit=0;
         double res=0.0;
         int num=n;
         while(num!=0){
         digit++;
         num=num/10;
      }    
         num=n;
         while(num!=0){
         int rem=num%10;
         res=res+pow(rem,digit);
         num=num/10;
        }
        
        if(res==n) return "true"; else return "false";
    }
        
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends