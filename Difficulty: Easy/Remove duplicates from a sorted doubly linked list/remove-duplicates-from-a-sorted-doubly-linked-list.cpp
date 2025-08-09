/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        Node* temp=head;
        while(temp!=NULL && temp->next!=NULL){
            Node* newNode=temp->next;
            while(newNode!=NULL && temp->data==newNode->data){
                newNode=newNode->next;
            }
           
            temp->next=newNode;
            if(newNode){
                
                newNode->prev=temp;
            }
            temp=temp->next;
            
            
        }
        return head;
        
    }
};