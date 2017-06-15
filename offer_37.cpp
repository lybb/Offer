//�ҳ���������ĵ�һ���������

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

//ʱ�临�Ӷȣ�O(m+n)	�ռ临�Ӷ�:O(mn)
//˼·����������ջ����list1��list2�ֱ�ѹ������ջ��Ȼ���ж�ջ��Ԫ���Ƿ���ͬ����ͬ��pop����ֱ���ҳ���ͬ��Ϊֹ
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


//ʱ�临�Ӷȣ�O(m+n)
//˼·����������ȷ��list1��list2�ĳ��ȣ���������Ȳ�diff���ýϳ�����������diff����Ȼ������ͬʱ�ߣ����������ȵģ��ͷ��ظý��
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
	if(length1 > length2){	//list�ϳ�
		int diff = length1 - length2;
		while(diff){
			p1 = p1->next;
			diff--;
		}
	}
	else if(length1 < length2){	//list2�ϳ�
		int diff = length2 - length1;
		while(diff){
			p2 = p2->next;
			diff--;
		}
	}
	else {}//һ����

	while(p1 && p2){
		if(p1->val == p2->val)
			return p1;
		p1 = p1->next;
		p2 = p2->next;
	}

	return NULL;
}