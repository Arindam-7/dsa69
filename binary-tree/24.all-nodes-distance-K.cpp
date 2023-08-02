class Solution {

  unordered_map<Node*, Node*> child_parent_map;
public:
    void preorder(Node* child, Node* parent) {
      if(child == NULL) return;

      child_parent_map[child] = parent;

      preorder(child -> left, child);
      preorder(child -> right, child);
    }
    
    void search(Node* root, int target, queue<Node* >& q) {
        if(!root) return;
        
        if(root -> data == target) {
            q.push(root);
            return;
        }
        
        search(root -> left, target, q);
        search(root -> right, target, q);
    }
    
    vector<int> KDistanceNodes(Node* root, int target, int k) {
      preorder(root, NULL);

      queue<Node* > q;
      unordered_set<Node* > visited;
      search(root, target, q);

      while(!q.empty() && k > 0) {
        k--;
        int s = q.size();

        for(int i = 0; i < s; i++) {
          Node* temp = q.front();
          q.pop();
          
          visited.insert(temp);


          if(visited.count(temp -> left) == 0 && temp -> left) q.push(temp -> left);

          if(visited.count(temp -> right) == 0 && temp -> right) q.push(temp -> right);

          if(visited.count(child_parent_map[temp]) == 0 && child_parent_map[temp]) q.push(child_parent_map[temp]);
        }
      }

      vector<int> ans;

      while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        ans.push_back(temp -> data);
      }
      
      sort(ans.begin(), ans.end());
      return ans;
    }
};
