#define NULL 0

struct RandomListNode {
	int label;     
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (!head)
		{
			return head;
		}
		
		RandomListNode *cur = head;
		while(cur)
		{
			RandomListNode *newNode = new RandomListNode(cur->label);
			newNode->next = cur->next;
			cur->next = newNode;
			cur = newNode->next;
		}
		cur = head;
		while(cur)
		{
			if (cur->random)
			{
				cur->next->random = cur->random->next;
			}
			cur = cur->next->next;
		}
		RandomListNode dummy(-1);
		RandomListNode *prev = &dummy;
		cur = head;
		while (cur)
		{
			prev->next = cur->next;
			prev = prev->next;

			cur->next = cur->next->next;
			cur = cur->next;
		}
		return dummy.next;
	}
};