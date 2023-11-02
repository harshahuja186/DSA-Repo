class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        vector<int> ans;
        
        for(int &a : asteroids){

            while(!ans.empty() && a < 0 and ans.back() > 0){
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