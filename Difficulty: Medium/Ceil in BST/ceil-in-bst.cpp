class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
        if (root == NULL) return -1;
      
        if(root->data==x){
            return x;
        }
        
        if(root->data<x){
            return findCeil(root->right,x);
        }
        else{
            int data=findCeil(root->left,x);
            if(data==-1){
                return root->data;
            }
            return data;
        }
    }
};
