/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

//思路分析：利用前序遍历大的方法，如果当前结点不为空，且左右子树不为空，就交换左右两
//个子树，递归进行。
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(pRoot == NULL || (pRoot->left==NULL && pRoot->right==NULL))
            return ;
        
        TreeNode* tmp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = tmp;
        
        if(pRoot->left)
            Mirror(pRoot->left);
        if(pRoot->right)
            Mirror(pRoot->right);
    }
};