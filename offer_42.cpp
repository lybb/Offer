#include <string>
#include <iostream>
using namespace std;

//左旋转字符串----分析：三步翻转法，即先将前后两端字符串分别翻转，最后将整体字符串进行翻转
//例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。
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

//翻转单词顺序---->先将整体字符串翻转，再将每个单词进行翻转
//I am a student. -----> student. a am I
//wonderful --->  wonderful
string ReverseSentence(string& str) 
{
	if(str.empty())
		return str;
	
	int right=0;
	int len = str.size();
	int left = 0;
	Reverse(str,0,len-1);
	for(right=0; right<len; right++)
	{
		if (str[right] == ' ')	//遇到空格就跳过
			right++;
		left = right;
		while (right < len && str[right] != ' ')	//right有可能会越界，因此这里必须先判断right是否超过了字符串的长度
		{
			right++;
		}
		Reverse(str,left,right-1);
	}
	return str;
}

int main()
{
	//string s("abcdef");
	//LeftRotateString(s,2);
	string s("I am a student.");
	string s1("wonderful");
	ReverseSentence(s);
	ReverseSentence(s1);
	cout<<s<<endl;
	cout<<s1<<endl;
	system("pause");
	return 0;
}