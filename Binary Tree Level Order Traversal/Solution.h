#include <vector>
#include <queue>
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
	vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int>> result;
		if (root==NULL)
		{
			return result;
		}
		
		queue<TreeNode*> q1;
		queue<TreeNode*> q2;
		q1.push(root);

		while(!q1.empty())
		{
			vector<int> level;
			while(!q1.empty())
			{
				TreeNode *node = q1.front();
				q1.pop();
				level.push_back(node->val);
				if (node->left)
				{
					q2.push(node->left);
				}
				if (node->right)
				{
					q2.push(node->right);
				}
			}
			std::swap(q1, q2);
			result.push_back(level);
		}
	}
};

class Solution1 {
public:
	vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int>> result;
		if (root==NULL)
		{
			return result;
		}
		queue<TreeNode*> que;
		que.push(root);
		TreeNode *split = NULL;

		while(!que.empty())
		{
			que.push(split);
			vector<int> level;
			while(que.front()!=split)
			{
				TreeNode *node = que.front();
				que.pop();
				level.push_back(node->val);
				if (node->left)
				{
					que.push(node->left);
				}
				if (node->right)
				{
					que.push(node->right);
				}
			}
			que.pop();
			result.push_back(level);
		}
		return result;
	}
};

class Solution2
{
public:
	vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int>> result;
		if (root==NULL)
		{
			return result;
		}
		levelOrderRecusion(root, 0, result);
		return result;
	}

	void levelOrderRecusion(TreeNode* root, int level, vector<vector<int>> &result)
	{
		if (level >= result.size())
		{
			result.push_back(vector<int>());
		}
		result[level].push_back(root->val);
		if (root->left)
		{
			levelOrderRecusion(root->left, level+1, result);
		}
		if (root->right)
		{
			levelOrderRecusion(root->right, level+1, result);
		}
	}
};