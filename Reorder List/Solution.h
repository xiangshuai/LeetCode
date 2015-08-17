#define NULL 0

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void reorderList(ListNode* head) {
		if (!head || !head->next || !head->next->next)
		{
			return ;
		}

		ListNode *low = head;
		ListNode *fast = head;
		while(fast->next && fast->next->next)
		{
			fast = fast->next->next;
			low = low->next;
		}
		
		ListNode *right = reverse(low->next);
		low->next = nullptr;
		
		ListNode *left = head;
		ListNode dummy(-1);
		ListNode *prev = &dummy;
		while(left && right)
		{
			prev->next = left;
			prev = prev->next;
			left = left->next;
			prev->next = right;
			right = right->next;
			prev = prev->next;
		}
		if (left)
		{
			prev->next = left;
		}
	}

	ListNode* reverse(ListNode *head)
	{
		if (!head || !head->next)
		{
			return head;
		}
		ListNode *prev = head;
		ListNode *cur = head->next;
		ListNode *next = cur->next;
		while(cur)
		{
			cur->next = prev;
			prev = cur;
			cur = next;
			next = next ? next->next : nullptr;
		}
		head->next = nullptr;
		return prev;
	}
};