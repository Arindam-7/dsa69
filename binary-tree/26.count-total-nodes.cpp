// Approach 1- O(n) time, traversal
class Solution {
public:
    int ans = 0;

    int countNodes(TreeNode* root) {
        if(!root) return ans;

        countNodes(root->left);
        ans++;
        countNodes(root->right);

        return ans;
    }
};


// Approach 2 - O(logn^2) time 
class Solution {
public:
    int countNodes(TreeNode* root) {
      if(root == NULL) return 0;

      int leftHeight = 0, rightHeight = 0;

      TreeNode* l = root;
      TreeNode* r = root;

      while(l != NULL) {
        leftHeight++;
        l = l -> left;
      }

      while(r != NULL) {
        rightHeight++;
        r = r -> right;
      }
      
      if(leftHeight == rightHeight) {
        return pow(2, leftHeight) - 1;
      }

      return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};
