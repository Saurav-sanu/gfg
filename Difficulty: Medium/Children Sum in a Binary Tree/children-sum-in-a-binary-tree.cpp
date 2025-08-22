/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
  public:
  
    int isSumProperty(Node *root) {
        if(root==NULL){
            return 1;
        }
         if(root->left==NULL && root->right==NULL){
         return 1;
         }
        
        int sum=0;
        int left=isSumProperty(root->left);
        int right=isSumProperty(root->right);
        if(left==0 || right==0){
          return 0;
        }
        
        if(root->left!=NULL){
            sum+=root->left->data;
        }
        if(root->right!=NULL){
            sum+=root->right->data;
        }
        
        if(sum==root->data){
            return 1;
        }
        return 0;
        
        
    }
};