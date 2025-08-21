/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  vector<int>result;
  void leftT(Node* root){
      //base case
      if(root == NULL || (root->left == NULL && root->right == NULL)) {
            return;
        }
      
      result.push_back(root->data);
      if(root->left){
          leftT(root->left);
      }
      else{
          leftT(root->right);
      }
  }
  void rightT(Node* root){
      //base case
      if(root == NULL || (root->left == NULL && root->right == NULL)) {
            return;
        }
      
      if(root->right){
          rightT(root->right);
      }
      else{
          rightT(root->left);
      }
      result.push_back(root->data);
  }
  void leafT(Node* root){
      //base case
      if(root==NULL){
          return;
      }
      
      if(root->left==NULL && root->right==NULL){
          result.push_back(root->data);
      }
      leafT(root->left);
      leafT(root->right);
  }
  
    vector<int> boundaryTraversal(Node *root) {
        // code herr
        if(root==NULL){
            return result;
        }   
        
        result.push_back(root->data);
        
        leftT(root->left);
        
        leafT(root->left);
        leafT(root->right);
        
        rightT(root->right);
        return result;
        
    }
};