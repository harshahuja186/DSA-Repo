//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        // code here
        vector<int> ans;
        
        for(int &a : asteroids){
            while(!ans.empty() && a < 0 && ans.back() > 0){
                if(abs(a) > ans.back()){
                    ans.pop_back();
                }else if(abs(a) == ans.back()){
                    a = 0;
                    ans.pop_back();
                    break;
                }else{
                    a = 0;
                    break;
                }
            }
            if(a!=0) ans.push_back(a);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends