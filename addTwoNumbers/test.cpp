#include "Solution.h"
#include <iostream>
using namespace std;

int main()
{
	ListNode *n11 = new ListNode(1);
	ListNode *n12 = new ListNode(4);
	ListNode *n13 = new ListNode(6);
	ListNode *n14 = new ListNode(8);
	ListNode n15(1);
	n11->next = n12;
	n12->next = n13;
	n13->next = n14;

	ListNode *r1 = &n15;
	while(r1!=NULL)
	{
		cout << r1->val;
		if (r1->next)
		{
			cout << "->";
		}
		r1=r1->next;
	}
	cout << endl;

	ListNode *n21 = new ListNode(2);
	ListNode *n22 = new ListNode(6);
	ListNode *n23 = new ListNode(7);
	ListNode *n24 = new ListNode(6);
	ListNode n25(9);
	n21->next = n22;
	n22->next = n23;
	//n23->next = n24;

	ListNode *r2 = &n25;
	while(r2!=NULL)
	{
		cout << r2->val;
		if (r2->next)
		{
			cout << "->";
		}
		r2=r2->next;
	}
	cout << endl;

	Solution sl;
	ListNode *rs = sl.addTwoNumbers(&n15, &n25);

	while(rs!=NULL)
	{
		cout << rs->val;

		if (rs->next)
		{
			cout << "->";
		}

		rs=rs->next;
	}
	cout << endl;
}