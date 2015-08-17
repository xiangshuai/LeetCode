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
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> result;
		postorderRecusion(root, result);
		return result;
	}

	void postorderRecusion(TreeNode *root, vector<int> &result)
	{
		if (root!=NULL)
		{
			postorderRecusion(root->left, result);
			postorderRecusion(root->right, result);
			result.push_back(root->val);
		}
	}
};

class Solution2
{
public:
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> result;
		postorderStack(root, result);
		return result;
	}

	void postorderStack(TreeNode *root, vector<int> &result)
	{
		if (root==NULL)
		{
			return ;
		}
		stack<TreeNode*> st;
		st.push(root);
		while(!st.empty())
		{
			TreeNode *cur = st.top();
			st.pop();
			result.push_back(cur->val);
			if (cur->left)
			{
				st.push(cur->left);
			}
			if (cur->right)
			{
				st.push(cur->right);
			}
		}
		std::reverse(result.begin(), result.end());
	}
};

class Solution3
{
public:
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> result;
		postorderStack(root, result);
		return result;
	}

	void postorderStack(TreeNode *root, vector<int> &result)
	{
		if (root==NULL)
		{
			return ;
		}
		stack<TreeNode*> st;
		TreeNode * last = NULL;
		st.push(root);
		while(!st.empty())
		{
			TreeNode *cur = st.top();
			if ((cur->left==NULL && cur->right==NULL) || last && (cur->right==last || cur->left==last))
			{
				st.pop();
				result.push_back(cur->val);
				last = cur;
			}
			else
			{
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
	}
};