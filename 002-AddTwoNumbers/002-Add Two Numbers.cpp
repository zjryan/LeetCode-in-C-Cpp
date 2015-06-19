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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* L1 = l1;
        ListNode* L2 = l2;
        int len1, len2;
        len1 = len2 = 0;
        while(L1 != nullptr) {
            len1++;
            L1 = L1->next;
        }
        while(L2 != nullptr) {
            len2++;
            L2 = L2->next;
        }
        if (len1 >= len2) 
            return addList(l1, l2); 
        else return addList(l2, l1);
    }
private:
    ListNode* addList (ListNode* l1, ListNode* l2){
        //assert len of l1 is no less than l2
        ListNode* L1 = l1;
        ListNode* L2 = l2;
        while(L1 != nullptr){
            if(L2 != nullptr){
                L1->val += L2->val;
                carry(L1);
                L2 = L2->next;
            }
            L1 = L1->next;
        }
        return l1;
    }
    
    void carry(ListNode* node){
        if(node->val < 10) return;
        node->val -= 10;
        if(node->next == nullptr) {
            ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
            node->next = newNode;
            newNode->val = 1;
            newNode->next = nullptr;
        }
        else {
            node->next->val++;
            carry(node->next);
        }
    }
};
