class Solution {
long long min_sum(vector<int> &nums,int n){
    vector<int> nsl(n,-1);
    vector<int> nsr(n,n);
    stack<int> st;

    for(int i = 0 ; i < n ; i++){
        while(!st.empty() && nums[st.top()] >= nums[i]){
            st.pop();
        }
        if(!st.empty()) nsl[i] = st.top();
        st.push(i);
    }

    while(!st.empty()) st.pop(); // empty the stack

    for(int i = n-1 ; i>=0 ; i--){
        while(!st.empty() && nums[st.top()] > nums[i]){
            st.pop();
        }
        if(!st.empty()) nsr[i] = st.top();
        st.push(i);
    }

    long long min_sumation = 0;
    for(int i = 0 ; i < n ; i++){
        min_sumation+=(static_cast<long long>(nums[i]) * (i-nsl[i]) * (nsr[i]-i) * 1LL);
    }
    return min_sumation;
}

long long max_sum(vector<int> &nums,int n){
    vector<int> ngl(n,-1);
    vector<int> ngr(n,n);
    stack<int> st;

    for(int i = 0 ; i < n ; i++){
        while(!st.empty() && nums[st.top()] <= nums[i]){
            st.pop();
        }
        if(!st.empty()) ngl[i] = st.top();
        st.push(i);
    }

    while(!st.empty()) st.pop(); // empty the stack;

    for(int i = n-1 ; i >= 0 ; i--){
        while(!st.empty() && nums[st.top()] < nums[i]){
            st.pop();
        }
        if(!st.empty()) ngr[i] = st.top();
        st.push(i);
    }

    long long max_sumation = 0;
    for(int i = 0 ; i < n ; i++){
        max_sumation+=(static_cast<long long>(nums[i]) * (i-ngl[i]) * (ngr[i]-i) );
    }
    return max_sumation;
}    
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long max_sumation = max_sum(nums, n);
        long long min_sumation = min_sum(nums, n);

        return max_sumation - min_sumation;        
    }
};