//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        unordered_map<int,pair<int,int>>mp;
        for(int i=0;i<arr.size();i++){
            int num = arr[i];
            if(mp.find(num)==mp.end()){ // num not present in map
                mp[num] = {i,i};
            }else{ // num present in map
                mp[num] = {mp[num].first,i};
            }
        }
        int maxi = INT_MIN;
        for(auto& m : mp){
            pair<int,int>value = m.second;
            int start = value.first;
            int end = value.second;
            maxi = max(maxi,(end-start));
        }
        
        
        return maxi;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);

        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends