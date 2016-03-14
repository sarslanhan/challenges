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
    void print(string name, ListNode *node) {
        cout << name << ": ";
        if (!node) {
            cout << "empty" << endl;
            return;
        }
        while (node) {
            cout << node->val << ' ';
            node = node->next;
        }

        cout << endl;
    }
public:
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) return head;

        ListNode *pivot = head;
        ListNode *pivotHead = new ListNode(-1);
        ListNode *pivotEnd = pivotHead;
        ListNode *leftHead = new ListNode(-1);
        ListNode *leftEnd = leftHead;
        ListNode *current = head;

        while (current && current->next) {
            if (current->next->val < pivot->val) {
                leftEnd->next = current->next;
                current->next = current->next->next;
                leftEnd->next->next = nullptr;
                leftEnd = leftEnd->next;
                continue;
            } else if (current->next->val == pivot->val) {
                pivotEnd->next = current->next;
                current->next = current->next->next;
                pivotEnd->next->next = nullptr;
                pivotEnd = pivotEnd->next;
                continue;
            }

            current = current->next;
        }

        ListNode *left = leftHead->next;
        ListNode *right = pivot->next;

        left = sortList(left);
        right = sortList(right);

        if (pivotHead->next) {
            pivot->next = pivotHead->next;
            pivotEnd->next = right;
        } else {
            pivot->next = right;
        }

        if (!left) return pivot;

        leftEnd = left;
        while (leftEnd && leftEnd->next) leftEnd = leftEnd->next;

        leftEnd->next = pivot;

        return left;
    }
};
