class Solution {
    vector<int> nsl_a(vector<int>&histogram, int n){
        stack<int> st;
        vector<int> nsl(n,-1);

        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && histogram[i] <= histogram[st.top()]){
                st.pop();
            }

            nsl[i] = st.empty() ? 0 : st.top()+1;
            st.push(i);
        }
        return nsl;
    }

    vector<int> nsr_a(vector<int> &histogram, int n){
        stack<int> st;
        vector<int> nsr(n,-1);

        for(int i = n-1 ; i>=0 ; i--){
            while(!st.empty() && histogram[i] <= histogram[st.top()]){
                st.pop();
            }

            nsr[i] = st.empty() ? n-1 : st.top()-1;
            st.push(i);
        }
        return nsr;
    }

    int find_largestArea(vector<int> &histogram, int n){

        vector<int> nsl = nsl_a(histogram,n);
        vector<int> nsr = nsr_a(histogram,n);

        int area = 0;

        for(int i = 0 ; i < n ; i++){
            area = max(area, (histogram[i]) * (nsr[i]-nsl[i]+1));
        }
        return area;
    }    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // Write your code here.
        int n = matrix.size();
        int m = matrix[0].size();
        if(n==0) return 0;

        int result = 0;

        vector<int> histogram(m,0);

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(matrix[i][j] == '1') histogram[j]+=1;
                else histogram[j] = 0;
            }
            result = max(result,find_largestArea(histogram,m));
        }
        
        return result;        
    }
};