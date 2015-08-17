#define NULL 0

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head || !head->next)
		{
			return head;
		}

		ListNode *cur = head->next;
		if (head->val==cur->val)
		{
			while (cur && cur->val==head->val)
			{
				ListNode *tmp = cur;
				cur = cur->next;
				head->next = cur;
				delete tmp;
			}
			delete head;
			return deleteDuplicates(cur);
		}
		else
		{
			head->next = deleteDuplicates(head->next);
			return head;
		}
	}
};

class Solution2 {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head)
		{
			return head;
		}
		ListNode dummy(0);
		ListNode *prev = &dummy;

		ListNode *pcur = head;
		ListNode *cur = head->next;
		while(cur)
		{
			if (pcur->val==cur->val)
			{
				while(cur && cur->val==pcur->val)
				{
					cur = cur->next;
				}
				if (!cur)
				{
					break;
				}
			}
			else
			{
				prev->next = pcur;
				prev = pcur;
				prev->next = nullptr;
			}
			pcur = cur;
			cur = cur->next;
		}
		if (!pcur->next)
		{
			prev->next = pcur;
		}
		return dummy.next;
	}
};