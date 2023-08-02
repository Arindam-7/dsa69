class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) 
            return true;
        
        return helper(root -> left, root -> right);
    }
    
    bool helper(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true;
        if(p == NULL || q == NULL)
            return false;
        
        if(p -> val != q -> val)
            return false;
        
        bool x = helper(p -> left, q -> right);
        bool y = helper(p -> right, q -> left);
        
        return x && y;
    }
};
