#define NULL 0 
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root)
        {
			return 0;
        }
		int ld = 0, rd = 0;
		TreeNode* ln = root;
		TreeNode* rn = root;
		while(ln)
		{
			ln = ln->left;
			ld++;
		}
		while(rn)
		{
			rn = rn->right;
			rd++;
		}
		if (ld==rd)
		{
			return (1 << ld) - 1;
		}
		return countNodes(root->left)
			+ countNodes(root->right) + 1;
    }
};

class Solution {
public:
	int countNodes(TreeNode* root) {
		int height = getHeight(root);
		if (height==0)
		{
			return 0;
		}
		int count = 1 << (height-1) - 1;

	}

	int getHeight(TreeNode* root)
	{
		if (!root)
		{
			return 0;
		}
		return getHeight(root->left)+1;
	}
};