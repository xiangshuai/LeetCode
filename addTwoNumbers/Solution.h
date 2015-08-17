#define NULL 0

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		
		int carry = 0;
		ListNode *pnd = new ListNode(0);
		pnd->next = l1;
		ListNode *fl = l1;
		ListNode *sl = l2;
		while(fl!=NULL && sl!=NULL)
		{
			fl->val = fl->val + sl->val + carry;
			carry = fl->val / 10;
			fl->val = fl->val % 10;

			pnd = fl;
			fl = fl->next;
			sl = sl->next;
		}

		if (fl==NULL && sl!=NULL)
		{
			pnd->next = sl;
		}

		while(fl!=NULL)
		{
			fl->val += carry;
			carry = fl->val / 10;
			fl->val = fl->val % 10;
			pnd = fl;
			fl = fl->next;
		}

		while (sl!=NULL)
		{
			sl->val += carry;
			carry = sl->val / 10;
			sl->val = sl->val % 10;
			pnd = sl;
			sl = sl->next;
		}

		if (carry)
		{
			ListNode *nd = new ListNode(carry);
			pnd->next = nd;
		}
		return l1;
	}
};