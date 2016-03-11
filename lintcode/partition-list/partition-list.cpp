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
    void print(string name, ListNode* head) {
        if (!head) return;

        cout << name << ' ';
        while(head) {
            cout << head->val << ' ';
            head = head->next;
        }

        cout << endl;
    }
public:
    /**
     * @param head: The first node of linked list.
     * @param x: an integer
     * @return: a ListNode
     */
    ListNode *partition(ListNode *head, int x) {
        ListNode *afterHead = new ListNode(-1);
        ListNode *beforeHead = new ListNode(-1);

        ListNode *after = afterHead;
        ListNode *before = beforeHead;

        ListNode *node = head;

        while (node != nullptr) {
            if (node->val < x) {
                before->next = node;
                before = before->next;
            } else {
                after->next = node;
                after = after->next;
            }

            //print("before", beforeHead->next);
            //print("after", afterHead->next);

            node = node->next;
        }

        before->next = afterHead->next;
        after->next = nullptr;
        //    cout << node << " - " << before << " " << after << endl;

        head = beforeHead->next;

        delete beforeHead;
        delete afterHead;

        return head;
    }
};


