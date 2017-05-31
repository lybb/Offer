/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot == NULL)
            return 0;
        if(pRoot->left==NULL && pRoot->right==NULL)
            return 1;
         
        int LDepth = TreeDepth(pRoot->left);
        int RDepth = TreeDepth(pRoot->right);
         
        return LDepth > RDepth ? LDepth+1 : RDepth+1;
     
    }
};