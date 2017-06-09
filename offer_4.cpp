#include <assert.h>
#include <iostream>
using namespace std;

//开辟新的内存----O(N)
void replaceSpace(char *str,int length) 
{
	if (str==NULL || length<0)
		return ;
	//we are happy ---> we%20are%20happy
	//先统计空格的次数
	int i = 0;
	int count = 0;
	for (; i<length; i++)
	{
		if (str[i] == ' ')
			count++;
	}
	int max = length+count*(strlen("%20")-1);
	char* arr=new char[max];
	printf("length = %d\n",length);
	printf("max = %d\n",max);
	for (int i=0,j=0; i<length,j<max; i++,j++)
	{
		if (str[i] == ' ')
		{
			arr[j++] = '%';
			arr[j++] = '2';
			arr[j++] = '0';
			i++;
		}
		arr[j] = str[i];
	}
	printf("%s\n",arr);
	delete[] arr;
}

//在原字符串修改

//从后向前替换----O(N)
void replaceSpace2(char str[],int length)
{
	assert(str && length>0);
	//统计空格次数
	int count = 0;
	int i=0;
	while(str[i] != '\0')
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	int newlength = length+count*(strlen("%20")-1);
	int prev = length;
	int last = newlength;
	for(; prev>=0; prev--)
	{
		if (str[prev] == ' ')
		{
			str[last--] = '0';
			str[last--] = '2';
			str[last--] = '%';

		}
		else
			str[last--] = str[prev];
	}
	printf("%s\n",str);
}

int main()
{
	//char* str="we are happy.";
	char* str="hello world";
	//printf("%d\n",strlen(str));
	//printf("%d\n",str[11]);
	//replaceSpace(str,strlen(str));
	replaceSpace2(str,strlen(str));
	system("pause");
	return 0;
}