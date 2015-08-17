#define NULL 0

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {

		ListNode ldummy(-1);
		ListNode rdummy(-1);
		ListNode *lprev = &ldummy;
		ListNode *rprev = &rdummy;
		ListNode *cur = head;

		while(cur)
		{
			if (cur->val<x)
			{
				lprev->next = cur;
				lprev = cur;
			}
			else
			{
				rprev->next = cur;
				rprev = cur;
			}
			cur = cur->next;
		}
		lprev = rdummy.next;
		rprev->next = nullptr;
		return ldummy.next;
	}
};