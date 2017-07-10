#include <iostream>
using namespace std;

//复杂链表的复制
//分析：分三步：
//(1)以原链表的next为主线，每次将拷贝的新结点连接在原来结点的后边，使新旧结点称为一条链表。如：原链表是1->2->3->4，经过这一步后变为1->1->2->2->3->3->4->4
//(2)从头遍历新链表，改变各个结点的random域；
//(3)从头遍历链表，将这条链表分割称为两个单独的链表。

namespace ListTopic
{
	//复杂链表的复制
	struct ComplexNode
	{
		int _data;
		ComplexNode* _next;
		ComplexNode* _random;
		ComplexNode(int data)
			:_data(data)
			,_next(NULL)
			,_random(NULL)
		{}
	};

	ComplexNode* CopyComplexNode(ComplexNode* head)
	{
		if(head == NULL)
			return NULL;
		ComplexNode* oldlist = head;
		ComplexNode* newlist = NULL;
		ComplexNode* newhead = NULL;
		while (oldlist)//将拷贝的结点连在旧链表结点的后边
		{
			newlist = new ComplexNode(oldlist->_data);
			newlist->_next = oldlist->_next;
			oldlist->_next = newlist;
			oldlist = oldlist->_next->_next;
		}
		oldlist = head;
		while (oldlist)	//修改random域
		{
			newlist = oldlist->_next;
			if (oldlist->_random)
				newlist->_random = oldlist->_random->_next;
			else
				newlist->_random = NULL;
			oldlist = oldlist->_next->_next;
		}
		oldlist = head;
		newhead = oldlist->_next;
		while (oldlist)	//分离链表
		{
			newlist = oldlist->_next;
			oldlist->_next = newlist->_next;
			if (oldlist->_next)
				newlist->_next = oldlist->_next->_next;
			else
				newlist->_next = NULL;
			oldlist = oldlist->_next;
		}
		return newhead;
	}
	void Test2()
	{
		ComplexNode* n1 = new ComplexNode(1);
		ComplexNode* n2 = new ComplexNode(2);
		ComplexNode* n3 = new ComplexNode(3);
		ComplexNode* n4 = new ComplexNode(4);
		n1->_next = n2;
		n2->_next = n3;
		n3->_next = n4;
		n1->_random = n3;
		n3->_random = NULL;
		n4->_random = n2;
		ComplexNode* ret = CopyComplexNode(n1);
	}
}


int main()
{
	ListTopic::Test2();
	//test_inter();
	system("pause");
	return 0;
}