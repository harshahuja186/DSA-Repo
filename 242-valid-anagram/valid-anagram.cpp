class Solution {
public:
    bool isAnagram(string str1, string str2) {
        int s1 = str1.length();
        int s2 = str2.length();

        if(s1!=s2) return false;

        unordered_map<char,int> mp;

        for(int i = 0 ; i < s1 ; i++){
            mp[str1[i]]++;
        }

        for(int i = 0 ; i < s1 ; i++){
            char ch = str2[i];
            if(mp.count(ch) == 0 or mp[ch] == 0) return false;
            else mp[ch]--;
        }
        return true;        
    }
};