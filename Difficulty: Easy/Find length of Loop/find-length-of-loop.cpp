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
    int lengthOfLoop(Node *head) {
        Node* slow=head;
        Node* fast=head;
        int count=0;
        
        while(fast){
            fast=fast->next;
            if(fast){
                fast=fast->next;
                slow=slow->next;
                
                
            }
            if(slow==fast){
                break;
            }
        }
        slow=head;
        if(fast==NULL){
            return NULL;
        }
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        
        while(fast){
            slow=slow->next;
            count++;
            fast=fast->next->next;
            
            
            if(fast==slow){
                // return count;
                break;
            }
        }
        
        return count;
        
        
        
    }
};