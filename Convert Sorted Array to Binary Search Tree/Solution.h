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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return arrayToTree(nums, 0, nums.size()-1);
	}

	TreeNode* arrayToTree(vector<int>& nums, int left, int right)
	{
		if (left<=right)
		{
			int mid = (left+right)/2;
			TreeNode* root = new TreeNode(nums[mid]);
			root->left = arrayToTree(nums, left, mid-1);
			root->right = arrayToTree(nums, mid+1, right);
			return root;
		}
		return NULL;
	}
};