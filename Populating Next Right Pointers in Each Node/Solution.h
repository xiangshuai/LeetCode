#define NULL 0 
#include <queue>
using namespace std;


struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };
 

// TLE
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root)
        {
			return ;
        }

		queue<TreeLinkNode*> que1;
		queue<TreeLinkNode*> que2;
		que1.push(root);
		TreeLinkNode dummy(0);
		TreeLinkNode* pre = &dummy;
		while(!que1.empty() || !que2.empty())
		{
			while(!que1.empty())
			{
				TreeLinkNode* cur = que1.front();
				que1.pop();
				pre->next = cur;
				pre = pre->next;
				if (cur->left)
				{
					que2.push(cur->left);
				}
				if (cur->right)
				{
					que2.push(cur->right);
				}
			}
			while(!que2.empty())
			{
				TreeLinkNode* cur = que2.front();
				que2.pop();
				pre->next = cur;
				pre = pre->next;
				if (cur->left)
				{
					que1.push(cur->left);
				}
				if (cur->right)
				{
					que1.push(cur->right);
				}
			}
		}
    }
};

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (root==NULL)
		{
			return ;
		}
		if (root->left)
		{
			root->left->next = root->right;
		}
		if (root->right)
		{
			root->right->next = root->next ? root->next->left : NULL;
		}
		connect(root->left);
		connect(root->right);
	}
};