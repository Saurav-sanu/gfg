/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution {
  public:

 Node* solve(Node* head1, Node* head2){
      //base case
      if(head1==NULL){
          return head2;
      }
      if(head2==NULL){
          return head1;
      }
      
      Node* result;
      
      if(head1->data<head2->data){
          result=head1;
          result->next=solve(head1->next,head2);
      }
      else{
          result=head2;
          result->next=solve(head1,head2->next);
      }
      return result;
  }
  Node* reverseList(Node* head) {
        //USING RECURSION
        if(head==NULL || head->next==NULL){
            return head;
        }

        Node* last=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;

        return last;

    }
  
  
    struct Node *mergeResult(Node *node1, Node *node2) {
        Node* result=solve(node1,node2);
        
        return reverseList(result);
    }
};