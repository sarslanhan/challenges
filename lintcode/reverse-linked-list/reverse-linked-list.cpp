/**
 * Definition of ListNode
 *
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *
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
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        if (!head) return head;
        if (!head->next) return head;

        ListNode *node = head->next;

        ListNode *last = head;
        last->next = nullptr;

        while (node != nullptr) {
            ListNode *temp = node->next;
            node->next = last;
            last = node;
            node = temp;
        }

        return last;
    }
};
