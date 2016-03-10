/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int jump = n;

        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;

        ListNode *first = dummyHead;
        ListNode *second = dummyHead;
        while (n > 0 && second != nullptr) {
            second = second->next;

            n--;
        }

        while (second->next != nullptr) {
            first = first->next;
            second = second->next;
        }

        first->next = first->next->next;

        return dummyHead->next;
    }
};


