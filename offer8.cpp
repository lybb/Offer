#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

//时间复杂度：O（N）
//int minNumberInRotateArray(vector<int> rotateArray)
//{
//	if (rotateArray.empty())
//		return -1;
//
//	unsigned int i=0;
//	for (; i<rotateArray.size()-1; i++)
//	{
//		if (rotateArray[i] > rotateArray[i+1])
//			break;
//	}
//	return rotateArray[i+1];
//}

//时间复杂度：O(logN)---类似于二分查找
int minNumberInRotateArray(vector<int> rotateArray)
{
	if (rotateArray.empty())
		return -1;
	unsigned int left=0;
	unsigned int right=rotateArray.size()-1;
	unsigned int mid=left;
	while (rotateArray[left] >= rotateArray[right])
	{
		if (right-left == 1)
		{
			mid = right;
			break;
		}
		mid = left+((right-left)>>1);

		if (rotateArray[mid]==rotateArray[left] && rotateArray[right]==rotateArray[mid])
			return rotateArray[mid];

		if (rotateArray[mid] >= rotateArray[left])
			left = mid;
		else if (rotateArray[mid] <= rotateArray[right])
			right = mid;
	}
	return rotateArray[mid];
}

int main()
{
	vector<int> v;
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(1);
	v.push_back(2);

	//sort(v.begin(),v.begin()+v.size());
	//cout<<*(v.begin())<<endl;

	int ret = minNumberInRotateArray(v);
	cout<<ret<<endl;

	//vector<int>::iterator it = v.begin();
	//while (it != v.end())
	//{
	//	cout<<*it<<" ";
	//	it++;
	//}
	cout<<endl;
	system("pause");
	return 0;
}