#define NULL 0
struct ListNode {
	 int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head==nullptr || k==0)
		{
			return head;
		}
		int len = 1;
		ListNode *p = head;
		while(p->next)
		{
			p = p->next;
			len++;
		}
		
		k %= len;
		if (k==0)
		{
			return head;
		}
		p = head;
		for (int i=0; i<len-k-1; i++)
		{
			p = p->next;
		}

		ListNode *newHead = p->next;
		p->next = nullptr;
		p = newHead;
		while(p->next)
		{
			p = p->next;
		}
		p->next = head;
		return newHead;
	}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head==nullptr || k==0)
		{
			return head;
		}
		int len = 1;
		ListNode *p = head;
		while(p->next)
		{
			p = p->next;
			len++;
		}

		k = len - k % len;
		p->next = head;
		for (int i=0; i<k; i++)
		{
			p = p->next;
		}
		head = p->next;
		p->next = nullptr;
		return head;
	}
};