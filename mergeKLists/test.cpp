#include "Solution.h"
#include <iostream>

int main()
{
	ListNode l11(2);
	ListNode l12(4);
	ListNode l13(6);
	l11.next = &l12;
	l12.next = &l13;

	ListNode l21(1);
	ListNode l22(3);
	ListNode l23(4);
	l21.next = &l22;
	l22.next = &l23;

	vector<ListNode*> lists;
	lists.push_back(&l11);
	lists.push_back(&l21);

	Solution2 sl;
	ListNode *head = sl.mergeKLists(lists);
	ListNode *p1 = head;
	while(p1)
	{
		cout << p1->val << endl;
		p1 = p1->next;
	}
}