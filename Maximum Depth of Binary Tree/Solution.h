#define NULL 0
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
    int maxDepth(TreeNode* root) {
		if (root==NULL)
		{
			return 0;
		}
		int ldp = maxDepth(root->left);
		int rdp = maxDepth(root->right);
		return max(ldp, rdp)+1;
    }
};