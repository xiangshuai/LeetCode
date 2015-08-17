#define NULL 0

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {

		ListNode dummy(-1);
		dummy.next = head;

		ListNode *prev = &dummy;
		ListNode *cur = prev->next;
		for (int i=0; i<m-1; i++)
		{
			prev = cur;
			cur = cur->next;
		}

		ListNode *next = cur;
		ListNode *head2 = prev->next;
		for (int i=m; i<=n; i++)
		{
			next = cur->next;
			cur->next = prev->next;
			prev->next = cur;
			cur = next;
		}
		head2->next = cur;
		return dummy.next;
	}
};