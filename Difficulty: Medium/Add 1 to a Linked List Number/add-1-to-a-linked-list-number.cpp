/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  int helper(Node* temp){
      //base case
      if(temp==NULL){
          return 1;
      }
      int carry=helper(temp->next);
      temp->data=temp->data+carry;
      if(temp->data<10){
          return 0;
      }
      temp->data=0;
      return 1;
  }
    Node* addOne(Node* head) {
        // Your Code here
        int  carry=helper(head);
        if(carry==1){
            Node* newNode=new Node(1);
            newNode->next=head;
            return newNode;
        }
        return head;
        
    }
};