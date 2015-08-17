#include <vector>
#include <stack>
using namespace std;
#define NULL 0

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        this->root = root;
		this->curr = NULL;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (root==NULL)
        {
			return false;
        }

		if (curr==NULL)
		{
			return true;
		}

		if (curr->right!=NULL)
		{
			return true;
		}
		
		TreeNode *succ = NULL;
		TreeNode *troot = root;
		while(troot!=NULL)
		{
			if (troot->val > curr->val)
			{
				succ = troot;
				troot = troot->left;
			}
			else if (troot->val < curr->val)
			{
				troot = troot->right;
			}
			else
			{
				break;
			}
		}
		if (succ==NULL)
		{
			return false;
		}
		else
		{
			return true;
		}
    }

    /** @return the next smallest number */
    int next() {
        if (curr==NULL)
        {
			curr = root;
			while(curr->left!=NULL)
			{
				curr = curr->left;
			}
			return curr->val;
        }

		if (curr->right!=NULL)
		{
			TreeNode *succ = curr->right;
			while(succ->left!=NULL)
			{
				succ = succ->left;
			}
			curr = succ;
			return curr->val;
		}


		TreeNode *succ = NULL;
		TreeNode *troot = root;
		while(troot!=NULL)
		{
			if (troot->val > curr->val)
			{
				succ = troot;
				troot = troot->left;
			}
			else if (troot->val < curr->val)
			{
				troot = troot->right;
			}
			else
			{
				break;
			}
		}
		curr = succ;
		return curr->val;
    }

private:
	TreeNode *root;
	TreeNode *curr;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

 class BSTIterator {
 public:
	 BSTIterator(TreeNode *root) {
		 dfs(root);
		 this->index = 0;
	 }

	 void dfs(TreeNode *root)
	 {
		 if (root==NULL)
		 {
			 return ;
		 }
		 dfs(root->left);
		 list.push_back(root);
		 dfs(root->right);
	 }

	 /** @return whether we have a next smallest number */
	 bool hasNext() {
		 if (index<list.size())
		 {
			 return true;
		 }
		 return false;
	 }

	 /** @return the next smallest number */
	 int next() {
		return list[index++]->val;
	 }

 private:
	 int index;
	 vector<TreeNode*> list;
 };


 class BSTIterator {
 public:
	 BSTIterator(TreeNode *root) {
		 TreeNode *pt = root;
		 while(pt!=NULL)
		 {
			 st.push(pt);
			 pt = pt->left;
		 }
	 }

	 /** @return whether we have a next smallest number */
	 bool hasNext() {
		 return !st.empty();
	 }

	 /** @return the next smallest number */
	 int next() {
		 TreeNode *pt = st.top();
		 int ret = pt->val;
		 st.pop();
		 if(pt->right!=NULL)
		 {
			 pt = pt->right;
			 while(pt!=NULL)
			 {
				 st.push(pt);
				 pt = pt->left;
			 }
		 }
		 return ret;
	 }
 private:
	 stack<TreeNode*> st;
 };