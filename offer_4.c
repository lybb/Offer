#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//ʱ�临�Ӷȣ�O(N)
void Replace(char* str,int len)		
{
	char* start = str;
	int blacknum = 0;
	int newlenth = 0;
	int prev = 0;
	int last = 0;
	if ((str == NULL) || (len < 0))
	{
		return ;
	}
	
	while (*start != '\0')
	{
		start++;
		if (*start == ' ')
		{
			blacknum++;		//ͳ�ƿո�ĸ���
		}
	}

	newlenth = len+blacknum*2;		//�滻���µ��ַ�������
	prev = len;
	last = newlenth;
	while (prev >= 0)
	{
		str[last--] = str[prev--];

		if (str[prev] == ' ')
		{
			str[last--] = '0';
			str[last--] = '2';
			str[last--] = '%';
			prev--;
		}
	}
}

int main()
{
	char str[] = "we are happy";
	int len = strlen(str);
	
	Replace(str,len);
	printf("%s\n",str);

	system("pause");
	return 0;
}