#include <queue>
#include <vector>
#include <algorithm>
using namespace  std;
#define NULL 0
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> ret;
		queue<TreeNode*> que1, que2;
		if (!root)
		{
			return ret;
		}
		que1.push(root);
		while(!que1.empty() || !que2.empty())
		{
			vector<int> item;
			while(!que1.empty())
			{
				TreeNode* cur = que1.front();
				que1.pop();
				item.push_back(cur->val);
				if (cur->left)
				{
					que2.push(cur->left);
				}
				if (cur->right)
				{
					que2.push(cur->right);
				}
			}
			ret.push_back(item);
			swap(que1, que2);
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
};