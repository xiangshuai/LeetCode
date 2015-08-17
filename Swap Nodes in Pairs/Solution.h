
#define NULL 0

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *swapPairs(ListNode *head) {
		ListNode *helper = new ListNode(0);
		helper->next = head;
		ListNode *p1 = helper;
		ListNode *p2 = helper;
		ListNode *pre = helper;

		int k=0;
		while(p1!=NULL)
		{
			p1 = p1->next;
			if (k>=1)
			{
				pre = p2;
				p2 = p2->next;
			}
			k++;

			if (k%2==0 && p1!=NULL)//½»»»
			{
				p2->next = p1->next;
				p1->next = p2;
				pre->next = p1;
				ListNode *t = p2;
				p2 = p1;
				p1 = t;
			}
		}
		return helper->next;
	}
};