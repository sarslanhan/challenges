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
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *dummyHead = new ListNode(-1);
        ListNode *current = dummyHead;

        while (l1 != nullptr || l2 != nullptr) {
            if (l1 != nullptr && l2 != nullptr) {
                if (l1->val < l2->val) {
                    current->next = new ListNode(l1->val);
                    l1 = l1->next;
                } else {
                    current->next = new ListNode(l2->val);
                    l2 = l2->next;
                }
            } else if (l1 != nullptr) {
                current->next = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                current->next = new ListNode(l2->val);
                l2 = l2->next;
            }

            current = current->next;
        }

        return dummyHead->next;
    }
};
