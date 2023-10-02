class Solution {
public:
    bool check(vector<int>& a) {
        int n = a.size();
        if(n==0 or n==1) return true;
        
        for(int i = 0 ; i < n - 1; i++){
            if(a[i] > a[i+1]) {
                for(int j = i+1 ; j < n-1 ; j++){
                    if(a[j] > a[j+1] or a[j] > a[0]){
                        return false;
                    } 
                }
                if(a[n-1] > a[0]) return false;
            }
        }
        return true;
    }
};