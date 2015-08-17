#define NULL 0
#include <algorithm>
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		if (root==NULL)
		{
			return true;
		}
		
		return isValidBST(root, LONG_MIN, LONG_MAX);
	}

	bool isValidBST(TreeNode* root, long min, long max)
	{
		if (root==NULL)
		{
			return true;
		}
		
		if (root->val>=max || root->val<=min)
		{
			return false;
		}
		return isValidBST(root->left, min, root->val) 
			&& isValidBST(root->right, root->val, max);
	}
};