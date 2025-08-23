// Function to search a node in BST.
class Solution {

  public:
    int floor(Node* root, int x) {
        // Code here
        if(root==NULL){
            return -1;
        }
        if(root->data==x){
            return x;
        }
        
        if(root->data<x){
            int data=floor(root->right,x);
            if(data==-1){
                return root->data;
            }
            return data;
        }
        else{
            return floor(root->left,x);
        }
        
    }
};