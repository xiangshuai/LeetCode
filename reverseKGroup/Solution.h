#define NULL 0

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *reverseKGroup(ListNode *head, int k) {
		ListNode dummy(0);
		dummy.next = head;
		ListNode *pre = &dummy;
		while (head)
		{
			int i;
			for (i=1; i<k && head->next; i++)
			{
				head = head->next;
			}
			if (k==i)
			{
				ListNode *last = pre->next;
				head = pre->next->next;
				for (int i=1; i<k; i++)
				{
					ListNode *t = head->next;
					head->next = pre->next;
					pre->next = head;
					head = t;
				}
				pre = last;
				last->next = head;
			}
			else
				break;
		}
		return dummy.next;
	}
	
};