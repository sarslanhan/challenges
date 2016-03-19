/**
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

    void replaceInParent(TreeNode *parent, TreeNode *node, TreeNode *replacement) {
        if (!parent) return;

        //cout << "replacing " << node->val << " in parent " << parent->val << " with " << (replacement ? to_string(replacement->val) : "null") << endl;

        if (parent->left == node) parent->left = replacement;
        else if(parent->right == node) parent->right = replacement;
    }

    void removeNode(TreeNode *node, TreeNode *parent, int value) {
        if (!node) return;

        //cout << "in node " << node->val << " of parent " << parent->val << endl;

        if (node->val == value) {
            if (!node->left && !node->right) {
                replaceInParent(parent, node, nullptr);
            } else if (node->left && !node->right) {
                replaceInParent(parent, node, node->left);
            } else if (node->right && !node->left) {
                replaceInParent(parent, node, node->right);
            } else {
                TreeNode *current = node->right;
                TreeNode *currentParent = node;

                while (current->left) {
                    currentParent = current;
                    current = current->left;
                }

                node->val = current->val;
                replaceInParent(currentParent, current, nullptr);
            }
        } else if (node->val < value) {
            removeNode(node->right, node, value);
        } else {
            removeNode(node->left, node, value);
        }
    }

public:
    /**
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode* removeNode(TreeNode* root, int value) {
        if (!root) return root;

        TreeNode *dummyRoot = new TreeNode(-1);
        dummyRoot->left = root;

        removeNode(root, dummyRoot, value);

        return dummyRoot->left;
    }
};
