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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return helper(inorder, postorder, 0, postorder.size()-1, inorder.size());
	}

	TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int fromi, int fromp, int length)
	{
		if (length<=0)
		{
			return nullptr;
		}
		TreeNode* root = new TreeNode(postorder[fromp]);
		int i = fromi;
		while(inorder[i]!=root->val)
		{
			i++;
		}

		root->left = helper(inorder, postorder, fromi, fromp-fromi-length+i, i-fromi);
		root->right = helper(inorder, postorder, i+1, fromp-1, fromi+length-1-i);
		return root;
	}
};