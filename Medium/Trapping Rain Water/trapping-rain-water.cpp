//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // Write your code here.
    
        vector<int> ngr(n,-1);
        vector<int> ngl(n,-1);
    
        int maxi = INT_MIN;
        for(int i = n-1 ; i >= 0 ; i--){
            ngr[i] = max(maxi,arr[i]);
            maxi = ngr[i];
        }
    
        maxi = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            ngl[i] = max(maxi,arr[i]);
            maxi = ngl[i];
        }
    
    
        
        long long ans = 0;
        for(int i = 0 ; i < n ; i++){        
            ans+=(min(ngr[i],ngl[i]) - arr[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends