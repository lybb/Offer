//栈的压入弹出顺序：例如压入顺序1,2,3,4,5，序列4,5,3,2,1是一个弹出顺序，则4,3,5,1,2就
//不可能是弹出顺序


#include <stack>
#include <vector>
#include <iostream>
using namespace std;

bool IsPopOrder(vector<int> pushV,vector<int> popV)
{
	if (pushV.empty() || popV.empty())
		return false;

	stack<int> s;
	vector<int> compV;	//将s的出栈顺序保存在该vetcor中，最后和popV比较
	vector<int>::iterator it1 = pushV.begin();
	vector<int>::iterator it2 = popV.begin();
	while (it1 != pushV.end())
	{
		s.push(*it1);
		it1++;
		while(!s.empty() && s.top()==*it2)
		{
			compV.push_back(s.top());
			s.pop();
			it2++;
		}
	}
	if (!s.empty() && s.top()!=*it2)//如果栈s内有数据，但栈顶数据不是当前it2的数据，说明不是出栈顺序
		return false;

	it2 = popV.begin();
	vector<int>::iterator it = compV.begin();
	while (it2!=popV.end() && it!=compV.end())	//比较comp和popV，如果有任意一个不同则表明popV不是出栈顺序
	{
		if (*it2 != *it)
			return false;
		it2++;
		it++;
	}
	return true;
}

int main()
{
	vector<int> pushV;
	for (int i=1; i<=5; i++)
	{
		pushV.push_back(i);
	}
	vector<int> popV;
	popV.push_back(4);
	popV.push_back(3);
	popV.push_back(5);
	popV.push_back(1);
	popV.push_back(2);
	//popV.push_back(4);
	//popV.push_back(5);
	//popV.push_back(3);
	//popV.push_back(2);
	//popV.push_back(1);
	cout<<IsPopOrder(pushV,popV)<<endl;
	system("pause");
	return 0;
}