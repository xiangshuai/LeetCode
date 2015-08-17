#define NULL 0
struct TreeNode {
	int val;
	TreeNode *left;     TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int sumNumbers(TreeNode* root) {
		return preorder(root);
	}

	int preorder(TreeNode* root) {
		if (root==NULL)
		{
			return 0;
		}

		if (root->left==NULL && root->right==NULL)
		{
			return root->val;
		}

		if (root->left)
		{
			root->left->val += root->val*10;
		}
		if (root->right)
		{
			root->right->val += root->val*10;
		}
		return preorder(root->left) + preorder(root->right);
	}
};