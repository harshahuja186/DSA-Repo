//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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

class Solution
{
    public:
    vector<int> getInOrderTraversal(Node *root)
    {
        vector<int> ans;
        
        Node* cur = root;
        while(cur!=nullptr){
            if(cur->left==nullptr){
                ans.push_back(cur->data);
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
                    ans.push_back(cur->data);
                    cur = cur -> right;
                }
            }
        }
        return ans;
    }
    
    vector<int> merge_bsts(vector<int> &bst1, vector<int> &bst2){
        
        int i = 0 , j = 0;
        vector<int> ans;
    
        while(i<bst1.size() && j<bst2.size()){
            if(bst1[i]<=bst2[j]){
                ans.push_back(bst1[i++]);
            }else{
                ans.push_back(bst2[j++]);
            }
        }
        while(i<bst1.size()){
            ans.push_back(bst1[i++]);
        }
        while(j<bst2.size()){
            ans.push_back(bst2[j++]);
        }
        return ans;
    }
        

    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int> bst1 = getInOrderTraversal(root1);
        vector<int> bst2 = getInOrderTraversal(root2);
    
        vector<int> ans = merge_bsts(bst1,bst2);
        return ans;        
    }
};

//{ Driver Code Starts.
int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);
       Solution obj;
       vector<int> vec = obj.merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends