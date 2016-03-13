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
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
    int count (ListNode *node) {
        int c = 0;

        while (node) {
            node = node->next;
            c++;
        }

        return c;
    }

    TreeNode* generate (int n) {
        if (n == 0) return nullptr;

        TreeNode *node = new TreeNode(-1);

        node->left = generate(n/2);
        node->right = generate(n-n/2-1);

        return node;
    }

    ListNode* fill (ListNode *lnode, TreeNode *tnode) {
        if (!lnode || !tnode) return lnode;

        lnode = fill (lnode, tnode->left);
        tnode->val = lnode->val;
        lnode = lnode->next;
        lnode = fill(lnode, tnode->right);

        return lnode;
    }

public:
    /**
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        int c = count(head);
        TreeNode *root = generate(c);

        fill(head, root);

        return root;
    }
};


