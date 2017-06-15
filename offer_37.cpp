//找出两个链表的第一个公共结点

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

//时间复杂度：O(m+n)	空间复杂度:O(mn)
//思路：借助两个栈，将list1和list2分别压入两个栈，然后判断栈顶元素是否相同，相同就pop掉，直到找出不同的为止
ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
	if(pHead1==NULL || pHead2==NULL)
		return NULL;

	stack<ListNode*> s1;
	stack<ListNode*> s2;
	ListNode* p1 = pHead1;
	ListNode* p2 = pHead2;
	while(p1){
		s1.push(p1);
		p1 = p1->next;
	}
	while(p2){
		s2.push(p2);
		p2 = p2->next;
	}

	//ListNode* t1 = NULL;
	//ListNode* t2 = NULL;
	ListNode* node = NULL;
	while(!s1.empty() && !s2.empty()){
		if((s1.top())->val == (s2.top())->val){
			//t1 = s1.top();
			//t2 = s2.top();
			node = s1.top();
		}
		s1.pop();
		s2.pop();
	}
	return node;            
}


//时间复杂度：O(m+n)
//思路分析：首先确定list1和list2的长度，并求出长度差diff，让较长的链表先走diff步，然后两个同时走，如果遇到相等的，就返回该结点
ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
	if(pHead1==NULL || pHead2==NULL)
		return NULL;

	int length1=0;
	int length2=0;
	ListNode* p1 = pHead1;
	ListNode* p2 = pHead2;
	while(p1){
		length1++;
		p1 = p1->next;
	}
	while(p2){
		length2++;
		p2 = p2->next;
	}

	p1 = pHead1;
	p2 = pHead2;
	if(length1 > length2){	//list较长
		int diff = length1 - length2;
		while(diff){
			p1 = p1->next;
			diff--;
		}
	}
	else if(length1 < length2){	//list2较长
		int diff = length2 - length1;
		while(diff){
			p2 = p2->next;
			diff--;
		}
	}
	else {}//一样长

	while(p1 && p2){
		if(p1->val == p2->val)
			return p1;
		p1 = p1->next;
		p2 = p2->next;
	}

	return NULL;
}