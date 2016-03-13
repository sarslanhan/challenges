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
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        else if (!head->next) return false;

        if (head->next == head) return true;

        ListNode *temp = head->next;
        head->next = head;

        return hasCycle(temp);
    }
};


