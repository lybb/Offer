#include <iostream>
using namespace std;

//ɾ�������е��ظ���㣺��1-2-3-3-4-4-5��ɾ���Ժ����1-2-5
//˼·������prevʼ��ָ���ظ�����ǰһ��λ�ã���Ϊ��ǣ�cur���������������������ͬ�Ľ�㣬�����ɾ��
//���������:prevָ��2��cur�ӵ�һ��3��ʼ������ɾ������cur��ֵ��cur->next��ֵ����ͬʱ��˵��û���ظ��Ľ�
//�㣬Ȼ����prev��nextָ��ָ��cur

namespace ListTopic
{
	struct Node
	{
		Node* next;
		int data;
		Node(int x)
			:data(x)
			,next(NULL)
		{}
	};

	Node* deleteDuplication(Node* head)
	{
		if(head == NULL)
			return NULL;
		if(head->next == NULL)
			return head;

		Node* cur = head;
		Node* prev = head;
		Node* del = NULL;
		int key = 0;
		while (cur)
		{
			prev = cur;
			cur = cur->next;
			while(cur && cur->next && cur->data==cur->next->data)//��ʱcur�Ѿ�ָ�����ظ����ĵ�һ��
			{
				key = cur->data;	//��Ҫ���ظ�����ֵ��¼����
				while (cur && cur->data == key)		//ɾ���������ظ����
				{
					del = cur;
					cur = cur->next;
					delete del;
				}
			}
			prev->next = cur;	//��ʱ�ظ�����Ѿ�ɾ����ɣ�ʹprev�ٴ����ߵĲ���������
		}
		return head;
	}

	void Test()
	{
		Node* n1 = new Node(1);
		Node* n2 = new Node(2);
		Node* n3 = new Node(3);
		Node* n4 = new Node(3);
		Node* n5 = new Node(4);
		Node* n6 = new Node(4);
		Node* n7 = new Node(4);
		//Node* n7 = new Node(5);
		n1->next = n2;
		n2->next = n3;
		n3->next = n4;
		n4->next = n5;
		n5->next = n6;
		n6->next = n7;
		Node* ret = deleteDuplication(n1);
	}
}

int main()
{
	ListTopic::Test();
	system("pause");
	return 0;
}