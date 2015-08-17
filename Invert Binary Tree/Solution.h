#define NULL 0
 struct TreeNode {
     int val;
     TreeNode *left;     TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        inorder(root);
		return root;
    }

	void preorder(TreeNode* root)
	{
		if (root==NULL)
		{
			return ;
		}

		inorder(root->left);
		TreeNode *tnode = root->left;
		root->left = root->right;
		root->right = tnode;
		inorder(root->left);
	}

	void inorder(TreeNode* root)
	{
		if (root==NULL)
		{
			return ;
		}

		TreeNode *tnode = root->left;
		root->left = root->right;
		root->right = tnode;

		inorder(root->left);
		inorder(root->right);
	}
};