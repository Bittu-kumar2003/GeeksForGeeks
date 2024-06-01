//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
         if (n == 1) {
            return 0;
        }
        
        int index = 0, end = 0, jump = 0, max = arr[0];
        
        while(index<=end) {
            if (index + arr[index] > max) {
                max = index + arr[index];
            }
            
            if (index == end) {
                if (max < n-1) {
                    end = max;
                    jump++;
                }
                else {
                    return ++jump;
                }
            }
            
            index++;
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends