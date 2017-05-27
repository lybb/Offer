#include "BinaryTree.h"
#include <vector>

typedef BinaryTreeNode<int> Node;

//根据前序遍历和中序遍历重建二叉树
Node* RebuildTree(vector<int> prev, vector<int> vin)
{
	if (prev.empty() || vin.empty())
		return NULL;

	//在前序遍历中prev中找根节点，并确定其在vin的位置
	size_t index = 0;
	for (; index<vin.size(); index++)
	{
		if (vin[index] == prev[0])
			break;
		//index = i;
		//break;
	}
	//已经找到根节点，并构造根节点
	Node* root = new Node(prev[0]);
	//Print(root);
	//根据中序遍历将根节点左右两侧一分为二，根节点的左侧为左子树，右侧为右子树
	vector<int> prev_left,prev_right;
	vector<int> vin_left,vin_right;
	//先将前序、中序中根节点的左右子树记录下来
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