#include <iostream>
using namespace std;

//����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
int FindNum(unsigned num)
{
	int i=0;
	int count=0;
	for(; i<32; i++)
	{
		if (num&1)
			count++;
		num >>= 1;
	}
	return count;
}

int main()
{
	unsigned num=0;
	cin>>num;
	int ret = FindNum(num);
	cout<<ret<<endl;
	system("pause");
	return 0;
}