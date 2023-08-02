class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        reverse_preorder(root, 0, res);
        return res;
    }

    void reverse_preorder(TreeNode* root, int level, vector<int>& res) {
      if(root == NULL) return ;

      // if res size is equal to level, hence we are visiting that level for the first time
      if(res.size() == level) res.push_back(root -> val);

      reverse_preorder(root -> right, level+1, res);
      reverse_preorder(root -> left, level+1, res);
    }
};

