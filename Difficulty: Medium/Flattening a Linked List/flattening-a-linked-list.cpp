/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
  
  Node* merge(Node* head1,Node* head2){
      //base case
      if(head1==NULL){
          return head2;
      }
      if(head2==NULL){
          return head1;
      }
      Node* result;
      if(head1->data<=head2->data){
          result=head1;
          result->bottom=merge(result->bottom,head2);
      }
      else{
          result=head2;
          result->bottom=merge(head1,result->bottom);
      }
      return result;
  }
  
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        // Your code here
        if(root==NULL){
            return NULL;
            
        }
        
        Node* head2=flatten(root->next);
        
       return  merge(root,head2);
        
    }
};