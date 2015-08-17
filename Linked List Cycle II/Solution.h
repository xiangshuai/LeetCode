#include <map>
#include <iostream>
using namespace std;
#define NULL 0

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		map<ListNode*, bool> visited;
		for (ListNode *cur=head; cur!=nullptr; cur=cur->next)
		{
			if (visited[cur]==true)
			{
				return cur;
			}
			visited[cur] = true;
		}
		return nullptr;
	}
};

class Solution2 {
public:
	ListNode *detectCycle(ListNode *head) {
		if (!head || !head->next)
		{
			return nullptr;
		}
		ListNode *low = head;
		ListNode *fast = head;
		while(fast && fast->next)
		{
			low = low->next;
			fast = fast->next->next;

			if (low==fast)
			{
				ListNode *low2 = head;
				while(low2!=low)
				{
					low2 = low2->next;
					low = low->next;
				}
				return low;
			}
		}
		return nullptr;
	}
};
