#define NULL 0

struct ListNode {
    int val;
    ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        ListNode* low = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next) {
            low = low->next;
            fast = fast->next->next;
        }
        ListNode* p = low->next;
        low->next = NULL;
        while(p) {
            ListNode* cur = p;
            p = p->next;
            cur->next = low->next;
            low->next = cur;
        }
        ListNode* p1 = head;
        ListNode* p2 = low->next;
        while(p1 && p2) {
            if(p1->val!=p2->val) return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};