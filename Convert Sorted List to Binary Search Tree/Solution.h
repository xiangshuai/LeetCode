#define NULL 0

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head==NULL)
        {
			return NULL;
        }
		ListNode* midNode = splitList(head);
		TreeNode* root = new TreeNode(midNode->val);
		if (head!=midNode)
		{
			root->left = sortedListToBST(head);
		}
		root->right = sortedListToBST(midNode->next);
		return root;
    }

	ListNode* splitList(ListNode* head)
	{
		ListNode dummy(0);
		dummy.next = head;
		ListNode* pre = &dummy;
		ListNode* low = head;
		ListNode* fast = head;
		while(low->next && fast->next && fast->next->next)
		{
			pre = low;
			low = low->next;
			fast = fast->next->next;
		}

		pre->next = NULL;
		return low;
	}
};