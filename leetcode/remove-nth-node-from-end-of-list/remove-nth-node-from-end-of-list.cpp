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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *current = head;
        ListNode *second = head;
        while (n > 0) {
            second = second->next;
            n--;
        }

        while (second != NULL && second->next != NULL) {
            second = second->next;
            current = current->next;
        }

        if (second == NULL) return current->next;

        current->next = current->next->next;

        return head;
    }
};

int main() {
    Solution s;


}
