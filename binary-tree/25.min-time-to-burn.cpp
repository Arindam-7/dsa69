// Totally similar to the question 'Print all nodes at a distance K'

class Solution {
  
  unordered_map<Node*, Node*> child_parent_map;
  public:
    void preorder(Node* child, Node* parent) {
      if(child == NULL) return;

      child_parent_map[child] = parent;

      preorder(child -> left, child);
      preorder(child -> right, child);
    }

    void search(Node* root, int target, queue<Node *>& q) {
      if(root == NULL) return;

      if(root -> data == target) {
        q.push(root);
        return;
      }

      search(root -> left, target, q);
      search(root -> right, target, q);
    }

    int minTime(Node* root, int target) 
    {
      preorder(root, NULL);

      queue<Node* > q;
      search(root, target, q);
      
      unordered_set<Node* > visited;

      int ans = 0;

      while(!q.empty()) {
        int s = q.size();
        ans++;

        for(int i = 0; i < s; i++) {
          Node* temp = q.front();
          q.pop();
          
          visited.insert(temp);

          if(visited.count(temp -> left) == 0 && temp -> left) q.push(temp -> left);

          if(visited.count(temp -> right) == 0 && temp -> right) q.push(temp -> right);

          if(visited.count(child_parent_map[temp]) == 0 && child_parent_map[temp]) q.push(child_parent_map[temp]);

        }
      }

      return ans-1;
    }
};
