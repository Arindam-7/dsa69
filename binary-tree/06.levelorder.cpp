vector<vector<int>> levelOrder(TreeNode* root) {
  vector<vector<int>> ans;

  if(root == NULL) return ans;

  queue<TreeNode* > q;
  q.push(root);

  while(!q.empty()) {
    vector<int> levelValues;
    int size = q.size();
    for(int i = 0; i < size; i++) {
      TreeNode* current = q.front();
      q.pop();

      levelValues.push_back(current -> val);

      if(current -> left != NULL) q.push(current -> left);
      if(current -> right != NULL) q.push(current -> right);
    }

    ans.push_back(levelValues);
  }

  return ans;
}
