/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  int solve(Node* node){
      if(node==NULL){
          return 0;
      }
      
      int left=solve(node->left);
      int right=solve(node->right);
      return 1+max(left,right);
  }
    int height(Node* node) {
        
        return solve(node)-1;
    }
};