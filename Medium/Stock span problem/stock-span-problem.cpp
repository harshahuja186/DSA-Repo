//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector<int> ans(n,-1);
       stack<pair<int,int>> s;
       for(int i = 0;i < n; i++){
           while(!s.empty() and price[i] >= s.top().first) s.pop();
           if(s.empty()) ans[i] = i+1;
           else ans[i] = i - s.top().second;
           s.push({price[i],i});
       }
       return ans;
    }
    
    //Function to calculate the span of stockâ€™s price for all n days.
    // vector <int> calculateSpan(int prices[], int n)
    // {
    //     stack<int> st;
    //     vector<int> ans(n, -1);
    
    //     for (int i = 0; i < n; i++) {
    //         while (!st.empty() && prices[i] > prices[st.top()]) {
    //             st.pop();
    //         }
    
    //         ans[i] = st.empty() ? i + 1 : i - st.top();
    //         st.push(i);
    //     }
    //     return ans;
    // }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends