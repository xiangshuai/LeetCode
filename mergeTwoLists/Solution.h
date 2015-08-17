#define NULL 0

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {

		ListNode *fkHead = new ListNode(0);
		ListNode *p1 = l1;
		ListNode *p2 = l2;
		ListNode *pre = fkHead;

		while(p1!=NULL && p2!=NULL)
		{
			if (p1->val<=p2->val)
			{
				pre->next = p1;
				p1 = p1->next;
				pre = pre->next;
			}
			else
			{
				pre->next = p2;
				p2 = p2->next;
				pre = pre->next;
			}
		}
		if (p1)
		{
			pre->next = p1;
		}
		else
		{
			pre->next = p2;
		}
		return fkHead->next;
	}
};