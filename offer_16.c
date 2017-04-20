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
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == NULL)
            return NULL;
        ListNode* cur = pHead;
        ListNode* tmp = pHead;
        ListNode* newHead = NULL;
        while(cur){
            tmp = cur;
            cur = cur->next;
            tmp->next = newHead;
            newHead = tmp;
        }
        return newHead;
    }
};