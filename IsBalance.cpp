//求二叉树的高度
size_t _Depth(Node* root)
{
	if(root == NULL)
		return 0;
	if(root->_left==NULL && root->_right==NULL)
		return 1;
	size_t ldepth = _Depth(root->_left);
	size_t rdepth = _Depth(root->_right);
	return ldepth > rdepth ? ldepth+1 : rdepth+1;
}
//判断二叉树是否是平衡二叉树
bool _IsBalance(Node* root)
{
	if(root == NULL)
		return true;

	int LDepth = _Depth(root->_left);
	int RDepth = _Depth(root->_right);
	int diff = LDepth-RDepth;
	if(diff < -1 || diff > 1)
		return false;
	return _IsBalance(root->_left) && _IsBalance(root->_right);//只有左子树和右子树都平衡的时候整棵树才平衡
}

class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		int depth=0;
		return Isbalance(pRoot,&depth);
	}
private:
	bool Isbalance(TreeNode* pRoot, int* depth){
		if(pRoot == NULL){
			*depth=0;
			return true;
		}

		int Ldepth;
		int Rdepth;
		if(Isbalance(pRoot->left,&Ldepth) && Isbalance(pRoot->right,&Rdepth)){
			int diff = Ldepth - Rdepth;
			if(diff>=-1 && diff<=1){
				*depth = (Ldepth > Rdepth ? Ldepth : Rdepth) +1;
				return true;
			}
		}            
		return false;
	}

};