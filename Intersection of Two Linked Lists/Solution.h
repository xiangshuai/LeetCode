#define NULL 0
struct ListNode {
     int val;
    ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n = getLen(headA);
		int m = getLen(headB);

		ListNode *p1, *p2;
		if (n>=m)
		{
			p1 = headA;
			p2 = headB;
			for (int i=0; i<n-m; i++)
			{
				p1 = p1->next;
			}
		}
		else
		{
			p1 = headB;
			p2 = headA;
			for (int i=0; i<m-n; i++)
			{
				p1 = p1->next;
			}
		}

		while(p1 && p2 && p1!=p2)
		{
			p1 = p1->next;
			p2 = p2->next;
		}

		if (p1)
		{
			return p1;
		}
		return nullptr;
    }

	int getLen(ListNode *head)
	{
		int len = 0;
		ListNode *p = head;
		while(p)
		{
			p = p->next;
			len++;
		}
		return len;
	}
};