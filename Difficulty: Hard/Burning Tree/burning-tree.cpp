/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  unordered_map<Node*,Node*>parent;
  void inorder(Node* root){
      //base case
      if(root==NULL){
          return ;
      }
      
      if(root->left){
          parent[root->left]=root;
        inorder(root->left);
      }
      if(root->right){
          parent[root->right]=root;
          inorder(root->right);
      }
      
  }
  
  void Bfs(Node* root,int &time){
      queue<Node*>q;
      q.push(root);
      unordered_set<int>visited;
      visited.insert(root->data);
      
      
      while(!q.empty()){
          int size=q.size();
          time++;
          
          while(size--){
              auto temp=q.front();
              q.pop();
              
              
              if(temp->left && !visited.count(temp->left->data)){
                  q.push(temp->left);
                  visited.insert(temp->left->data);
              }
               if(temp->right && !visited.count(temp->right->data)){
                  q.push(temp->right);
                  visited.insert(temp->right->data);
              }
               if(parent.count(temp) && !visited.count(parent[temp]->data)){
                  q.push(parent[temp]);
                  visited.insert(parent[temp]->data);
              }
          }
      }
  }
    int minTime(Node* root, int target) {
        inorder(root);
        int time=-1;
        
        
        
        //finding node int he tr
        Node* temp=NULL;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            
            if(curr->data==target){
                temp=curr;
                break;
            }
            
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
        
        
        
        
        Bfs(temp,time);
        return time;
        
    }
};