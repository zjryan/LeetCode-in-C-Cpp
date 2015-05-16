/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* L = head;
    struct ListNode* preL = head;
    while(L != NULL){
        //first elem.val = key
        if(L->val == val && preL == L){
            L = L->next;
            preL = L;
            head = L;
        }
        else if(L->val == val){
            preL->next = L->next;
            L = L->next;
        }
        else if(L->val == val && L->next == NULL){
            preL->next == NULL;
        }
        else{
            preL = L;
            L = L->next;            
        }
    }
    return head;
}
