/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> v;
		stack<int> s;
		ListNode* cur = head;
		while(cur){
			s.push(cur->val);
			cur = cur->next;
		}
		while (!s.empty())
		{
			v.push_back(s.top());
			s.pop();
		}
		return v;
	}
};
