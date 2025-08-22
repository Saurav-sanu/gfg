/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  vector<vector<int>>result;
  void traversal(Node* root,vector<int>&ans){
      //base case
      if(root==NULL){
          return ;
      }
      
      
      ans.push_back(root->data);
      if(root->left==NULL && root->right==NULL){
          result.push_back(ans);
          ans.pop_back();
          return;
      }
      traversal(root->left,ans);
      traversal(root->right,ans);
      ans.pop_back();
  }
    vector<vector<int>> Paths(Node* root) {
        vector<int>ans;
        traversal(root,ans);
        return result;
        
    }
};