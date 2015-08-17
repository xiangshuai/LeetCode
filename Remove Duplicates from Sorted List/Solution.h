#define NULL 0

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head==NULL)
		{
			return head;
		}
		ListNode dummy(head->val+1);
		ListNode *prev = &dummy;
		ListNode *cur = head;

		while(cur)
		{
			if (prev->val==cur->val)
			{
				prev->next = cur->next;
			}
			else
			{
				prev->next = cur;
				prev = cur;
			}
			cur = cur->next;
		}
		return dummy.next;
	}
};