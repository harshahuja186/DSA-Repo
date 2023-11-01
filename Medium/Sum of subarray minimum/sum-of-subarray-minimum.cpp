//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    vector<int> nsl_indices(vector<int> arr, int n){
        vector<int> nsl(n,-1);
        stack<int> st;
    
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(!st.empty()) nsl[i] = st.top();
            st.push(i);
        }
        return nsl;
    }
    
    
    vector<int> nsr_indices(vector<int> arr, int n){
        stack<int> st;
        vector<int> nsr(n,n);
    
        for(int i = n-1 ; i >= 0 ; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty()) nsr[i] = st.top();
            st.push(i);
        }
        return nsr;
    }    
  public:
    int sumSubarrayMins(int n, vector<int>&arr) {
        long sum = 0;
        int MOD = 1e9+7;
    
        vector<int> nsl = nsl_indices(arr, n);
        vector<int> nsr = nsr_indices(arr, n);
    
        for(int i = 0 ; i < n; i++){
            int ls = i-nsl[i];
            int rs = nsr[i]-i;
    
            int totol_ways = ls * rs;
            sum = (sum + (static_cast<long>(arr[i]) * totol_ways))%MOD;
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.sumSubarrayMins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends