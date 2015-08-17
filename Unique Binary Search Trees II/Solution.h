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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
		dfs(1, n, res);
		return res;
    }

	void dfs(int st, int ed, vector<TreeNode*> &res)
	{
		if (st>ed)
		{
			res.push_back(NULL);
			return ;
		}

		for (int i=st; i<=ed; i++)
		{
			vector<TreeNode*> left;
			dfs(st, i-1, left);
			vector<TreeNode*> right;
			dfs(i+1, ed, right);

			for (int li=0; li<left.size(); li++)
			{
				for (int lr=0; lr<right.size(); lr++)
				{
					TreeNode* root = new TreeNode(i);
					root->left = left[li];
					root->right = right[lr];
					res.push_back(root);
				}
			}
		}
	}
};