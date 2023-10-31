class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int maxi = INT_MIN;
        vector<int> ngl(n,0);
        vector<int> ngr(n,0);

        for(int i = 0 ; i < n ; i++){
            ngl[i] = max(maxi,height[i]);
            maxi = ngl[i];
        }
        maxi = INT_MIN;
        for(int i = n-1 ; i >= 0 ; i--){
            ngr[i] = max(maxi,height[i]);
            maxi = ngr[i];
        }

        int ans = 0;

        for(int i = 0 ; i< n ; i++){
            ans+=(min(ngr[i],ngl[i])-height[i]);
        }
        return ans;
    }
};