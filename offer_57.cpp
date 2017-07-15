#include <iostream>
using namespace std;

//删除链表中的重复结点：如1-2-3-3-4-4-5，删除以后就是1-2-5
//思路分析：prev始终指向重复结点的前一个位置，作为标记，cur向后遍历，如果遇到连续相同的结点，就逐个删除
//如上述结点:prev指向2，cur从第一个3开始逐个向后删除，当cur的值与cur->next的值不相同时，说明没有重复的结
//点，然后让prev的next指针指向cur

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
			while(cur && cur->next && cur->data==cur->next->data)//此时cur已经指向了重复结点的第一个
			{
				key = cur->data;	//需要将重复结点的值记录下来
				while (cur && cur->data == key)		//删除连续的重复结点
				{
					del = cur;
					cur = cur->next;
					delete del;
				}
			}
			prev->next = cur;	//此时重复结点已经删除完成，使prev再次与后边的部分连接上
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