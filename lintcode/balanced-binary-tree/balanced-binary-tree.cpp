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
    int inline abs(int n) {
        return n >= 0 ? n : (-1*n);
    }

    int isBalanced_(TreeNode *root) {
        if (!root) return 0;

        int left = isBalanced_(root->left);
        int right = isBalanced_(root->right);

        if (left == -1 || right == -1 || this->abs(left - right) > 1) return -1;

        return (left > right ? left : right) + 1;
    }
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        return isBalanced_(root) != -1;
    }
};
