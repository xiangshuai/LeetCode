#define NULL 0
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> ret;
		if (root==NULL)
		{
			return ret;
		}
		queue<TreeNode*> q1;
		q1.push(root);

		while (!q1.empty())
		{
			vector<TreeNode*> level;
			queue<TreeNode*> q2;
			while(!q1.empty())
			{
				TreeNode *node = q1.front();
				q1.pop();
				if (node->left)
				{
					q2.push(node->left);
				}
				if (node->right)
				{
					q2.push(node->right);
				}
				level.push_back(node);
			}
			ret.push_back(level[level.size()-1]->val);
			level.clear();
			q1 = q2;
		}
		return ret;
	}
};