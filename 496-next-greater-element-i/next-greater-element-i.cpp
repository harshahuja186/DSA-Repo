class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int,int> ans;
        stack<int> st;

        for(int i = n-1 ; i>=0 ; i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            if(st.empty()) ans[nums2[i]] = -1;
            else ans[nums2[i]] = st.top();

            st.push(nums2[i]);
        }

        vector<int> output(nums1.size(),-1);
        for(int i = 0 ; i < nums1.size(); i++){
            output[i] = ans[nums1[i]];
        }
        return output;
    }
};