#include <vector>

#include <iostream>
using namespace std;

//不考虑相对位置是否改变：1 2 3 4 5  --->   1 5 3 4 2
void reOrderArray(vector<int> &array) {
	if (array.empty())
		return ;

	int left = 0;
	int right = array.size()-1;
	while (left < right){
		if (array[left]%2==0 && array[right]%2!=0)
			swap(array[left],array[right]);

		if (array[left]%2 != 0)
			left++;
		if (array[right]%2 == 0)
			right--;
	}
	if (left >= right)
		return ;
}

//考虑相对位置不变：1 2 3 4 5  --->  1 3 5 2 4


//时间复杂度：O(N)；空间复杂度：O(N)
//void reOrderArray(vector<int> &array){
//	if (array.empty())
//		return ;
//
//	vector<int> v1;
//	vector<int> v2;
//	for (size_t i=0; i<array.size(); i++)
//	{
//		if (array[i]%2 != 0)
//			v1.push_back(array[i]);
//		else
//			v2.push_back(array[i]);
//	}
//	for (size_t i=0; i<v1.size(); i++)
//	{
//		array[i] = v1[i];
//	}
//	for (size_t i=0,j=v1.size(); i<v2.size(),j<array.size(); i++,j++)
//	{
//		array[j] = v2[i];
//	}
//
//}

int main()
{
	vector<int> v;
	//for (int i=1; i<=7; i++)
	//{
	//	v.push_back(i);
	//}
	v.push_back(2);
	v.push_back(4);
	v.push_back(6);
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);
	reOrderArray(v);

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout<<*it<<" ";
		it++;
	}
	cout<<endl;
	system("pause");
	return 0;
}