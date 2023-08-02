class Solution {
public:
    vector <int> boundary(Node *root)
    {
      vector<int> ans;

      if(!root) return ans;

      if(!isLeaf(root)) ans.push_back(root -> data);

      addLeftBoundary(root, ans);
      addLeaf(root, ans);
      addRightBoundary(root, ans);

      return ans;
    }

    bool isLeaf(Node* root) {
      if(!root->left && !root->right) return true;

      return false;
    }

    void addLeftBoundary(Node* root, vector<int>& ans) {
      Node* curr = root->left;

      while(curr != NULL) {
        if(!isLeaf(curr)) ans.push_back(curr->data);

        if(curr->left) curr = curr->left;
        else curr = curr->right;
      }
    }

    void addRightBoundary(Node* root, vector<int>& ans) {
      Node* curr = root -> right;
      stack<int> st;

      while(curr != NULL) {
        if(!isLeaf(curr)) st.push(curr -> data);

        if(curr -> right) curr = curr -> right;
        else curr = curr -> left;
      }

      while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
      }
    }

    void addLeaf(Node* root, vector<int>& ans) {
      if(isLeaf(root)) ans.push_back(root -> data);

      if(root -> left) addLeaf(root -> left, ans);
      if(root -> right) addLeaf(root -> right, ans);
    }
};
