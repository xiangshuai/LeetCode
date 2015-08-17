#define NULL 0
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int minDepth(TreeNode* root) {
		if (!root)
		{
			return 0;
		}
		int lmind = minDepth(root->left);
		int rmind = minDepth(root->right);
		if (lmind==0 && rmind==0)
		{
			return 1;
		}

		if (lmind==0)
		{
			lmind = INT_MAX;
		}

		if (rmind==0)
		{
			lmind = INT_MAX;
		}

		return min(lmind, rmind) + 1;	
	}
};