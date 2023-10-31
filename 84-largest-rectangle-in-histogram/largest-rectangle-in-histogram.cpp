class Solution {
public:
    vector<int> nsl_a(vector<int> &heights, int n){
    stack<int> st;
    vector<int> nsl(n,-1);

    for(int i = 0 ; i < n ; i++){
        while(!st.empty() && heights[i] <= heights[st.top()]){
        st.pop();
        }

        nsl[i] = st.empty() ? 0 : st.top()+1;
        st.push(i);
    }
    return nsl;
    }
    
    vector<int> nsr_a(vector<int> &heights, int n){
    stack<int> st;
    vector<int> nsr(n,-1);

    for(int i = n-1 ; i >= 0 ; i--){
        while(!st.empty() && heights[i] <= heights[st.top()]){
        st.pop();
        }

        nsr[i] = st.empty() ? n-1 : st.top()-1;
        st.push(i);
    }
    return nsr;
    }
    
    int largestRectangleArea(vector < int > & heights) {
    // Write your code here.
    int n = heights.size();
        vector<int> nsl = nsl_a(heights,n);
        vector<int> nsr = nsr_a(heights,n);

        int area = 0;

        for(int i = 0 ; i < n ; i++){
        area = max(area,(heights[i])*(nsr[i]-nsl[i]+1));
        }
        return area;
    }
};