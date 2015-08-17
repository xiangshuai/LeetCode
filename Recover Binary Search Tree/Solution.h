#define NULL 0 
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void recoverTree(TreeNode* root) {
		vector<TreeNode*> list;
		vector<int> vals;
		inOrder(root, list, vals);
		sort(vals.begin(), vals.end());
		for (int i=0; i<list.size(); i++)
		{
			list[i]->val = vals[i];
		}
	}

	void inOrder(TreeNode* root, vector<TreeNode*> &list, vector<int> &vals)
	{
		if (!root)
		{
			return ;
		}

		inOrder(root->left, list, vals);
		list.push_back(root);
		vals.push_back(root->val);
		inOrder(root->right, list, vals);
	}

private:
	static bool less(TreeNode* a, TreeNode* b)
	{
		return a->val < b->val;
	}
};