//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/*The Node structure is defined as
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

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    public:
    int countNodes(Node* root) {
        int count = 0;
        Node* current = root;
    
        while (current != nullptr) {
            if (current->left == nullptr) {
                // No left child, count this node and move to the right
                count++;
                current = current->right;
            } else {
                // Find the in-order predecessor
                Node* pre = current->left;
                while (pre->right != nullptr && pre->right != current) {
                    pre = pre->right;
                }
    
                if (pre->right == nullptr) {
                    // Make threaded connection to the current node
                    pre->right = current;
                    current = current->left;
                } else {
                    // Remove the threaded connection and move to the right
                    pre->right = nullptr;
                    count++;
                    current = current->right;
                }
            }
        }
    
        return count;
    }

    int kthLargest(Node* root, int k) {
        
        Node* cur = root;
        int count = 0;
        int ksmall = -1;
        k = countNodes(root)-k+1;
    
        while(cur!=nullptr){
            if(cur->left==nullptr){
                count++;
                if(count==k){
                    ksmall = cur->data;
                }
                cur=cur->right;
            }else{
                Node* prev = cur->left;
                while(prev->right && prev->right!=cur){
                    prev = prev->right;
                }
    
                if(prev->right==nullptr){
                    prev->right = cur;
                    cur = cur->left;
                }else{
                    prev->right = nullptr;
                    count++;
                    if(count==k){
                        ksmall = cur->data;
                    }
                    cur = cur -> right;
                }
            }
        }
        return ksmall;
    }    
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int k;
        cin>>k;
        getchar();
        
        Solution ob;
        cout << ob.kthLargest( head, k ) << endl;
    }
    return 1;
}
// } Driver Code Ends