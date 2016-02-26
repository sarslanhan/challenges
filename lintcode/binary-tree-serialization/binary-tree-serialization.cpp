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
     * This method will be invoked first, you should design your own algorithm
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        if (root == NULL) return "# ";

        return to_string(root->val) + ' ' + serialize(root->left) + serialize(root->right);
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in
     * "serialize" method.
     */
    TreeNode *deserialize(istringstream &iss) {
        if (!iss.good()) return NULL;

        string val;

        iss >> val;

        if (val.compare("#") == 0) return NULL;
        else {
            TreeNode *node = new TreeNode(stoi(val));
            node->left = deserialize(iss);
            node->right = deserialize(iss);

            return node;
        }
    }

    TreeNode *deserialize(string data) {
        istringstream iss(data);

        return deserialize(iss);
    }
};
