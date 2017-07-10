#include <iostream>
using namespace std;

//��������ĸ���
//��������������
//(1)��ԭ�����nextΪ���ߣ�ÿ�ν��������½��������ԭ�����ĺ�ߣ�ʹ�¾ɽ���Ϊһ�������磺ԭ������1->2->3->4��������һ�����Ϊ1->1->2->2->3->3->4->4
//(2)��ͷ�����������ı��������random��
//(3)��ͷ������������������ָ��Ϊ��������������

namespace ListTopic
{
	//��������ĸ���
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
		while (oldlist)//�������Ľ�����ھ�������ĺ��
		{
			newlist = new ComplexNode(oldlist->_data);
			newlist->_next = oldlist->_next;
			oldlist->_next = newlist;
			oldlist = oldlist->_next->_next;
		}
		oldlist = head;
		while (oldlist)	//�޸�random��
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
		while (oldlist)	//��������
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