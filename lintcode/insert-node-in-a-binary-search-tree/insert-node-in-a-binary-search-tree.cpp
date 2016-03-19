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
public:
    /**
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        if (!root) return node;

        TreeNode *current = root;

        while (current) {
            if (current->val > node->val) {
                if (!current->left) {
                    current->left = node;
                    break;
                }

                current = current->left;
            } else {
                if (!current->right) {
                    current->right = node;
                    break;
                }

                current = current->right;
            }
        }

        return root;
    }
};
