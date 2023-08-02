// recursive
int minDepth(TreeNode* root) {
  if(root == NULL) return 0;

  int left = minDepth(root -> left);
  int right = minDepth(root -> right);

  if(left == 0 || right == 0) return max(left+1, right+1);

  return min(left+1, right+1);
}


// iterative
class Solution {
public:
    int minDepth(TreeNode* root) {
        int depth = 0;
        if(root == NULL)
            return depth;
        
        queue<TreeNode *> q;
        q.push(root);
        
        while(!q.empty()) {
            depth++;
            int size = q.size();
            
            for(int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                
                if(curr -> left == NULL && curr -> right == NULL)
                    return depth;
                
                if(curr -> left)
                    q.push(curr -> left);
                if(curr -> right)
                    q.push(curr -> right);
            }
        }
        return -1;
    }
};
