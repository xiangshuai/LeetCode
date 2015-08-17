#define NULL 0

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		ListNode *fkHead = new ListNode(0);
		ListNode *tp = fkHead;
		ListNode *node = fkHead;
		ListNode *pre = fkHead;
		fkHead->next = head;

		int k=0;
		while(tp!=NULL)
		{
			k++;
			tp = tp->next;
			if (k>n)
			{
				pre = node;
				node = node->next;
			}
		}
		pre->next = node->next;
		if (node==head)
		{
			head = pre->next;
		}
		
		return head;
	}
};