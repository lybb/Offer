#include <stack>
#include <iostream>
using namespace std;

//s1用于入栈，s1出栈后压入s2，再从s2出栈

//void StackToQueue(int data)
//{
//	//if (arr==NULL)
//	//	return;
//	stack<int> s1;
//	stack<int> s2;
//	int ret=0;
//	s1.push(data);
//	if (s2.size()<=0)
//	{
//		while (s1.size() > 0)
//		{
//			ret=s1.top();
//			s2.push(s1.top());
//			s1.pop();
//		}
//	}
//	if(s2.size() > 0)
//	{
//		cout<<s2.top()<<" ";
//		s2.pop();
//	}	
//}

class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}
	int pop() {
		int ret=0;
		if (stack2.size()<=0)
		{
			while (stack1.size() > 0)
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		if(stack2.size() > 0)
		{
			ret = stack2.top();
			stack2.pop();
		}
		return ret;
	}
private:
	stack<int> stack1;
	stack<int> stack2;
};

int main()
{
	Solution s1;
	int i=0;
	for (; i<10; i++)
	{
		s1.push(i);
	}
	for (i=0; i<10; i++)
	{
		cout<<s1.pop()<<" ";
	}
	cout<<endl;
	//int arr[]={0,1,2,3,4,5,6,7,8,9};
	//int len=sizeof(arr)/sizeof(arr[0]);
	system("pause");
	return 0;
}