struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* L1 = l1;
    struct ListNode* L2 = l2;
    struct ListNode* resultList = NULL;
    if(L1 != NULL && L2 != NULL){
        if(L1->val < L2->val){
            resultList = L1;
        }
        else{
            resultList = L2;
        }
    }
    else if(L1 == NULL){
        return L2;
    }
    else if(L2 == NULL){
        return L1;
    }
    
    struct ListNode* tmpL1;
    struct ListNode* tmpL2;
    
    while(L1 != NULL && L2 != NULL){
        //assert L1 and L2 are not NULL
        if(L1 == NULL || L2 == NULL){
            break;
        }
        if(L2->val > L1->val){
            while(L1 != NULL && L2->val > L1->val){
                tmpL1 = L1;
                L1 = L1->next;
            }
            //assert L2.val <= L1.val
            tmpL1->next = L2;
            if(L2->next == NULL){
                L2->next = L1;
                break;
            }
        }
        else{
            while(L2 != NULL && L2->val <= L1->val){
                tmpL2 = L2;
                L2 = L2->next;
            }
            tmpL2->next = L1;
            
            if(L1->next == NULL){
                L1->next = L2;
                break;
            }
        }
    }
    return resultList;
}
