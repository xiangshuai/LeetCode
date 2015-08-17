#include <vector>
#include <stack>
using namespace std;
#define NULL 0

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> result;
		preorderRecusion(root, result);
		return result;
	}

	void preorderRecusion(TreeNode *root, vector<int> &result)
	{
		if (root!=NULL)
		{
			result.push_back(root->val);
			preorderRecusion(root->left, result);
			preorderRecusion(root->right, result);
		}
	}
};

class Solution2
{
public:
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> result;
		preorderStack(root, result);
		return result;
	}

	void preorderStack(TreeNode *root, vector<int> &result)
	{
		if (root==NULL)
		{
			return;
		}
		stack<TreeNode*> st;
		st.push(root);
		while(!st.empty())
		{
			TreeNode *cur = st.top();
			st.pop();
			result.push_back(cur->val);
			if (cur->right)
			{
				st.push(cur->right);
			}
			if (cur->left)
			{
				st.push(cur->left);
			}
		}
	}
};