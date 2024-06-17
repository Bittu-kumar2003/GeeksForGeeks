//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string doIntersect(int p1[], int q1[], int p2[], int q2[]) {
        // code here
        double m1, c1, m2, c2;
        
        // Calculate the slopes and intercepts of the lines
        bool isVertical1 = (q1[0] - p1[0]) == 0;
        bool isVertical2 = (q2[0] - p2[0]) == 0;
        
        if (!isVertical1) {
            m1 = (q1[1] - p1[1]) / (double)(q1[0] - p1[0]);
            c1 = p1[1] - m1 * p1[0];
        }
        
        if (!isVertical2) {
            m2 = (q2[1] - p2[1]) / (double)(q2[0] - p2[0]);
            c2 = p2[1] - m2 * p2[0];
        }
        
        // Check if the lines are parallel
        if ((isVertical1 && isVertical2) || (!isVertical1 && !isVertical2 && m1 == m2)) {
            return "false"; // Lines are parallel
        }
        
        // Find the intersection point
        double ix, iy;
        if (isVertical1) {
            ix = p1[0];
            iy = m2 * ix + c2;
        } else if (isVertical2) {
            ix = p2[0];
            iy = m1 * ix + c1;
        } else {
            ix = (c2 - c1) / (m1 - m2);
            iy = m1 * ix + c1;
        }
        
        // Check if the intersection point is within both segments
        if (isBetween(p1[0], q1[0], ix) && isBetween(p1[1], q1[1], iy) &&
            isBetween(p2[0], q2[0], ix) && isBetween(p2[1], q2[1], iy)) {
            return "true";
        }
        
        return "false";
    }

private:
    bool isBetween(double a, double b, double c) {
        return min(a, b) <= c && c <= std::max(a, b);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p1[2], q1[2], p2[2], q2[2];
        cin >> p1[0] >> p1[1] >> q1[0] >> q1[1] >> p2[0] >> p2[1] >> q2[0] >> q2[1];
        // if (q2[1] == -2) {
        //     cout << "true" << endl;
        //     return 0;
        // }
        Solution ob;
        // int a = ob.doIntersect(p1, q1, p2, q2);
        // if (a)
        cout << ob.doIntersect(p1, q1, p2, q2) << "\n";
    }
}
// } Driver Code Ends