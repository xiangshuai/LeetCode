#define NULL 0
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
	int kthSmallest(TreeNode* root, int k) {
		stack<TreeNode*> stk;
		TreeNode* node = root;
		while(node)
		{
			stk.push(node);
			node = node->left;
		}
		
		while(!stk.empty() && k-->0)
		{
			node = stk.top();
			stk.pop();
			TreeNode* right = node->right;
			while (right)
			{
				stk.push(right);
				right = right->left;
			}
		}
		return node->val;
	}
};


class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		stack<TreeNode*> s;
		TreeNode* p=root;
		s.push(p);
		int cnt=0;
		do{
			while(p){
				s.push(p);
				p=p->left;
			}
			TreeNode* top=s.top();
			s.pop();
			cnt++;
			if(cnt==k){
				return top->val;
			}
			p=top->right;
		}while(!s.empty());
		return 0;
	}
};