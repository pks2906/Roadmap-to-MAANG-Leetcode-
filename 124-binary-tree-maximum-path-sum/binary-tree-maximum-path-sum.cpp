class Solution {
public:
    int findMaxPathSum(TreeNode* root, int& maxi) {
        if (root == nullptr) {
            return 0;
        }

        int leftMaxPath = std::max(0, findMaxPathSum(root->left, maxi));
        int rightMaxPath = std::max(0, findMaxPathSum(root->right, maxi));

        // Use root->val instead of root->data
        maxi = std::max(maxi, leftMaxPath + rightMaxPath + root->val);

        return std::max(leftMaxPath, rightMaxPath) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        findMaxPathSum(root, maxi);
        return maxi;
    }
};
