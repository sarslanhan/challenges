/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;

        ListNode *s = new ListNode(-1);
        ListNode *c = s;

        while (l1 || l2 || carry) {
            int n = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;

            carry = n / 10;
            n = n % 10;

            c->next = new ListNode(n);
            c = c->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }

        return s->next;
    }
};
