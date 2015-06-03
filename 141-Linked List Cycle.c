/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *L1, *L2;
    if(head == NULL || head->next == NULL) return false;
    L1 = L2 = head;
    while(L2 != NULL && L2->next != NULL){
        L1 = L1->next;
        L2 = L2->next->next;
        if(L1 == L2) return true;
    }
    return false;
}
