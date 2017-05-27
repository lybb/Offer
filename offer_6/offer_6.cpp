#include "BinaryTree.h"
#include <vector>

typedef BinaryTreeNode<int> Node;

//����ǰ���������������ؽ�������
Node* RebuildTree(vector<int> prev, vector<int> vin)
{
	if (prev.empty() || vin.empty())
		return NULL;

	//��ǰ�������prev���Ҹ��ڵ㣬��ȷ������vin��λ��
	size_t index = 0;
	for (; index<vin.size(); index++)
	{
		if (vin[index] == prev[0])
			break;
		//index = i;
		//break;
	}
	//�Ѿ��ҵ����ڵ㣬��������ڵ�
	Node* root = new Node(prev[0]);
	//Print(root);
	//����������������ڵ���������һ��Ϊ�������ڵ�����Ϊ���������Ҳ�Ϊ������
	vector<int> prev_left,prev_right;
	vector<int> vin_left,vin_right;
	//�Ƚ�ǰ�������и��ڵ������������¼����
	for (size_t j=0; j<index; j++)
	{
		prev_left.push_back(prev[j+1]);
		vin_left.push_back(vin[j]);
	}
	for (size_t j=index+1; j<vin.size(); j++)
	{
		prev_right.push_back(prev[j]);
		vin_right.push_back(vin[j]);
	}
	root->_left = RebuildTree(prev_left,vin_left);
	root->_right = RebuildTree(prev_right,vin_right);

	return root;
}

void Print(Node* root)
{
	if (root == NULL)
		return ;

	Print(root->_left);
	cout<<root->_data<<" ";
	Print(root->_right);
}
int main()
{
	vector<int> InOrder,PrevOrder;
	InOrder.push_back(3);
	InOrder.push_back(2);
	InOrder.push_back(4);
	InOrder.push_back(1);
	InOrder.push_back(6);
	InOrder.push_back(5);
	PrevOrder.push_back(1);
	PrevOrder.push_back(2);
	PrevOrder.push_back(3);
	PrevOrder.push_back(4);
	PrevOrder.push_back(5);
	PrevOrder.push_back(6);
	Node* ret = RebuildTree(PrevOrder,InOrder);
	//Print(ret);
	system("pause");
	return 0;
}