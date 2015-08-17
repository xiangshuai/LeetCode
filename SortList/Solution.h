#define NULL 0

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (head==NULL || head->next==NULL)
		{
			return head;
		}
		
		ListNode *fast = head, *slow = head;
		while (fast->next && fast->next->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		ListNode *nd = slow->next;
		slow->next = NULL;

		ListNode *L1 = sortList(head);
		ListNode *L2 = sortList(nd);
		return mergeTwoLists(L1, L2);
	}

	ListNode* mergeTwoLists(ListNode* L1, ListNode* L2)
	{
		ListNode dummy(0);
		ListNode* p = &dummy;
		while(L1 && L2)
		{
			if (L1->val <= L2->val)
			{
				p->next = L1;
				L1 = L1->next;
				p = p->next;
			}
			else
			{
				p->next = L2;
				L2 = L2->next;
				p = p->next;
			}
		}
		while(L1)
		{
			p->next = L1;
			L1 = L1->next;
			p = p->next;
		}
		while(L2)
		{
			p->next = L2;
			L2 = L2->next;
			p = p->next;
		}
		return dummy.next;
	}
};