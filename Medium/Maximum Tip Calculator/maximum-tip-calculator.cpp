//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &a, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        // code here
          vector<pair<int,int>> abs_diff;
        
        for(int i=0;i<n;i++){
            int diff=abs(arr[i]-brr[i]);
            int ind=i;
            abs_diff.push_back({diff,ind});
        }
        
        sort(abs_diff.begin(),abs_diff.end());
        reverse(abs_diff.begin(),abs_diff.end());
        
        long long int ans=0;
        int x_orders=0;
        int y_orders=0;
        for(auto order:abs_diff){
            int ind=order.second;
            if((arr[ind]>brr[ind] && x_orders<x) || y_orders>=y){
                ans+=arr[ind];
                x_orders++;
            }else{
                ans+=brr[ind];
                y_orders++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}

// } Driver Code Ends