// BFS
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;
        
        q.push({root, {0, 0}});
        
        bfs(q, 0, 0, nodes);
        
        vector<vector<int>> ans;
        for(auto i : nodes) {
            vector<int> col;
            
            auto s = i.second;
            for(auto r : s) {
                col.insert(col.end(), r.second.begin(), r.second.end());
            }
            ans.push_back(col);
        }
        
        return ans;
    }

    void bfs(queue<pair<TreeNode*, pair<int, int>>>& q, int x, int y, map<int, map<int, multiset<int>>>& nodes) {
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            
            TreeNode* node = p.first;
            int x = p.second.first;
            int y = p.second.second;
            
            nodes[x][y].insert(node -> val);
            
            if(node -> left) {
                q.push({node -> left, {x - 1, y + 1}});
            }
            if(node -> right) {
                q.push({node -> right, {x + 1, y + 1}});
            }
        }
    }
};


// DFS
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;        
        vector<vector<int>> ans;

        dfs(root, 0, 0, nodes);

        for(auto i : nodes) {
            vector<int> col;
            
            auto s = i.second;
            for(auto r : s) {
                col.insert(col.end(), r.second.begin(), r.second.end());
            }
            ans.push_back(col);
        }
        
        return ans;
    }
    
    // pre-order traversal for dfs
    void dfs(TreeNode* root, int x, int y, map<int, map<int, multiset<int>>>& nodes) {
        if(root == NULL) return;

        nodes[x][y].insert(root -> val);

        if(root -> left) dfs(root -> left, x-1, y+1, nodes);
        if(root -> right) dfs(root -> right, x+1, y+1, nodes);
    }
};
