class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int i = 1 ; i <= s.length() ; i++){
            if(goal == s.substr(i) + s.substr(0,i)) return true;
        }
        return false;
    }
};