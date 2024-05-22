//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    public:
    double calc(const vector<int> &a, int k, double mid) {
        int count = 0;
        int n = a.size();
        for (int i = 1; i < n; ++i) {
            double distance = a[i] - a[i - 1];
            if (distance > mid) {
                count += ceil(distance / mid) - 1;
            }
        }
        return count;
    }
    
    double findSmallestMaxDist(vector<int> &stations, int k) {
        double l = 0;
        double r = *max_element(stations.begin(),stations.end());
        double ans = DBL_MAX;
    
        while (r - l > 1e-6) {
            double mid = l + (r - l) / 2;
            if (calc(stations, k, mid) <= k) {
                ans = mid;
                r = mid;
            } else {
                l = mid;
            }
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
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
// } Driver Code Ends