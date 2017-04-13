#include <iostream>
using namespace std;

//输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
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