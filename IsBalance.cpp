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