#define NULL 0
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return helper(preorder, inorder, 0, 0, preorder.size());
	}

	TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int formp, int fromi, int length)
	{
		if (length==0)
		{
			return nullptr;
		}

		TreeNode* root = new TreeNode(preorder[formp]);
		int i = fromi;
		while (inorder[i]!=root->val)
		{
			i++;
		}
		root->left = helper(preorder, inorder, formp+1, fromi, i-fromi);
		root->right = helper(preorder, inorder, formp+i-fromi+1, i+1, length-1-i+fromi);
		return root;
	}
};