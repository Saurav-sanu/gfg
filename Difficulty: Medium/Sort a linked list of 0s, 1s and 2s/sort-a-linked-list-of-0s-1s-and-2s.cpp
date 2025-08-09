/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    Node* segregate(Node* head) {
        Node* zerod = new Node(-1);
        Node* oned  = new Node(-1);
        Node* twod  = new Node(-1);
        
        Node* zero = zerod;
        Node* one  = oned;
        Node* two  = twod;
        
        Node* temp = head;
        
        while (temp != NULL) {
           
            if (temp->data == 0) {
                zero->next = temp;
                zero = zero->next;
            }
            else if (temp->data == 1) {
                one->next = temp;
                one = one->next;
            }
            else {
                two->next = temp;
                two = two->next;
            }
            
            temp = temp->next;
        }
        
        zero->next = (oned->next) ? oned->next : twod->next;
        one->next  = twod->next;
        two->next  = NULL;
        
        Node* result = zerod->next; 
        
        delete zerod;
        delete oned;
        delete twod;
        
        return result;
    }
};