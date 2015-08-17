#define NULL 0

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		ListNode dummy(0);
		while(head)
		{
			ListNode *p = findPos(&dummy, head);
			ListNode *hp = head->next;
			head->next = p->next;
			p->next = head;
			head = hp;
		}
		return dummy.next;
	}

	ListNode* findPos(ListNode* dummy, ListNode* nd)
	{
		ListNode* pre = dummy;
		ListNode* p = dummy->next;
		while(p!=NULL)
		{
			if (nd->val >= p->val)
			{
				pre = p;
				p = p->next;
			}
			else
			{
				break;
			}
		}
		return pre;
	}

	
};