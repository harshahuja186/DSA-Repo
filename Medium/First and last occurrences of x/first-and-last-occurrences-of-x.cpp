//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    { 
      vector<int> ans;
        int left=0,right=n-1;
        while(right>=left)
        {
            int mid=(left+right)/2;
            if(arr[mid]==x)
            {   
                if(arr[mid-1]==x)
                right=mid-1;
                else
                {ans.push_back(mid); break;}
            }
            else if(arr[mid]>x)
            right=mid-1;
            else
            left=mid+1;
        }
        right=n-1;
        left=0;
        while(right>=left)
        {
            int mid=(left+right)/2;
            if(arr[mid]==x)
            {   
                if(arr[mid+1]==x)
                left=mid+1;
                else
                {ans.push_back(mid); break;}
            }
            else if(arr[mid]>x)
            right=mid-1;
            else
            left=mid+1;
        } 
        if(ans.size()==0){
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends