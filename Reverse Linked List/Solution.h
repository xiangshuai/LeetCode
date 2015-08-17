#define NULL 0
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
		if(head==NULL)
		{
			return head;
		}
		
		ListNode dummy(-1);
		dummy.next = head;
		ListNode *p = head->next;
		head->next = nullptr;
		while(p)
		{
			ListNode *next = p->next;
			p->next = dummy.next;
			dummy.next = p;
			p = next;
		}
		return dummy.next;
    }
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
		if(head==NULL)
		{
			return head;
		}
		ListNode *rhead;
		reverse(head, &rhead);
		return rhead;
    }

	void reverse(ListNode *p, ListNode **rhead)
	{
		if(p->next==NULL)
		{
			*rhead = p;
			return;
		}
		reverse(p->next, rhead);
		p->next->next = p;
		p->next = nullptr;
	}
};