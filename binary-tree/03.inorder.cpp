// Recursive 
class Solution {
public:
    vector<int> arr;
    vector<int> inorderTraversal(TreeNode* root) {
        if (root!= NULL){
            inorderTraversal(root->left);
            arr.push_back(root->val);
            inorderTraversal(root->right);
        }
        
        return arr;
    }
};


// Iterative
class Solution {
  public:
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> inorder;
      stack<TreeNode* > st;
      TreeNode* node = root;

      while(1) {
        if(node != NULL) {
          st.push(node);
          node = node -> left;
        }
        else {
          if(st.empty()) break;

          node = st.top();
          st.pop();
          inorder.push_back(node -> val);
          node = node -> right;
        }
      }

      return inorder;
    }
};
