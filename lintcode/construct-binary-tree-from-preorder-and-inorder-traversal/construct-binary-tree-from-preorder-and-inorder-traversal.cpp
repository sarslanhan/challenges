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

    void print(string name, vector<int> &list) {
        cout << name << ": ";

        for (auto &i : list) cout << i << " ";

        cout << endl;
    }

    int binarySearch(vector<int> &list, int target) {
        for (int i=0; i<list.size(); i++) {
            if (target == list[i]) return i;
        }

        return -1;
    }

    /**
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) return nullptr;

        //this->print("preorder", preorder);
        //this->print("inorder", inorder);

        int rootVal = preorder[0];
        TreeNode *root = new TreeNode(rootVal);

        int rootInorderIdx = this->binarySearch(inorder, rootVal);

        int leftSubtreeSize = 0;

        if (rootInorderIdx > 0) {
            leftSubtreeSize = rootInorderIdx;

            vector<int> leftInorder(inorder.begin(), inorder.begin()+leftSubtreeSize);
            vector<int> leftPreorder(preorder.begin()+1, preorder.begin()+1+leftSubtreeSize);

            root->left = buildTree(leftPreorder, leftInorder);
        }

        if (leftSubtreeSize + 1 < inorder.size()) {
            vector<int> rightInorder(inorder.begin() + rootInorderIdx + 1, inorder.end());
            vector<int> rightPreorder(preorder.begin() + leftSubtreeSize + 1, preorder.end());
            root->right = buildTree(rightPreorder, rightInorder);
        }

        return root;
    }
};
