//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    int floorSqrt(int n) {
        // Your code goes here
        int ans = 0;
        long long int start = 0;
        long long int end = n;
        long long int mid = start + (end - start) / 2;
        while (start <= end) {

            if (mid * mid == n) {
                return mid; // Perfect square case
            }

            if (mid * mid < n) {
                ans = mid; // Store potential floor value
                start = mid + 1;
            } else {
                end = mid - 1;
            }
            mid = start + (end - start) / 2;
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends