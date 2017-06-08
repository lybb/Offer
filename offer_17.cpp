#include <list>

#include <iostream>
using namespace std;


//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) :
//	val(x), next(NULL) {
//	}
//};

//剑指offer17---合并两个链表
Node* Merge(Node* phead1, Node* phead2)
{
	if (phead1==NULL && phead2==NULL)
		return NULL;
	if (phead1==NULL && phead2!=NULL)
		return phead2;
	if (phead2==NULL && phead1!=NULL)
		return phead1;

	Node* p1=phead1;
	Node* p2 = phead2;
	Node* newhead = NULL;

	//确定头结点
	if (p1->data < p2->data)
	{
		newhead = p1;
		p1 = p1->next;
	}
	else
	{
		newhead = p2;
		p2 = p2->next;
	}
	Node* cur = newhead;
	while (p1 && p2)
	{
		if (p1->data < p2->data) //p1<p2
		{
			cur->next = p1;
			p1 = p1->next;
			cur = cur->next;
		}
		else //p1>p2 || p1==p2
		{
			cur->next = p2;
			p2 = p2->next;
			cur = cur->next;
		}
	}
	//将p1和p2较长的部分挂在新链表的尾部
	if (p1)
		cur->next = p1;
	if (p2)
		cur->next = p2;
	return newhead;
}


int main()
{
	list<int> mylist1;
	mylist1.push_back(1);
	mylist1.push_back(3);
	mylist1.push_back(5);
	mylist1.push_back(7);

	list<int> mylist2;
	mylist2.push_back(2);
	mylist2.push_back(4);
	mylist2.push_back(6);
	mylist2.push_back(8);
	//list<int>::iterator it = mylist.begin();
	//while (it != mylist.end())
	//{
	//	cout<<*it<<" ";
	//	it++;
	//}
	//cout<<endl;
	system("pause");
	return 0;
}