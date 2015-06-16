/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* L = head;
    int length = 0;
    if(L == NULL) return NULL;
    while(L != NULL){
        length++;
        L = L->next;
    }
    L = head;
    int cnt = length;
    struct ListNode* preL = L;
    while(L != NULL){
        if(cnt == n + 1) preL = L;
        else if(length == n) return head->next;
        else if(cnt == n){
            preL->next = L->next;
            return head;
        }
        L = L->next;
        cnt--;
    }
}
