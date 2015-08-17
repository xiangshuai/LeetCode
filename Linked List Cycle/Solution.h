#define NULL 0

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (!head || !head->next)
		{
			return false;
		}
		ListNode *low = head;
		ListNode *fast = head;
		while(low && fast)
		{
			low = low->next;
			fast = fast->next->next;
			
			if (low==fast)
			{
				return true;
			}
		}
		return false;
	}
};