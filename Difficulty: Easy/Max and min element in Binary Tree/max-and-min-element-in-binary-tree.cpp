/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    int findMax(Node *root) {
        int maxi=INT_MIN;
        while(root->right){
            root=root->right;
        }
        maxi=max(maxi,root->data);
        
        return maxi;
        
    }

    int findMin(Node *root) {
        int mini=INT_MAX;
        while(root->left){
           root=root->left;
            
        }
        mini=min(mini,root->data);
        
        return mini;
        
    }
};