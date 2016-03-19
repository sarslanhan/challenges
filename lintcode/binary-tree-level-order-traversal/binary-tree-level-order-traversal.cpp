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
    void levelOrder(TreeNode *root, int level, vector<vector<int>> &levels) {
        if (!root) return;

        if (levels.size() <= level) {
            levels.push_back(vector<int>{root->val});
        } else {
            levels[level].push_back(root->val);
        }

        levelOrder(root->left, level + 1, levels);
        levelOrder(root->right, level + 1, levels);
    }
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> result;

        levelOrder(root, 0, result);

        return result;
    }
};
