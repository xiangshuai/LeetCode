#define NULL 0
#define abs(x) x > 0 ? x : -x
#define max(x, y) x >y ? x : y

 struct TreeNode {
	 int val;
	 TreeNode *left;
	 TreeNode *right;
	 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
	bool isBalanced(TreeNode *root) {
		if (root==NULL)
		{
			return true;
		}
		int left = depth(root->left);
		int right = depth(root->right);
		if (abs(left-right)>1)
		{
			return false;
		}
		return isBalanced(root->left) && isBalanced(root->right);
	}
	int depth(TreeNode *root)
	{
		if (root==NULL)
		{
			return 0;
		}
		return max(depth(root->left), depth(root->right))+1;
	}
};

class Solution1 {
public:
	bool isBalanced(TreeNode *root) {
		return depth(root)>=0;
	}
	int depth(TreeNode *root)
	{
		if (root==NULL)
		{
			return 0;
		}

		int left = depth(root->left);
		int right = depth(root->right);
		if (left==-1 || right==-1 || abs(left-right)>1)
		{
			return -1;
		}
		return max(left, right)+1;
	}
};