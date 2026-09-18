class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head==NULL) return NULL;
        int count =0;
        ListNode* temp = head;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
         temp = head;
         for(int i=0;i<count/2;i++){
            temp = temp->next;
         }
         return temp;
    }
};