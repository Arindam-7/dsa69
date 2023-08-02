class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        int left = height(root -> left);
        int right = height(root -> right);

        return abs(left - right) <= 1 && isBalanced(root -> left) && isBalanced(root -> right);
    }

    int height(TreeNode* root) {
        if(!root) return 0;
        return max(height(root -> left)+1, height(root -> right)+1);
    }
};

