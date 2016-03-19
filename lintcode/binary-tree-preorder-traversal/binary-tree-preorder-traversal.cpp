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
    void preorderTraversal(TreeNode *root, vector<int> &results) {
        if (!root) return;

        results.push_back(root->val);
        preorderTraversal(root->left, results);
        preorderTraversal(root->right, results);
    }
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> results;

        preorderTraversal(root, results);

        return results;
    }
};
