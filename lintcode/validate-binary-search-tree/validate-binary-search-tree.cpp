
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
    bool isValidBST(TreeNode *root, long min, long max) {
        if (!root) return true;

        return (long) root->val > min
            && (long) root->val < max
            && isValidBST(root->left, min, root->val)
            && isValidBST(root->right, root->val, max);
    }
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        return isValidBST(root, numeric_limits<long>::min(), numeric_limits<long>::max());
    }
};
