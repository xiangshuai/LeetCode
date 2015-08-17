#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define NULL 0

 struct ListNode {
	 int val;
	 ListNode *next;
	 ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		ListNode *head = NULL;
		if (lists.size()<1)
		{
			return head;
		}
		head = lists[0];
		for (int i=1; i<lists.size(); i++)
		{
			head = merge2Lists(head, lists[i]);
		}
		return head;
	}

	ListNode *merge2Lists(ListNode *l1, ListNode *l2)
	{
		if (l1==NULL)
		{
			return l2;
		}
		if (l2==NULL)
		{
			return l1;
		}

		ListNode helper(0);
		ListNode *p1 = l1;
		ListNode *p2 = l2;
		ListNode *pre = &helper;

		while(p1 && p2)
		{
			if (p1->val<=p2->val)
			{
				pre->next = p1;
				p1 = p1->next;
				pre = pre->next;
			}
			else
			{
				pre->next = p2;
				p2 = p2->next;
				pre = pre->next;
			}
		}
		if (p1)
		{
			pre->next = p1;
		}
		else if(p2)
		{
			pre->next = p2;
		}

		return helper.next;
	}
};

class Solution1 {
public:
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		ListNode *head = NULL;
		if (lists.empty())
		{
			return head;
		}
		int n = lists.size();
		return helper(lists, 0, n-1);
	}
private:
	ListNode *helper(vector<ListNode*> &lists, int l, int r)
	{
		if (l<r)
		{
			int m = (l+r)/2;
			return merge(helper(lists, l, m), helper(lists, m+1, r));
		}
		return lists[l];
	}
	ListNode *merge(ListNode *l1, ListNode *l2)
	{
		ListNode dummy(0);
		if (l1==NULL)
		{
			return l2;
		}
		if (l2==NULL)
		{
			return l1;
		}

		ListNode *pre = &dummy;
		ListNode *p1 = l1;
		ListNode *p2 = l2;

		while(p1 && p2)
		{
			if (p1->val<=p2->val)
			{
				pre->next = p1;
				p1 = p1->next;
				pre = pre->next;
			}
			else
			{
				pre->next = p2;
				p2 = p2->next;
				pre = pre->next;
			}
		}
		if (p1)
		{
			pre->next = p1;
		}
		if (p2)
		{
			pre->next = p2;
		}
		return dummy.next;
	}
};

struct cmp
{
	bool operator()(const ListNode *a, const ListNode *b)
	{
		return a->val > b->val;
	}
};
class Solution2 {
public:
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		if (lists.empty())
		{
			return NULL;
		}
		ListNode dummy(0);
		priority_queue<ListNode*, vector<ListNode*>, cmp> pq_type;
		int n = lists.size();

		for (int i=0; i<n; i++)
		{
			if (lists[i]!=NULL)
			{
				pq_type.push(lists[i]);
			}
		}

		ListNode *pre = &dummy;
		while(!pq_type.empty())
		{
			pre->next = pq_type.top();
			pq_type.pop();
			if (pre->next->next)
			{
				pq_type.push(pre->next->next);
			}
			pre = pre->next;
		}
		return dummy.next;
	}
};