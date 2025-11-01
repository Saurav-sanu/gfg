/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
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
    Node* sortedMerge(Node* head1, Node* head2) {
        //using 
        return solve(head1,head2);
    }
};