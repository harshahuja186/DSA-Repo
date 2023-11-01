//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat, int n) 
    {
        // int n = mat.size();
        int i;
        for(i = 0 ; i < n ; i++){
            bool flag = false;
            for(int col = 0 ; col < n ; col++){
                if(mat[i][col] == 1){
                    flag = true;
                    break;
                }
            }
            if(flag == true) continue;
            
            flag = false;
            
            for(int row = 0 ; row < n ; row++){
                if(row!=i && mat[row][i] == 0){
                    flag = true;
                    break;
                }
            }
            if(flag == true){
                continue;
            }else break;
        }
        return i<n ? i : -1;
    }
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
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends