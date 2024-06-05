//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        sort(a, a+n);
        sort(b, b+m);
        int sumA = accumulate(a, a+n, 0);
        int sumB = accumulate(b, b+m, 0);
        int last = -1;
        for(int i = 0; i < n; i++){
            if(last == a[i]){
                continue;
            }
            sumA -= a[i];
            sumB += a[i];
            int l = 0, r = m-1;
            while(l <= r){
                int mid = ((r-l)>>1)+l;
                if((sumA+b[mid]) == (sumB-b[mid])){
                    return 1;
                }
                else if((sumA+b[mid]) > (sumB-b[mid])){
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
            sumA += a[i];
            sumB -= a[i];
            last = a[i];
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends