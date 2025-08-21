/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        map<int,int>mp;
        queue<pair<Node*, int>> q;
        q.push({root,0});
        
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            Node* r=top.first;
            int number=top.second;
            
            if(mp.find(number)==mp.end()){
                mp[number]=r->data;
            }
            
            if(r->left){
                q.push({r->left,number-1});
            }
            if(r->right){
                q.push({r->right,number+1});
            }
        }
        
        for(auto it:mp){
            ans.push_back(it.second);
        }
        
        return ans;
        
    }
};