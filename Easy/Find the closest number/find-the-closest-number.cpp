//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
   public:
    int findClosest(int n, int k, int arr[]) 
    { 
        // Edge case: single element in array
        if (n == 1) return arr[0];

        // Initialize pointers for binary search
        int s = 0;
        int e = n - 1;
        
        while (s < e) {
            int mid = s + (e - s) / 2;

            // If we find the exact element, return it
            if (arr[mid] == k) return arr[mid];

            if (arr[mid] < k) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }

        // Post-processing to determine the closest value
        // s and e should converge to the closest candidate
        // If we exit the loop with s == e, we have a candidate
        // We need to check if the previous element might be closer or not
        if (s == 0) {
            return arr[0];
        } else if (s == n) {
            return arr[n - 1];
        } else {
            int left = arr[s - 1];
            int right = arr[s];
            
            // Compare both elements to find the closest
            if (abs(left - k) == abs(right - k)) {
                return max(left, right);
            } else if (abs(left - k) < abs(right - k)) {
                return left;
            } else {
                return right;
            }
        }
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends