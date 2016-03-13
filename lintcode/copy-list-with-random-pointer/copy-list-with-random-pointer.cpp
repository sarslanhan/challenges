/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return head;

        map<RandomListNode*, RandomListNode*> nodes;

        RandomListNode *newHead = new RandomListNode(head->label);
        RandomListNode *current = newHead;

        nodes[head] = current;

        while (head && (head->next || head->random)) {
            if (head->next) {
                auto it = nodes.find(head->next);
                if (it != nodes.end()) {
                    current->next = (*it).second;
                } else {
                    current->next = new RandomListNode(head->next->label);
                    nodes[head->next] = current->next;
                }
            }

            if (head->random) {
                auto it = nodes.find(head->random);
                if (it != nodes.end()) {
                    current->random = (*it).second;
                } else {
                    current->random = new RandomListNode(head->random->label);
                    nodes[head->random] = current->random;
                }
            }

            current = current->next;
            head = head->next;
        }

        return newHead;
    }
};
