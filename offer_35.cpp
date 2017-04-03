#include <assert.h>
#include <iostream>
using namespace std;

//ʱ�临�Ӷȣ�N*N ===> O(N^2)
char Find(char* str)
{
	if (str == NULL)
		return NULL;

	char* prev=str;
	char* last=str;
	int count=1;
	while(*prev)
	{
		count = 1; //countÿ����Ҫ������1
		last = prev;
		while(*last)
		{
			last++;
			if (*last == *prev)//last�ڱ���������������*prev��ͬ���ַ�
				count++;
		}
		if (count == 1)	//last���һ�α�����û���ҵ��ظ����ַ�
			return *prev;
		else
			prev++;		
	}
	return NULL;
}

//ʱ�临�Ӷȣ�2*N ===> O(N)
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