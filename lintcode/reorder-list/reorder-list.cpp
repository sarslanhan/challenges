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
     * @return: void
     */
    void reorderList(ListNode *head) {
        ListNode* current = head;

        while (current != nullptr) {
            ListNode *last = current;
            while (last && last->next && last->next->next != nullptr) {
                last = last->next;
            }

            if (current != last) {
                ListNode *temp = current->next;
                current->next = last->next;
                last->next->next = temp;
                last->next = nullptr;

                current = temp;
            } else {
                current = current->next;
            }
        }
    }
};


