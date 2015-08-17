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
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> rets;
		if (!root)
		{
			return rets;
		}
		vector<int> item;
		dfs(root, sum, rets, item);
		return rets;
	}

	void dfs(TreeNode* root, int sum, vector<vector<int>> &rets, vector<int> &item)
	{
		if (!root->left && !root->right && root->val==sum)
		{
			rets.push_back(item);
			return ;
		}

		item.push_back(root->val);
		if (root->left)
		{
			dfs(root->left, sum-root->val, rets, item);
		}

		if (root->right)
		{
			dfs(root->right, sum-root->val, rets, item);
		}
		item.pop_back();
	}
};