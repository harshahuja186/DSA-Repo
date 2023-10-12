//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {

int findMaxDistance(unordered_map<Node*, Node*> parent_track, Node* start){
    int maxi = 0;
    queue<Node*> q;
    q.push(start);
    unordered_map<Node*, bool> visited;
    visited[start] = true;

    while(!q.empty()){
        bool flag = false;
        int size = q.size();

        for(int i = 0 ; i < size ; i++){
            Node* current = q.front();
            q.pop();
            if(current->left && !visited[current->left]){
                q.push(current->left);
                visited[current->left] = true;
                flag = true;
            }
            if(current->right && !visited[current->right]){
                q.push(current->right);
                visited[current->right] = true;
                flag = true;
            }
            if(parent_track[current] && !visited[parent_track[current]]){
                q.push(parent_track[current]);
                visited[parent_track[current]] = true;
                flag = true;
            }
        }
        if(flag==true) maxi++;
    }
    return maxi;
}

Node* mark_parents(Node* root, unordered_map<Node*, Node*>& parent_track, int target) {
    queue<Node*> q;
    q.push(root);
    Node* goal;
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        if(current->data == target) goal = current;
        if (current->left) {
            parent_track[current->left] = current;
            q.push(current->left);
        }
        if (current->right) {
            parent_track[current->right] = current;
            q.push(current->right);
        }
    }
    return goal;
}

    
  public:
    int minTime(Node* root, int target) 
    {
        unordered_map<Node*,Node*> parent_track;
        Node* goal = mark_parents(root,parent_track,target);
        int maxi = findMaxDistance(parent_track,goal);
        return maxi; 
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends