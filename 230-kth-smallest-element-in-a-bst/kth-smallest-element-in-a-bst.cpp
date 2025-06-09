/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void inorder(TreeNode* node, int& count, int k, int& result) {
        if (!node || count >= k) return;

        inorder(node->left, count, k, result);

        count++;
        if (count == k) {
            result = node->val;
            return;
        }

        inorder(node->right, count, k, result);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int result = -1;
        inorder(root, count, k, result);
        return result;
    }
};
