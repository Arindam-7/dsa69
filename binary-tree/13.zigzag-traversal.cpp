// Approach 1 - Level order traversal + reverse
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> arr;
        if(root == NULL) return arr;
        
        queue<TreeNode*> q;
        q.push(root);
                
        bool right_to_left = false;
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> level_vals;
            for(int i = 0; i < size; i++) {
                TreeNode* current = q.front();
                q.pop();
                level_vals.push_back(current -> val);
                
                if(current -> left) 
                    q.push(current -> left);
                if(current -> right) 
                    q.push(current -> right);
            }   
                            
            if(right_to_left)
                reverse(level_vals.begin(), level_vals.end());
            
            arr.push_back(level_vals);
            
            right_to_left = !right_to_left;
        }
        return arr;
    }
};

// Approach 2 - without reverse operation
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> arr;
        if(root == NULL) return arr;
        
        queue<TreeNode*> q;
        q.push(root);
                
        bool left_to_right = true;
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> level_vals(size);
            
            for(int i = 0; i < size; i++) {
                TreeNode* current = q.front();
                q.pop();
                
                int index = left_to_right ? i : (size - 1 - i);
                
                level_vals[index] = current -> val;
                
                if(current -> left) 
                    q.push(current -> left);
                if(current -> right) 
                    q.push(current -> right);
            }  
            left_to_right = !left_to_right;
            
            arr.push_back(level_vals);
        }
        return arr;
    }
};
