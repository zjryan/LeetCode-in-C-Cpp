/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* L = head;
    struct ListNode* preL = L;

    while(L != NULL){
        L = L->next;
        if(L == NULL){
            break;
        }
        if(preL->val == L->val){
            //lazy delete L
            preL->next = L->next;
        }
        else{
            preL = L;
        }
    }
    
    return head;
}
