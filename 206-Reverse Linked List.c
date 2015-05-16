/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL){
        return NULL;
    }
    else{
        struct ListNode* First = head;
        int Length = 0;
        while(First != NULL){
            Length++;
            First = First->next;
        }
        if(Length == 1){
            return head;
        }
        else{
            int Cnt = Length;
            First = head;
            struct ListNode* Second = First->next;
            struct ListNode* reversedNode;
            
            while(Cnt > 1){
                struct ListNode* Prelast = First;
                struct ListNode* Last = Second;    
                while (Last->next != NULL){
                    Last = Last->next;
                    Prelast = Prelast->next;
                }
                if(Cnt == Length){
                    reversedNode = Last;
                }
                Last->next = Prelast;
                Prelast->next = NULL;
                Cnt--;
            }
            return reversedNode;
        }
    }
}
