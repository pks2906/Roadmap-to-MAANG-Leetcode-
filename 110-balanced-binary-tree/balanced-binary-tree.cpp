class Solution {
public:
    bool isBalanced(TreeNode *root) {
  
        return dfsHeight(root) != -1;
    }

private:
    int dfsHeight(TreeNode *root) {
 
        if (root == nullptr) return 0;

        int leftHeight = dfsHeight(root->left);
     
        if (leftHeight == -1) return -1;

        int rightHeight = dfsHeight(root->right);
    
        if (rightHeight == -1) return -1;

        if (std::abs(leftHeight - rightHeight) > 1) return -1;

        return std::max(leftHeight, rightHeight) + 1;
    }
};

