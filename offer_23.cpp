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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> v;
        queue<TreeNode*> q;
        if(root == NULL)
            return v;
        
        q.push(root);
        while(!q.empty()){
            TreeNode* tmp=q.front();
            if(tmp->left)
                q.push(tmp->left);
            if(tmp->right)
                q.push(tmp->right);
             
            v.push_back(tmp->val);
            q.pop();
        }
        return v;
    }
};