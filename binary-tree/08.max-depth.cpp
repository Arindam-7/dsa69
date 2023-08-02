// recursive
int maxDepth(TreeNode* root) {
  if(root == NULL) return 0;

  int left = maxDepth(root -> left);
  int right = maxDepth(root -> right);

  return max(left+1, right+1);
}


// iterative
int maxDepth(TreeNode* root) {
  int count = 0;

  if(root == NULL) return count;

  queue<TreeNode* > q;
  q.push(root);

  while(!q.empty()) {
    count++;
    int size = q.size();
    for(int i = 0; i < size; i++) {
      TreeNode* curr = q.front();
      q.pop();
      if(curr -> left) q.push(curr -> left);
      if(curr -> right) q.push(curr -> right);
    }
  }

  return count;
}


