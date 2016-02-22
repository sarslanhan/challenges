#include <iostream>

using namespace std;

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *root = new ListNode(-1);
        ListNode *last = root;

        while (l1 || l2) {
            ListNode *c;
            if (l1 && l2) {
                if (l1->val > l2->val) {
                    c = l2;
                    l2 = l2->next;
                } else {
                    c = l1;
                    l1 = l1->next;
                }
            } else if(l1) {
                c = l1;
                l1 = l1->next;
            } else {
                c = l2;
                l2 = l2->next;
            }

            last->next = new ListNode(c->val);
            last = last->next;
        }

        return root->next;
    }
};
