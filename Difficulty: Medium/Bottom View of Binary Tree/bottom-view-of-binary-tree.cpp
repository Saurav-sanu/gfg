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
    vector<int> bottomView(Node *root) {
        vector<int>ans;
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            Node* root=top.first;
            int number=top.second;
            
            mp[number]=root->data;
            
            if(root->left){
                q.push({root->left,number-1});
            }
            if(root->right){
                q.push({root->right,number+1});
            }
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
        
    }
};