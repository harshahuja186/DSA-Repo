//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    bool isOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/');
    }
  public:
    string preToInfix(string s) {
        // Write your code here
            stack<string> st;

            int n = s.length();
            for (int i = n - 1; i >= 0; i--) {
                if (isOperator(s[i])) {
                    string op1 = st.top();
                    st.pop();
                    string op2 = st.top();
                    st.pop();
                    string temp = "(" + op1 + s[i] + op2 + ")";
                    st.push(temp);
                } else {
                    st.push(string(1,s[i]));  // Convert char to string
                }
            }
        
            return st.top();
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends