//ջ��ѹ�뵯��˳������ѹ��˳��1,2,3,4,5������4,5,3,2,1��һ������˳����4,3,5,1,2��
//�������ǵ���˳��


#include <stack>
#include <vector>
#include <iostream>
using namespace std;

bool IsPopOrder(vector<int> pushV,vector<int> popV)
{
	if (pushV.empty() || popV.empty())
		return false;

	stack<int> s;
	vector<int> compV;	//��s�ĳ�ջ˳�򱣴��ڸ�vetcor�У�����popV�Ƚ�
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
	if (!s.empty() && s.top()!=*it2)//���ջs�������ݣ���ջ�����ݲ��ǵ�ǰit2�����ݣ�˵�����ǳ�ջ˳��
		return false;

	it2 = popV.begin();
	vector<int>::iterator it = compV.begin();
	while (it2!=popV.end() && it!=compV.end())	//�Ƚ�comp��popV�����������һ����ͬ�����popV���ǳ�ջ˳��
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