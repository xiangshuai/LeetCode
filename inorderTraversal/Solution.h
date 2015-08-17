#include <vector>
#include <queue>
#include <stack>
#define NULL 0
#define abs(x) x > 0 ? x : -x
#define max(x, y) x >y ? x : y
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> inorderTraversal(TreeNode *root) {
		vector<int> result;
		inorderRecusion(root, result);
		return result;
	}

	void inorderRecusion(TreeNode *root, vector<int> &result)
	{
		if (root!=NULL)
		{
			inorderRecusion(root->left, result);
			result.push_back(root->val);
			inorderRecusion(root->right, result);
		}
	}
};

class Solution2 {
public:
	vector<int> inorderTraversal(TreeNode *root) {
		vector<int> result;
		inorderStack(root, result);
		return result;
	}

	void inorderStack(TreeNode *root, vector<int> &result)
	{
		stack<TreeNode*> st;
		TreeNode *next = root;
		while(next || !st.empty())
		{
			if (next)
			{
				st.push(next);
				next = next->left;
			}
			else
			{
				next = st.top();
				st.pop();
				result.push_back(next->val);
				next = next->right;
			}
		}
	}
};