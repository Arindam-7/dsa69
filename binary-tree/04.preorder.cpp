// Recursive
class Solution {
public:
    vector<int> arr;
    vector<int> preorderTraversal(TreeNode* root) {
        if (root!= NULL){
            arr.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        
        return arr;
    }
};


// Iterative
class Solution {
  public:
    vector<int> preorderTraversal(TreeNode* root) {
      vector<int> preorder;
      if(root == NULL) return preorder;

      stack<TreeNode* > st;
      st.push(root);

      while(!st.empty()) {
        root = st.top();
        st.pop();

        preorder.push_back(root -> val);

        if(root -> right != NULL) st.push(root -> right);
        
        if(root -> left != NULL) st.push(root -> left);
      }

      return preorder;
    }
};
