#include <iostream>
using namespace std;

//0 1 1 2 3 5 8 13 21...

//�ݹ�
int Fib(int num)
{
	if (num <= 1)
		return num;

	return num<2 ? num:(Fib(num-1)+Fib(num-2));
}


////�ǵݹ�
//int Fib(int n)//n�ǵڼ���
//{
//	if(n <= 1)
//		return n;
//	int first = 0;
//	int second = 1;
//	int third = first + second;
//	for(int i=2; i<n; i++)
//	{
//		third = first + second;
//		first = second;
//		second = third;
//	}
//	return third;
//}

int main()
{
	int num=0;
	cin>>num;

	cout<<Fib(num)<<endl;
	system("pause");
	return 0;
}