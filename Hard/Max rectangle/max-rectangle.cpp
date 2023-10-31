//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
    

    int find_largestArea(vector < int > & histo, int n) {
      stack < int > st;
      int maxA = 0;
      for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
          int height = histo[st.top()];
          st.pop();
          int width;
          if (st.empty())
            width = i;
          else
            width = i - st.top() - 1;
          maxA = max(maxA, width * height);
        }
        st.push(i);
      }
      return maxA;
    }
    
  public:
    int maxArea(int mat[MAX][MAX], int n, int m) {
    	// Write your code here.
    	if(n==0) return 0;
    
    	int result = 0;
    
    	vector<int> histogram(m,0);
    
    	for(int i = 0 ; i < n ; i++){
    		for(int j = 0 ; j < m ; j++){
    			if(mat[i][j] == 1) histogram[j]+=1;
    			else histogram[j] = 0;
    		}
    		result = max(result,find_largestArea(histogram,m));
    	}
    	
    	return result;
    }
};



//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends