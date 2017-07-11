#include <string>
#include <iostream>
using namespace std;

//����ת�ַ���----������������ת�������Ƚ�ǰ�������ַ����ֱ�ת����������ַ������з�ת
//���磬�ַ�����S=��abcXYZdef��,Ҫ�����ѭ������3λ��Ľ��������XYZdefabc����
//(1)cbaXYZdef	(2)cbafedZYX	(3)XYZdefabc


//void Reverse(int* begin,int* end)
//{
//	char tmp = 0;
//	while (begin < end)
//	{
//		tmp = *begin;
//		*begin = *end;
//		*end = tmp;
//		begin++;
//		end--;
//	}
//}

void Reverse(string& s,int left,int right){
	while(left < right){
		swap(s[left],s[right]);
		left++;
		right--;
	}
}

string LeftRotateString(string str, int n) {
	int len = str.size();
	int left = n-1;
	int right = len-1;
	Reverse(str,0,left);
	Reverse(str,left+1,right);
	Reverse(str,0,right);
	return str;
}

int main()
{
	string s("abcdef");
	LeftRotateString(s,2);
	cout<<s<<endl;
	system("pause");
	return 0;
}