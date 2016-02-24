#include <vector>
#include <string>

using namespace std;

/**
 * Definition of TreeNode:
 */
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution {
private:
    void generatePaths(TreeNode *root, vector<string> &paths, string current) {
        if (!root) return;

        if (current.empty()) current += to_string(root->val);
        else current += "->" + to_string(root->val);

        if (!root->left && !root->right) {
            paths.push_back(current);

            return;
        }

        generatePaths(root->left, paths, current);
        generatePaths(root->right, paths, current);
    }
public:
    /**
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;

        this->generatePaths(root, result, "");

        return result;
    }
};
