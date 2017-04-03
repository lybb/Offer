#include <assert.h>
#include <iostream>
using namespace std;

//时间复杂度：N*N ===> O(N^2)
char Find(char* str)
{
	if (str == NULL)
		return NULL;

	char* prev=str;
	char* last=str;
	int count=1;
	while(*prev)
	{
		count = 1; //count每次需要重新置1
		last = prev;
		while(*last)
		{
			last++;
			if (*last == *prev)//last在遍历过程中遇到与*prev相同的字符
				count++;
		}
		if (count == 1)	//last完成一次遍历后没有找到重复的字符
			return *prev;
		else
			prev++;		
	}
	return NULL;
}

//时间复杂度：2*N ===> O(N)
//char Find(char* str)
//{
//	assert(str);
//
//	int src[256] = {0};
//	char* start = str;
//	while (*start != '\0')
//	{
//		src[*start]++;
//		start++;
//	}
//	while (*str)
//	{
//		if(src[*str] == 1)
//			return *str;
//		*str++;
//	}
//	return NULL;
//}

int main()
{
	//char* str = "abacdeeff";
	//char* str = "acdef";
	char* str = "";
	char ret = Find(str);
	cout<<ret<<endl;
	system("pause");
	return 0;
}