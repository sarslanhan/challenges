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
    /**
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) return head;
        else if(!head->next) return head;

        ListNode *first = head;
        ListNode *second = head;

        while (k > 0) {
            second = second->next;
            k--;

            if (second == nullptr) {
                second = head;
            }
        }

        while (second != nullptr && second->next != nullptr) {
            second = second->next;
            first = first->next;
        }

        second->next = head;

        head = first->next;

        first->next = nullptr;

        return head;
    }
};

int main() {
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(3);
    ListNode *d = new ListNode(4);
    ListNode *e = new ListNode(5);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    Solution s;

    ListNode *l = s.rotateRight(a, 2);

    while (l != nullptr) {
        cout << l->val << ' ';
        l = l->next;
    }

    cout << endl;
}
