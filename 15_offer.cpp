/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == NULL || k <= 0)
            return NULL;
         
        ListNode* head = pListHead;
        ListNode* tail = pListHead;
        unsigned int i=1;
        while(i++ < k){           
            if(tail->next == NULL)
                return NULL;
            tail = tail->next;           
        }
         
        while(tail->next){
            head = head->next;
            tail = tail->next;
        }
 
        return head;
    }
     
};