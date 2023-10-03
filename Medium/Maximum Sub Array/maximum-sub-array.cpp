//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
 vector<int> findSubarray(int a[], int n) {
        
        int s=-1;
        int res=0;
        int sum=0;
        int fs=-1,fe=-1;
        
        for(int i=0;i<n;i++)
        {
           if(sum==0)
           {
               s=i;
           }
           
            sum+=a[i];
           
            if(sum>res && a[i]>0)
            {
                fs=s;
                fe=i;
                res=sum;
            }
            else if(a[i]>0 && sum==res && (i-s)>(fe-fs))
            {
                fs=s;
                fe=i;
            }
            
            if(a[i]<0)
            {
                sum=0;
            }
            
        }
        
        vector<int>ans;
        
        if(fs==-1 && fe==-1) return ans;
        
        for(int i=fs;i<=fe;i++)
        {
            ans.push_back(a[i]);
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends