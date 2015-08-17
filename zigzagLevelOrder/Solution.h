#include <vector>
#include <queue>
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
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int>> result;
		if (root==NULL)
		{
			return result;
		}
		levelOrder(root, result);
		for (int i=0; i<result.size(); i++)
		{
			if (i & 0x1)
			{
				reverse(result[i].begin(), result[i].end());
			}
		}
		return result;
	}

	void levelOrder(TreeNode *root, vector<vector<int>> &result)
	{
		queue<TreeNode *> que1;
		queue<TreeNode *> que2;
		vector<int> level;
		que1.push(root);
		while(!que1.empty())
		{
			TreeNode *cur = que1.front();
			que1.pop();
			level.push_back(cur->val);
			if (cur->left)
			{
				que2.push(cur->left);
			}
			if (cur->right)
			{
				que2.push(cur->right);
			}

			if (que1.empty())
			{
				swap(que1, que2);
				result.push_back(level);
				level.clear();
			}
		}
	}
};