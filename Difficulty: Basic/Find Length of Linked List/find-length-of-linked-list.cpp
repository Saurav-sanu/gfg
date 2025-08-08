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
    int getCount(Node* head) {
        int count=0;
        Node* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        return count;
        
    }
};