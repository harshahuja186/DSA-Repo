//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    vector<long long> nsl_a(long long *heights, int n){
        stack<long long> st;
        vector<long long> nsl(n,-1);
    
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && heights[i] <= heights[st.top()]){
            st.pop();
            }
    
            nsl[i] = st.empty() ? 0 : st.top()+1;
            st.push(i);
        }
        return nsl;
    }
    
    vector<long long> nsr_a(long long *heights, int n){
        stack<long long> st;
        vector<long long> nsr(n,-1);
    
        for(int i = n-1 ; i >= 0 ; i--){
            while(!st.empty() && heights[i] <= heights[st.top()]){
            st.pop();
            }
    
            nsr[i] = st.empty() ? n-1 : st.top()-1;
            st.push(i);
        }
        return nsr;
    }
    

    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long heights[], int n) {
    // Write your code here.
        vector<long long> nsl = nsl_a(heights,n);
        vector<long long> nsr = nsr_a(heights,n);

        long long area = 0;

        for(int i = 0 ; i < n ; i++){
        area = max(area,(heights[i])*(nsr[i]-nsl[i]+1));
        }
        return area;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends