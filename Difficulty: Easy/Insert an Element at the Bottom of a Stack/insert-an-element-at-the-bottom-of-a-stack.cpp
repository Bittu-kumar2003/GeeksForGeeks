//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    // solve using the recursion 
public:
   // Recursive function to push an element at the bottom of the stack
void solve(stack<int> &st, int x) {
    // Base case: If the stack is empty, push the element and return
    if (st.empty()) {
        st.push(x);
        return;
    }

    // Store the top element and remove it
    int num = st.top();
    st.pop();

    // Recursive call to reach the bottom of the stack
    solve(st, x);

    // Push the stored element back on the stack
    st.push(num);
}

    stack<int> insertAtBottom(stack<int> st,int x){
        solve(st,x);
        return st;
        
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n;
        cin>>x;
        stack<int> st;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            st.push(a);
        }
        Solution ob;
        stack<int> tmp=ob.insertAtBottom(st,x);
        vector<int> v;
        while(tmp.size()){
            v.push_back(tmp.top());tmp.pop();
        }
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            cout<<v[i];
            if(i!=v.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    
cout << "~" << "\n";
}
    
    return 0;
}
// } Driver Code Ends