/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = length(headA);
        int lenB = length(headB);
        while(lenA > lenB){
            headA = headA->next;
            lenA--;
        }
        while(lenB > lenA){
            headB = headB->next;
            lenB--;
        }
        while(headA != nullptr && headB != headA){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
    
private:
    int length(ListNode *root){
        int cnt = 0;
        while(root != nullptr){
            cnt++;
            root = root->next;
        }
        return cnt;
    }
};
