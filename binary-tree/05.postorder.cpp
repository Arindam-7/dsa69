// Recursive
class Solution {
public:
    vector<int> arr;
    vector<int> postorderTraversal(TreeNode* root) {
        if (root!= NULL){
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            arr.push_back(root->val);
        }
        
        return arr;
    }
};

// Iterative: Approach 1 (using 2 stacks)
class Solution {
  public: 
    vector<int> postorderTraversal(TreeNode* root) {
      stack<TreeNode* > st1;
      stack<TreeNode* > st2;
      vector<int> postorder;
      if(root == NULL) return postorder;

      st1.push(root);

      while(!st1.empty()) {
        root = st1.top();
        st1.pop();
        st2.push(root);
        if(root -> left != NULL) st1.push(root -> left);
        if(root -> right != NULL) st1.push(root -> right);
      }

      while(!st2.empty()) {
        TreeNode* temp = st2.top();
        st2.pop();
        postorder.push_back(temp -> val);
      }

      return postorder;
    }
};

// Iterative: Approach 2 (using 1 stack)
class Solution {
  public:
    vector<int> postorderTraversal(TreeNode* root) {
      stack<TreeNode* > st;
      vector<int> postorder;
      if(root == NULL) return postorder;

      st.push(root);

      while(!st.empty()) {
        root = st.top();
        st.pop();

        postorder.push_back(root -> val);

        if(root -> left != NULL) st.push(root -> left);
        if(root -> right != NULL) st.push(root -> right);
      }

      reverse(postorder.begin(), postorder.end());
      return postorder;
    }
};
