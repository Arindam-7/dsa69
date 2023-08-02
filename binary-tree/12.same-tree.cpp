class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        
        if(p -> val != q -> val) return false;
        
        bool x = isSameTree(p -> left, q -> left);
        bool y = isSameTree(p -> right, q -> right);
        
        return x && y;
    } 
};
