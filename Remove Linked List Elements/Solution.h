#define NULL 0

struct ListNode {
	 int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode dummy(-1);
		ListNode *prev = &dummy;
		ListNode *p = head;
		prev->next = p;
		while(p)
		{
			if (p->val==val)
			{
				prev->next = p->next;
				delete p;
				p = prev->next;
			}
			else
			{
				prev = p;
				p = p->next;
			}
		}
		return dummy.next;
	}
};