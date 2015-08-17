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
	void flatten(TreeNode* root) {
		stack<TreeNode*> stk;
		TreeNode* p = root;
		while(p!=NULL || !stk.empty())
		{
			if (p->right)
			{
				stk.push(p->right);
			}

			if (p->left)
			{
				p->right = p->left;
				p->left = NULL;
			}
			else if(!stk.empty())
			{
				p->right = stk.top();
				stk.pop();
			}
			p = p->right;
		}
	}
};