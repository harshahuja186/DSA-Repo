class Solution {
public:
    int maxDepth(string s) {
        int open = 0;
        int max_open = 0;
        int n = s.length();
        for(int i = 0 ; i < n; i++){
            char ch = s[i];
            if(ch == '('){
                open++;
            }
            else if(ch == ')'){
                max_open = max(max_open , open);
                open--;
            }
        }
        return max_open;
    }
};