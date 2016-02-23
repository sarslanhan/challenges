#include <vector>
#include <iostream>
#include <algorithm>

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if (lists.size() == 0) return NULL;
        else if (lists.size() == 1) return *lists.begin();

        vector<int> heap;

        make_heap(heap.begin(), heap.end());

        for (int i=0; i<lists.size();i++) {
            ListNode *current = lists[i];

            while (current != NULL) {
                heap.push_back(current->val);
                push_heap(heap.begin(), heap.end());

                current = current->next;
            }
        }

        sort_heap(heap.begin(), heap.end());

        ListNode *head = new ListNode(-1);
        ListNode *last = head;

        for (int i=0; i<heap.size(); i++) {
            last->next = new ListNode(heap[i]);
            last = last->next;
        }

        return head->next;
    }
};

int main() {
    Solution s;

    ListNode *a = new ListNode(1);

    vector<ListNode*> l = { NULL, a };

    s.mergeKLists(l);
}
