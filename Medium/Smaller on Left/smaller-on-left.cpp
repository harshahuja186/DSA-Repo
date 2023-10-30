//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


vector<int> Smallestonleft(int arr[], int n);


int main() {
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n;
	    cin >> n;
	    int arr[n+1];
	    
	    for(int i=0;i<n;i++){
	        cin>> arr[i];
	    }
	    
	    vector<int> b;
	    b = Smallestonleft(arr, n);
	    for(int i=0;i<n;i++)
	        cout << b[i] << " ";
	       
	    cout << endl;
	    
	    
	}
	
	return 0;
}
// } Driver Code Ends


vector<int> Smallestonleft(int arr[], int n) {
    vector<int> result;
    set<int> elements;

    for (int i = 0; i < n; i++) {
        auto it = elements.lower_bound(arr[i]); // Find the smallest or equal element to the current element.
        
        if (it == elements.begin()) {
            result.push_back(-1); // No smaller element to the left.
        } else {
            --it; // Move to the smaller element.
            result.push_back(*it); // Store the smaller element to the left.
        }

        elements.insert(arr[i]); // Insert the current element into the set.
    }

    return result;
}
